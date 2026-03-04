#include <iostream>

const int ARRAY_SIZE = 10;

using namespace std;

int* ReverseArray(const int arr[], int size);

void print(const int arr[], int size);

int main()
{
    // Main array of primes is populated
    int primes[ARRAY_SIZE] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

    int* reversePrimes;


    return 0;
}

int* ReverseArray(const int arr[], int size)
{
    int *reversePrimes = new int[ARRAY_SIZE];

    int j = 0; // Counter variable for constant input array

    for (int i = (size - 1); i >= 0; i--) // Starts from the last element and works down
    {
        reversePrimes[i] = arr[j];

        j++; // Input index is increased
    }
}
