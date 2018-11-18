#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
double X[10];
double Y[10];
int how[10];
int ANS[10];
int used[10];
int N;
double ans;
void DFS(int now,int last,double length)
{
    //cout << now << " " << last << " " << length;
    //system("pause");
        for(int i = 0;i < N;i++)
        {
            if(used[i] == 0)
            {
                used[i] = 1;
                how[now + 1] = i;
                DFS(now + 1,i,length + sqrt((X[i] - X[last])* (X[i] - X[last]) + (Y[i] - Y[last])* (Y[i] - Y[last])));
                used[i] = 0;
            }
        }
    if(now >= N - 1)
    {
        //cout << "hello" << endl;
        if(length < ans)
        {
            ans = length;
            for(int i = 0;i < N;i++)
            {
                ANS[i] = how[i];
            }
        }
        return;
    }


}
int main()
{
    int i,a,b,c,d,temp,j,big,K;
    K = 0;
    while(cin >> N)
    {
        K++;
        if(N == 0) break;
        ans = 1000000000;
        for(i = 0;i < N;i++)
        {
            used[i] = 0;
            cin >> X[i] >> Y[i];
        }
        for(i = 0;i < N;i++)
        {
            used[i] = 1;
            how[0] = i;
            DFS(0,i,0);
            used[i] = 0;
        }
        cout << "**********************************************************" << endl;
        printf("Network #%d\n",K);
        double R;
        for(i = 1;i < N;i++)
        {
            R = sqrt((X[ANS[i]] - X[ANS[i - 1]])*(X[ANS[i]] - X[ANS[i - 1]]) + (Y[ANS[i]] - Y[ANS[i - 1]])*(Y[ANS[i]] - Y[ANS[i - 1]]));
            //cout << X[ANS[i - 1]]<< " " << Y[ANS[i - 1]] << " " << X[ANS[i]] << " " << Y[ANS[i]] << R << endl;
            printf("Cable requirement to connect (%.0lf,%.0lf) to (%.0lf,%.0lf) is %.2lf feet.\n",X[ANS[i - 1]],Y[ANS[i - 1]],X[ANS[i]],Y[ANS[i]],R + 16);
        }
        printf("Number of feet of cable required is %.2lf.\n",ans + 16 * (N - 1));
    }


}

