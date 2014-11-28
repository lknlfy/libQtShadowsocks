#ifndef BASECONTROLLER_H
#define BASECONTROLLER_H

/*
 * This is an abstract class for all controller classes.
 * i.e. LocalController is a sub-class of the BaseController.
 */

#include <QByteArray>
#include <QDebug>
#include <QHostAddress>
#include <QList>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "qtshadowsocks_global.h"
#include "sprofile.h"
#include "connection.h"
#include "encryptor.h"

class BaseController : public QObject
{
    Q_OBJECT
public:
    BaseController(QObject *parent = 0);
    virtual ~BaseController();

    virtual quint16 getServerPort();
    virtual QString getServerAddr();

signals:
    void error(const QByteArray &);
    void info(const QByteArray &);

public slots:
    virtual void start(const SProfile &p) = 0;
    virtual void stop();

protected://children can access protected members
    bool running;
    QTcpServer *tcpServer;
    SProfile profile;
    QList<Connection *> conList;

protected slots:
    virtual void onTcpServerError();
    virtual void onNewConnection() = 0;
    virtual void onConnectionDisconnected();
};

#endif // BASECONTROLLER_H
