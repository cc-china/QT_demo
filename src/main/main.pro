QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

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


TARGET = hynitron_touch_tool

!include(../../root.pri) {
    message("No find file root.pri")
}

SOURCES += \
    $${LOCAL_SRC_PATH}/main.cpp \
    $${LOCAL_SRC_PATH}/mainwindow.cpp \
    src/mylistbuddy.cpp \
    src/openfilewindow.cpp \
    ui/detailspage.cpp \
    ui/featruedialog.cpp \
    ui/featureitemview.cpp \
    ui/slidingnavigation.cpp

HEADERS += \
    $${LOCAL_INC_PATH}/mainwindow.h \
    src/featureitemmodel.h \
    src/mylistbuddy.h \
    src/openfilewindow.h \
    ui/detailspage.h \
    ui/featruedialog.h \
    ui/featureitemview.h \
    ui/slidingnavigation.h

FORMS += \
    $${LOCAL_UI_PATH}/mainwindow.ui \
    ui/detailspage.ui \
    ui/featruedialog.ui \
    ui/featureitemview.ui \
    ui/slidingnavigation.ui

TRANSLATIONS += \
    $${ROOT_TS_LIST}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
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
LIBS += -L$${DESTDIR} -lutil
#hyn added, end

DISTFILES +=

RESOURCES += \
    main.qrc
