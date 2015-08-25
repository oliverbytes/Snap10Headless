APP_NAME = Snap2ChatHeadlessService

CONFIG 	+= qt warn_on

include(config.pri)

LIBS += -lbb -lbbsystem -lbbplatform -lbbdata -lbbnetwork -lunifieddatasourcec -lbbpim
QT += network
LIBS += -lcrypto
LIBS += -lhuapi
QT 	+= xml
QT += declarative
LIBS += -lbbdata

QMAKE_CFLAGS *= -g
QMAKE_CXXFLAGS *= -g