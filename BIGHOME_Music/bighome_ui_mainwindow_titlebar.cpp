#include "bighome_ui_mainwindow_titlebar.h"

BIGHOME_UI_MainWindow_titleBar::BIGHOME_UI_MainWindow_titleBar(QWidget *parent)
    : QWidget(parent)
{
  ui.setupUi(this);
  init();
  setstyle();
}

BIGHOME_UI_MainWindow_titleBar::~BIGHOME_UI_MainWindow_titleBar()
{

}
void BIGHOME_UI_MainWindow_titleBar::init()
{
  ui.smallBtn->setText("");
  ui.closeBtn->setText("");
  ui.aboutBtn->setText("");
}
void BIGHOME_UI_MainWindow_titleBar::setstyle()
{
  ui.smallBtn->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//small.png);} QPushButton::hover {border: none; border-image:url(.//Resources//smalls.png);}");
  ui.closeBtn->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//close.png);} QPushButton::hover {border: none; border-image:url(.//Resources//closes.png);}");
  ui.aboutBtn->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//about.png);} QPushButton::hover {border: none; border-image:url(.//Resources//abouts.png);}");
}
