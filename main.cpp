#include <QApplication>
#include <QQmlApplicationEngine>
#include "mainquickview.h"
#include "soundwrapper.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainQuickView view;
    view.setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    view.resize(720, 720);

    SoundWrapper soundWrapper;
    QObject::connect(&soundWrapper, &SoundWrapper::setQmlObjectProperty,
                     &view, &MainQuickView::setQmlObjectProperty);
    QObject::connect(&soundWrapper, &SoundWrapper::setQmlVariantProperty,
                     &view, &MainQuickView::setQmlVariantProperty);

    soundWrapper.start();
    view.show();
    return app.exec();
}
