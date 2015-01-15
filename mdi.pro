QT += widgets

HEADERS       = mainwindow.h \
                mdichild.h \
    windowexample.h \
    isubwindow.h
SOURCES       = main.cpp \
                mainwindow.cpp \
                mdichild.cpp \
    windowexample.cpp
RESOURCES     = mdi.qrc

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/mainwindows/mdi
INSTALLS += target

FORMS += \
    windowexample.ui
