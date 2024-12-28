#include <iostream>
using namespace std;

int bf(string s, string t)
{
    int i = 0, j = 0, k = 0, sz_s = s.size(), sz_t = t.size();
    while (i < sz_s && j < sz_t)
    {
        if (s[i] == t[j])
        {
            ++i, ++j;
            if (j == sz_t)
                return k;
        }
        else
        {
            ++k, i = k, j = 0;
        }
    }
    return -1;
}

int main()
{
    string s = "ababcabcacbab", t = "abcac";
    int pos = bf(s, t);
    if (pos != -1)
        cout << "查找成功，子串位于下标" << pos << endl;
    else
        cout << "查找失败，子串不在字符串中" << endl;
    return 0;
}