#include <iostream>
using namespace std;

void kmp_next(string t, int next[])
{
    int i = 0, j = -1, sz = t.size();
    next[0] = -1;
    while (i < sz)
    {
        if (j == -1 || t[i] == t[j])
        {
            ++i, ++j;
            if (t[i] == t[j])
                next[i] = next[j];
            else
                next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}

int kmp(string s, string t)
{
    int i = 0, j = 0, sz_s = s.size(), sz_t = t.size();
    int next[sz_t];
    kmp_next(t, next);
    while (i < sz_s && j < sz_t)
    {
        if (j == -1 || s[i] == t[j])
        {
            ++i, ++j;
            if (j == sz_t)
                return i - j;
        }
        else
        {
            j = next[j];
        }
    }
    return -1;
}

int main()
{
    string s = "ababcabcacbab", t = "abcac";
    int pos = kmp(s, t);
    if (pos != -1)
        cout << "查找成功，子串位于下标" << pos << endl;
    else
        cout << "查找失败，子串不在字符串中" << endl;
    return 0;
}