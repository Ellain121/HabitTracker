#pragma once

#include <QTableView>

class HabitDelegate;

// Same as QTableView, but most mouse events overridden
class HabTableView : public QTableView
{
    Q_OBJECT
public:
    HabTableView(QWidget* parent);

    void setHabitDelegate(HabitDelegate* delegate);

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseDoubleClickEvent(QMouseEvent* event) override;

    void wheelEvent(QWheelEvent* event) override;
signals:
    void wheelScrolled(int);

private:
    HabitDelegate* mHabitDelegate;
};
