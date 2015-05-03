TEMPLATE = app

QT += qml quick multimedia

SOURCES += main.cpp

INCLUDEPATH += ../lib
win32 {
    LIBS += -L../lib/debug -lhummbeere
} else {
    LIBS += -L../lib -lhummbeere
}

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)
