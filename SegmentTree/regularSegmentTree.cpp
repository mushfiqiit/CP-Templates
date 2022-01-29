#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pi;
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define mx 100001
int arr[mx];
int t[mx * 3];
void init(int node, int b, int e)
{
    if (b == e) {
        t[node] = arr[b];
        return;
    }
    int l = node * 2;
    int r = node * 2 + 1;
    int md = (b + e) / 2;
    init(l, b, md);
    init(r, md + 1, e);
    t[node]=t[l]+t[r];
}
ll query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return 0; 
    if (b >= i && e <= j)
        return t[node]; 
    int l = node * 2; 
    int r = node * 2 + 1;
    int md = (b + e) / 2;
    int p1 = query(l, b, md, i, j);
    int p2 = query(r, md + 1, e, i, j);
    return p1 + p2; 
}
void update(int node, int b, int e, int i, ll newvalue)
{
    if (i > e || i < b)
        return; 
    if (b >= i && e <= i) { 
        t[node] = newvalue;
        return;
    }
    int l=node*2; 
    int r=node * 2 + 1;
    int md=(b+e)/2;
    update(l, b, md, i, newvalue);
    update(r, md + 1, e, i, newvalue);
    t[node] = t[l] + t[r];
}
