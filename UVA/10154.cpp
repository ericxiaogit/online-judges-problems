#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
int ans = 0,N;
char a,b;
struct Node
{
    int num;
    Node *left;
    Node *right;
    int all;
}*root;
void build(Node *p)
{
    int l = 0,r = 0,pp = 0,fo;
    int temp = 0;
    fo = 1;
    while(cin >> a)
    {
        if(a == '(' || a == ')') break;
        if(a == '-')
            fo = -1;
        else
            l = l*10 + (a- '0');
    }

    if(l != 0)
    {
        //cout << "l = " << l << endl;
        l*=fo;
        temp = 1;
        p->left = new Node;
        p->left->num = l;
        p->left->all = p->all + l;
        p->left->left = NULL;
        p->left->right = NULL;
        build(p->left);
        cin >> a;
    }
    cin >> a;
    fo = 1;
    while(cin >> a)
    {
        //cout << "ra = " << a << endl;
        if(a == '(' || a == ')') break;
        if(a == '-')
            fo = -1;
        else
            r = r*10 + (a- '0');
    }
    //cout << "r = " << r << endl;
    if(r != 0)
    {
        //cout << "r = " << r << endl;
        r *= fo;
        temp = 1;
        p->right = new Node;
        p->right->num = r;
        p->right->all = p->all + r;
        p->right->left = NULL;
        p->right->right = NULL;
        build(p->right);
        cin >>a;
    }
    //cout << p->num << " " <<p->all << " " << temp << endl;
    if(temp == 0 && p->all == N)
    {
        ans = 1;
    }
    return;
}
void show(Node *t)
{
    cout << t->num <<endl;
    if(t->left != NULL)
        show(t->left);
    if(t->right != NULL)
        show(t->right);
}
int main()
{
    int sum,need,temp,foo;
    int last;
    char trash;

    while(cin >> N)
    {
        ans = 0;
        cin >> trash;
        need = 0;
        last = 1;
        foo = 1;
        while(cin >>trash)
        {
            if(trash == '(' || trash == ')') break;
            if(trash == '-')
                foo = -1;
            else
                need = need*10 + (trash-'0');
        }
        need*= foo;
        //cout << "need = " << need << endl;
        if(trash == ')')
        {
            cout << "no" << endl;
            continue;
        }
        root = new Node;
        root->left = NULL;
        root->right = NULL;
        root->num = need;
        root->all = need;
        build(root);
        cin >>trash;
        //show(root);
        if(ans == 0)
            cout << "no" << endl;
        else
            cout << "yes" <<endl;
    }
}



