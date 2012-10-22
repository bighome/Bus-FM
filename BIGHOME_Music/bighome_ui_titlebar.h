#ifndef BIGHOME_UI_TITLEBAR_H
#define BIGHOME_UI_TITLEBAR_H

#include <QWidget>
#include "ui_bighome_ui_titlebar.h"

class BIGHOME_UI_titleBar : public QWidget
{
    Q_OBJECT

public:
    BIGHOME_UI_titleBar(QWidget *parent = 0);
    ~BIGHOME_UI_titleBar();

private:
    Ui::BIGHOME_UI_titleBarClass ui;
};

#endif // BIGHOME_UI_TITLEBAR_H
