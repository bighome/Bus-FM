#ifndef BIGHOME_UI_COMMENTSMANAGER_H
#define BIGHOME_UI_COMMENTSMANAGER_H

#include <QWidget>
#include "ui_bighome_ui_commentsmanager.h"

class BIGHOME_UI_commentsManager : public QWidget
{
    Q_OBJECT

public:
    BIGHOME_UI_commentsManager(QWidget *parent = 0);
    ~BIGHOME_UI_commentsManager();
    void setComments(int value);

private:
    void init();
    void setStyle();

private slots:
    void slotStar1();
    void slotStar2();
    void slotStar3();
    void slotStar4();
    void slotStar5();

signals:
    void signalComments(int value);

private:
    Ui::BIGHOME_UI_commentsManagerClass ui;
    static int s_comments;
};

#endif // BIGHOME_UI_COMMENTSMANAGER_H
