#ifndef BIGHOME_RADIO_LRC_H
#define BIGHOME_RADIO_LRC_H

#include <QWidget>
#include "ui_bighome_radio_lrc.h"

class BIGHOME_Radio_lrc : public QWidget
{
    Q_OBJECT

public:
    BIGHOME_Radio_lrc(QWidget *parent = 0);
    ~BIGHOME_Radio_lrc();

private:
    Ui::BIGHOME_Radio_lrcClass ui;
};

#endif // BIGHOME_RADIO_LRC_H
