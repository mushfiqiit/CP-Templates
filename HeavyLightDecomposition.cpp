#define mx 10001

vector<pi> g[mx];
ll parent[mx], depth[mx], heavy[mx], head[mx], pos[mx], val[mx];
ll cur_pos=0, N;

class SegmentTree {
      #define Lc( idx )      idx * 2
      #define Rc( idx )      idx * 2 + 1
      public:
            struct node {
                  ll value;
                  int lazy;
                  node () {
                        this->value = 0;
                        this->lazy = 0;
                  }
            };
            vector < node > segT;
            vector < ll > A;
 
            SegmentTree( int sz ) {
 
                  segT.resize(4 * sz + 10);
                  A.resize(sz + 1);
            }
 
            node Merge(node L, node R) {
                  node F;
                  F.value = max(L.value, R.value);
                  return F;
            }
 
            void MakeSegmentTree( int L, int R, int idx ) {
                  if ( L == R ) {
                        segT[ idx ].value = A[L];
                        return;
                  }
 
                  int M = ( L + R ) / 2;
 
                  MakeSegmentTree( L, M, Lc( idx ) );
                  MakeSegmentTree( M + 1, R, Rc( idx ) );
                  segT[ idx ] = Merge( segT[ Lc( idx ) ], segT[ Rc( idx ) ] );
            }
 
            node RangeQuery( int L, int R, int idx, int l, int r, ll carry) {
                  node F;
                  //cout << L << " " << R << " " << segT[idx].value << "\n";
                  if ( L > r || R < l )    return F;
                  if ( L >= l && R <= r ) {
                    F=segT[idx];
                    F.value+=carry;
                    return F;
                  }
 
                  int M = ( L + R ) / 2;
 
                  F = Merge( RangeQuery( L, M, Lc( idx ), l, r, carry+segT[idx].lazy),
                  RangeQuery( M + 1, R, Rc( idx ), l, r, carry+segT[idx].lazy ) );
                  
                  return F;
            }
 
            void RangeUpdate(int L, int R, int idx, int l, int r, ll x) {
                if(L>r || R<l) return;
                if(L>=l && R<=r)
                {
                    segT[idx].value+=x;
                    segT[idx].lazy+=x;
                    return;
                }
                int M = ( L + R ) / 2;
                RangeUpdate(L, M, idx*2, l, r, x);
                RangeUpdate(M+1, R, idx*2+1, l, r, x);
                segT[idx].value=max(segT[idx*2].value, segT[idx*2+1].value)+segT[idx].lazy;
            }

            void Update(int L, int R, int idx, int pos, ll x) {
                if(L>pos || R<pos) return;
                if(L>=pos && R<=pos)
                {
                    segT[idx].value=x;
                    return;
                }
                int M = ( L + R ) / 2;
                Update(L, M, idx*2, pos, x);
                Update(M+1, R, idx*2+1, pos, x);
                segT[idx].value=max(segT[idx*2].value, segT[idx*2+1].value);
            }
};

SegmentTree st(mx);


ll dfs(ll u)
{
    //cout << u << "\n";
    ll size=1;
    ll max_v_size=0;
    for(int j=0;j<g[u].size();j++)
    {
        ll w=g[u][j].first;
        ll v=g[u][j].second;
        if(v!=parent[u])
        {
            parent[v]=u, depth[v]=depth[u]+1;
            val[v]=w;
            ll v_size=dfs(v);
            size+=v_size;
            //cout << v << " " << v_size << "\n";
            if(v_size>max_v_size) {
            max_v_size=v_size, heavy[u]=v;
            //cout << heavy[u] << "\n";
            }
        }
    }
    return size;
}

void decompose(ll u, ll h)
{
    //cout << u << "\n";
    //cout << u << " " << h << " " << heavy[u] << "\n";
    head[u]=h; pos[u]=cur_pos++;
    if(heavy[u]!=-1) decompose(heavy[u], h);

    for(int j=0;j<g[u].size();j++)
    {
        ll v=g[u][j].second;
        ll w=g[u][j].first;
        if(v!=parent[u] && v!=heavy[u])
            decompose(v, v);
    }

}

void init()
{
    cur_pos=1;
    val[1]=0;
    dfs(1);
    //cout << "dfs done\n";
    
    decompose(1,1);
    forn(i, N) {  
        //cout << i << " " << pos[i] << " " << val[i] << "\n";
        st.A[pos[i]]=val[i];
    }
    st.MakeSegmentTree(1, N, 1);
}

ll query(ll a, ll b)
{
    ll res=0;
    for(;head[a]!=head[b];b=parent[head[b]])
    {
        if(depth[head[a]]>depth[head[b]]) swap(a, b);
        ll cur_heavy_path_max=st.RangeQuery(1, N, 1, pos[head[b]], pos[b], 0).value;
        res=max(res, cur_heavy_path_max);
        //cout << a << " " << b << " " << head[a] << " " << head[b] << " " << res << "\n";
    }
    
    if (depth[a] > depth[b])
        swap(a, b);
    ll last_heavy_path_max = st.RangeQuery(1, N, 1, pos[a]+1, pos[b], 0).value;
    //cout << a << " " << b << " " << last_heavy_path_max << "\n";
    res = max(res, last_heavy_path_max);
    return res;
}
