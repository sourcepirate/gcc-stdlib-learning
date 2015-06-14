TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += link_pkgconfig
PKGCONFIG += gstreamer-0.10
SOURCES += main.c

OTHER_FILES += \
    README.md

