class SegmentTree {
    #define Lc(idx)      idx * 2
    #define Rc(idx)      idx * 2 + 1
    public:
        struct node {
            vector <int> As;
            vector <Long> Ss;
            node() {
            }
        };
        vector <node> segT;
        vector <int> A;

        SegmentTree(int sz) {
            int ssz = 1;
            while (ssz < sz) ssz += ssz;
            // need to clear!
            segT.resize(2 * ssz);
            A.resize(sz + 1);
        }

        void Merge(node &L, node &R, node &F) {
            Long PS = 0;
            int CN = 0;
            for (int i = 0, j = 0; i < (int)L.As.size() || j < (int)R.As.size();) {
                if (i == (int)L.As.size()) CN = R.As[j++];
                else if (j == (int)R.As.size())  CN = L.As[i++];
                else if (L.As[i] <= R.As[j])  CN = L.As[i++];
                else  CN = R.As[j++];
                PS += CN;
                F.As.push_back(CN);
                F.Ss.push_back(PS);
            }
        }

        void MakeSegmentTree(int L, int R, int idx) {
            if (L == R) {
                segT[idx].As.push_back(A[L]);
                segT[idx].Ss.push_back(A[L]);
                return;
            }

            int M = (L + R) / 2;

            MakeSegmentTree(L, M, Lc(idx));
            MakeSegmentTree(M + 1, R, Rc(idx));
            Merge(segT[Lc(idx)], segT[Rc(idx)], segT[idx]);
        }

        Long RangeQuery(int L, int R, int idx, int l, int r, int Mx) {
            if (L > r || R < l)    return 0LL;
            if (L >= l && R <= r) {
                if (Mx >= segT[idx].As.back())  return segT[idx].Ss.back();
                int ii = lower_bound(segT[idx].As.begin(), segT[idx].As.end(), Mx + 1) -  segT[idx].As.begin();
                if (ii == 0)  return 0LL;
                return segT[idx].Ss[--ii];
            } 

            int M = (L + R) / 2;

            Long F = RangeQuery(L, M, Lc(idx), l, r, Mx) + RangeQuery(M + 1, R, Rc(idx), l, r, Mx);
            
            return F;
        }
};
