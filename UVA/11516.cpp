#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int live[100000] = {0};
int wifi[100000] = {0};
float ff(float num)
{
    return int(num*10 + 0.5)/10.0;
}
int main()
{

    int i ,N,a,b,j,k,apn;
    float up,down,mid;
    cin >> N;
    for(i = 0;i < N;i++)
    {
        cin >> a >> b;
        for(j = 0;j < b;j++)
        {
            cin >> live[j];
        }
        sort(live,live + b);
        up = live[b - 1];
        down = 0.0;
        mid = (up + down)/2;
        //cout << "mid = " << mid << endl;
        while(1)
        {
            if(ff(up) == ff(down))break;
            //cout << mid << endl;
            apn = 0;
            for(j = 0;j < b;j++)
            {
                wifi[j] = 0;
            }
            //cout << "hello1" << endl;
            for(j = 0;j < b;j++)
            {
                //cout << "hello2" << endl;
                if(wifi[j] == 0)
                {
                    //cout << "hello3" << endl;
                    apn++;
                    for(k = j;live[k] <= live[j] + mid*2 && k < b;k++)
                    {
                        //cout <<"k = " << k << endl;
                        //cout <<"live[k] = " << live[k] << endl;
                        wifi[k] = 1;
                    }
                    //cout << "hello4" << endl;
                }

            }
            //cout << apn << endl;
            //system("pause");
            if(apn <= a)
            {
                up = mid;
                mid = (up + down)/2;
            }
            else
            {
                down = mid;
                mid = (up + down)/2;
            }
        }
        printf("%.1f\n",mid);

    }

}
