#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

//If condition is true return first value (a), false returns second (b)
#define max(a,b) ((a)>(b)?(a):(b))

using namespace std;

static const int n = 8;
const int mainArray[n] = { -1, 2, 4, -3, 5, 2, -5 , 2 };

//Predefine functions
void SlowMaxSub();
void MedMaxSub();
void FastMaxSub();

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    const static int algoTypes = 3;
    int curType = 0;

    using namespace std::chrono;
    high_resolution_clock::time_point t1, t2;
    duration<double> time_span[algoTypes];

    t1 = high_resolution_clock::now();
    //Algorithm 1
    SlowMaxSub();
    t2 = high_resolution_clock::now();

    time_span[curType] = duration_cast<duration<double>>(t2 - t1);
    curType++;

    t1 = high_resolution_clock::now();
    //Algorithm 2
    MedMaxSub();
    t2 = high_resolution_clock::now();

    time_span[curType] = duration_cast<duration<double>>(t2 - t1);
    curType++;

    t1 = high_resolution_clock::now();
    //Algorithm 3
    FastMaxSub();
    t2 = high_resolution_clock::now();

    time_span[curType] = duration_cast<duration<double>>(t2 - t1);

    for (int i = 0; i < algoTypes; i++)
    {
        std::cout << "algoTypes " << i << ": " << time_span[i].count() << " seconds \n";
    }
}

void SlowMaxSub()
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

void MedMaxSub()
{
    int best = 0;
    //Start sum with this value
    for (int a = 0; a < n; a++) 
    {
        int sum = 0;
        //Check sum of all possible values start at a until n
        for (int b = a; b < n; b++) 
        {
            //Add next value to sum
            sum += mainArray[b];
            //Set new max value based on previous or new sum
            best = max(best, sum);
        }
    }
    cout << best << "\n";
}

void FastMaxSub()
{
    int best = 0, sum = 0;
    //Start sum with this value
    for (int k = 0; k < n; k++) 
    {
        //Determine if the max subArray should start before k or at k
        //based on the (max sum + k) or the value of k
        //Ex if max sum is negative
        sum = max(mainArray[k], sum + mainArray[k]);
        best = max(best, sum);
    }
    cout << best << "\n";
}