#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setFixedSize(1280, 720);

    m_gameField = new GameField;
    m_layout = new QVBoxLayout;
    m_layout->addWidget(m_gameField);
    this->setLayout(m_layout);
}

Widget::~Widget()
{
    delete ui;
}
