#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstdlib>
#include<cstdio>
using namespace std;
//int A[100 + 5];
int B[10000 + 5];
int in[10000 + 5][10000 + 5];
int main()
{
    int i,T,temp,j,t,len,N;
    int high,low,mid;
    int now;
    string S,way;
    N = 0;
    //cin >> temp
    while(scanf("%d",&temp) != EOF)
    {

        //cout << "temp = " << temp << endl;
        N++;
        if(N == 1)
        {
            B[0] = temp;
            len = 1;
            in[0][0] = temp;
            continue;
        }

        else
        {
            if(temp > B[len - 1])
            {
                B[len] = temp;
                for(i = 0;i < len;i++)
                {
                    in[len][i] = in[len - 1][i];
                }
                in[len][len] = temp;
                len ++;
                continue;
            }
            high = len;
            low = 0;
            while(low < high)
            {
                mid = (high + low)/2;
                if(B[mid] >= temp)
                {

                    if(mid <= 0)
                    {
                        B[mid] = temp;
                        in[0][0] = temp;
                        break;
                    }

                    else if(B[mid - 1] < temp)
                    {

                        B[mid] = temp;
                        for(i = 0;i < mid;i++)
                        {
                            in[mid][i] = in[mid - 1][i];
                        }
                        in[mid][mid] = temp;
                        break;
                    }
                    else
                    {
                        high = mid;
                    }
                }
                else
                {
                    low = mid + 1;
                }
            }
        }
        /*
        cout << len << endl;
        cout << "hello" << endl;
        for(i = 0;i < len;i++)
        {
            //cout << "hello" << endl;
            cout << in[len - 1][i] << endl;
            //cout << "goodbye" << endl;
        }
        cout << "goodbye" << endl;
        */
    }
    cout << len << endl;
    cout << '-' << endl;
    for(i = 0;i < len;i++)
    {
        //cout << "hello" << endl;
        cout << in[len - 1][i] << endl;
        //cout << "goodbye" << endl;
    }
}
