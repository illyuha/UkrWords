#include "wheelukrword.h"
#include <qmath.h>

void WheelUkrWord::draw() const
{
    QGraphicsScene * scene = _view->scene();

    int letterHeight = 30;
    int radius1 = 20, radius2 = radius1 + letterHeight;

    QPen pen;
    pen.setWidth(2);

    scene->addEllipse(-radius1,-radius1,2*radius1,2*radius1,pen);
    scene->addEllipse(-radius2,-radius2,2*radius2,2*radius2,pen);

    for (int i = 0; i < author().length(); ++i)
    {
        qreal phi = M_PI * (360 / author().length() * i) / 180;
        qreal x1 = radius1 * cos(phi), y1 = radius1 * sin(phi);
        qreal x2 = radius2 * cos(phi), y2 = radius2 * sin(phi);
        scene->addLine(x1,y1,x2,y2,pen);
    }

}
