#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int is_prime[1300000];
int main()
{
    int N,M,K,i,j,left,right;
    is_prime[1] = 0;
    for(i = 2;i < sqrt(1300000)+1;i++)
    {
        if(is_prime[i]== 1) continue;
        for(j = i*i;j < 1300000;j+= i)
        {
            is_prime[j] = 1;
        }
    }
    /*
    for(i = 0;i < 20;i++)
    {
        cout << is_prime[i] << " ";
    }
    cout << endl*/
    while(cin >> N)
    {
        if(N == 0) break;
        left = N;
        right = N;
        while(is_prime[left] == 1)
        {
            left --;
        }
        while(is_prime[right] == 1)
        {
            right ++;
        }
        cout << right - left << endl;
    }
}
