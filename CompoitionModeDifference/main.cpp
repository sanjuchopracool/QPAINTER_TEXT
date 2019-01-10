#include "widget.h"
#include <QApplication>
#include <QHBoxLayout>
#include <glwidget.h>
#include <QSurfaceFormat>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;
    Widget w1;
    Widget w2;
    GLWidget w3;
    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);
    format.setSamples(4);
    format.setProfile(QSurfaceFormat::CoreProfile);
    w3.setFormat(format); // must be called before the widget or its parent window gets shown

    w2.setUseImage(false);
    QHBoxLayout layout;
    layout.setMargin(0);
    layout.addWidget(&w1);
    layout.addWidget(&w2);
    layout.addWidget(&w3);
    w.setLayout(&layout);
    w.show();

    return a.exec();
}
