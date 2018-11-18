#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
#define SIZE 100000
int a,b,N,alen,t,lon;
int queue_front, queue_back;
bool visited[1000][1000];
int ans[100000];
string A[7] = {"","fill A","pour A B","empty A","fill B","pour B A","empty B"};
void water(int n,int an,int bn,int how)
{
    if(how == 1)
        an = a;
    else if(how == 2)
    {
        int sum = an + bn;
        bn = min(an + bn,b);
        an = sum - bn;
    }
    else if(how == 3)
    {
        an = 0;
    }
    else if(how == 4)
        bn = b;
    else if(how == 5)
    {
        int sum = an + bn;
        an = min(an + bn,a);
        bn = sum - an;
    }
    else if(how == 6)
    {
        bn = 0;
    }
    if(visited[an][bn] == true) return;
    visited[an][bn] = true;
    //cout << an << " " << bn << " " << n << endl;
    ans[n - 1] = how;
    if(an == N || bn == N)
    {
        //cout <<"hello" << endl;
        t = 1;
        lon = n;
        return;
    }
    int i;
    if(t == 1) return;
    for(i = 1;i <= 6;i++)
    {
        if(t == 1) return;
        water(n+1,an,bn,i);
        if(t == 1) return;
    }
    visited[an][bn] = false;
    return;

}
//Bot queue[SIZE];
int main()
{
    //string a;
    int i,j;
    while(cin >> a >> b >> N)
    {
        for(i = 0;i <= a;i++)
        {
            for(j = 0;j <= b;j++)
            {
                visited[i][j] = false;
            }
        }
        t = 0;
        visited[0][0] = true;
        for(i = 1;i <= 6;i++)
        {
            water(1,0,0,i);
            if(t == 1) break;
        }

        for(i = 0;i <= lon;i++)
        {
            if(i != lon)
                cout << A[ans[i]] << endl;
        }
        cout << "success" <<endl;

        //cout << "answer = " << answer << endl;
    }
}

