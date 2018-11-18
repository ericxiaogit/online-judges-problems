#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
char A[100];
int ans[800];
using namespace std;
struct Node
{
    int num,spot;
    Node *left,*right;

};
void build(Node *s)
{
    int l,r;
    cin >> l;
    if(l != -1)
    {
        s->left = new Node;
        s->left->num = l;
        s->left->spot = s->spot - 1;
        s->left->left = NULL;
        s->left->right = NULL;
        build(s->left);
    }
    cin >> r;
    if(r != -1)
    {
        s-> right = new Node;
        s->right->num = r;
        s->right->spot = s->spot + 1;
        s->right ->left = NULL;
        s->right ->right = NULL;
        build(s->right);
    }
    return;
}
void show(Node *t)
{
    ans[t->spot] += t->num;
    if(t -> left != NULL)
    {
        //cout << "ww" <<endl;
        show(t->left);
    }
    if(t -> right != NULL)
    {
        //cout <<"ww" <<endl;
        show(t->right);
    }

}
int main()
{
    int N,i,j,k = 0,temp;
    Node *root;
    while(1)
    {
        k++;
        cin >> temp;
        if(temp == -1)
            break;
        root = new Node;
        root -> num = temp;
        root ->spot = 100;
        /*
        if(root -> left == NULL)
        {
            cout << "yeews" <<endl;
        }*/
        root->left = NULL;
        root ->right = NULL;
        build(root);
        for(i = 0;i < 800;i++)
        {
            ans[i] = 0;
        }
        show(root);
        j = 0;
        cout << "Case " << k << ":" << endl;
        for(i = 0;i < 800;i++)
        {
            if(ans[i] != 0)
            {
                cout << ans[i];
                if(ans[i+1] == 0) break;
                else
                    cout << " ";
            }
        }
        cout << endl <<endl;

    }
}



