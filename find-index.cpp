// find index such that sum of left side is equal to sum of right side
#include <iostream>
using namespace std;

int FindLeftSum(int *arr, int index)
{
    int sum = 0;
    for (int i = 0; i < index; i++)
    {
        sum += arr[i];
    }
    // cout<<"Sum Left: "<<sum<<endl;
    return sum;
}

int FindRightSum(int *arr, int index, int size)
{
    int sum = 0;
    for (int i = index + 1; i < size; i++)
    {
        sum += arr[i];
    }

    // cout<<"Sum Right: "<<sum<<endl;
    return sum;
}

int main()
{
    int arr[] = {5,1,2,3,4,3,2,4,1,1};

    int size = sizeof(arr) / sizeof(int);
    int index = 0;

    for (index; index < size-1; index++)
    {
        if (FindRightSum(arr, index, size) == FindLeftSum(arr, index))
        {
            cout << "Index: " << index << endl;
            break;
        }
    }
    
    // cout << "There is no such index" << endl;

    return 0;
}