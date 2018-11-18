#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
#define SIZE 10000000
string fron,mid;
int trash;
int A[10000];
int B[10000];
int mans,sum,n,ans;
struct Node
{
    int num;
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
        if(A[t] == B[now])
            break;
    }
    //cout << "t = " << t << endl;

    if(t > le)
    {
        p->left = new Node;
        p->left->num = B[now-ri+t];
        //cout << "add " << p ->left-> num << endl;
        //system("pause");
        p->left->left = NULL;
        p->left->right = NULL;
        build(le,t,now-ri+t,p->left);
    }
    if(t < ri - 1)
    {
        p->right = new Node;
        p->right->num = B[now - 1];
        //cout <<"now = " << now<< endl;
        //cout << "ri = " << ri << endl;
        //cout << "t = " << t << endl;
        //cout <<now + ri - t  -  1<< endl;
        //cout << "add " << p-> right -> num << endl;
        //system("pause");
        p->right->left = NULL;
        p->right->right = NULL;
        build(t+1,ri,now - 1,p->right);
    }

}
void show(Node *s)
{
    //cout << s->num;
    sum += s->num;
    if(s->left != NULL)
    {
        show(s->left);
    }
    if(s->right != NULL)
    {
        show(s->right);
    }
    if(s->left == NULL &&s->right == NULL)
    {
        if(sum < mans)
        {
            mans = sum;
            ans = s->num;
        }
        else if(sum == mans && s->num < ans)
        {
            ans = s->num;
        }

    }
    sum -= s->num;
}
int main()
{
    int N,i,j,k,r,l,temp;
    char a;
    while(cin >> A[0])
    {
        temp = 1;
        a = cin.peek();
        i = 1;
        while(a == ' ')
        {
            cin >> A[i];
            i++;
            a = cin.peek();
        }
        for(j = 0;j < i;j++)
        {
            cin >> B[j];
        }
        root = new Node;
        root->num = B[i - 1];
        root->left = NULL;
        root->right = NULL;
        build(0,i,i -1,root);
        mans = 1000000000;
        sum = 0;
        n = 100000;
        ans = -1;
        show(root);
        cout << ans << endl;
    }

}

