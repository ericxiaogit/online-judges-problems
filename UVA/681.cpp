#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <string>
using namespace std;
#define SIZE 10000000
struct point
{
    int x,y;
    double cos;
};
point A[600];
point hull[600];
int start;
int dot(point a,point b)
{
    return a.x*b.x + a.y*b.y;
}
//point vec[600];
bool rot(point a,point b)
{
    if(a.x * b.y - a.y * b.x > 0)
        return 1;
    else
        return 0;
}
double cs(point a)
{
    point w;
    w.x = a.x - A[0].x;
    w.y = a.y - A[0].y;
    return (w.x)/sqrt((double)(w.x*w.x + w.y*w.y));
}
bool cmp(const point &q,const point &p)
{
    if(q.cos != p.cos)
        return q.cos > p.cos;
    else
        return q.x < p.x;
}
int main()
{
    //string a;
    int N,K,i,j,trash,temp,minx,miny,much,tf,trash1,trash2;
    point r,s;
    cin >> N;
    for(i = 0;i < N;i++)
    {
        cin >> K;
        cin >> A[0].x >> A[0].y;
        minx = A[0].x;
        miny = A[0].y;
        start = 0;
        for(j = 1;j < K - 1;j++)
        {
            cin >> A[j].x >> A[j].y;
            if(A[j].y < miny)
            {
                start = j;
                miny = A[j].y;
                minx = A[j].x;
            }
            else if(A[j].y == miny && A[j].x < minx)
            {
                start = j;
                miny = A[j].y;
                minx = A[j].x;
            }
            //vec[j].x = A[j].x - A[j - 1].x;
            //vec[j].y = A[j].y - A[j - 1].y;
        }
        cin >> trash1;
        cin >> trash2;
        if(i < N - 1)
            cin >> trash;
        swap(A[start].x,A[0].x);
        swap(A[start].y,A[0].y);
        for(j = 1;j < K-1;j++)
        {
            A[j].cos = cs(A[j]);
        }
        sort(A+1,A+K - 1,cmp);
        //cout << A[0].x << " " << A[0].y << endl;
        /*
        for(j = 1;j < K-1;j++)
        {
            cout <<A[j].x << " " << A[j].y << " " << A[j].cos<<endl;
        }*/

        //A[K].x= A[1].x;
        //A[K].y = A[1].y;
        //vec[K].x = A[K].x - A[K - 1].x;
        //vec[K].y = A[K].y - A[K - 1].y;
        //K++;
        /*
        for(j = 0;j < K - 1;j++)
        {
            cout <<A[j].x << " " << A[j].y <<endl;
        }*/
        much = 2;
        hull[0].x = A[0].x;
        hull[0].y = A[0].y;
        //cout << A[start].x << " " <<A[start].y <<endl;
        hull[1].x = A[1].x;
        hull[1].y = A[1].y;
        //cout << A[start + 1].x << " " <<A[start+1].y <<endl;
        for(j = 2;j < K - 1;j++)
        {

            //temp = (start+j) % (K - 1);
            s.x = A[j].x - hull[much - 1].x;
            s.y = A[j].y - hull[much-1].y;
            r.x = hull[much - 1].x - hull[much - 2].x;
            r.y = hull[much - 1].y - hull[much-2].y;
            //cout << A[temp].x << " " <<A[temp].y<< endl;
           // cout << r.x <<  " " << r.y << "      " << s.x << " " << s.y << endl;
            while(rot(r,s) == 0)
            {
                much--;
                if(much == 1)
                {
                    //hull[much].x = A[temp].x;
                    //hull[much].y = A[temp].y;
                    //much++;
                    break;
                }
                else
                {
                    s.x = A[j].x - hull[much - 1].x;
                    s.y = A[j].y - hull[much-1].y;
                    r.x = hull[much - 1].x - hull[much - 2].x;
                    r.y = hull[much - 1].y - hull[much-2].y;
                }
              //  cout << r.x <<  " " << r.y << "      " << s.x << " " << s.y << endl;
            }
            hull[much].x = A[j].x;
            hull[much].y = A[j].y;
            much ++;
            //cout << "much = " << much << endl;

        }
        s.x = A[start].x - hull[much - 1].x;
        s.y = A[start].y - hull[much-1].y;
        r.x = hull[much - 1].x - hull[much - 2].x;
        r.y = hull[much - 1].y - hull[much-2].y;
        //cout << A[temp].x << " " <<A[temp].y<< endl;
        //cout << r.x <<  " " << r.y << "      " << s.x << " " << s.y << endl;
        while(rot(r,s) == 0)
        {
            much--;
            if(much == 1)
            {
                    //hull[much].x = A[temp].x;
                    //hull[much].y = A[temp].y;
                    //much++;
                break;
            }
            else
            {
                s.x = A[0].x - hull[much - 1].x;
                s.y = A[0].y - hull[much-1].y;
                r.x = hull[much - 1].x - hull[much - 2].x;
                r.y = hull[much - 1].y - hull[much-2].y;
            }


        }
        hull[much].x = A[0].x;
        hull[much].y = A[0].y;
        much ++;
        if(i == 0)
            cout << N <<endl;
        cout << much << endl;
        for(j = 0;j < much;j++)
        {
            cout << hull[j].x << " " << hull[j].y << endl;
        }
        if(i != N-1)
            cout << -1 << endl;

        /*
        for(j = 1;j < much;j++)
        {
            if(hull[j].x != hull[j - 1].x || hull[j].y != hull[j - 1].y)
            {
                //cout << hull[j].x << " " << hull[j].y << endl;
                continue;
            }
            else if(hull[j].x != A[start].x || hull[j].y != A[start].y)
            {
                t = 1;
            }

        }
        if(t == 0)
            much--;
        cout << much <<endl;
        cout << hull[0].x << " " << hull[0].y << endl;
        for(j = 1;j < much - 1 ;j++)
        {
            if(hull[j].x != hull[j - 1].x || hull[j].y != hull[j - 1].y)
            {
                cout << hull[j].x << " " << hull[j].y << endl;
            }
            else
            {
                much++;
            }
        }
        cout << hull[0].x << " " << hull[0].y << endl;*/
    }
}

