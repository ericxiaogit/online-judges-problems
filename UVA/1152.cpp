#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdio>
long long int A[4000];
long long int B[4000];
long long int C[4000];
long long int D[4000];
long long int first[16000000 +80];
long long int second[16000000 + 80];
using namespace std;
int main()
{
    string s;
    long long int i,T,j,k;
    long long int N;
    long long int ans,now;
    int a,b;
    while(cin >> N)
    {
        for(i = 0;i < N;i++)
        {
            cin >> T;
            ans = 0;
            for(j = 0;j < T;j++)
            {
                cin >> A[j] >> B[j] >> C[j] >> D[j];
            }
            now = 0;
            for(j = 0;j < T;j++)
            {
                for(k = 0;k < T;k++)
                {
                     first[now] = A[j] + B[k];
                     second[now] = C[j] + D[k];
                    now ++;
                }
            }
            sort(second,second+now);
            reverse(second,second+now);
            sort(first,first+now);
            /*
            for(j = 0;j < now;j++)
            {
                cout << first[j] << " ";
            }
            cout << endl;
            for(j = 0;j < now;j++)
            {
                cout << second[j] << " ";
            }
            cout << endl;*/
            j = 0;
            k = 0;
            while(j < now && k < now)
            {
                if(first[j] + second[k] == 0)
                {
                    a = 0;
                    b = 0;
                    while(first[j] + second[k] == 0)
                    {
                        j++;
                        a++;
                    }
                    while(first[j - 1] + second[k] == 0)
                    {
                        k++;
                        b++;
                    }
                    ans += a*b;
                }
                else if(first[j] + second[k] < 0)
                {
                    j++;
                }
                else
                    k++;
            }
            if(i != 0)
                cout << endl;
            cout << ans << endl;
        }



    }
}
