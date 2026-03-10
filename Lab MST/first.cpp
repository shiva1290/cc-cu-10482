#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> tasks = {{1, 2}, {2, 4}, {4, 8}};
    // vector<vector<int>> tasks = {{1, 3}, {2, 4}, {10, 11}, {10, 12}, {8, 9}};

    sort(tasks.begin(), tasks.end(), [](auto &a, auto &b)
         { return (b[1] - b[0]) < (a[1] - a[0]); });

    int curr = 0;
    int ans1 = 0;

    for (int i = 0; i < tasks.size(); i++)
    {
        int mini = tasks[i][1];
        int act = tasks[i][0];
        if (curr < mini)
        {
            ans1 += mini - curr;
            curr = mini;
        }
        curr -= act;
    }
    cout << "Answer for first: " << ans1 << " ";
    return 0;
}