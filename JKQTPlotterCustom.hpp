#pragma once

#include <jkqtplotter/jkqtplotter.h>

#include <QTimer>

class JKQTPlotterCustom : public JKQTPlotter
{
public:
	JKQTPlotterCustom(QWidget* parent = nullptr);

protected:
	void wheelEvent(QWheelEvent* event) override;

private:
    QTimer* mTimer = nullptr;
    double	mZoomXMin;
    double	mZoomXMax;
    double	mYMin;
    double	mYMax;
};
