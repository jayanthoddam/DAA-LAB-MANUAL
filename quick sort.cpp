#include <iostream>
using namespace std;
int partition(int a[], int low, int high)
{
    int pIndex = low;
    int pivot = a[high];
    for (int i = low; i < high; i++)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
    swap(a[high], a[pIndex]);
    return pIndex;
}
void quick_sort(int a[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);
        quick_sort(a, low, pi - 1);
        quick_sort(a, pi + 1, high);
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
    quick_sort(array, 0, size - 1);
    cout << "After Array";
    printArray(array, size);
    return 0;
}
