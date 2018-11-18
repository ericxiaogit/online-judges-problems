#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    int i,T;
    string N;
    long long int k;
    while(cin >>T)
    {
        for(i = 0;i < T;i++)
        {
            cin >> N;
            if(N == "0")
                cout << 1 << endl;
            else if(N == "1")
                cout << 66 <<endl;
            else if(N[N.length()-1] == '2' || N[N.length()-1] == '7')
                cout << 56 << endl;
            else if(N[N.length()-1] == '3' || N[N.length()-1] == '8')
                cout << 96 << endl;
            else if(N[N.length()-1] == '4' || N[N.length()-1] == '9')
                cout << 36 << endl;
            else if(N[N.length()-1] == '5' || N[N.length()-1] == '0')
                cout << 76 << endl;
            else
                cout << 16 << endl;
        }



    }
}
