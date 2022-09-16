#define mx 1501
ll const mod=1e9+9, mod2=972663749;
ll const p=97266353, p2=97336357;
string s; string gb; 
ll pp[mx], h[mx], pr[mx], h2[mx], pp2[mx];
void init()
{
    ll n=s.length();
    pp[0]=1;
    pp2[0]=1;
    for(int i=0;i<n;i++)
    {
        pp[i+1]=(pp[i]*p)%mod;
        pp2[i+1]=(pp2[i]*p2)%mod2;
        //cout << pp[i+1] << "\n";
    }
    h[0]=0;
    h2[0]=0;
    for(int i=0;i<n;i++)
    {
        h[i+1]=(h[i]+(s[i]-'a'+1)*pp[i+1])%mod;
        h2[i+1]=(h2[i]+(s[i]-'a'+1)*pp2[i+1])%mod2;
    }

    
    //forn(i, n) cout << pp[i] << " "; cout << "\n";
}

pi subhash(ll l, ll r)
{
    ll n=s.length();
    pi res;
    res.first=(h[r]-h[l-1]+mod)%mod;
    res.first=(res.first*pp[n-l])%mod;
    res.second=(h2[r]-h2[l-1]+mod2)%mod2;
    res.second=(res.second*pp2[n-l])%mod2;
    return res;
}
