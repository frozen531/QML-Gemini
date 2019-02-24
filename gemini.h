#ifndef GEMINI_H
#define GEMINI_H

// Gemini.h
#include <QObject>
#include <QDebug>

class Gemini : public QObject // 必须共有继承自QObject，这样才可以在里面写信号、槽函数等特性
{
    Q_OBJECT // 必须写，用来声明信号与槽

signals:
    void begin();

public slots:
    void doSomething() {
        qDebug() << "Gemini::doSomething() called";
    }
};
#endif // GEMINI_H
