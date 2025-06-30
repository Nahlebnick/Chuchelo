

#ifndef GAME_H
#define GAME_H
#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QRandomGenerator>
#include <QMouseEvent>
#include <QVector>

class chuchelo;
class GameField;

class chuchelo
{
    friend GameField;
    //Q_OBJECT
public:
    explicit chuchelo();
    void draw(QPainter *painter);

private:
    int speedX, speedY;
    int m_x, m_y;
    float m_direction_y, m_direction_x;

    float m_accelerate_x, m_accelerate_y;
    QVector<QImage> images;
    int m_currentImg;

};

class GameField: public QWidget
{
    Q_OBJECT
public:
    GameField(QWidget *parent = nullptr);
    chuchelo *Zu;

    QTimer *chuchelo_timer;

protected:
    void paintEvent(QPaintEvent*);
    void mouseMoveEvent(QMouseEvent* pe);
    void mousePressEvent(QMouseEvent* pe);
private slots:
    void MoveChucheloSlot();
};

class MYCLASS
{
    int x;
public:
    MYCLASS();
};

#endif // GAME_H



