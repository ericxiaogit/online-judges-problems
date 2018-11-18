#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
struct len
{
    int start;
    int ends;
    int place;
};
int now,N;
len A[300000];//+100000
int B[100000 +100];
int C[100000 + 100];
int sparses[30][100000+1];
void make_spars()
{
    int i;
    for(i = 0;i < now;i++)
    {
        sparses[0][i] = C[i];
    }
    int temp = 1;
    for(i = 1;i < 24;i++)
    {
        temp *= 2;
        for(int j = 0;j + temp < 100000+1;j++)
        {
            sparses[i][j] = max(sparses[i-1][j],sparses[i-1][j+temp/2]);
            //cout << sparse[i][j] << " ";
        }
        //cout << endl;
        //system("pause");
    }
}
int find_max(int l,int r)
{
    if(r < l) return 0;
    int temp = 1;
    int i = 0;
    while(l + temp < r-temp+1)
    {
        temp *= 2;
        i++;
    }
    return max(sparses[i][l],sparses[i][r-temp+1]);
}
int main()
{
    int i,j,Q,temp,last,from,to,lef,rig;
    int a,b;
    int ans;
    while(cin >> N)
    {
        if(N == 0) break;
        now = 0;
        cin >> Q;
        cin >> B[0];
        A[B[0] + 100000].start = 0;
        A[B[0] + 100000].place = 0;
        for(i = 1;i < N;i++)
        {
            cin >> B[i];
            if(B[i] != B[i - 1])
            {
                A[B[i - 1] + 100000].ends = i - 1;
                A[B[i] + 100000].start = i;
                A[B[i] + 100000].place = now+1;
                C[now] = A[B[i - 1] + 100000].ends - A[B[i - 1] + 100000].start+1;
                now++;

            }
            last = temp;

        }
        A[B[N-1] + 100000].ends = N - 1;
        C[now] = A[B[N - 1] + 100000].ends - A[B[N - 1] + 100000].start+1;
        now++;
        //system("pause");
        make_spars();
        //cout << "****" << endl;
        //cout << A[-1+100000].place <<" "<< A[1+100000].place <<" "<< A[3+100000].place <<" "<< A[10+100000].place <<endl;
        for(i = 0;i < now;i++)
        {
            cout << C[i] << " ";
        }
        cout <<endl;
        /*
        for(i = 0;i < now;i++)
        {
            for(j = 0;j <now;j++)
            {
                cout << sparses[i][j] << " ";
            }
            cout <<endl;
        }*/
        //cout << "Q = " <<Q <<endl;
        //system("pause");
        for(i = 0;i < Q;i++)
        {
            cin >> from >> to;
            from--;
            to--;
            lef = A[B[from]+100000].ends;
            rig = A[B[to]+100000].start;
            //cout << B[lef+1] << " " << B[rig-1] << endl;

            if(B[from]==B[to])
                cout << to - from +1 << endl;
            else
            {
                //cout << A[B[lef+1]+100000].place << " " << A[B[rig-1]+100000].place <<endl;
                //cout << find_max(A[B[lef+1]+100000].place,A[B[rig-1]+100000].place) << " " << lef-from+1 << " " << to-rig+1 <<endl;
                cout << max(find_max(A[B[lef+1]+100000].place,A[B[rig-1]+100000].place),max(lef-from+1,to-rig+1)) <<endl;
            }


        }

    }

}



