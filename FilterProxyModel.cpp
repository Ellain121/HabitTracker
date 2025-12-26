#include "FilterProxyModel.hpp"

FilterProxyModel::FilterProxyModel(QObject* parent)
    : QSortFilterProxyModel{parent}
    , mTABLE_COLUMN_NUMBER{7}
    , mFirstClmnIndx{1}
{
}

bool FilterProxyModel::filterAcceptsColumn(
    int sourceColumn, const QModelIndex& sourceParent) const
{
    return sourceColumn == 0 || (sourceColumn >= mFirstClmnIndx &&
                                    sourceColumn < mFirstClmnIndx + mTABLE_COLUMN_NUMBER);
}

int FilterProxyModel::columnCount(const QModelIndex& parent) const
{
    return mTABLE_COLUMN_NUMBER;
}

void FilterProxyModel::scrollView(int offset)
{
    int realColumnNumber = sourceModel()->columnCount();

    mFirstClmnIndx -= offset;    // inversion -1 --> 1     1 --> -1
    mFirstClmnIndx =
        (std::abs(mFirstClmnIndx) + mFirstClmnIndx) >> 1;    // fancy way of std::min(0,v)
    mFirstClmnIndx =
        std::min(realColumnNumber - mTABLE_COLUMN_NUMBER + 1, mFirstClmnIndx);

    emit invalidateFilter();
    emit newFirstColumnIndx(mFirstClmnIndx);
}
