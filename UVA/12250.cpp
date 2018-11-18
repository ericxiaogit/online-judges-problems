#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
int Y[30];
int A[30];
int B[20];
int g(int a,int b)
{
    int t,c,d;
    c = a;
    d = b;
    while(1)
    {
        a = a % b;
        if(a == 0 || b == 0)
        {
            break;
        }
        b = b % a;
        if(a == 0 || b == 0)
        {
            break;
        }
    }
    t = abs(a - b);
    return (c * d) / t;
}
int f(int a,int b,int c,int d)// X%a == b  X % c == d return
{
    int i = 1;
    for(i = 1;2 > 1;i++)
    {
        if(i % a == b && i % c == d)
        {
            return i;
            break;
        }
    }

}
int main()
{
    int i,c,d,j,t,big,K;
    t = 0;
    int rolls,cig,ans;
    int a,b;
    int temp;
    string N;
    temp = 0;
    while(cin >> N)
    {
        temp ++;
        if(N == "#") break;
        cout << "Case " << temp << ": ";
        if(N == "HELLO")
            cout << "ENGLISH" <<endl;
        else if(N == "HOLA")
            cout << "SPANISH" <<endl;
        else if(N == "HALLO")
            cout << "GERMAN" <<endl;
        else if(N == "BONJOUR")
            cout << "FRENCH" <<endl;
        else if(N == "ZDRAVSTVUJTE")
            cout << "RUSSIAN" <<endl;
        else if(N == "CIAO")
            cout << "ITALIAN" <<endl;
        else
            cout << "UNKNOWN" <<endl;
    }


}

