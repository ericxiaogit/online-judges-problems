#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
vector<int> lis;
vector<int> first;

int main()
{
    int N,i,j,temp =0;
    while(cin >> N)
    {
        if(N == -1) break;
        temp++;
        first.clear();
        lis.clear();
        first.push_back(N);
        while(cin >> N)
        {
            if(N == -1) break;
            first.push_back(N);
        }
        reverse(first.begin(),first.end());
        lis.push_back(first[0]);
        for(i = 1;i < first.size();i++)
        {
            if(first[i] >= lis[lis.size() - 1])
            {
                lis.push_back(first[i]);
            }
            else
            {
                *upper_bound(lis.begin(),lis.end(),first[i]) = first[i];
            }
        }
        cout <<"Test #" << temp << ":" <<endl;
        cout << "  maximum possible interceptions: ";
        cout << lis.size() << endl << endl;
    }
}



