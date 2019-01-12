#ifndef PAINTROUTINE_H
#define PAINTROUTINE_H

#include <QPainter>
inline void paintFunction(QPainter *painter, const QString& text)
{
    painter->setRenderHints(QPainter::Antialiasing);

    // Customize fonts
    QFont font = painter->font();
    font.setPointSize(20);
    painter->setFont(font);

    // draw text passed as argument
    painter->drawText(QPointF(20, 50), text);

    // get canvas size (widget size)
    auto paintRect = QRect(0, 0, painter->device()->width(), painter->device()->height());

    // save painter state, because we are moving to center
    // and will paint our A there, later we can restore state
    // which will reset painter
    painter->save();
    painter->translate(paintRect.width()/2, paintRect.height()/2);

    // Customize fonts and pen width
    font.setPointSize(400);
    font.setBold(true);
    painter->setFont(font);
    QPen pen = painter->pen();
    pen.setWidth(5);
    painter->setPen(pen);

    // Create a painter path to draw A with yellow brush
    QPainterPath textPath;
    textPath.addText(0,0, font, "A");
    painter->setBrush(Qt::yellow);
    auto textRect = textPath.boundingRect();
    painter->translate(-textRect.width()/2, textRect.height()/2);
    painter->drawPath(textPath);
    painter->restore();

    // now fill background behind current render using destination over
    // composition mode
    painter->setCompositionMode(QPainter::CompositionMode_DestinationOver);
    painter->fillRect(paintRect, Qt::darkGray);
}

#endif // PAINTROUTINE_H
