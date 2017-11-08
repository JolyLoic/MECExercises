#pragma once

class BigData
{
public:
    BigData();
    double summary();
    void addDataPoint(double d);
private:
    std::vector<double> myRawData;
    double mySummary;
    bool isMySummaryUpToDate;
    static double computeSummary(std::vector<double> &data);

};
