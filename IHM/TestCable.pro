QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# Vous pouvez définir cette option pour désactiver les API dépréciées avant Qt 6.0.0
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

# Liste des fichiers source
SOURCES += \
    aide.cpp \
    clicablelabel.cpp \
    main.cpp \
    readchip.cpp \
    testcable.cpp

# Liste des fichiers d'en-tête
HEADERS += \
    aide.h \
    clicablelabel.h \
    ftd2xx.h \
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

# Spécification du chemin vers la bibliothèque FTD2XX
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libFTD2XX/amd64 -lftd2xx
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libFTD2XX/amd64 -lftd2xx

# Inclusion et dépendance pour la bibliothèque FTD2XX
INCLUDEPATH += $$PWD/../libFTD2XX
DEPENDPATH += $$PWD/../libFTD2XX

# Spécification du chemin vers la bibliothèque SQLite
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../sqlite3 -lsqlite3
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../sqlite3 -lsqlite3

# Inclusion et dépendance pour la bibliothèque SQLite
INCLUDEPATH += $$PWD/../sqlite3/sqlite-amalgamation-3430100
DEPENDPATH += $$PWD/../sqlite3/sqlite-amalgamation-3430100

DISTFILES += \
    USBRS232.jpg \
    USBRS485.jpg \
    USBTTL3V3.jpg \
    USBTTL3V3REG.jpg \
    USBTTL5V.jpg

RESOURCES += \
    images.qrc
