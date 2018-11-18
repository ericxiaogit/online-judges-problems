#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
    int N;
    int temp,sum = 0;
    int i ,j;
    for(i = 0;i <200;i++)
    {
        for(j = 0;j < 200;j++)
        {
            if(i*i+j*j == i*i*j*j-14*i*j+49)
                cout << i << " " << j << endl;
        }
    }

}
