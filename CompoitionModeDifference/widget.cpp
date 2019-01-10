#include "widget.h"
#include <QPainter>

#include <QPainterPath>
#include <QResizeEvent>
#include <paintroutine.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}

Widget::~Widget()
{

}

void Widget::setUseImage(bool use)
{
    if(mUseImage != use)
    {
        mUseImage = use;
        if(mUseImage)
        {
            mImage = QImage(size(), QImage::Format_ARGB32_Premultiplied);
            mDirty = true;
        }
    }
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter1(this);

    QRect widgetRect(rect());
    if(mUseImage)
    {
        if(mDirty)
        {
            mImage.fill(0);
            QPainter painter(&mImage);
            paintFunction(&painter, "Painting on QImage");
            mDirty = false;
        }
        painter1.drawImage(widgetRect, mImage);
    }
    else
    {
        paintFunction(&painter1, "Painting on QWidget");
    }
}

void Widget::resizeEvent(QResizeEvent *event)
{
    if(mUseImage)
    {
        mImage = QImage(event->size(), QImage::Format_ARGB32_Premultiplied);
        mDirty = true;
    }
}

QSize Widget::sizeHint() const
{
    return QSize(400, 700);
}
