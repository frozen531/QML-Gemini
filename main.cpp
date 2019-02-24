#include <QGuiApplication>
#include <QQmlApplicationEngine>

/* 添加头文件 */
#include <gemini.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    /* int qmlRegisterType(const char * uri, int versionMajor, int versionMinor, const char * qmlName)
    * 功能：
    *   注册c++类到Qt元对象中，用于后面的.qml文件中 import Union.Lotto.Gemini 1.0
    * 参数:
    *   第一个参数* uri指的是QML中import后的内容，相当于头文件名;
    *   第二个第三个参数分别是主次版本号;
    *   第四个指的是QML中类的名字,你在.qml文件中使用的时候就是用这个名字，类似于Rectangle
    */
    qmlRegisterType<Gemini>("Union.Lotto.Gemini",1,0,"Gemini");  // 将类Gemini注册到Qt中

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
