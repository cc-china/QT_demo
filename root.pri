ROOT_PATH = $${_PRO_FILE_PWD_}/../..
ROOT_TS_PATH = $${ROOT_PATH}/res
ROOT_TS_LIST = \
    $${ROOT_TS_PATH}/root_en_US.ts

LOCAL_INC_PATH = inc
LOCAL_SRC_PATH = src
LOCAL_UI_PATH = ui
LOCAL_LIB_PATH = lib
OUT_PATH = $${ROOT_PATH}/out
OBJ_PATH = $${ROOT_PATH}/../obj
MAKEFILE_PATH = $${OBJ_PATH}

CONFIG += warn_on

CONFIG(debug, debug|release):{
    DESTDIR = $${OUT_PATH}/debug/bin
    OUT_CFG_DIR = $${OUT_PATH}/debug/cfg
    OUT_DATA_DIR = $${OUT_PATH}/debug/data
    OUT_DOC_DIR = $${OUT_PATH}/debug/doc
}
CONFIG(release, debug|release):{
    DESTDIR = $${OUT_PATH}/release/bin
    OUT_CFG_DIR = $${OUT_PATH}/release/cfg
    OUT_DATA_DIR = $${OUT_PATH}/release/data
    OUT_DOC_DIR = $${OUT_PATH}/release/doc
}

INCLUDEPATH += $${_PRO_FILE_PWD_}/$${LOCAL_INC_PATH} \
                $${ROOT_PATH}/inc
DEPENDPATH += $${DESTDIR}
