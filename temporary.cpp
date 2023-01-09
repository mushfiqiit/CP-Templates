#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pi;
#define mp make_pair
#define pb push_back
#define forn(i, n) for (int i = 1; i <= int(n); i++)
#define sz(v) (int)v.size()

class SegmentTree {
#define Lc( idx )      idx * 2
#define Rc( idx )      idx * 2 + 1
public:
    struct node {
        ll val[26];
        char pref, suff; ll presz, sufsz;
        ll tot;
        node () {
            memset(val, 0, sizeof val); tot=0;
        }
    };
    vector < node > segT;
    string S;

    SegmentTree( int sz ) {
        segT.resize(4 * sz + 10); S.resize(sz);
    }

    node Merge(node L, node R) {
        node F;
        for(int i=0;i<26;i++) F.val[i]=max(L.val[i], R.val[i]);
        if(L.suff==R.pref)
        {
            F.val[R.pref-'A']=max(F.val[R.pref-'A'], R.presz+L.sufsz);
        }
        F.pref=L.pref; F.presz=L.presz; F.suff=R.suff; F.sufsz=R.sufsz;
        if(L.presz==L.tot && L.pref==R.pref) F.presz=L.tot+R.presz;
        if(R.sufsz==R.tot && L.suff==R.suff) F.sufsz=R.tot+L.sufsz; 
        F.tot=L.tot+R.tot;
        return F;
    }

    void MakeSegmentTree( int L, int R, int idx ) {
        if ( L == R ) {
            segT[idx].val[S[L-1]-'A']=1;
            segT[idx].pref=S[L-1]; segT[idx].presz=1;
            segT[idx].suff=S[L-1]; segT[idx].sufsz=1;
            segT[idx].tot=1;
            return;
        }

        int M = ( L + R ) / 2;

        MakeSegmentTree( L, M, Lc( idx ) );
        MakeSegmentTree( M + 1, R, Rc( idx ) );
        segT[ idx ] = Merge( segT[ Lc( idx ) ], segT[ Rc( idx ) ] );
    }

    node RangeQuery( int L, int R, int idx, int ind) {
        node F;
        F=segT[1];
        return F;
    }

    void Update(int L, int R, int idx, int ind) {
        if(L==R) {
            S[ind-1]='#';
            segT[idx].pref='#'; segT[idx].presz=0; segT[idx].suff='#'; segT[idx].sufsz=0;
            segT[idx].tot=0;
            memset(segT[idx].val, 0, sizeof segT[idx].val);
            return;
        }
        int M = ( L + R ) / 2;

        Update( L, M, Lc( idx ), ind);
        Update( M + 1, R, Rc( idx ), ind);
        segT[ idx ] = Merge( segT[ Lc( idx ) ], segT[ Rc( idx ) ] );
    }
};


void solve()
{
    string St; cin >> St; 
    ll n=St.length(); SegmentTree st(n+2); st.S=St;
    st.MakeSegmentTree(1, n, 1);
    ll Q; cin >> Q;
    while(Q--)
    {
        ll c, ind; cin >> c >> ind;
        if(c==1) cout << st.RangeQuery(1,n,1,ind).val[St[ind]-'A'] << "\n";
        else { st.Update(1,n,1,ind+1); }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
#else
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int T; T=1; 
    cin >> T;
    forn(i, T)
    {
        cout << "Case " << i << ": \n";
        solve();
    }
}

