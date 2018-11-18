#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
#define SIZE 10000000
int a,b,N,alen;
int queue_front, queue_back;
//bool visited[1000][1000];
char maps[10000][10000];
int block[10000][10000];
struct Node
{
    int xx;
    int yy;
    int steps;
};
Node queu[SIZE];

int main()
{
    //string a;
    int i,j,k;
    int x,y;
    int start_x,start_y;
    int T;
    long long int N,K,X;
    while(cin >> T)
    {
        for(i = 0;i < T;i++)
        {
            cin >> N >> K >> X;
            cout << "Case " << i+1 << ": ";
            cout << (N*(N + 1)/2) - (2*X + (K - 1)) * K/2 <<endl;
        }
    }


}

