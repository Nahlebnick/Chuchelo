#include "game.h"

GameField::GameField(QWidget *parent)
    : QWidget{parent}
{
    Zu = new chuchelo;
    chuchelo_timer = new QTimer();
    connect(chuchelo_timer, &QTimer::timeout, this, &GameField::MoveChucheloSlot);
    chuchelo_timer->start(20);
    setFixedSize(1280, 720);
    setMouseTracking(true);
    setFocusPolicy(Qt::StrongFocus);
}

void GameField::paintEvent(QPaintEvent *)
{
    //Отрисовка всего
    QPainter painter(this);
    Zu->draw(&painter);
    painter.drawRect(0, 0, width(), height());
}

void GameField::mouseMoveEvent(QMouseEvent *pe)
{
    // Смотрим, когда мышь наведена на объект
    QPoint p(pe->pos());
    QRect r(Zu->m_x-10, Zu->m_y-10, Zu->images[Zu->m_currentImg].width()+10, Zu->images[Zu->m_currentImg].height()+10);
    if(r.contains(p))
    {

        Zu->speedY = QRandomGenerator::global()->generate() % 20 + 20;
        Zu->speedX = QRandomGenerator::global()->generate() % 20 + 20;
    }
}

void GameField::mousePressEvent(QMouseEvent *pe)
{
    QPoint p(pe->pos());

    QRect r(Zu->m_x, Zu->m_y, Zu->images[Zu->m_currentImg].width(), Zu->images[Zu->m_currentImg].height());
    if(r.contains(p))
    {
        qDebug() << p;
    }
}

void GameField::MoveChucheloSlot()
{
    //Изменяем положение объекта
    Zu->m_x += Zu->m_direction_x * Zu->speedX;
    Zu->m_y += Zu->m_direction_y * Zu->speedY;
    if (Zu->speedX != 0) Zu->speedX -= Zu->m_accelerate_x;
    if (Zu->speedY != 0) Zu->speedY -= Zu->m_accelerate_y;

    //Check edges
    if (Zu->m_x <= 0)
    {
        Zu->m_x = 1;
        Zu->m_direction_x *= -1;
    }
    else if (Zu->m_x > width()-Zu->images[Zu->m_currentImg].width())
    {
        Zu->m_x = width()-Zu->images[Zu->m_currentImg].width();
        Zu->m_direction_x *= -1;
    }
    if (Zu->m_y <= 0)
    {
        Zu->m_y = 1;
        Zu->m_direction_y *= -1;
    }
    else if (Zu->m_y > height()-Zu->images[Zu->m_currentImg].height())
    {
        Zu->m_y = height()-Zu->images[Zu->m_currentImg].height();
        Zu->m_direction_y *= -1;
    }

    //Перерисовываем
    repaint();
}
