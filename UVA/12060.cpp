#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
int GCD(int a,int b)
{
    if(a < b)
        swap(a,b);
    if(a % b == 0)
        return b;
    else
        return GCD(b,a % b);
}
int main()
{
    int SZ,P,i,j,ll;
    double t;
    int even,odd,evans;
    int trash,temp;
    int N;
    trash = 0;
    int flag;
    int alen,blen,clen;
    int sum;
    int ans1;
    SZ = 0;
    while(cin >> N)
    {
        if(N == 0) break;
        SZ++;
        cout << "Case " << SZ << ":" <<endl;
        flag = 0;
        sum = 0;
        for(i = 0;i < N;i++)
        {
            cin >> P;
            sum+=P;
        }
        if(abs(sum)%abs(N) == 0)
        {
            if(sum < 0)
                cout << "- ";
            cout << abs(sum)/N << endl;
        }
        else if(abs(sum) < abs(N))
        {
            temp = GCD(abs(sum),abs(N));
            if(sum < 0)
                flag = 1;
            sum = abs(sum);
            sum = sum/temp;
            N = N/temp;
            alen = log10(N) + 1;
            blen = log10(sum) + 1;
            if(flag ==1)
                cout << "  ";
            for(j = 0;j < alen - blen;j++)
                cout << " ";
            cout << sum <<endl;
            if(flag == 1)
                cout << "- ";
            for(j = 0;j < alen;j++)
                cout << "-";
            cout <<endl;
            if(flag == 1)
                cout << "  ";
            cout << N <<endl;
        }
        else
        {
            ans1 = abs(sum)/N;
            temp = GCD(abs(sum),abs(N));
            if(sum < 0)
                flag = 1;
            sum = abs(sum);
            sum = sum/temp;
            N = N/temp;
            sum = sum % N;
            alen = log10(N) + 1;
            blen = log10(sum) + 1;
            clen = log10(ans1) + 1;
            if(flag ==1)
                cout << "  ";
            for(j = 0;j < clen;j++)
                cout << " ";
            for(j = 0;j < alen - blen;j++)
                cout << " ";
            cout << sum <<endl;
            if(flag == 1)
                cout << "- ";
            cout << ans1;
            for(j = 0;j < alen;j++)
                cout << "-";
            cout <<endl;
            if(flag == 1)
                cout << "  ";
            for(j = 0;j < clen;j++)
                cout << " ";
            cout << N <<endl;
        }

    }
}

