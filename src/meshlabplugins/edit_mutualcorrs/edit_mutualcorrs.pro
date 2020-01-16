include (../../shared.pri)

HEADERS += ./alignset.h \
    ./levmarmethods.h \
    ./mutual.h \
    ./parameters.h \
    ./shutils.h \
    ./solver.h \
    ./edit_mutualcorrs.h \
    ./edit_mutualcorrsDialog.h \
    ./edit_mutualcorrs_factory.h

SOURCES += ./alignset.cpp \
    ./edit_mutualcorrs.cpp \
    ./edit_mutualcorrsDialog.cpp \
    ./edit_mutualcorrs_factory.cpp \
    ./solver.cpp \
    ./levmarmethods.cpp \
    ./mutual.cpp \
    ./parameters.cpp

TARGET        = edit_mutualcorrs

RESOURCES     = edit_mutualcorrs.qrc

FORMS         = edit_mutualcorrsDialog.ui

INCLUDEPATH *= ../../external/levmar-2.3 ../../external/newuoa/include

win32-msvc:  LIBS += ../../external/lib/win32-msvc/levmar.lib
win32-g++:LIBS += -L../../external -llevmar
linux-g++:LIBS += -llevmar
macx:LIBS            += $$MACLIBDIR/liblevmar.a

