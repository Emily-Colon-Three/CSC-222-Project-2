/*
    This program first creates an array of 10 prime numbers, its size defined as a constant. Then, the program uses pointers and a dynamic array to create a mirrored version of the original
    array. After the arrays are properly set up, they are both printed to the terminal, first the original, then the reversed. Memory is deallocated before the program terminates.
*/
#include <iostream>

const int ARRAY_SIZE = 10;

using namespace std;

int* ReverseArray(const int arr[], int size);

void print(const int arr[], int size);

int main()
{
    // Main array of primes is populated
    int primes[ARRAY_SIZE] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

    int* reversePrimes = ReverseArray(primes, ARRAY_SIZE);

    print(primes, ARRAY_SIZE); // Prints original array

    print(reversePrimes, ARRAY_SIZE); // Prints reversed array

    delete[] reversePrimes; // Deallocates memory of reversed prime array (VERY IMPORTANT!!)

    return 0;
}

/*
    Summary: Takes in an array, reverses its values into a dynamic array, then outputs said dynamic array.
    Parameters: const int arr[], which is the integer array passed in and made constant to preserve contents, and int size, which holds the exact size of the input and output array.
    Return: Int pointer, which should return the elements of the input array in reverse order.
    Preconditions: arr[] should be filled beforehand, and be of the passed in size.
    Postconditions: space for dynamic array elements must be deallocated later.
*/
int* ReverseArray(const int arr[], int size)
{
    int *output = new int[ARRAY_SIZE];

    int j = 0; // Counter variable for constant input array

    for (int i = (size - 1); i >= 0; i--) // Starts from the last element and works down
    {
        output[i] = arr[j];

        j++; // Input index is increased
    }

    return output;
}

/*
    Summary: Prints out the contents of an array to console, a space between each integer element.
    Parameters: const int arr[], the input array of integers which cannot be changed, and int size, the exact size of the array passed in.
    Return: None.
    Preconditions: arr[] should have contents inside and be of exactly the size specified in the size variable.
    Postconditions: Contents are printed to the terminal/console using cout.
*/
void print(const int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " "; // Prints each element with space between
    }

    cout << endl;
}
