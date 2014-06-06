#include "myutils.h"

MyUtils::MyUtils()
{
}

int MyUtils::randInt(int low, int high)
{
    // Random number between low and high
    return qrand() % ((high + 1) - low) + low;
}
