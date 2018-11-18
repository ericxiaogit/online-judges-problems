#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
int A[205][205];
int node[205];
int color[205];
long long int N;
int ans;
void F(int k)
{
    int i,j;
    for(i = 0;i < node[k];i++)
    {
        if(ans == 0) return;
        if(color[A[k][i]] != 0 && color[A[k][i]] == color[k])
        {
            //cout << "goodbye" << endl;
            ans = 0;
            return;
        }
        else if(color[A[k][i]] == 0)
        {
            color[A[k][i]] = 0 - color[k];
            //cout << "hello" << endl;
            F(A[k][i]);

        }

    }
}
int main()
{
    long long int sum;
    int a,b;
    long long int i,k,j,L;
    double avg,temp;
    int now,low;
    int fin;
    while(cin >> N)
    {
        sum = 0;
        for(i = 1;i < N;i++)
        {
            if(i*(i + 1)/2 > N) break;
            if(i % 2 == 0 && N % i != 0 && (2 * N) % i == 0)
                sum++;
            if(i %2 == 1 && N % i == 0)
                sum ++;


        }
        cout << sum << endl;

    }

}



