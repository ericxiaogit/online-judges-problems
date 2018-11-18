#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
char maps[105][105];
int visited[105][105];
long long int A[1000+5][1000+5];
int N,M;

int main()
{
    unsigned long long int i,j,T,k;
    long long int a,b,c;
    long long int now,temp,ans;
    string x,y;
    now = 3;
    temp = 0;
    while(cin >> a >> b >> c)
    {
        if(a == 0 && b == 0 && c == 0) break;
        if(c < b)
            swap(b,c);
        if(c < a)
            swap(a,c);
        if(a * a + b * b == c * c)
            cout << "right" << endl;
        else
            cout << "wrong" << endl;
    }





}

