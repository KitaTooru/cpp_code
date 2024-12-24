#include <iostream>
using namespace std;

typedef char datatype;
struct adjMatrix
{
    datatype data[eNum];
    int edge[eNum][eNum];
    int v;
    int e;
};