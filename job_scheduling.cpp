#include <iostream>
#include <algorithm>

using namespace std;
struct Job
{
    int deadline;
    int profit;
};
int main()
{
    int size;
    cout << "Enter jobs count";
    cin >> size;
    Job jobs[size];
    int max;
    cout << "Enter Jobs details";
    for (int i = 0; i < size; i++)
    {
        cout << "Enter job " << i + 1 << " deadline:";
        cin >> jobs[i].deadline;
        cout << "Enter job " << i + 1 << " profit:";
        cin >> jobs[i].profit;
        if (i == 0)
        {
            max = jobs[i].deadline;
        }
        else
        {
            if (max < jobs[i].deadline)
            {
                max = jobs[i].deadline;
            }
        }
    }
    // sort the jobs based on profit
    sort(jobs, jobs + size, [](Job &a, Job &b)
         { return a.profit > b.profit; });
    for (int i = 0; i < size; i++)
    {
        cout << jobs[i].profit << "(" << jobs[i].deadline << ")" << endl;
    }
    // slots, selected jobs
    int slots[max];
    Job selectedJobs[max];

    for (int i = 0; i < max; i++)
    {
        slots[i] = 0; // not allocated default value
    }
    int totalProfit = 0;
    for (int i = 0; i < size; i++)
    {
        int d = jobs[i].deadline;
        cout << i << " " << jobs[i].deadline << " " << jobs[i].profit << endl;
        for (int j = d - 1; j >= 0; j--)
        {
            if (slots[j] == 0) // slot is not allocated
            {
                slots[j] = 1;
                selectedJobs[j] = jobs[i];
                totalProfit += jobs[i].profit;
                cout << "profit" << jobs[i].profit << "slot" << j;
                break;
            }
        }
    }
    cout << endl
         << endl;
    for (int i = 0; i < size; i++)
    {
        cout << jobs[i].profit << "(" << jobs[i].deadline << ")" << endl;
    }
    cout << "Selected Jobs:" << endl;
    for (int i = 0; i < max; i++)
    {
        cout << selectedJobs[i].profit << "(" << selectedJobs[i].deadline << ")" << endl;
    }
    cout << "Total profit:" << totalProfit;

    return 0;
}
