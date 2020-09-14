#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

//If condition is true return first value (a), false returns second (b)
#define max(a,b) ((a)>(b)?(a):(b))

using namespace std;

static const int n = 8;
const int mainArray [n] = { -1, 2, 4, -3, 5, 2, -5 , 2 };

//Predefine functions
void slowMaxSub();

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    const static int algoTypes = 1;
    int curType = 0;

    using namespace std::chrono;
    high_resolution_clock::time_point t1, t2;
    duration<double> time_span[algoTypes];

    t1 = high_resolution_clock::now();
    //First Algorithm
    slowMaxSub();
    t2 = high_resolution_clock::now();

    time_span[curType] = duration_cast<duration<double>>(t2 - t1);
    curType++;




    for (int i = 0; i < algoTypes; i++)
    {
        std::cout << "algoTypes " << i << ": " << time_span[i].count() << " seconds \n";
    }
}

void slowMaxSub()
{
    int best = 0;
    //Start sum with this value
    for (int a = 0; a < n; a++) 
    {
        //End sum with this value
        for (int b = a; b < n; b++) 
        {
            int sum = 0;
            //Add up the values between a and b
            for (int k = a; k <= b; k++) 
            {
                sum += mainArray[k];
            }
            //Set new max value based on previous or new sum
            best = max(best, sum);
        }
    }
    //Print results
    cout << best << "\n";
}

