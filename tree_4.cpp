#include <iostream>
using namespace std;

typedef int elementType;
typedef struct heap
{
    elementType *elements;
    int size;
};

void heap_ajust(elementType heap[], int n, int cur)
{
    int i;
    elementType tmp = heap[cur];
    while ((i = 2 * cur + 1) < n)
    {
        if (i + 1 < n && heap[i] < heap[i + 1])
            i++;
        if (tmp >= heap[i])
            break;
        heap[cur] = heap[i];
        cur = i;
    }
    heap[cur] = tmp;
}

void heap_make(elementType heap[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heap_ajust(heap, n, i);
}

int find(heap h, elementType e)
{
    for (int i = 0; i < h.size; i++)
    {
        if (h.elements[i] == e)
        {
            return i + 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cout << "输入堆元素个数: ";
    cin >> n;

    elementType *elements = new elementType[n];
    cout << "输入元素: ";
    for (int i = 0; i < n; i++)
    {
        cin >> elements[i];
    }

    heap_make(elements, n);
    heap h = {elements, n};

    cout << "最大堆: ";
    for (int i = 0; i < n; i++)
        cout << h.elements[i] << " ";
    cout << endl;

    elementType e;
    cout << "输入要查找的元素: ";
    cin >> e;

    int position = find(h, e);
    if (position > 0)
        cout << "元素在位置: " << position << endl;
    else
        cout << "元素不在堆中." << endl;

    delete[] elements;
    return 0;
}
