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
    int N;
    string str;
    char p;
    int flag;
    flag = 0;
    char now;
    int first = 0;
    while(cin >> str)
    {
        if(str == "*") break;
        if(first == 0)
        {
            first = 1;
            now = str[0];
            flag = 0;
            if(now <= 'Z')
                now = 'a' + (now - 'A');

        }
        p = cin.peek();
        if(p == '\n')
        {
            //cout << "hello" << endl;
            if(flag == 0)
            {
                cout << "Y" << endl;
            }
            else
            {
                cout << "N" << endl;
            }
            first = 0;
        }
        else
        {
            if(str[0] != now && str[0] != now + 'A' - 'a')
                flag = 1;
        }
    }
}

