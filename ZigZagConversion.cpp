#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string convert(string s, int n)
    {
        if (n <= 1)
        {
            return s;
        }

        string dst = "";

        for (int k = 1; k <= n; k++)
        {
            if (k == 1)
            {
                if (k <= s.size())
                    dst.push_back(s[k - 1]);

                int idx = k + 2 * (n - k);
                while (k < n && idx <= s.size())
                {
                    dst.push_back(s[idx - 1]);
                    idx += 2 * (n - k);
                }
            }
            else if (k == n)
            {
                if (k <= s.size())
                    dst.push_back(s[k - 1]);

                int idx = k + 2 * (n - 1);
                while (idx <= s.size())
                {
                    dst.push_back(s[idx - 1]);
                    idx += 2 * (n - 1);
                }
            }
            else
            {
                int i = 0;
                int idx = k + 2 * (n - 1) * i;
                int v = idx + 2 * (n - k);

                for (i++; idx <= s.size(); i++)
                {
                    dst.push_back(s[idx - 1]);
                    if (v <= s.size())
                    {
                        dst.push_back(s[v - 1]);
                    }

                    idx = k + 2 * (n - 1) * i;
                    v = idx + 2 * (n - k);
                }
            }
        }

        return dst;
    }
};

int main()
{
    Solution solution;

    string s;
    int rows;
    while (cin >> s >> rows)
    {
        cout << solution.convert(s, rows) << endl;
    }

    return 0;
}
