#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job
{
    string name;
    int profit;
    int deadline;
};

bool compareJobs(const Job &job1, const Job &job2)
{
    return job1.profit > job2.profit;
}

int main()
{
    cout << "Enter the number of jobs: ";
    int n;
    cin >> n;
    vector<Job> table(n);
    cout << "Enter Name profit deadline" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> table[i].name >> table[i].profit >> table[i].deadline;
    }

    sort(table.begin(), table.end(), compareJobs);

    cout << endl;
    int maxDeadline = 0;
    for (const Job &job : table)
    {
        maxDeadline = max(maxDeadline, job.deadline);
        cout << job.name << " " << job.profit << " " << job.deadline << endl;
    }

    cout << endl;
    vector<Job> gc(maxDeadline);
    vector<int> selected(maxDeadline, 0);
    for (const Job &job : table)
    {
        int place = job.deadline - 1;
        while (place >= 0)
        {
            if (selected[place] == 0)
            {
                selected[place] = 1;
                gc[place] = job;
                break;
            }
            place--;
        }
    }

    for (const Job &job : gc)
    {
        cout << job.name << " " << job.profit << " " << job.deadline << endl;
    }

    return 0;
}