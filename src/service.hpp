#ifndef SERVICE_H_
#define SERVICE_H_

#include <QObject>

#include <stdint.h>
#include <QtNetwork/QNetworkAccessManager>
#include <QtCore/QVariant>
#include <QTimer>

#include <QSettings>
//#include "UDSUtil.hpp"
//#include <bb/pim/unified/unified_data_source.h>
//#include "UDSUtil.hpp"
//#include "HubCache.hpp"
//#include "TestAccount.hpp"

#include <huctx.h>
#include <hugse56.h>
#include <huseed.h>
#include <husha2.h>
#include "huctx.h"
#include "sbdef.h"
#include "sbreturn.h"
#include "sbmem.h"

#include <QtNetwork/QTcpSocket>

//#include <QFileSystemWatcher>

namespace bb
{
	class Application;

	namespace platform
	{
		class Notification;
	}

	namespace system
	{
		class InvokeManager;
		class InvokeRequest;
		class InvokeTargetReply;
		class ApplicationStartupMode;
	}
}

using bb::Application;
using bb::system::ApplicationStartupMode;
using bb::system::InvokeManager;
using bb::system::InvokeRequest;
using bb::system::InvokeTargetReply;

class Service: public QObject
{
	Q_OBJECT

public:

	Service(bb::Application * app);
	virtual ~Service();

	static const QString AUTHOR;
	static const QString APPNAME;

	Q_SLOT void onInvoked(const bb::system::InvokeRequest& request);

	Q_INVOKABLE void socketSend(QString data);

	Q_INVOKABLE void refresh();
	Q_INVOKABLE void parseUpdatesJSON(QString jsonString);
	Q_INVOKABLE void request(QVariant params);

    //Q_INVOKABLE int64_t headlessMemory();
	Q_INVOKABLE void notifyHub(QString title, QString message, QString id);
	Q_INVOKABLE bool contains(QString text, QString find);
	Q_INVOKABLE QString getSetting(const QString &objectName, const QString &defaultValue);
	Q_INVOKABLE void setSetting(const QString &objectName, const QString &inputValue);

	Q_INVOKABLE QString generateRequestToken(quint64 timestamp, QString token);
	Q_INVOKABLE int init();
	Q_INVOKABLE void end();
	Q_INVOKABLE QString intToHex(int decimal);
	Q_INVOKABLE int hash(const QString input_data, unsigned char* messageDigest);

public Q_SLOTS:

	void connected();
	void disconnected();

	//void settingsChanged(const QString & path);

private slots:

//	void processNewMessage(QByteArray message);
//	void markHubItemRead(QVariantMap itemProperties);
//	void markHubItemUnread(QVariantMap itemProperties);
//	void removeHubItem(QVariantMap itemProperties);
	void onTimeout();

	void onComplete();
	void timedout();

	//void changesTimerTimeOut();

Q_SIGNALS:

	void complete(QString response, QString httpcode, QString endpoint);

private:

	//QFileSystemWatcher* m_settingsWatcher;

	int m_port;
	QTcpSocket *m_clientSocket;
	void connectToServer();

//	TestAccount* _testAccount;
//	HubCache*     _hubCache;
//	UDSUtil*      _udsUtil;
	QSettings*    _settings;

//	int  _itemCounter;
//	Application* _app;

	QNetworkAccessManager m_manager;
	QTimer *timer;

	QTimer *changesTimer;

	bb::platform::Notification * m_notify;
	bb::system::InvokeManager * _invokeManager;

//	void triggerNotification();

	int ticks;

	sb_GlobalCtx sbCtx;
	sb_Context sha256Context;
};

#endif /* SERVICE_H_ */
