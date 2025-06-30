#include "game.h"

chuchelo::chuchelo()
{

    images.push_back(QImage("chuchelo_left_small.png"));
    images.push_back(QImage("chuchelo_right_small.png"));
    m_currentImg = 0;

    m_x = 500;
    m_y = 500;
    speedX = 20;
    speedY = 20;

    m_direction_x = -1;
    m_direction_y = -1;

    m_accelerate_x = .5;
    m_accelerate_y = .5;
}

void chuchelo::draw(QPainter *painter)
{
    if (m_direction_x == 1) m_currentImg = 1;
    else m_currentImg = 0;
    painter->drawImage(m_x, m_y, images[m_currentImg]);
}
