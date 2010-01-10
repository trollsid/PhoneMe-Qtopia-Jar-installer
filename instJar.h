#ifndef INSTJAR_H
#define INSTJAR_H

#include <QContent>
#include <QDialog>
#include <QStackedWidget>

class ListScreen;

class instJar:public QStackedWidget
{
    Q_OBJECT
public:
    instJar(QWidget *parent = 0, Qt::WFlags = 0);
    ListScreen *listScreen();
private:
    ListScreen *_listScreen;
};
#endif
