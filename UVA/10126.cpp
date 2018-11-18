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
class words
{
public:
    string str;
    int times;

    bool operator() (const words&a,const words &b) const
    {
        return a.str < b.str;
    }
};
set<words,words> my_set;
int main()
{
    int sum,need,foo,N,i = 0;
    int last;
    char trash;
    words w;
    string now = "",temp;
    while(cin >> N)
    {
        i++;
        if(i != 1)
        {
            cout <<endl;
        }
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
                //cout << "now = " << now << endl;
                if(now == "")
                {
                    //cout << 10101 << endl;
                    continue;
                }
                else if(now == "endoftext")
                {
                    //cout <<"hello world" << endl;
                    now = "";
                    /*do some thing*/
                    int c = 0;
                    for(set<words>::iterator it = my_set.begin();it != my_set.end();it++)
                    {
                        if(it->times == N)
                        {
                            c++;
                            cout << it->str <<endl;
                        }

                    }
                    if(c == 0)
                    {
                        cout << "There is no such word." <<endl;
                    }
                    my_set.clear();
                    now = "";
                    break;
                }
                //cout << 3 << endl;
                w.str = now;
                w.times = 1;
                if(!my_set.count(w))
                {
                    my_set.insert(w);
                }
                else
                {
                    w.times += my_set.find(w)->times;
                    my_set.erase(w);
                    my_set.insert(w);
                }
                now = "";

            }
        }

    }
}



