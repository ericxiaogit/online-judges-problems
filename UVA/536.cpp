#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
#define SIZE 10000000
string fron,mid;
int trash;
struct Node
{
    char num;
    Node *left,*right;
}*root;
void build(int le,int ri,int now,Node *p)
{

    int t;
    if(le >= ri - 1)
        return;
    //cout << le << " " << ri << " " << now << endl;
    for(t = le;t < ri;t++)
    {
        if(mid[t] == fron[now])
            break;
    }
    //cout << "t = " << t << endl;

    if(t > le && now+1 < trash)
    {
        p->left = new Node;
        p->left->num = fron[now+1];
        //cout << "add " << p ->left-> num << endl;
        //system("pause");
        p->left->left = NULL;
        p->left->right = NULL;
        build(le,t,now+1,p->left);
    }
    if(t < ri - 1 && now + t - le + 1< trash)
    {
        p->right = new Node;
        p->right->num = fron[now + t - le + 1];
        //cout <<"now = " << now<< endl;
        //cout << "ri = " << ri << endl;
        //cout << "t = " << t << endl;
        //cout <<now + ri - t  -  1<< endl;
        //cout << "add " << p-> right -> num << endl;
        //system("pause");
        p->right->left = NULL;
        p->right->right = NULL;
        build(t+1,ri,now + t - le + 1,p->right);
    }

}
void show(Node *s)
{
    if(s->left != NULL)
        show(s->left);
    if(s->right != NULL)
        show(s->right);
    cout << s->num;
}
int main()
{
    int N,i,j,k,r,l;
    cin >> N;
    for(i = 0;i < N;i++)
    {
        cin >> trash;
        cin >> fron >> mid;
        root = new Node;
        root->num = fron[0];
        //cout << "add " << root -> num << endl;
        root -> left = NULL;
        root -> right = NULL;
        build(0,trash,0,root);
        show(root);
        cout << endl;
    }
}

