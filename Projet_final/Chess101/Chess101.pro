QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Case.cpp \
    Echequier.cpp \
    EtatJeu.cpp \
    Piece.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Case.h \
    Echequier.h \
    EtatJeu.h \
    Piece.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    pieces_png/Chess_bdt45.png \
    pieces_png/Chess_blt45.png \
    pieces_png/Chess_ndt45.png \
    pieces_png/Chess_nlt45.png \
    pieces_png/Chess_pdt45.png \
    pieces_png/Chess_plt45.png \
    pieces_png/Chess_qdt45.png \
    pieces_png/Chess_qlt45.png \
    pieces_png/Chess_rdt45.png \
    pieces_png/Chess_rlt45.png

RESOURCES += \
    piecesRessources.qrc
