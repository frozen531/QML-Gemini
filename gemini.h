#ifndef GEMINI_H
#define GEMINI_H

// Gemini.h
#include <QObject>
#include <QDebug>

class Gemini : public QObject // 必须共有继承自QObject，这样才可以在里面写信号、槽函数等特性
{
    Q_OBJECT // 必须写，用来声明信号与槽
    Q_ENUMS(BALL_COLOR) // // 枚举类型，要想在QML中使用该枚举，就需要加宏Q_ENUMS()
    /*
     * Q_PROPERTY(类型 变量名 READ 读取变量函数名 WRITE 设置变量函数名) // 这里的变量名就是QML调用时用的名字
     * READ：读取属性值，如果没有设置MEMBER的话，它是必需的。一般情况下，函数是个const函数，返回值类型必须是属性本身的类型或这个类型的const引用，没有参数。
     * WRITE：设置属性值，可选项。函数必须返回void，有且仅有一个参数，参数类型必须是属性本身的类型或这个类型的指针或引用。
     * NOTIFY：与属性关联的可选信号。这个信号必须在类中声明过，当属性值改变时，就可触发这个信号，可以没有参数，有参数的话只能是一个类型同属性本身类型的参数，用来记录属性改变后的值。
    */
    Q_PROPERTY(unsigned int ballNumber READ ballNumber WRITE setBallNumber NOTIFY ballNumberChanged)

public:
    Gemini():m_ballColor(BALL_COLOR_YELLOW){ // 使用枚举默认的初始化列表
        qDebug()<<"Gemini::Gemini() called";
    }

    enum BALL_COLOR{
        BALL_COLOR_YELLOW,
        BALL_COLOR_RED,
        BALL_COLOR_BLUE,
        BALL_COLOR_ALL
    };

    Q_INVOKABLE void stop(){ // 如果想让QML调用C++类的成员函数，要使用宏Q_INVOKABLE
        qDebug()<<"Gemini::stop() called";
    }

    unsigned int ballNumber() const { // 读取属性值函数
        return m_ballNumber;
    }

    void setBallNumber(unsigned int& ballNumber) { // 设置属性值函数
        if(ballNumber != m_ballNumber) {
            m_ballNumber = ballNumber;
            emit ballNumberChanged(); // 信号在C++中使用时要用到emit关键字,而在QML中就是普通的函数
        }
    }

signals:
    void begin();
    void ballNumberChanged(); // Q_PROPERTY中NOTIFY的函数名，与属性关联的可选信号。这个信号必须在类中声明过，当属性值改变时，就可触发这个信号，
                              // 可以没有参数，有参数的话只能是一个类型同属性本身类型的参数，用来记录属性改变后的值。

public slots:
    void doSomething(BALL_COLOR ballColor) {
        qDebug() << "Gemini::doSomething() called with"<<ballColor;
        if(ballColor!=m_ballColor){
            m_ballColor=ballColor;
            qDebug()<<"ball color changed";
        }
    }

private:
    BALL_COLOR m_ballColor;
    unsigned int m_ballNumber; // QML要访问的成员变量
};
#endif // GEMINI_H
