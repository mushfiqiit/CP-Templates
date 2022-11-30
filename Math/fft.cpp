using cd = complex<double>;
const double PI = acosl(-1);
const ll N=1e5+1;
int rev[N]; cd w[N]; static cd f[N];

void prepare(int &n){
int sz = __builtin_ctz(n);
for(int i=1; i<n; i++) rev[i] = (rev[i>>1] >>1)|((i&1)<<(sz-1));
w[0] = 0, w[1] = 1, sz = 1; while(1 << sz < n){
cd w_n = cd(cos(2*PI / (1<<(sz+1))),sin(2*PI / (1 << (sz+1))));
for(int i=1<<(sz-1);i<1<<(sz);i++){
    w[i<<1] = w[i], w[i<<1 | 1] = w[i] * w_n;
} sz++; } }

void fft(cd *a, int n){ for(int i=1; i<n-1; i++){
if(i < rev[i]) swap(a[i], a[rev[i]]); }
for(int h=1; h<n; h<<=1){ for(int s=0; s<n; s+=h<<1){ for(int i=0; i<h; i++){
cd &u = a[s+i], &v = a[s+i+h], t = v*w[h+i];
v = u-t, u = u+t; } } } }

vector<ll>multiply(vector<ll>a, vector<ll>b){ 
int n = a.size(), m = b.size(), sz = 1; 
if(!n or !m) return {};
while(sz < n+m-1) sz <<= 1;
    prepare(sz);
for(int i=0; i<sz; i++) f[i] = cd(i < n ? a[i]:0,i<m?b[i]:0);
fft(f, sz);
for(int i=0; i<=(sz>>1); i++){
int j = (sz - i) & (sz - 1);
        cd x = (f[i]*f[i] - conj(f[j]*f[j])) *cd(0, -0.25);
        f[j] = x, f[i] = conj(x);
    }
fft(f, sz);
vector<ll>c(n+m-1);
for(int i=0; i<n+m-1; i++) c[i] =round(f[i].real()/sz);
return c; }
