#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <set>
#include <string>
using namespace std;
int ans = 0,N;
char a,b;
set<string> my_set;
int main()
{
    int sum,need,foo;
    int last;
    char trash;
    string now = "",temp;
    while(cin.get(trash))
    {
        if(trash >= 'a' && trash <= 'z')
        {
            now.push_back(trash);
        }
        else if(trash >= 'A' && trash <= 'Z')
        {
            now.push_back('a'+trash-'A');
        }
        else
        {
            if(now == "")
            {
                continue;
            }
            my_set.insert(now);
            now = "";
        }
    }
    for(set<string>::iterator it = my_set.begin();it != my_set.end();it++)
    {
        cout << *it << endl;
    }
}



