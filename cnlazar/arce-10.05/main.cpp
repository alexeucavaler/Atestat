#include <iostream>
#include<fstream>
using namespace std;
int i,j,n, m, a[20], x;
struct muchie
{
    int x,y;
} v[45];

void matrice(int &n, int &m, muchie v[20])
{
    int i,j;
    ifstream f("date.in");
    f>>n;
    f>>m;
    for(int k=1; k<=m; k++)
    {
    f>>v[k].x;
    f>>v[k].y;
    }
    f.close();

}

int grad_ext(int t)
{
   int g=0;
    for(int k=1; k<=m; k++)
    if(v[k].x==t)
      g++;
      return g;
}

void grad_extern()
{
    for(int i=1; i<=n; i++)
    cout<<"gradul extern al nodului "<<i<<" este: "<<grad_ext(i)<<endl;

}

int grad_int(int t)
{
   int g=0;
    for(int k=1; k<=m; k++)
    if(v[k].y==t)
      g++;
      return g;
}

void grad_intern()
{
    for(int i=1; i<=n; i++)
    cout<<"gradul extern al nodului "<<i<<" este: "<<grad_int(i)<<endl;

}
void succesori(int t)
{
    int ok=0;
    for(int k=1; k<=n; k++)
      if(v[k].x==t)
      {
          cout<<v[k].y<<' ';
          ok++;
      }
     if(ok==0)
     cout<<"nu are succesori";
}
void lista_succesori()
{
    for(int t=1;t<=n;t++)
    {
        cout<<"succesori nodului "<<t<<"sunt: ";
        succesori(t);
    }
}

void predecesori(int t)
{
    int ok=0;
    for(int k=1; k<=n; k++)
      if(v[k].y==t)
      {
          cout<<v[k].x<<' ';
          ok++;
      }
     if(ok==0)
     cout<<"nu are predecesori";
}
void lista_predecesori()
{
    for(int t=1;t<=n;t++)
    {
        cout<<"predecesorii nodului "<<t<<"sunt: ";
        predecesori(t);
    }
}


int main()
{
    matrice(n,m,v);cout<<endl;
    grad_extern();cout<<endl;
    grad_intern();cout<<endl;
    lista_succesori();cout<<endl;
    lista_predecesori();cout<<endl;
    return 0;
}

