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
    double viewWidth = xMax - xMin;

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
        mTimer = new QTimer(this);
        connect(mTimer, &QTimer::timeout, this, [this]() { setX(mZoomXMin, mZoomXMax); });
        mTimer->start(15);
    }
    qDebug() << "wheelEvent: " << event->angleDelta()
             << " absX: " << QDateTime::fromMSecsSinceEpoch(absMinX)
             << " mZoomXMin: " << QDateTime::fromMSecsSinceEpoch(mZoomXMin);
}
