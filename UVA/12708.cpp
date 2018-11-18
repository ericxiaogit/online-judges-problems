#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long int N,M,i,j,k;
    while(cin >> N)
    {
        for(i = 0;i <N;i++)
        {
            cin >> k;
            if(k == 1)
                cout << 1 << endl;
            else
                cout << (k/2) <<endl;
        }
    }

}
