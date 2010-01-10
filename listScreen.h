#ifndef LISTSCREEN_H
#define LISTSCREEN_H

#include <QListWidget>
#include <QApplication>
#include <QContent>

class instJar;
class QAction;
class QContentSet;
class QContentSetModel;

class ListScreen: public QListWidget
{
    Q_OBJECT
public:
    ListScreen(instJar *_instJar);
protected:
    void setupContent();
    void populate();
public slots:
    void updateList(QContentList a, QContent::ChangeType b);
    void onSelectJar(const QModelIndex &index);
private:
    void onOpenJar(int row);
    instJar *_instJar;
    QContentSet *_cs;
    QContentSetModel *_csm; 
};

#endif