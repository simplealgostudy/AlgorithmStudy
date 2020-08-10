// https://www.acmicpc.net/problem/2331
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

vector<int> sequenceVector;
int found = 0;

bool findRecursion(int compare, vector<int> sequenceVector)
{
    int size = sequenceVector.size();

    for (int i = 0; i < size; i++)
    {
        if (compare == sequenceVector[i])
        {
            found = i;
            return true;
        }
    }
    return false;
}

void makeNextSequence(int currentSequence, int powerNumber)
{
    int nextSequence = 0;
    if (findRecursion(currentSequence, sequenceVector))
        return;

    sequenceVector.push_back(currentSequence);

    while (currentSequence != 0)
    {
        nextSequence += pow(currentSequence % 10, powerNumber);
        currentSequence /= 10;
    }

    makeNextSequence(nextSequence, powerNumber);
}

int main()
{
    int firstNumber;
    int powerNumber;
    cin >> firstNumber;
    cin >> powerNumber;

    makeNextSequence(firstNumber, powerNumber);
    cout << found << endl;

    return EXIT_SUCCESS;
}
