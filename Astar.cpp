#include <bits/stdc++.h>
using namespace std;
int g = 0;
void print(int puzzle[])
{
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0)
            cout << endl;
        if (puzzle[i] == -1)
            cout << "_ ";
        else
            cout << puzzle[i] << " ";
    }
    cout << endl
         << endl;
}
bool solvable(int start[])
{
    int invrs = 0;
    for (int i = 0; i < 9; i++)
    {
        if (start[i] <= 1)
            continue;
        for (int j = i + 1; j < 9; j++)
        {
            if (start[j] == -1)
                continue;
            if (start[i] > start[j])
                invrs++;
        }
    }
    return (invrs & 1) == 0;
}
void moveLeft(int start[], int position)
{
    int temp = start[position];
    start[position] = start[position - 1];
    start[position - 1] = temp;
}
void moveRight(int start[], int position)
{
    int temp = start[position];
    start[position] = start[position + 1];
    start[position + 1] = temp;
}
void moveUp(int start[], int position)
{
    int temp = start[position];
    start[position] = start[position - 3];
    start[position - 3] = temp;
}
void moveDown(int start[], int position)
{
    int temp = start[position];
    start[position] = start[position + 3];
    start[position + 3] = temp;
}

int heuristic(int start[], int goal[])
{
    int h = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (start[i] == goal[j] && start[i] != -1)
            {
                h += abs((j - i) / 3) + abs((j - i) % 3);
            }
        }
    }
    return h + g;
}

void moveTile(int start[], int goal[])
{
    int emptyAt = 0;
    for (int i = 0; i < 9; i++)
    {
        if (start[i] == -1)
        {
            emptyAt = i;
            break;
        }
    }
    int t1[9];
    int t2[9];
    int t3[9];
    int t4[9];
    int f1, f2, f3, f4 = 1000;
    for (int i = 0; i < 9; i++)
    {
        t1[i] = start[i];
        t2[i] = start[i];
        t3[i] = start[i];
        t4[i] = start[i];
    }
    int row = emptyAt / 3;
    int col = emptyAt % 3;
    if (col - 1 >= 0)
    {
        moveLeft(t1, emptyAt);
        f1 = heuristic(t1, goal);
    }
    if (col + 1 < 3)
    {
        moveRight(t2, emptyAt);
        f2 = heuristic(t2, goal);
    }
    if (row + 1 < 3)
    {
        moveDown(t3, emptyAt);
        f3 = heuristic(t3, goal);
    }
    if (row - 1 >= 0)
    {
        moveUp(t4, emptyAt);
        f4 = heuristic(t4, goal);
    }
    if (f1 <= f2 && f1 <= f3 && f1 <= f4)
    {
        moveLeft(start, emptyAt);
    }
    else if (f2 <= f1 && f2 <= f3 && f2 <= f4)
    {
        moveRight(start, emptyAt);
    }
    else if (f3 <= f1 && f3 <= f2 && f3 <= f4)
    {
        moveDown(start, emptyAt);
    }
    else
    {
        moveUp(start, emptyAt);
    }
}
void solveEight(int start[], int goal[])
{
    g++;
    moveTile(start, goal);
    print(start);
    int f = heuristic(start, goal);
    if (f == g)
    {
        cout << "Solved in " << f << " moves" << endl;
        return;
    }
    solveEight(start, goal);
}
int main()
{
    int start[9];
    int goal[9];
    cout << "Enter the initial state" << endl;
    for (int i = 0; i < 9; i++)
    {
        cin >> start[i];
    }
    cout << "Enter the goal state" << endl;
    for (int i = 0; i < 9; i++)
    {
        cin >> goal[i];
    }
    print(start);
    if (solvable(start))
    {
        solveEight(start, goal);
    }
    else
    {
        cout << "\nImpossible To Solve" << endl;
    }
}