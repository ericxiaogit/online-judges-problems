#define _USE_MATH_DEFINES
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
# define XX 1035671
using namespace std;
struct Node
{
    long long int num;
    Node *next;
    int empt;
}*p;
Node* hashs[XX];
long long int ser(long long int a,Node *s)
{
    if(s->num == a)
        return 1;
    else if(s->empt == 0)
        return 0;
    else
        return ser(a,s->next);
}
void clean(Node* u)
{
    if(u->empt == 0)
    {
        return;
    }
    clean(u->next);
    delete u -> next;
    return;
}
int main()
{
    long long int sum,need,temp,foo,found;
    long long int last,a,i,b;
    char trash;
    string str;
    stringstream sin;
    for(i = 0;i < XX;i++)
    {
        hashs[i] = new Node;
        hashs[i]->empt = 0;
    }
    last = 0;
    while(getline(cin,str))
    {
        last++;
        if(last != 1)
        {
            for(i = 0;i < XX;i++)
            {
                clean(hashs[i]);
                hashs[i]->empt = 0;
                //delete hashs[i]->next;

            }
        }
        sin.clear();
        sin.str(str);
        a = 0;
        b = 0;
        while(sin >> foo)
        {
            a++;
            p = new Node;
            p->num = foo;
            long long int temp = foo%XX;
            if( hashs[temp]->empt == 0)
            {
                hashs[temp]->empt = 1;
                p->empt = 0;
                hashs[temp]->next = p;
            }
            else
            {
                p->next = hashs[temp]->next;
                hashs[temp]->next = p;
            }
        }
        getline(cin,str);
        sin.clear();
        sin.str(str);
        found = 0;
        while(sin >> foo)
        {
            b++;
            if(hashs[foo%XX]->empt == 0)
                continue;
            found += ser(foo,hashs[foo%XX]->next);
        }
        if(found == a && a == b)
        {
            cout << "A equals B" <<endl;
        }
        else if(found == a)
        {
            cout << "A is a proper subset of B" <<endl;
        }
        else if(found == b)
        {
            cout << "B is a proper subset of A" <<endl;
        }
        else if(found == 0)
        {
            cout << "A and B are disjoint" << endl;
        }
        else
        {
            cout << "I'm confused!" <<endl;
        }
    }
}



