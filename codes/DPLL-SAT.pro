QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Clause.cpp \
    DPLL.cpp \
    dpll_widget.cpp \
    main.cpp \
    mainwindow.cpp \
    sudoku_dialog.cpp \
    sudoku_widget.cpp

HEADERS += \
    Clause.h \
    dpll_widget.h \
    mainwindow.h \
    sudoku_dialog.h \
    sudoku_widget.h

FORMS += \
    mainwindow.ui \
    dpll_widget.ui \
    sudoku_dialog.ui \
    sudoku_widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    SAT测试/sat-20.cnf

RESOURCES += \
    res.qrc
