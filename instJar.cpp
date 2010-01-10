#include "instJar.h"
#include "listScreen.h"
#include <QStackedWidget>

instJar::instJar(QWidget *parent, Qt::WFlags)
    :QStackedWidget(parent)
{
    _listScreen = 0;
    setCurrentWidget(listScreen());
}

ListScreen* instJar::listScreen()
{
    if(!_listScreen)
    {
	_listScreen = new ListScreen(this);
	addWidget(_listScreen);
    }
    return _listScreen;
}
    
