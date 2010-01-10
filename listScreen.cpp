#include "listScreen.h"
#include "instJar.h"

#include <QContentSet>
#include <QContentSetModel>
#include <QIcon>
#include <QListWidgetItem>
#include <QDebug>
#include <Qtopia>
#include <QProcess>
ListScreen::ListScreen(instJar *instJar)
:QListWidget(instJar), _instJar(instJar)
{
    setupContent();
    populate();
    connect(this, SIGNAL(activated(const QModelIndex&)),
                    this, SLOT(onSelectJar(const QModelIndex&)));
}

void ListScreen::setupContent()
{
    _cs  = new QContentSet(QContentFilter::MimeType, "application/java-archive", this);
    _csm = new QContentSetModel(_cs, this);
}

void ListScreen::populate()
{
    clear();
    foreach (QContent c, _cs->items()) 
    {
	QListWidgetItem *i = new QListWidgetItem(this);
	QIcon icon(c.file());
	i->setText(c.name());
	i->setIcon(icon);
    }
    if(count() > 0) 
    {
	QListWidgetItem *i = item(0);
	setCurrentItem(i);
    }
}

void ListScreen::updateList(QContentList a, QContent::ChangeType b)
{
    populate();
}

void ListScreen::onSelectJar(const QModelIndex& index)
{
    onOpenJar(currentIndex().row());
}

void ListScreen::onOpenJar(int row)
{
    QContent c = _cs->content(row);
    QString jarPath = "file:///" + c.fileName();
    QString arg1 = "internal";
    QString classPath = "com.sun.midp.scriptutil.CommandLineInstaller";
    QString arg2 = "I";
    QString appName = Qtopia::qtopiaDir()+"bin"+"/runMidlet";
    qDebug() << appName << jarPath;
    QStringList args;
    args << arg1 << classPath << arg2 << jarPath;
    QProcess::execute(appName, args);
}
