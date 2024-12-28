#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> sl, int left, int right, int k)
{
    int mid;
    if (left > right)
        return -1;
    mid = (left + right) >> 1;
    if (sl[mid] == k)
        return mid;
    else if (sl[mid] > k)
        return binary_search(sl, left, mid - 1, k);
    else
        return binary_search(sl, mid + 1, right, k);
}

int main()
{
    vector<int> sl = {10, 12, 15, 20, 24, 28, 30, 35, 46, 50, 55, 68};
    int k = 24;
    int pos = binary_search(sl, 0, sl.size() - 1, k);
    if (pos != -1)
        cout << "查找成功，元素" << k << "位于下标" << pos << endl;
    else
        cout << "查找失败，元素" << k << "不在数组中" << endl;
    return 0;
}