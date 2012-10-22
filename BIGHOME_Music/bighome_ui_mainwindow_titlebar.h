#ifndef BIGHOME_UI_MAINWINDOW_TITLEBAR_H
#define BIGHOME_UI_MAINWINDOW_TITLEBAR_H

#include <QWidget>
#include "ui_bighome_ui_mainwindow_titlebar.h"

class BIGHOME_UI_MainWindow_titleBar : public QWidget
{
    Q_OBJECT

public:
    BIGHOME_UI_MainWindow_titleBar(QWidget *parent = 0);
    ~BIGHOME_UI_MainWindow_titleBar();
private:
    void init();
    void setstyle();

private:
    Ui::BIGHOME_UI_MainWindow_titleBarClass ui;
};

#endif // BIGHOME_UI_MAINWINDOW_TITLEBAR_H
