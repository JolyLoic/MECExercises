#include "stdafx.h"
#include "BigData.h"
#include <random>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    std::mt19937 gen(0); //Constant seed for now
    std::uniform_real_distribution<> dis(-1, 1);
    cout << setprecision(4) << right << fixed;
    for (int attempt = 0; attempt < 100; ++attempt)
    {
        BigData d;
        for (int i = 0; i < 100; ++i)
        {
            d.addDataPoint(dis(gen));
        }
        cout << setw(10) << d.summary() << "\t";
        for (int i = 0; i < 100000; ++i)
        {
            d.addDataPoint(dis(gen));
        }
        cout << setw(10) << d.summary() << endl;
    }
    return 0;
}

