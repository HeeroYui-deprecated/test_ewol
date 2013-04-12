

###############################################################################
### Files Listes                                                            ###
###############################################################################

# Globals debug tool:
FILE_LIST:=		appl/Debug.cpp \
                appl/init.cpp \
                appl/MainWindows.cpp \
                appl/TestButton.cpp \
                appl/TestImage.cpp \
                appl/TestButtonColor.cpp \
                appl/TestLabel.cpp \
                appl/TestScene.cpp

LOCAL_COPY_FOLDERS := ../data/icon.*: \
                      ../data/cube.*: \
                      ../data/grass.*: \
                      ../data/stone*: \
                      ../data/sphere.png: \
                      ../data/sphere.obj:

ifneq ($(__EWOL_INTEGRATED_FONT__),$(empty))
LOCAL_COPY_FILES := ../data/FreeSerif*:fonts/FreeSerif.ttf
endif
