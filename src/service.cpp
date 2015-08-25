#include "service.hpp"

#include <bb/Application>
#include <bb/platform/Notification>
#include <bb/platform/NotificationDefaultApplicationSettings>
#include <bb/system/InvokeManager>
#include <QTimer>

#include <sys/procfs.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdint.h>

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include <QUrl>
#include <QtNetwork/QtNetwork>
#include <QtCore/QtCore>

#include <huctx.h>
#include <hugse56.h>
#include <huseed.h>
#include <husha2.h>
#include "huctx.h"
#include "sbdef.h"
#include "sbreturn.h"
#include "sbmem.h"

#include <bb/data/JsonDataAccess>

using bb::data::JsonDataAccess;
using namespace bb::platform;
using namespace bb::system;

const QString Service::AUTHOR 		= "NEMORY";
const QString Service::APPNAME 		= "SNAP2CHAT";

#define BB_OPEN_INVOCATION_ACTION 	"bb.action.OPEN"
#define INVOKE_TARGET_KEY_OPEN 		"com.nemory.snap2chat.hub.invoke.open.lite"

const QString HOST 					= "feelinsonice-hrd.appspot.com";
const QString PROTOCOL 				= "https://";
//const QString USER_AGENT 			= "Snapchat/6.1.2 (iPhone6,2; iOS 7.0.4; gzip)";
const QString USER_AGENT 			= "Snapchat/4.1.07 (SAMSUNG-SGH-I747; Android 19; gzip)";
const QString ACCEPT_LANGUAGE 		= "en;q=1, en;q=0.9";
const QString ACCEPT_LOCALE 		= "en_US";
const QString CONNECTION 			= "Keep-Alive";
const QString CONTENT_TYPE 			= "application/x-www-form-urlencoded";

const QString SECRET 				= "iEk21fuwZApXlz93750dmW22pw389dPwOk";
const QString STATIC_TOKEN 			= "m198sOkJEn37DjqZ32lpRu76xmw288xSQ9";
const QString BLOB_ENCRYPTION_KEY 	= "M02cnQ51Ji97vwT4";
const QString HASH_PATTERN 			= "0001110111101110001111010101111011010001001110011000110001000110";

const int MEDIA_IMAGE 							= 0;
const int MEDIA_VIDEO 							= 1;
const int MEDIA_VIDEO_NOAUDIO 					= 2;
const int MEDIA_VIDEO_ZIPPED 					= 500;
const int MEDIA_FRIEND_REQUEST 					= 3;
const int MEDIA_FRIEND_REQUEST_IMAGE 			= 4;
const int MEDIA_FRIEND_REQUEST_VIDEO 			= 5;
const int MEDIA_FRIEND_REQUEST_VIDEO_NOAUDIO 	= 6;

const int STATUS_NONE 		= -1;
const int STATUS_SENT 		= 0;
const int STATUS_DELIVERED 	= 1;
const int STATUS_UNOPENED 	= 1;
const int STATUS_OPENED 	= 2;
const int STATUS_SCREENSHOT = 3;

const int FRIEND_CONFIRMED 		= 0;
const int FRIEND_UNCONFIRMED 	= 1;
const int FRIEND_BLOCKED 		= 2;
const int FRIEND_DELETED 		= 3;

const int PRIVACY_EVERYONE 	= 0;
const int PRIVACY_FRIENDS 	= 1;

QStringList receivedUnopenedSnaps;
QStringList friendRequestsList;

bool socketConnected 	= false;
bool isSynchronized 	= false;
bool refreshing 		= false;

QString _username 		= "";
QString _auth_token 	= "";

Service::Service(bb::Application * app)	:
		QObject(app),
		m_notify(new Notification(this)),
		_invokeManager(new InvokeManager(this)),
//		_testAccount(NULL),
//		_hubCache(NULL),
//		_udsUtil(NULL),
//		_itemCounter(0),
		//,
		//m_settingsWatcher(new QFileSystemWatcher(this))
		m_port(9876),
		m_clientSocket(new QTcpSocket(this))
{
	_settings = new QSettings(AUTHOR, APPNAME);

	connect(m_clientSocket, SIGNAL(connected()), this, SLOT(connected()));
	connectToServer();

	_username 		= getSetting("username", "");
	_auth_token 	= getSetting("auth_token", "");

	ticks = 0;

	NotificationDefaultApplicationSettings notificationSettings;
	notificationSettings.setPreview(NotificationPriorityPolicy::Allow);
	notificationSettings.apply();

	onTimeout();

	connect(_invokeManager, SIGNAL(invoked(const bb::system::InvokeRequest&)),this, SLOT(onInvoked(const bb::system::InvokeRequest&)));

	switch(_invokeManager->startupMode())
	{
		case ApplicationStartupMode::LaunchApplication:
			//qDebug() << "Service: Regular application launch";
			break;
		case ApplicationStartupMode::InvokeApplication:
			//qDebug() << "Service: Launching app from invoke";
			break;
		case ApplicationStartupMode::InvokeCard:
			//qDebug() << "Service: Launching card from invoke";
			break;
		// enable when 10.3 beta is released
		//case ApplicationStartupMode::InvokeHeadless:
		//    qDebug() << "Service: Launching headless from invoke";
		//    break;
		default:
			//qDebug() << "Service: other launch: " << _invokeManager->startupMode();
			break;
	}

	// =======================================
//	 if (_invokeManager->startupMode() == 4)
//	 {
//		// initialize UDS
//		if (!_udsUtil)
//		{
//			_udsUtil = new UDSUtil(QString("Snap2Chat"), QString("hubassets"));
//			_udsUtil->initialize();
//			_hubCache = new HubCache(_settings);
//			_testAccount = new TestAccount(_udsUtil, _hubCache);
//		}
//	}
	// =======================================

	refresh();

	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(timedout()));
	int interval = getSetting("refreshFeedsEvery", "80000").toInt();
	timer->start(interval);
}

Service::~Service()
{
//    bool notificationsEnabled           = (getSetting("headlessStateNotifications", "false") == "true");
//
//    if(notificationsEnabled)
//    {
//        notifyHub("Snap2Chat Headless", "Stopped...", "1000");
//    }

    isSynchronized = false;

    // =======================================
//    if (_testAccount)
//    {
//        delete _testAccount;
//    }
//
//    if (_hubCache)
//    {
//        delete _hubCache;
//    }
//
//    if (_udsUtil)
//  {
//      delete _udsUtil;
//  }
    // =======================================

//    if (_settings)
//    {
//        delete _settings;
//    }

    m_clientSocket->close();
    m_clientSocket->deleteLater();

    //qDebug() << "******* DESCTRUCTOR";
}

void Service::connectToServer()
{
	//m_clientSocket->disconnectFromHost();

    if (!m_clientSocket->isOpen())
    {
        m_clientSocket->connectToHost(QHostAddress::LocalHost, m_port);
        connect(m_clientSocket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    }
    else
    {
        connected();
    }
}

void Service::socketSend(QString data)
{
    m_clientSocket->write(data.toUtf8());
    m_clientSocket->flush();
}

void Service::connected()
{
	socketConnected = true;

	QString jsonCommand2 = "{\"action\":\"connected\", \"data\":\"data\"}";
	socketSend(jsonCommand2);

	//qDebug() << "******* HEADLESS connected() : " << socketConnected;
}

void Service::disconnected()
{
	isSynchronized = false;
	socketConnected = false;

	//qDebug() << "******* HEADLESS disconnected() : " << socketConnected;
}

void Service::onInvoked(const bb::system::InvokeRequest& request)
{
	//qDebug() << "**** HEADLESS INVOKED: " << request.action() + " : " << socketConnected;

	// =======================================
    // Sometimes this method gets invoked before the constructor initializes fully so the following code should handle this scenario.
//    if (!_udsUtil)
//    {
//        _udsUtil = new UDSUtil(QString("Snap2Chat"), QString("hubassets"));
//        _hubCache = new HubCache(_settings);
//        _testAccount = new TestAccount(_udsUtil, _hubCache);
//    }
//    else
//    {
//        if (!_udsUtil->initialized())
//        {
//            _udsUtil->initialize();
//        }
//    }
	// =======================================

    if (request.action().compare("bb.action.CHOICE") == 0)
    {
		QString jsonCommand = QString(request.data());

		if(jsonCommand.length() > 0)
		{
			JsonDataAccess jda;
			QVariant jsonDATA 					= jda.loadFromBuffer(jsonCommand);
			jda.deleteLater();
			QVariantMap parentJSONMap 			= jsonDATA.toMap();

			QString action 	= parentJSONMap["action"].toString();
			QString data 	= parentJSONMap["data"].toString();

			if(action.length() > 0)
			{
				if (action == "loadLoginDetails")
				{
					QVariantMap dataMap = parentJSONMap["data"].toMap();

					_username 		= dataMap["username"].toString();
					_auth_token 	= dataMap["auth_token"].toString();

					//qDebug() << "HEADLESS LOAD LOGIN DETAILS: " << dataMap;
				}
				else if (action == "parseUpdatesJSON" && data.length() > 0)
				{
					parseUpdatesJSON(data);
				}
				else if (action == "refresh")
				{
					refresh();
				}
				else if (action == "connect")
				{
					//connectToServer();
				}
				else if (action == "connected")
				{
					isSynchronized = true;
				}
				else if (action == "resetTimer")
				{
					int interval = getSetting("refreshFeedsEvery", "80000").toInt();
					timer->setInterval(interval);
				}
//				else if (action == "markAsRead")
//				{
//					JsonDataAccess jda2;
//					QVariant jsonDATA2 					= jda2.loadFromBuffer(data);
//					jda2.deleteLater();
//
//					QVariantMap attributesMap 			= jsonDATA2.toMap()["attributes"].toMap();
//
//					markHubItemRead(attributesMap);
//				}
//				else if (action == "markAsReadBySnapID")
//				{
//				    QVariantList items = _testAccount->items();
//
//                    foreach(QVariant item, items)
//                    {
//                        QVariantMap itemMap = item.toMap();
//
//                        if(itemMap["snapID"].toString() == data)
//                        {
//                            markHubItemRead(itemMap);
//                        }
//                    }
//				}
			}
		}
	}
    else if(request.action().compare("bb.action.system.STARTED") == 0)
	{
		//connectToServer();
    	refresh();
	}
	else if(request.action().compare("bb.action.START") == 0)
	{
		//connectToServer();
		refresh();
	}
	else if(request.action().compare("bb.action.STOP") == 0)
	{
		//qDebug() << "Service: onInvoked: Service : stop";
		//_app->quit();
		//_app->requestExit();
    }
//	else if(request.action().compare("bb.action.MARKREAD") == 0)
//	{
//        JsonDataAccess jda;
//
//        QVariantMap objectMap = (jda.loadFromBuffer(request.data())).toMap();
//        QVariantMap attributesMap = objectMap["attributes"].toMap();
//
//        markHubItemRead(attributesMap);
//
//    }
//    else if(request.action().compare("bb.action.MARKUNREAD") == 0)
//    {
//        JsonDataAccess jda;
//
//        QVariantMap objectMap = (jda.loadFromBuffer(request.data())).toMap();
//        QVariantMap attributesMap = objectMap["attributes"].toMap();
//
//        markHubItemUnread(attributesMap);
//
//    }
//    else if(request.action().compare("bb.action.MARKPRIORREAD") == 0)
//    {
//        JsonDataAccess jda;
//
//        qint64 timestamp = (jda.loadFromBuffer(request.data())).toLongLong();
//        QDateTime date = QDateTime::fromMSecsSinceEpoch(timestamp);
//
//        _testAccount->markHubItemsReadBefore(_testAccount->categoryId(), timestamp);
//
//    }
//    else if(request.action().compare("bb.action.DELETE") == 0)
//    {
//        JsonDataAccess jda;
//
//        QVariantMap objectMap = (jda.loadFromBuffer(request.data())).toMap();
//        QVariantMap attributesMap = objectMap["attributes"].toMap();
//
//        removeHubItem(attributesMap);
//
//    }
//    else if(request.action().compare("bb.action.DELETEPRIOR") == 0) {
//        JsonDataAccess jda;
//
//        qint64 timestamp = (jda.loadFromBuffer(request.data())).toLongLong();
//        QDateTime date = QDateTime::fromMSecsSinceEpoch(timestamp);
//
//        //qDebug() << "Service: onInvoked: mark prior delete : " << timestamp << " : " << request.data();
//
//        _testAccount->removeHubItemsBefore(_testAccount->categoryId(), timestamp);
//
//    }
    else
    {
        //qDebug() << "Service: onInvoked: unknown service request " << request.action() << " : " << request.data();
    }
}

//void Service::markHubItemRead(QVariantMap itemProperties)
//{
//    qDebug()  << "Service::markHubItemRead: item: " << itemProperties;
//    qDebug()  << "Service::markHubItemRead: item src Id: " << itemProperties["sourceId"].toString();
//    qDebug()  << "Service::markHubItemRead: item message Id: " << itemProperties["messageid"].toString();
//
//    qint64 itemId;
//    qint64 itemCategoryId;
//
//    if (itemProperties["sourceId"].toString().length() > 0) {
//        itemId = itemProperties["sourceId"].toLongLong();
//    } else if (itemProperties["messageid"].toString().length() > 0) {
//        itemId = itemProperties["messageid"].toLongLong();
//    }
//
//    _testAccount->markHubItemRead(_testAccount->categoryId(), itemId);
//}
//
//void Service::markHubItemUnread(QVariantMap itemProperties)
//{
//    qDebug()  << "Service::markHubItemUnread: item: " << itemProperties;
//    qDebug()  << "Service::markHubItemUnread: item src Id: " << itemProperties["sourceId"].toString();
//    qDebug()  << "Service::markHubItemUnread: item message Id: " << itemProperties["messageid"].toString();
//
//    qint64 itemId;
//    qint64 itemCategoryId;
//
//    if (itemProperties["sourceId"].toString().length() > 0)
//    {
//        itemId = itemProperties["sourceId"].toLongLong();
//    }
//    else if (itemProperties["messageid"].toString().length() > 0)
//    {
//        itemId = itemProperties["messageid"].toLongLong();
//    }
//
//    _testAccount->markHubItemUnread(_testAccount->categoryId(), itemId);
//}
//
//void Service::removeHubItem(QVariantMap itemProperties)
//{
//    qDebug()  << "Service::removeHubItem: item: " << itemProperties;
//    qDebug()  << "Service::removeHubItem: item src Id: " << itemProperties["sourceId"].toString();
//    qDebug()  << "Service::removeHubItem: item message Id: " << itemProperties["messageid"].toString();
//
//    qint64 itemId;
//    if (itemProperties["sourceId"].toString().length() > 0) {
//        itemId = itemProperties["sourceId"].toLongLong();
//    } else if (itemProperties["messageid"].toString().length() > 0) {
//        itemId = itemProperties["messageid"].toLongLong();
//    }
//
//    _testAccount->removeHubItem(_testAccount->categoryId(), itemId);
//}
//
//void Service::processNewMessage(QByteArray message)
//{
//	qDebug()  << "Service::processNewMessage: message: " << message;
//
//    bool notify = false;
//    QString priority("");
//    QString from("From");
//    QString title("Title");
//    QString body("Body");
//
//    QVariantMap* itemMap = new QVariantMap();
//    (*itemMap)["body"] = body;
//
//    _itemCounter++;
//    bool retVal = _testAccount->addHubItem(_testAccount->categoryId(), *itemMap, from, title, QDateTime::currentDateTime().toMSecsSinceEpoch(), QString::number(_itemCounter),"", "",  notify);
//}

void Service::parseUpdatesJSON(QString jsonString)
{
	bool notificationsEnabled 			= (getSetting("notificationsEnabled", "false") == "true");

	qDebug() << "#### NOTIFICATIONS: " << notificationsEnabled;

	QString allLastUnopenedFromSetting 	= getSetting("allLastUnopenedID", "");
	QString allFriendRequestsFromSetting= getSetting("allFriendRequestsID", "");

	JsonDataAccess jda;
	QVariant jsonDATA 					= jda.loadFromBuffer(jsonString);
	jda.deleteLater();

	QVariantMap parentJSONMap 			= jsonDATA.toMap();

	QVariantList _friends = parentJSONMap.value("friends").toList();

	// ----------------------------- FORMAT SNAPS -------------------------------- //

	QVariantList newSnaps 		= parentJSONMap.value("snaps").toList();

	for(int k = 0; k < (newSnaps.size() / 2); k++ ) newSnaps.swap(k, newSnaps.size() - (1 + k));

	QVariantList formattedSnaps;

	if(newSnaps.size() > 0)
	{
		foreach(QVariant thesnap, newSnaps)
		{
			QVariantMap snapMap					= thesnap.toMap();

			const QString id 					= snapMap["id"].toString();
			const QString media_id 				= (snapMap.contains("c_id") ? snapMap["c_id"].toString() : "false");
			const bool zippedVideo 				= (snapMap.contains("zipped") ? snapMap["zipped"].toBool() : false);
			int media_type 						= (zippedVideo ? 500 : snapMap["m"].toInt());
			const QString sender 				= (snapMap.contains("sn") ? snapMap["sn"].toString() : _username);

			if(media_type == MEDIA_FRIEND_REQUEST)
			{
				bool friendRequestInFriends = false;

				foreach(QVariant theFriend, _friends)
				{
					QVariantMap friendMap = theFriend.toMap();

					if(friendMap["name"] == sender)
					{
						friendRequestInFriends = true;
						break;
					}
				}

				if(!friendRequestInFriends)
				{
				    if(notificationsEnabled && !contains(allFriendRequestsFromSetting, id))
                    {
				        notifyHub(sender, "New Friend Request from " + sender, "");
                    }

                    if(!friendRequestsList.contains(id, Qt::CaseSensitive))
                    {
                        friendRequestsList << id;
                    }
				}

				continue;
			}

			const int status = snapMap["st"].toInt();

			QString sentReceived = (contains(id, "r") ? "received" : "sent");

			if(status == STATUS_UNOPENED || status == STATUS_DELIVERED)
			{
				if(sentReceived == "received")
				{
					if(notificationsEnabled && !contains(allLastUnopenedFromSetting, id))
					{
					    notifyHub(sender, "New Snap from " + sender, "");

//						QVariantMap* itemMap 	= new QVariantMap();
//						(*itemMap)["body"] 		= "New Snap from " + sender + "";
//						(*itemMap)["snapID"]    = id;
//
//						_itemCounter++;
//
//						_testAccount->addHubItem(_testAccount->categoryId(), *itemMap, sender, "New Snap from " + sender, QDateTime::currentDateTime().toMSecsSinceEpoch(), QString::number(_itemCounter), "", "",  true);
					}

					if(!receivedUnopenedSnaps.contains(id, Qt::CaseSensitive))
					{
						receivedUnopenedSnaps << id;
					}
				}
			}
		}
	}

	QString allLastUnopenedID = receivedUnopenedSnaps.join(",");
	setSetting("allLastUnopenedID", allLastUnopenedID);

	QString allFriendRequestsID = friendRequestsList.join(",");
	setSetting("allFriendRequestsID", allFriendRequestsID);
}

void Service::refresh()
{
	QString	refreshFeeds	= getSetting("refreshFeeds", "true");

	_username 		= getSetting("username", "");
	_auth_token 	= getSetting("auth_token", "");

	if(_auth_token.length() > 0 && _username.length() > 0 && refreshFeeds == "true")
	{
		if(!refreshing)
		{
			QVariantMap paramsMap;

			quint64 timestamp = QDateTime::currentMSecsSinceEpoch();

			paramsMap["endpoint"] 	= "/bq/updates";
			paramsMap["username"] 	= _username;
			paramsMap["timestamp"] 	= timestamp;
			paramsMap["req_token"] 	= generateRequestToken(timestamp, _auth_token);

			request(paramsMap);

			refreshing = true;

//			timer->stop();
//			timer->start();

			qDebug() << "***** HEADLESS REFRESH REQUESTED";
		}
	}
	else
	{
		//qDebug() << "***** HEADLESS NOT LOGGED IN, DIDN'T REFRESHED";
		//qDebug() << "***** username: " << _username << ", authtoken: " << _auth_token << ", refresh: " << refreshFeeds;
	}
}

void Service::timedout()
{
	ticks++;

	//qDebug() << "******* HEADLESS timedout: " << ticks << ", interval: " << timer->interval();

	refresh();
}

bool Service::contains(QString text, QString find)
{
	if(find == "" || find == " " || find == "  " || text == "" || text == " " || text == "  ")
	{
		return false;
	}

	bool result;

	if(getSetting("caseSensitive", "false") == "true")
	{
		result = text.contains(find, Qt::CaseSensitive);
	}
	else if(getSetting("caseSensitive", "false") == "false")
	{
		result = text.contains(find, Qt::CaseInsensitive);
	}

	return result;
}

QString Service::getSetting(const QString &objectName, const QString &defaultValue)
{
	QSettings settings(AUTHOR, APPNAME);

	if (settings.value(objectName).isNull() || settings.value(objectName) == "")
	{
		return defaultValue;
	}

	return settings.value(objectName).toString();
}

void Service::setSetting(const QString &objectName, const QString &inputValue)
{
	QSettings settings(AUTHOR, APPNAME);
	settings.setValue(objectName, QVariant(inputValue));
}

void Service::notifyHub(QString title, QString message, QString id)
{
    Notification* notification = new Notification(this);
    notification->setTitle(title);
    notification->setBody(message);
    notification->setIconUrl(QUrl("app/native/assets/images/icon.png")) ;
    notification->setSoundUrl(QUrl("app/native/assets/sounds/tone.mp3"));

    InvokeRequest invokeRequest;
    invokeRequest.setTarget("com.nemory.snap2chat.invoke.open.lite");
    invokeRequest.setAction("bb.action.OPEN");
    invokeRequest.setMimeType("text/plain");

    notification->setInvokeRequest(invokeRequest);
    notification->notify();
}

//int64_t Service::headlessMemory()
//{
//       int rc, n, i, num;
//       int64_t memsize = -1ll;
//       procfs_mapinfo *maps = NULL;
//       int fd = open("/proc/self/as", O_RDONLY);
//       if (fd == -1)
//              return -1ll;
//       do {
//              rc = devctl(fd, DCMD_PROC_PAGEDATA, NULL, 0, &num);
//              if (rc)
//                     goto cleanup;
//              maps = (procfs_mapinfo*) realloc(maps, num * sizeof(*maps));
//              if (!maps)
//                     goto cleanup;
//              // pre-subtract the allocation we just made, rounded up to page size
//              memsize = 0ll - ((num * sizeof(*maps) + __PAGESIZE - 1) & ~(__PAGESIZE - 1));
//              rc = devctl(fd, DCMD_PROC_PAGEDATA, maps, num * sizeof(*maps), &n);
//
//              if (rc)
//              {
//                     memsize = -1ll;
//                     goto cleanup;
//              }
//       } while (n > num);
//
//       for (i = 0; i < n; i++)
//       {
//              if ((maps[i].flags & (MAP_ANON | MAP_STACK | MAP_ELF | MAP_TYPE)) == (MAP_ANON | MAP_PRIVATE))
//              {
//                     memsize += maps[i].size;
//              }
//       }
//
//       cleanup: close(fd);
//       free(maps);
//
//       return memsize;
//}

void Service::request(QVariant params)
{
	QUrl dataToSend;

	QVariantMap paramsMap 		= params.toMap();

	const QString endpoint		= paramsMap.value("endpoint").toString();
	const QString username		= paramsMap.value("username").toString();
	const QString timestamp		= paramsMap.value("timestamp").toString();
	const QString req_token		= paramsMap.value("req_token").toString();

	dataToSend.addQueryItem("username", username);
	dataToSend.addQueryItem("timestamp", timestamp);
	dataToSend.addQueryItem("req_token", req_token);

	QNetworkRequest request;
	request.setUrl(QUrl(PROTOCOL + HOST + endpoint));
	request.setHeader(QNetworkRequest::ContentTypeHeader, CONTENT_TYPE);
	request.setRawHeader("User-Agent", USER_AGENT.toAscii());
	request.setRawHeader("Accept-Language", ACCEPT_LANGUAGE.toAscii());
	request.setRawHeader("Accept-Locale", ACCEPT_LOCALE.toAscii());
	request.setRawHeader("Connection", CONNECTION.toAscii());
	request.setRawHeader("Host", HOST.toAscii());

	QNetworkReply* reply = m_manager.post(request, dataToSend.encodedQuery());
	reply->setProperty("endpoint", endpoint);
	connect (reply, SIGNAL(finished()), this, SLOT(onComplete()));

//	QString jsonCommand2 = "{\"action\":\"startLoading\", \"data\":\"data\"}";
//	socketSend(jsonCommand2);

	//qDebug() << "**** REQUEST: " << dataToSend;
}

void Service::onComplete()
{
	QNetworkReply* reply 	= qobject_cast<QNetworkReply*>(sender());
	int status 				= reply->attribute( QNetworkRequest::HttpStatusCodeAttribute ).toInt();
	QString reason 			= reply->attribute( QNetworkRequest::HttpReasonPhraseAttribute ).toString();

	QString response;

	if (reply)
	{
		if (reply->error() == QNetworkReply::NoError)
		{
			const int available = reply->bytesAvailable();

			if (available > 0)
			{
				const QByteArray buffer(reply->readAll());
				response = QString::fromUtf8(buffer);
			}
		}
		else
		{
			response = "error";
		}

		reply->deleteLater();
	}

	if (response.trimmed().isEmpty())
	{
		response = "error";
	}

	if(QString::number(status) == "200")
	{
		response = ((response.length() > 0 && response != "error") ? response : QString::number(status));
	}
	else
	{
		response = QString::number(status);
	}

	ticks++;

	if(response.length() && status == 200)
	{
		parseUpdatesJSON(response);
	}
	else if(status == 0)
    {
	    //notifyHub("Warning", "You need to relogin Snap2Chat because it looks like you've logged in from another SnapChat App.", "2000");
    }

//	QString jsonCommand = "{\"action\":\"parseUpdatesJSON\", \"data\":"+ response +", \"httpcode\":\"" + QString::number(status) + "\"}";
//	socketSend(jsonCommand);
//
//	QString jsonCommand2 = "{\"action\":\"stopLoading\", \"data\":\"data\"}";
//	socketSend(jsonCommand2);

	refreshing = false;

	//qDebug() << "**** HEADLESS onComplete(): " << response;
}

QString Service::generateRequestToken(quint64 timestamp, QString token)
{
	init();

	unsigned char message_digest1[SB_SHA256_DIGEST_LEN];

	QString first = SECRET + token;
	QString second = QString::number(timestamp) + SECRET;

	QString hash1;
	QString hash2;

	int result1 = SB_SUCCESS;

	result1 = hash(first, message_digest1);

	if (result1 == SB_SUCCESS)
	{
		QByteArray hash1data = QByteArray::fromRawData(reinterpret_cast<const char *>(message_digest1), SB_SHA256_DIGEST_LEN);
		hash1 = QString::fromAscii(hash1data.toHex());
	}

	unsigned char message_digest2[SB_SHA256_DIGEST_LEN];

	int result2 = SB_SUCCESS;

	result2 = hash(second, message_digest2);

	if (result2 == SB_SUCCESS)
	{
		QByteArray hash2data = QByteArray::fromRawData(reinterpret_cast<const char *>(message_digest2), SB_SHA256_DIGEST_LEN);
		hash2 = QString::fromAscii(hash2data.toHex());
	}

	QString resultCode = "";

	for (int i = 0; i < HASH_PATTERN.length(); i++)
	{
		QString currentDigit = HASH_PATTERN.at(i);

		if(currentDigit == "1")
		{
			resultCode.append(hash2.at(i));
		}
		else
		{
			resultCode.append(hash1.at(i));
		}
	}

	end();

	return resultCode;
}

QString Service::intToHex(int decimal)
{
	QString hexadecimal;
	hexadecimal.setNum(decimal, 16);
	return hexadecimal;
}

int Service::init()
{
	int returnCode = SB_SUCCESS; /* Return Code */

	returnCode = hu_GlobalCtxCreateDefault(&sbCtx);

	if (returnCode != SB_SUCCESS)
	{
		//qDebug() << "XXXX makeHash ERROR creating SB contexts:" << intToHex(returnCode);
		return returnCode;
	}

	returnCode = hu_RegisterSbg56(sbCtx);

	if (returnCode != SB_SUCCESS)
	{
		//qDebug() << "XXXX makeHash ERROR calling hu_RegisterSbg56:" << intToHex(returnCode);
		return returnCode;
	}

	returnCode = hu_InitSbg56(sbCtx);

	if (returnCode != SB_SUCCESS)
	{
		//qDebug() << "XXXX makeHash ERROR calling hu_InitSbg56:" << intToHex(returnCode);
		return returnCode;
	}

	return returnCode;
}

void Service::end()
{
	(void) hu_SHA256End(&sha256Context, NULL, sbCtx);
	hu_GlobalCtxDestroy(&sbCtx);
}

int Service::hash(const QString input_data, unsigned char* messageDigest)
{
	int returnCode = SB_SUCCESS; /* Return Code */

	QByteArray input_bytes = input_data.toUtf8();
	unsigned char* hash_input = reinterpret_cast<unsigned char*>(input_bytes.data());

	returnCode = hu_SHA256Begin((size_t) SB_SHA256_DIGEST_LEN, NULL, &sha256Context, sbCtx);

	if (returnCode != SB_SUCCESS)
	{
		//qDebug() << "XXXX makeHash ERROR initialising SHA-256 context:" << intToHex(returnCode);
		return returnCode;
	}

	returnCode = hu_SHA256Hash(sha256Context, (size_t) input_bytes.length(), hash_input, sbCtx);

	if (returnCode != SB_SUCCESS)
	{
		//qDebug() << "XXXX makeHash ERROR creating hash:" << intToHex(returnCode);
		return returnCode;
	}

	returnCode = hu_SHA256End(&sha256Context, messageDigest, sbCtx);

	if (returnCode != SB_SUCCESS)
	{
		//qDebug() << "XXXX makeHash ERROR completing hashing" << intToHex(returnCode);
		return returnCode;
	}

	return SB_SUCCESS;
}

//void Service::triggerNotification()
//{
//	QTimer::singleShot(2000, this, SLOT(onTimeout()));
//}

void Service::onTimeout()
{
//	Notification::clearEffectsForAll();
//	Notification::deleteAllFromInbox();
//	m_notify->notify();
}
