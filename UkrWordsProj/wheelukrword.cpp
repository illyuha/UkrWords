#include "wheelukrword.h"
#include <qmath.h>

void WheelUkrWord::draw() const
{
    QGraphicsScene * scene = _view->scene();

    int letterHeight = 30;
    qreal radius1 = 20, radius2 = radius1 + letterHeight, radius3 = 200, radius4 = radius3 + letterHeight;

    QPen pen;
    pen.setWidth(2);

    scene->addEllipse(-radius1,-radius1,2*radius1,2*radius1,pen);
    scene->addEllipse(-radius2,-radius2,2*radius2,2*radius2,pen);
    scene->addEllipse(-radius3,-radius3,2*radius3,2*radius3,pen);
    scene->addEllipse(-radius4,-radius4,2*radius4,2*radius4,pen);

    QVector<QPointF> surnamePoints;
    QVector<qreal> angles;

    for (uint i = 0; i < surnameLength(); ++i)
    {
        qreal phi = M_PI * (360 / surnameLength() * i) / 180;
        qreal x1 = radius1 * cos(phi), y1 = radius1 * sin(phi);
        qreal x2 = radius2 * cos(phi), y2 = radius2 * sin(phi);
        scene->addLine(x1,y1,x2,y2,pen);
        surnamePoints.push_back(QPointF(x2,y2));
        // TODO: avoid additional computations (i.e. unnecessary conversion from radians to degrees
        angles.push_back(phi * 180 / M_PI);
    }
    surnamePoints.push_back(surnamePoints[0]);
    angles.push_back(360);

    QVector<QPointF> aphorismPoints;

    for (int i = 0; i < aphorism().length(); ++i)
    {
        qreal phi = M_PI * (360 / aphorism().length() * i) / 180;
        qreal x1 = radius3 * qCos(phi), y1 = radius3 * qSin(phi);
        qreal x2 = radius4 * qCos(phi), y2 = radius4 * qSin(phi);
        scene->addLine(x1,y1,x2,y2,pen);
        aphorismPoints.push_back(QPointF(x1,y1));
    }

    aphorismPoints.push_back(aphorismPoints[0]);

    for (uint i = 0; i < surnameLength(); ++i)
    {
        qreal part = 0.5 * (angles[i] + angles[i+1]) / 360 * aphorism().length();
        //part = qFloor(phi);
        int ipart = part;
        scene->addLine(surnamePoints[i].x(),surnamePoints[i].y(),aphorismPoints[ipart].x(),aphorismPoints[ipart].y(),pen);
        scene->addLine(surnamePoints[i+1].x(),surnamePoints[i+1].y(),aphorismPoints[ipart+1].x(),aphorismPoints[ipart+1].y(),pen);
    }

}
