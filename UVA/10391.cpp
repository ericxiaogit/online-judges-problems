#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
string A[120000+5];
int temp;
bool IsBigger(string a,string b)
{
    int i;
    for(i = 0;i < min(a.length(),b.length());i++)
    {
        if(a[i] > b[i])
            return true;
        else if(a[i] < b[i])
            return false;
    }
    if(a.length() >= b.length())
        return true;
    else
        return false;
}
bool fin(string str)
{
    int where;
    int low,high,mid;
    where = temp;
    low = 0;
    high = where;
    while(high != low )
    {
        mid = (low + high)/2;
        if(A[mid] == str)
            return true;
        else if(IsBigger(A[mid],str))
            high = mid;
        else
            low = mid + 1;
    }
    return false;
}
int main()
{
    //string a;
    int num,i,how,nows,j,a,big,print,b,k;
    temp = -1;
    string N,M;
    string fron,bac;
    string trash;
    while(cin >> N)
    {

        temp++;
        A[temp] = N;
    }
    //cout << "ess " << fin("ess") << endl;
    for(i = 0;i <= temp;i++)//string
    {
        for(j = 1;j < A[i] .length();j++)//cut place
        {
            fron = "";
            bac = "";
            for(k = 0;k < A[i] .length();k++)
            {
                trash = " ";
                trash[0] = A[i][k];
                if(k < j)
                {
                    fron = fron + trash;
                }
                else
                    bac = bac + trash;
            }
            if(fin(fron) == true && fin(bac) == true)
            {
                cout << A[i] << " " << j << endl;
                break;
            }

        }
    }

}

