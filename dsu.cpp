int dsu[200001], sz[200001];

void init( int N)
{
    for(int i = 1;i<=N;i++)
    {
    dsu[ i ] = i ;
    sz[ i ] = 1;
    }
}


int root (int i)
{
    while(dsu[ i ] != i)
    {
        dsu[ i ] = dsu[ dsu[ i ] ] ;
        i = dsu[ i ];
    }
return i;
}


void un(int A, int B)
{
    int root_A = root(A);
    int root_B = root(B);
    if(sz[root_A] < sz[root_B ])
    {
dsu[ root_A ] = dsu[root_B];
sz[root_B] += sz[root_A];
}
    else
    {
dsu[ root_B ] = dsu[root_A];
sz[root_A] += sz[root_B];
}

}

bool fin(int A,int B)
{
    if( root(A)==root(B) )
     return true;
    else
    return false;
}

