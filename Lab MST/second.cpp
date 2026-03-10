#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<string> words = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    // vector<string> words = {"a", "ab", "abc", "d", "cd", "bcd"};
    // vector<string> words = {"a", "aa", "aaa", "aaaa"};

    int n = words.size();
    vector<int> bitmask(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (char c : words[i])
        {
            bitmask[i] |= (1 << (c - 'a'));
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((bitmask[i] & bitmask[j]) == 0)
            {
                ans = max(ans, (int)(words[i].size() * words[j].size()));
            }
        }
    }
    cout << "Answer for second: " << ans << " ";
    return 0;
}