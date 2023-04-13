int vis[mx], low[mx], tin[mx], timer=0;
void dfs(ll u, ll p=-1) { vis[u]=1;
    low[u]=tin[u]=++timer;
    for(ll v:g[u]) { if(v==p) continue;
        if(!vis[v]) { dfs(v, u); low[u]-min(low[u], low[v]); }
        else { low[u]=min(low[u], tin[v]); }
        if(low[v]>tin[u]) { // isbridge(u, v);
        }
    }
}
