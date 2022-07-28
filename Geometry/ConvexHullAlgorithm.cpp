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
