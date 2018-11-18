#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    int SZ,P,i,j,ll;
    double t;
    string L,M,a,b,c,d;
    int even,odd,evans;
    int trash;
    int N;
    while(cin >> N)
    {
        for(i = 0;i <N;i++)
        {
            cin >> a >> b >> c >> d;
            evans = 0;
            even = 0;
            odd = a[1] - '0' + a[3] -'0' + b[1] - '0' + b[3] -'0' + c[1] - '0' + c[3] -'0' +  d[1] - '0' + d[3] -'0';
            for(j = 0;j < 3;j += 2)
            {
                trash = (a[j] - '0') * 2;
                //cout << "trash = " <<trash;
                while(trash > 0)
                {
                    evans += trash%10;
                    trash = trash/10;
                }
                //cout << " evans = " << evans << endl;
                trash = (b[j] - '0') * 2;
                //cout << "trash = " <<trash;
                while(trash > 0)
                {
                    evans += trash%10;
                    trash = trash/10;
                }
                 //cout << " evans = " << evans << endl;
                trash = (c[j] - '0') * 2;
                //cout << "trash = " <<trash;
                while(trash > 0)
                {
                    evans += trash%10;
                    trash = trash/10;
                }
                 //cout << " evans = " << evans << endl;
                trash = (d[j] - '0') * 2;
                //cout << "trash = " <<trash;
                while(trash > 0)
                {
                    evans += trash%10;
                    trash = trash/10;
                }
                 //cout << " evans = " << evans << endl;



            }
            ll = evans + odd;
            if(ll % 10 == 0)
                cout << "Valid" << endl;
            else
                cout << "Invalid" << endl;
        }


    }
}

