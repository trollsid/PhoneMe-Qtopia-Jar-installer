qtopia_project(qtopia app)
    
TARGET = instjar

CONFIG+=qtopia_main no_singleexec no_quicklaunch no_tr
            
HEADERS += instJar.h  listScreen.h
SOURCES += main.cpp instJar.cpp listScreen.cpp
