#include "glwidget.h"
#include <QPainter>
#include <paintroutine.h>
GLWidget::GLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{

}

void GLWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter(this);
    paintFunction(&painter, "Painting on OpenGLWidget");
}

QSize GLWidget::sizeHint() const
{
    return QSize(400, 700);
}
