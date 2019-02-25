#ifndef GEMINI_H
#define GEMINI_H

// Gemini.h
#include <QObject>
#include <QDebug>

class Gemini : public QObject // 必须共有继承自QObject，这样才可以在里面写信号、槽函数等特性
{
    Q_OBJECT // 必须写，用来声明信号与槽
    Q_ENUMS(BALL_COLOR) // // 枚举类型，要想在QML中使用该枚举，就需要加宏Q_ENUMS()

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

signals:
    void begin();

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
};
#endif // GEMINI_H
