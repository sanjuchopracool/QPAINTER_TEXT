#ifndef PAINTROUTINE_H
#define PAINTROUTINE_H

#include <QPainter>
inline void paintFunction(QPainter *painter, const QString& text)
{
    painter->setRenderHints(QPainter::Antialiasing);
    QFont font = painter->font();
    font.setPointSize(20);
    painter->setFont(font);
    painter->drawText(QPointF(20, 30), text);

    auto paintRect = QRect(0, 0, painter->device()->width(), painter->device()->height());
    painter->save();

    painter->translate(paintRect.width()/2, paintRect.height()/2);
    font.setPointSize(400);
    font.setBold(true);
    painter->setFont(font);
    QPen pen = painter->pen();
    pen.setWidth(5);
    painter->setPen(pen);

    QPainterPath textPath;
    textPath.addText(0,0, font, "A");
    painter->setBrush(Qt::yellow);
    auto textRect = textPath.boundingRect();
    painter->translate(-textRect.width()/2, textRect.height()/2);
    painter->drawPath(textPath);
    painter->restore();

    painter->setBrush(Qt::darkGray);
    painter->setCompositionMode(QPainter::CompositionMode_DestinationOver);
    painter->drawRect(paintRect);
}

#endif // PAINTROUTINE_H
