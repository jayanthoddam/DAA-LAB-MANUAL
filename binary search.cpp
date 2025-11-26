#include <iostream>
using namespace std;
int binary_search(int a[], int left, int right, int target)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        if (a[mid] == target)
        {
            return mid;
        }
        else if (a[mid] < target)
        {
            return binary_search(a, mid + 1, right, target);
        }
        else if (a[mid] > target)
        {
            return binary_search(a, left, mid - 1, target);
        }
    }
    else
    {
        return -1;
    }
}
void printArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i];
    }
    cout << endl;
}
int main()
{
    cout << "Enter size of array";
    int size;
    cin >> size;

    int array[size];
    for (int ind = 0; ind < size; ind++)
    {
        cout << "Enter array element at index " << ind;
        cin >> array[ind];
    }

    cout << "Original Array";
    printArray(array, size);

    cout << "Enter target";
    int target;
    cin >> target;

    int ret = binary_search(array, 0, size - 1, target);
    if (ret == -1)
        cout << "target not found";
    else
        cout << "target found at index " << ret;
    return 0;
}
