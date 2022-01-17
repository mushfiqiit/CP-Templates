#define mx 200001
vector<ll> g[mx];
ll vi[mx], d[mx];
void bfs(ll s)
{
    queue<ll> q; q.push(s);
    vi[s]=1;
    d[s]=0;
    while(!q.empty())
    {
        ll u=q.front(); q.pop();
        for(int j=0;j<g[u].size();j++)
        {
            ll v=g[u][j];
            if(!vi[v])
            {
                q.push(v); d[v]=d[u]+1; vi[v]=1;
            }
        }
    }
}

