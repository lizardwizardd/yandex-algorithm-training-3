#include <cmath>
#include <iostream>

int main() 
{
    float hrsA, minA, secA, hrsB, minB, secB, hrsC, minC, secC;

    scanf("%f:%f:%f", &hrsA, &minA, &secA);
    scanf("%f:%f:%f", &hrsB, &minB, &secB);
    scanf("%f:%f:%f", &hrsC, &minC, &secC);

    int timeToAnswer;
    int correctedTimeSeconds;

    if (hrsC >= hrsA)
    {
        timeToAnswer = round((((hrsC - hrsA) * 3600 + (minC - minA) * 60) + (secC - secA)) / 2);
    }
    else 
    {
        timeToAnswer = round((((24 - hrsA + hrsC) * 3600 + (minC - minA) * 60) + (secC - secA)) / 2);
    }
    correctedTimeSeconds = hrsB * 3600 + minB * 60 + secB + timeToAnswer;

    int hrs = correctedTimeSeconds / 3600 % 24;
    int mins = correctedTimeSeconds / 60 % 60;
    int secs = correctedTimeSeconds % 60;

    std::printf("%02d:%02d:%02d", hrs, mins, secs);

  return 0;
}
