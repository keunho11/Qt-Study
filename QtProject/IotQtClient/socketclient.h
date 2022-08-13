#ifndef SOCKETCLIENT_H
#define SOCKETCLIENT_H

/* kccistc embedded & iot by ksh */

#include <QTcpSocket>
#include <QHostAddress>
#include <QInputDialog>
#include <QMessageBox>

#define BLOCK_SIZE      1024
class SocketClient : public QWidget
{
	Q_OBJECT

private:
    QTcpSocket *pQTcpSocket;
    QString SERVERIP = "10.10.141.31";
    int SERVERPOT = 5000;
    QString LOGID = "1";
    QString LOGPW = "PASSWD";
public:
	SocketClient(QWidget *parent = 0, Qt::WindowFlags flags = 0);
	~SocketClient();

signals:
    void sigSocketRecv(QString);

private slots:
    void slotSocketReadData();//수신될 데이터가 있으면 수신
	void slotSocketError();
	void slotConnectServer();

public slots:
    void slotConnectToServer(bool&);
    void slotClosedByServer();
    void slotSocketSendData(QString);
};

#endif // SOCKETCLIENT_H