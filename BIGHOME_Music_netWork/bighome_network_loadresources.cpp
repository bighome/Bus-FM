#include "bighome_network_loadresources.h"
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>

BIGHOME_NetWork_loadResources::BIGHOME_NetWork_loadResources(QObject *parent)
  : QObject(parent)
{
  m_netWorkManager = new QNetworkAccessManager;
}

BIGHOME_NetWork_loadResources::~BIGHOME_NetWork_loadResources()
{

}
void BIGHOME_NetWork_loadResources::loadNetWorkImg(QUrl url)
{
  QNetworkRequest request;
  request.setUrl(QUrl(url));
  QNetworkReply *reply = m_netWorkManager->get(request);
  connect(reply, SIGNAL(finished()), this, SLOT(slotsFilished()));
}
void BIGHOME_NetWork_loadResources::slotsFilished()
{
  QNetworkReply* reply = (QNetworkReply*)sender();
  QByteArray IMGbyetArry = reply->readAll();
  QPixmap pixmap;
  if (pixmap.loadFromData(IMGbyetArry))
  {
    emit signalsGetLoadImg(pixmap);
    return;
  }
  emit signalsGetLoadImg(NULL);
}