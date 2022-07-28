struct point{
int x, y;
};

struct vect{
int a, b;
};

point pinitial;

int crossProduct(vect v1, vect v2)
{
    return ((v1.a*v2.b)-(v1.b*v2.a));
}

int direction(point pi, point pj, point pk)
{
    vect v1, v2;
    v1.a=pk.x-pi.x;
    v1.b=pk.y-pi.y;

    v2.a=pj.x-pi.x;
    v2.b=pj.y-pi.x;
    //cout << crossProduct(v1, v2) << endl;
    return crossProduct(v1, v2);
}

bool cmpr(point p1, point p2)
{
    if(direction(pinitial, p2, p1)>0)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int main()
{
    int minix=1000000000;
    int miniy=1000000000;
    int mini=-1;
    for(int i=0;i<n;i++)
    {
        if(p[i].y<miniy || (p[i].y==miniy && p[i].x<minix))
        {
            mini=i;
            minix=p[i].x;
            miniy=p[i].y;
        }
    }

    point temp;
    temp=p[0];
    p[0]=p[mini];
    p[mini]=temp;

    pinitial=p[0];
    sort(p+1, p+n, cmpr);


    S.push_back(p[0]);
    S.push_back(p[1]);
    S.push_back(p[2]);

    for(int i=3;i<n;i++)
    {
        point top=S[S.size()-1];
        point ntotop=S[S.size()-2];
        int d=direction(top, ntotop, p[i]);
        //cout << "Top " << top.x << " " << top.y << endl;
        //cout << "NTOTOP " << ntotop.x << " " << ntotop.y << endl;
        //cout << "New " << p[i].x << " " << p[i].y << endl;
        //cout << d << endl;
        if(d<0)
        {
            S.pop_back();
        }
        S.push_back(p[i]);
    }
}
