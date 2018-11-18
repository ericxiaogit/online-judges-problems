#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
int A;
int main()
{
    long long int T,N,D,i,j,ans,temp,start,now,second;
    char trash,s;
    while(cin >> T)
    {
        for(i = 0;i < T;i++)
        {
            ans = 0;
            temp = 0;
            start = 0;
            cin >> N >> D;
            j = 0;
            while(1)
            {
                trash = cin.get();
                cin >>s;
                trash = cin.get();
                cin >> second;
                j++;
                if(s == 'B')
                {
                    ans = max(ans,second - start);
                    start = second;
                    if(j >= N) break;
                    continue;
                }
                if(j >= N) break;
                while(1)
                {
                    trash = cin.get();
                    cin >>s;
                    trash = cin.get();
                    cin >> now;
                    j++;
                    ans = max(ans,now - start);
                    if(j >= N) break;
                    start = second;
                    second = now;
                    if(s == 'B') break;
                }
                if(j >= N)
                {
                    if(s == 'B')
                        start = now;
                    else
                        start = second;
                    //cout <<"second = " << second << endl;
                    break;

                }
                start = now;
            }
            //cout <<"start = " << start << endl;
            ans = max(ans,D - start);

            cout << "Case "<< i + 1 << ": " << ans << endl;
        }
    }

}

