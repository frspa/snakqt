#include <iostream>
#include <stdlib.h>

#include <QtCore>
#include <QtQuick/QQuickView>

#include <QtGui/QFont>
#include <QtGui/QGuiApplication>

#include <QtQml/QQmlApplicationEngine>
#include <QtQml/QQmlContext>
#include <QtQml/QQmlEngine>
#include <QtQml/QQmlProperty>

#include <board.hpp>
#include <startup.hpp>

int main(int argc, char *argv[]) {

  std::cout << "Starting SNAKQT, your snake game with cmake, Qt and QML! \n";
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QGuiApplication app(argc, argv);
  app.setOverrideCursor(Qt::BlankCursor);
  QFont font("Noto Sans");
  app.setFont(font);

  QQmlApplicationEngine engine;
  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
  if (engine.rootObjects().isEmpty()) {
    return -1;
  }

  QQuickWindow *rootObject;
  rootObject = static_cast<QQuickWindow *>(engine.rootObjects().first());
  rootObject->showFullScreen();

  boardspace::Board gameBoard(uint(100));

  // GUI init and startup process
  boardspace::setInitialFruit(&gameBoard);

  std::cout << "Application started successfully. \n";
  return app.exec();
}
