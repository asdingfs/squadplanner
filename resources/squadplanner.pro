HEADERS       = ../src/mainwindow.h
SOURCES       = ../src/main.cpp \
                ../src/mainwindow.cpp
RESOURCES     = squadplanner.qrc

# install
target.path = $$[QT_INSTALL_EXAMPLES]/mainwindows/squadplanner
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS squadplanner.pro images
sources.path = $$[QT_INSTALL_EXAMPLES]/mainwindows/squadplanner
INSTALLS += target sources
