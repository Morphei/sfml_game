TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -L"/home/morphei/Libraries/SFML 2.3/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += "/home/morphei/Libraries/SFML 2.3/include"
DEPENDPATH += "/home/morphei/Libraries/SFML 2.3/include"

SOURCES += main.cpp \
    menu.cpp \
    gamemap.cpp \
    resourceholder.inl \
    game.cpp \
    networkoperator.cpp \
    parser.cpp \
    application.cpp \
    gamestates.cpp \
    button.cpp \
    resourcemanager.cpp \
    player.cpp \
    world.cpp \
    entity.cpp \
    animation.cpp \
    entitymanager.cpp \
    enemy.cpp \
    entityconfigurator.cpp \
    networkconfiguration.cpp \
    form.cpp \
    textbox.cpp \
    formmanager.cpp \
    messagesender.cpp

HEADERS += \
    menu.h \
    gamemap.h \
    resourceholder.hpp \
    game.h \
    networkoperator.h \
    parser.h \
    application.h \
    gamestates.h \
    button.h \
    resourcemanager.h \
    player.h \
    world.h \
    entity.h \
    animation.h \
    entitymanager.h \
    enemy.h \
    entityconfigurator.h \
    networkconfiguration.h \
    form.h \
    textbox.h \
    formmanager.h \
    messagesender.h

CONFIG += c++11

CONFIG += link_pkgconfig
PKGCONFIG += x11
