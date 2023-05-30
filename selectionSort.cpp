#include <bits/stdc++.h>
using namespace std;
const int SIZE = 100;
int main()
{
    int array[SIZE];
    cout << "enter the size of the array" << endl;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "enter element" << endl;
        cin >> array[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[i])
            {
                swap(array[i], array[j]);
            }
        }
    }
    cout << "sorted array" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
}