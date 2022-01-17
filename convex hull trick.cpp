struct line{
ll m, c;
ll value(ll x) { return m*x+c; }
};

vector<line> hull;
ll ptr=0;
bool isBad(line p, line q, line r)
{
   return ((r.c-p.c)*(1.0))/((p.m-r.m)*(1.0))<=((q.c-p.c)*(1.0)/(p.m-q.m)*(1.0));
}

void addLine(line l)
{
   while(!hull.empty() && hull.back().m==l.m)
   {
       if(l.c<hull.back().c) hull.pop_back();
       else return;
   }

   while(hull.size()>=2 && isBad(hull[hull.size()-2], hull.back(), l))
   {
       hull.pop_back();
   }
   hull.push_back(l);
}

ll query(ll x)
{
   while(ptr+1<hull.size() && hull[ptr].value(x)>hull[ptr+1].value(x))
     {
         //cout << hull[ptr].value(x) << " " << hull[ptr+1].value(x) << "\n";
         //cout << ptr << "\n";
         ptr++;
     }
   return hull[ptr].value(x);
}

