class SegmentTree {
      #define Lc( idx )      idx * 2
      #define Rc( idx )      idx * 2 + 1
      public:
            struct node {
                  ll value;
                  int lazy;
                  node () {
                        this->value = 2000000001;
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
                  F.value = min(L.value, R.value);
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
                  //cout << L << " " << R << " " << idx << " " << carry << " " << l << " " << r << "\n";
                  if ( L > r || R < l )    return F;
                  if ( L >= l && R <= r ) {
                    F=segT[idx];
                    F.value+=carry;
                    //cout << "value " << F.value << "\n";
                    return F;
                  }
 
                  int M = ( L + R ) / 2;
 
                  F = Merge( RangeQuery( L, M, Lc( idx ), l, r, carry+segT[idx].lazy),
                  RangeQuery( M + 1, R, Rc( idx ), l, r, carry+segT[idx].lazy ) );
                  //cout << "combined " << L << " " << R << " " << F.value << "\n";
                  return F;
            }
 
            void RangeUpdate(int L, int R, int idx, int l, int r, ll x) {
                if(L>r || R<l) return;
                if(L>=l && R<=r)
                {
                    segT[idx].value+=x;
                    segT[idx].lazy+=x;
                    //cout << "update " << idx << " " << L << " " << R << " " << x << "\n";
                    return;
                }
                int M = ( L + R ) / 2;
                RangeUpdate(L, M, idx*2, l, r, x);
                RangeUpdate(M+1, R, idx*2+1, l, r, x);
                segT[idx].value=min(segT[idx*2].value, segT[idx*2+1].value)+segT[idx].lazy;
            }
};
