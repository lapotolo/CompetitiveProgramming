#include <iostream>
#include <string>
#include <limits>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cstring>
#include <climits>
using namespace std;
    // #define PR(x) cout << #x " = " << x << "\n";

int64_t arr[100006];
int64_t t[262200];
int64_t lazy[262200];

void build(int64_t node, int64_t a, int64_t b) // node=pos, a=low, b=high
{
    if(a>b) return;
    if (a==b)
    {
        t[node]=arr[a];
        return;
    }
    
    build(node*2, a, (a+b)/2);
    build(node*2+1,(a+b)/2+1,b);
    
    t[node]=t[node*2]+t[node*2+1];
}

int64_t query(int64_t node, int64_t a, int64_t b, int64_t i, int64_t j)
{
    if(a>b||a>j||b<i) return 0;
    if (lazy[node] !=0 )
    {
        t[node]+=lazy[node]*(b-a+1);
        if (a!=b)
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    
    if (a>=i && b<=j) return t[node];
    
    int64_t q1=query(node*2, a, (a+b)/2, i, j);
    int64_t q2=query(node*2+1, (a+b)/2+1, b, i, j);
    
    return q1+q2;
}

void update(int64_t node, int64_t a, int64_t b, int64_t i, int64_t j, int64_t inc)
{
    if(a>b) return;
    if (lazy[node]!=0)
    {
        t[node]+=lazy[node]*(b-a+1);
        if (a!=b)
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(a>b||a>j||b<i) return;
    
    if (a>=i && b<=j)
    {
        t[node]+=inc*(b-a+1);
        if (a!=b)
        {
            lazy[node*2]+=inc;
            lazy[node*2+1]+=inc;
        }
        return;
    }
    
    update(node*2, a, (a+b)/2, i, j, inc);
    update(node*2+1, (a+b)/2+1, b,i, j, inc);
    t[node] = t[node*2] + t[node*2+1];
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    int64_t t,n,qu,q,p,a; cin>>t;
    int64_t inc;
    while(t--)
    {
        cin>>n>>qu;
        build(1,0,n-1);
        for (int i = 0; i < 262200; ++i) lazy[i]=0;
        while(qu--)
        {
            cin>>a;
            if (a==0)
            {
                cin>>p>>q>>inc;
                update(1,0,n-1,p-1,q-1,inc);
            }
            else
            {
                cin>>p>>q;
                cout<<query(1,0,n-1,p-1,q-1)<<endl;
            }
        }
        
    }
    return 0;
} 

