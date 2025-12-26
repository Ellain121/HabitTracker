#pragma once

#include <QSortFilterProxyModel>

class FilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    explicit FilterProxyModel(QObject* parent = nullptr);

    bool filterAcceptsColumn(
        int sourceColumn, const QModelIndex& sourceParent) const override;

    int columnCount(const QModelIndex& parent = QModelIndex()) const override;

signals:
    void newFirstColumnIndx(int);

public slots:
    void scrollView(int offset);

private:
    const int mTABLE_COLUMN_NUMBER;
    int       mFirstClmnIndx;
};
