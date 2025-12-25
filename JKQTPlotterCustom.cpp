#include "JKQTPlotterCustom.hpp"

JKQTPlotterCustom::JKQTPlotterCustom(QWidget* parent)
    : JKQTPlotter{parent}
{
    // resizeTimer.setInterval(std::chrono::milliseconds(200));
}
// temp
#include <QDateTime>
void JKQTPlotterCustom::wheelEvent(QWheelEvent* event)
{
    double xMin = getXMin();
    double xMax = getXMax();
    mYMin = getYMin();
    mYMax = getYMax();
    double viewWidth = xMax - xMin;

    //	double zoomStep = (xMax - xMin) / 10;
    double sign = (-1.0) * event->angleDelta().y() / 120;
    double day = 86400000;
    double mult = 2.0;

    double absMaxX = getXAxis()->getAbsoluteMax();
    double absMinX = getXAxis()->getAbsoluteMin();

    mZoomXMin = xMin + day * sign * mult;
    mZoomXMax = xMax + day * sign * mult;
    if (mZoomXMin < absMinX)
    {
        mZoomXMin = absMinX;
        mZoomXMax = absMinX + viewWidth;
    }
    if (mZoomXMax > absMaxX)
    {
        mZoomXMin = absMaxX - viewWidth;
        mZoomXMax = absMaxX;
    }

    if (mTimer == nullptr)
    {
        // setXY(mZoomXMin, mZoomXMax, mYMin, mYMax);
        mTimer = new QTimer(this);
        connect(mTimer, &QTimer::timeout, this,
            [this]() { setXY(mZoomXMin, mZoomXMax, mYMin, mYMax); });
        mTimer->start(40);
    }
    // setX(z)
    qDebug() << "wheelEvent: " << event->angleDelta()
             << " absX: " << QDateTime::fromMSecsSinceEpoch(absMinX)
             << " mZoomXMin: " << QDateTime::fromMSecsSinceEpoch(mZoomXMin);
}
