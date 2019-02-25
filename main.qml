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
        onBegin: doSomething(Gemini.BALL_COLOR_RED) // begin信号函数，响应doSomething()槽函数，使用时是<用类名>.<枚举类型变量>
        onBallNumberChanged: console.log("new ball number is", ballNumber) // Q_PROPERTY中与属性关联的信号函数
        Component.onCompleted: console.log("default ball number is", ballNumber) // 如果属性没有变，执行
    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
            gemini.begin() // 会先响应begin()对应的后续响应函数
            gemini.stop() // begin()对应的后续响应函数doSomething()响应完后才执行stop()
            gemini.ballNumber = 10 // 属性赋值
        }
    }
}
