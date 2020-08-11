QT -= gui

TEMPLATE = lib
DEFINES += UTIL_LIBRARY

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


TARGET = util
QMAKE_EXT_OBJ += .so

!include(../../root.pri) {
    message("No find file root.pri")
}

SOURCES += \
    $${LOCAL_SRC_PATH}/util.cpp \
    $${LOCAL_SRC_PATH}/hlog.cpp

HEADERS += \
    $${LOCAL_INC_PATH}/util_global.h \
    $${LOCAL_INC_PATH}/util.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

#hyn added, start
CONFIG(debug, debug|release):{
    OBJECTS_DIR = $${OBJ_PATH}/debug/$${TARGET}
    MOC_DIR = $${OBJ_PATH}/debug/$${TARGET}
    OUT_PWD = $${MAKEFILE_PATH}/debug/$${TARGET}
}
CONFIG(release, debug|release):{
    OBJECTS_DIR = $${OBJ_PATH}/release/$${TARGET}
    MOC_DIR = $${OBJ_PATH}/release/$${TARGET}
    OUT_PWD = $${MAKEFILE_PATH}/release/$${TARGET}
}
#hyn added, end
