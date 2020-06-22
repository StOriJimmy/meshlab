include (../general.pri)
EXIF_DIR = ../external/jhead-3.04

QT += opengl
QT += xml
QT += xmlpatterns

TEMPLATE = lib
TARGET = meshlab-common
DEPENDPATH += .

DESTDIR = $$MESHLAB_DISTRIB_DIRECTORY/lib

win32-msvc:CONFIG += staticlib
win32-g++:DLLDESTDIR = $$MESHLAB_DISTRIB_DIRECTORY/lib

linux:CONFIG += dll

INCLUDEPATH *= \
    ../.. \
    $$VCGDIR \
    $$EIGENDIR \
    $$EXIF_DIR

!CONFIG(system_glew) {
    INCLUDEPATH *= $$GLEWDIR/include
    GLEWCODE = $$GLEWDIR/src/glew.c
}

!CONFIG(system_glew) {
    SOURCES += $$GLEWCODE
    DEFINES += GLEW_STATIC
}

# defining meshlab version
exists(../../ML_VERSION){
    MESHLAB_VERSION = $$cat(../../ML_VERSION)
    message(MeshLab Version: $$MESHLAB_VERSION)
    DEFINES += "MESHLAB_VERSION=$$MESHLAB_VERSION"
}

# Input
HEADERS += 	\
    GLExtensionsManager.h \
    filterparameter.h \
    filterscript.h \
    GLLogStream.h \
    interfaces.h \
    ml_mesh_type.h \
    meshmodel.h \
    pluginmanager.h \
    mlexception.h \
    mlapplication.h \
    meshlabdocumentxml.h \
    ml_shared_data_context.h \
    ml_selection_buffers.h \
    meshlabdocumentxml.h

SOURCES += \
    GLExtensionsManager.cpp \
    filterparameter.cpp \
    interfaces.cpp \
    filterscript.cpp \
    GLLogStream.cpp \
    meshmodel.cpp \
    pluginmanager.cpp \
    mlapplication.cpp \
    searcher.cpp \
    meshlabdocumentxml.cpp \
    meshlabdocumentbundler.cpp \
    ml_shared_data_context.cpp \
    ml_selection_buffers.cpp

macx:QMAKE_POST_LINK = "\
    if [ -d  $$MESHLAB_DISTRIB_DIRECTORY/meshlab.app/Contents/Frameworks/ ]; \
    then  \
        echo "Copying";  \
    else  \
        mkdir -p $$MESHLAB_DISTRIB_DIRECTORY/meshlab.app/Contents/Frameworks;  \
    fi;   \
    cp $$MESHLAB_DISTRIB_DIRECTORY/lib/libmeshlab-common.* $$MESHLAB_DISTRIB_DIRECTORY/meshlab.app/Contents/Frameworks/ ;\
#    if [ -d ../external/ ];\
#    then \
#        echo "ok external dir exists"; \
#    else \
#        ln -s ../../meshlab/src/external ../external;\
#        echo "linked external dir"; \
#    fi;\
#    if [ -d $$MESHLAB_DISTRIB_DIRECTORY/shaders/ ];\
#    then \
#        echo "ok shader dir exists"; \
#    else \
#        ln -s ../../../meshlab/src/distrib/shaders ../distrib/shaders ;\
#        echo "linked shader dir"; \
#    fi;\
    "

