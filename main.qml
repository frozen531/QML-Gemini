import QtQuick 2.6
import QtQuick.Window 2.2

// 源自于main.cpp中的qmlRegisterType<Gemini>("Union.Lotto.Gemini",1,0,"Gemini");
// 声明了import的内容，版本号，在QML中使用时的名字为Gemini
import Union.Lotto.Gemini 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: "Union Lotto Gemini"
    color: "#d8d8d8"

    Gemini{
        id:gemini
        onBegin: doSomething() // begin信号函数，响应doSomething()槽函数
    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
            gemini.doSomething()
        }
    }
}
