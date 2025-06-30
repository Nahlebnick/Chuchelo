#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "game.h"
#include <QVBoxLayout>


QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    GameField *m_gameField;
    QVBoxLayout *m_layout;

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
