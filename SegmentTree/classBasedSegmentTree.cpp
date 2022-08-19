class SegmentTree {
#define Lc( idx )      idx * 2
#define Rc( idx )      idx * 2 + 1
public:
    struct node {
        ll value;
        int lazy;
        node () {
            this->value = LONG_LONG_MIN;
            this->lazy = 0;
        }
    };
    vector < node > segT;
    vector < ll > A;

    SegmentTree( int sz ) {
        // need to clear!
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

    node RangeQuery( int L, int R, int idx, int l, int r ) {
        node F;

        if ( L > r || R < l )    return F;
        if ( L >= l && R <= r )  return segT[ idx ];

        int M = ( L + R ) / 2;

        F = Merge( RangeQuery( L, M, Lc( idx ), l, r ), RangeQuery( M + 1, R, Rc( idx ), l, r ) );
        segT[ idx ] = Merge( segT[ Lc( idx ) ], segT[ Rc( idx ) ] ); //is it useful?

        return F;
    }
};
