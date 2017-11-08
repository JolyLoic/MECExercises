
#include "stdafx.h"
#include "BigData.h"
#include <numeric>


BigData::BigData() : 
    isMySummaryUpToDate(false)
{
}

double BigData::summary()
{
    if (!isMySummaryUpToDate)
    {
        mySummary = computeSummary(myRawData);
        isMySummaryUpToDate = true;
    }
    return mySummary;
}

void BigData::addDataPoint(double d)
{
    myRawData.push_back(d);
    isMySummaryUpToDate = false;
}

double BigData::computeSummary(std::vector<double>& data)
{
    return std::accumulate(data.begin(), data.end(), 0.0); // Beware, it has to be 0.0, not 0
}


