TEMPLATE = subdirs
SUB_MODULE = main \
            util

SUBDIR_SRC_PATH = src

for(module, SUB_MODULE) {
    SUBDIRS += $${SUBDIR_SRC_PATH}/$${module}
}
