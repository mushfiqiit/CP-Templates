#define M 1000000007
typedef long long int ll;
ll fr[1001];
ll fac[100005];
ll p(ll a, ll n){ 
    ll res=1; while(n){
        if(n%2) {
res=((res%M)*(a%M))%M; n--; }
        else {
            a=((a%M)*(a%M))%M; n=n/2; } }
    return res; }

void f(ll n)
{
    fac[0]=1;
    ll res=1;
    for(ll i=1;i<=n;i++)
    {
        res=((res%M)*(i%M))%M;
        fac[i]=res;
    }
}

ll ncr(ll n, ll r)
{
    ll ans=0;
    ans=(ans+fac[n])%M;
    ll invr=p(fac[r], M-2);
    ll invnmr=p(fac[n-r], M-2);
    ans=((ans%M)*(invr%M))%M;
    ans=((ans%M)*(invnmr%M))%M;
    return ans;
}

