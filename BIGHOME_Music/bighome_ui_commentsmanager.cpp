#include "bighome_ui_commentsmanager.h"

int BIGHOME_UI_commentsManager::s_comments = 0;
BIGHOME_UI_commentsManager::BIGHOME_UI_commentsManager(QWidget *parent)
    : QWidget(parent)
{
  ui.setupUi(this);
  connect(ui.star1, SIGNAL(pressed()), this, SLOT(slotStar1()));
  connect(ui.star2, SIGNAL(pressed()), this, SLOT(slotStar2()));
  connect(ui.star3, SIGNAL(pressed()), this, SLOT(slotStar3()));
  connect(ui.star4, SIGNAL(pressed()), this, SLOT(slotStar4()));
  connect(ui.star5, SIGNAL(pressed()), this, SLOT(slotStar5()));
  init();
  setStyle();
}

BIGHOME_UI_commentsManager::~BIGHOME_UI_commentsManager()
{

}
void BIGHOME_UI_commentsManager::init()
{
  this->setMaximumSize(QSize(74, 20));
  this->setMinimumSize(QSize(74, 20));
  ui.star1->setMaximumSize(QSize(12, 12));
  ui.star1->setMinimumSize(QSize(12, 12));
  ui.star1->setText("");

  ui.star2->setMaximumSize(QSize(12, 12));
  ui.star2->setMinimumSize(QSize(12, 12));
  ui.star2->setText("");

  ui.star3->setMaximumSize(QSize(12, 12));
  ui.star3->setMinimumSize(QSize(12, 12));
  ui.star3->setText("");

  ui.star4->setMaximumSize(QSize(12, 12));
  ui.star4->setMinimumSize(QSize(12, 12));
  ui.star4->setText("");

  ui.star5->setMaximumSize(QSize(12, 12));
  ui.star5->setMinimumSize(QSize(12, 12));
  ui.star5->setText("");
}
void BIGHOME_UI_commentsManager::setStyle()
{
  ui.star1->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//star.png);}");
  ui.star2->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//star.png);}");
  ui.star3->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//star.png);}");
  ui.star4->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//star.png);}");
  ui.star5->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//star.png);}");
}
void BIGHOME_UI_commentsManager::slotStar1()
{
  ui.star1->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//starPress.png);}");
  ui.star2->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//star.png);}");
  ui.star3->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//star.png);}");
  ui.star4->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//star.png);}");
  ui.star5->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//star.png);}");
  s_comments = 1;
  emit signalComments(s_comments);
}
void BIGHOME_UI_commentsManager::slotStar2()
{
  ui.star1->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//starPress.png);}");
  ui.star2->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//starPress.png);}");
  ui.star3->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//star.png);}");
  ui.star4->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//star.png);}");
  ui.star5->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//star.png);}");
  s_comments = 2;
  emit signalComments(s_comments);
}
void BIGHOME_UI_commentsManager::slotStar3()
{
  ui.star1->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//starPress.png);}");
  ui.star2->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//starPress.png);}");
  ui.star3->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//starPress.png);}");
  ui.star4->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//star.png);}");
  ui.star5->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//star.png);}");
  s_comments = 3;
  emit signalComments(s_comments);
}
void BIGHOME_UI_commentsManager::slotStar4()
{
  ui.star1->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//starPress.png);}");
  ui.star2->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//starPress.png);}");
  ui.star3->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//starPress.png);}");
  ui.star4->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//starPress.png);}");
  ui.star5->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//star.png);}");
  s_comments = 4;
  emit signalComments(s_comments);
}
void BIGHOME_UI_commentsManager::slotStar5()
{
  ui.star1->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//starPress.png);}");
  ui.star2->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//starPress.png);}");
  ui.star3->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//starPress.png);}");
  ui.star4->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//starPress.png);}");
  ui.star5->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//starPress.png);}");
  s_comments = 5;
  emit signalComments(s_comments);
}
void BIGHOME_UI_commentsManager::setComments(int value)
{
  switch(value){
        case 0:
          ui.star1->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//star.png);}");
          ui.star2->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//star.png);}");
          ui.star3->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//star.png);}");
          ui.star4->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//star.png);}");
          ui.star5->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//star.png);}");
          break;
    case 1:
      ui.star1->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//starPress.png);}");
      ui.star2->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//star.png);}");
      ui.star3->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//star.png);}");
      ui.star4->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//star.png);}");
      ui.star5->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//star.png);}");
      break;
    case 2:
      ui.star1->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//starPress.png);}");
      ui.star2->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//starPress.png);}");
      ui.star3->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//star.png);}");
      ui.star4->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//star.png);}");
      ui.star5->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//star.png);}");
      break;
    case 3:
      ui.star1->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//starPress.png);}");
      ui.star2->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//starPress.png);}");
      ui.star3->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//starPress.png);}");
      ui.star4->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//star.png);}");
      ui.star5->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//star.png);}");
      break;
    case 4:
      ui.star1->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//starPress.png);}");
      ui.star2->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//starPress.png);}");
      ui.star3->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//starPress.png);}");
      ui.star4->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//starPress.png);}");
      ui.star5->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//star.png);}");
      break;
    case 5:
      ui.star1->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//starPress.png);}");
      ui.star2->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//starPress.png);}");
      ui.star3->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//starPress.png);}");
      ui.star4->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//starPress.png);}");
      ui.star5->setStyleSheet("QPushButton {border: none; border-image:url(.//Resources//starPress.png);}");
      break;
  }
}