#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pi;
#define mp make_pair
#define pb push_back
#define F first
#define S second
struct info {
    i64 prop, sum;
} t[mx * 3];
void update(int node, int b, int e, int i, int j, i64 x)
{
    if (i > e || j < b)
        return;
    if (b >= i && e <= j) 
    {
        t[node].sum += ((e - b + 1) * x); 
        t[node].prop += x; 
        return;
    }
    int l = node * 2;
    int r = (node * 2) + 1;
    int md = (b + e) / 2;
    update(l, b, md, i, j, x);
    update(r, md + 1, e, i, j, x);
    t[node].sum = t[l].sum + t[r].sum + (e - b + 1) * t[node].prop;
}

int query(int node, int b, int e, int i, int j, int carry = 0)
{
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j)
        return t[node].sum + carry * (e - b + 1); 

    int l = node << 1;
    int r = (node << 1) + 1;
    int md = (b + e) >> 1;

    int p1 = query(l, b, md, i, j, carry + t[node].prop); 
    int p2 = query(r, md + 1, e, i, j, carry + t[node].prop);

    return p1 + p2;
}
