QT += opengl core gui svg xml network
TEMPLATE = lib
TARGET = tupipen

INSTALLS += target
target.path = /lib/

macx {
    CONFIG += staticlib warn_on
} else {
    CONFIG += dll warn_on
}

HEADERS += tuppenwidget.h 
           # tuppenthicknesswidget.h
SOURCES += tuppenwidget.cpp 
           # tuppenthicknesswidget.cpp

FRAMEWORK_DIR = "../../framework"
include($$FRAMEWORK_DIR/framework.pri)

unix {
    STORE_DIR = ../../store/
    INCLUDEPATH += $$STORE_DIR
    LIBS += -L$$STORE_DIR -ltupistore

    LIBBASE_DIR = ../../libbase/
    INCLUDEPATH += $$LIBBASE_DIR
    LIBS += -L$$LIBBASE_DIR -ltupibase

    LIBTUPI_DIR = ../../libtupi/
    INCLUDEPATH += $$LIBTUPI_DIR
    LIBS += -L$$LIBTUPI_DIR -ltupi

    !include(../../../tupiglobal.pri) {
             error("Run ./configure first!")
    }
}

win32 {
    include(../../../win.pri)

    STORE_DIR = ../../store/
    INCLUDEPATH += $$STORE_DIR
    LIBS += -L$$STORE_DIR/release/ -ltupistore

	LIBBASE_DIR = ../../libbase/
    INCLUDEPATH += $$LIBBASE_DIR
    LIBS += -L$$LIBBASE_DIR/release/ -ltupibase

	LIBTUPI_DIR = ../../libtupi/
    INCLUDEPATH += $$LIBTUPI_DIR
    LIBS += -L$$LIBTUPI_DIR/release/ -ltupi 
}
