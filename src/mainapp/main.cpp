#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "audiorecorder.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setOrganizationName("Hummbeere");
    app.setOrganizationDomain("peterbouda.eu");
    app.setApplicationName("Hummbeere");

    AudioRecorder recorder;

    QQmlApplicationEngine* engine = new QQmlApplicationEngine();
    engine->rootContext()->setContextProperty("recorder", &recorder);
    engine->load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
