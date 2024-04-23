QT       += core gui
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# Vous pouvez définir cette option pour désactiver les API dépréciées avant Qt 6.0.0
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

# Liste des fichiers source
SOURCES += \
    Lib/sqlite3/sqlite-amalgamation-3430100/shell.c \
    Lib/sqlite3/sqlite-amalgamation-3430100/sqlite3.c \
    aide.cpp \
    clicablelabel.cpp \
    datecode.cpp \
    main.cpp \
    progchip.cpp \
    readchip.cpp \
    testcable.cpp

# Liste des fichiers d'en-tête
HEADERS += \
    Lib/libFTD2XX/ftd2xx.h \
    Lib/sqlite3/sqlite-amalgamation-3430100/sqlite3.h \
    Lib/sqlite3/sqlite-amalgamation-3430100/sqlite3ext.h \
    aide.h \
    clicablelabel.h \
    datecode.h \
    ftd2xx.h \
    progchip.h \
    readchip.h \
    testcable.h

# Liste des formulaires Qt Designer
FORMS += \
    aide.ui \
    testcable.ui

# Configuration des règles de déploiement
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

copy.path = $$OUT_PWD
copy.files = BDD.db
QMAKE_PRE_LINK += $$copy

DISTFILES += \
    BDD.db \
    Lib/libFTD2XX/Static/amd64/ftd2xx.lib \
    Lib/libFTD2XX/Static/i386/ftd2xx.lib \
    Lib/libFTD2XX/amd64/ftbusui.dll \
    Lib/libFTD2XX/amd64/ftcserco.dll \
    Lib/libFTD2XX/amd64/ftd2xx.lib \
    Lib/libFTD2XX/amd64/ftd2xx64.dll \
    Lib/libFTD2XX/amd64/ftdibus.sys \
    Lib/libFTD2XX/amd64/ftlang.dll \
    Lib/libFTD2XX/amd64/ftser2k.sys \
    Lib/libFTD2XX/amd64/ftserui2.dll \
    Lib/libFTD2XX/ftdibus.cat \
    Lib/libFTD2XX/ftdibus.inf \
    Lib/libFTD2XX/ftdiport.cat \
    Lib/libFTD2XX/ftdiport.inf \
    Lib/libFTD2XX/i386/ftbusui.dll \
    Lib/libFTD2XX/i386/ftcserco.dll \
    Lib/libFTD2XX/i386/ftd2xx.dll \
    Lib/libFTD2XX/i386/ftd2xx.lib \
    Lib/libFTD2XX/i386/ftdibus.sys \
    Lib/libFTD2XX/i386/ftlang.dll \
    Lib/libFTD2XX/i386/ftser2k.sys \
    Lib/libFTD2XX/i386/ftserui2.dll \
    Lib/sqlite3/sqlite3.def \
    Lib/sqlite3/sqlite3.dll \
    Lib/sqlite3/sqlite3.exp \
    Lib/sqlite3/sqlite3.lib \
    USBRS232.jpg \
    USBRS485.jpg \
    USBTTL3V3.jpg \
    USBTTL3V3REG.jpg \
    USBTTL5V.jpg

RESOURCES += \
    images.qrc

INCLUDEPATH += $$PWD/Lib/libFTD2XX
DEPENDPATH += $$PWD/Lib/libFTD2XX/amd64

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/Lib/libFTD2XX/amd64/ -lftd2xx
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/Lib/libFTD2XX/amd64/ -lftd2xx

INCLUDEPATH += $$PWD/Lib/sqlite3/sqlite-amalgamation-3430100
DEPENDPATH += $$PWD/Lib/sqlite3

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/Lib/sqlite3/ -lsqlite3
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/Lib/sqlite3/ -lsqlite3
