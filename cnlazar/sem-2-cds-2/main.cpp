#include <iostream>
#include<fstream>
using namespace std;
int n,m,a[10][10],i,j,k;
void matrice_adiacenta(int &n, int &m, int a[10][10]) 
{   
   ifstream f("date.in");
   f>>n>>m;
   k=m;
   for (int k=1; k<=m; k++)
     {
         f>>i>>j;
         a[i][j]=1;
         a[j][i]=1;
     }
}

void matrice_adiacenta_t(int &n, int &m, int a[10][10]) 
{
    do {cout<<"nr de noduri: "; cin>>n;} while (n<2 || n>10);
    do {cout<<"nr de muchii: "; cin>>m;} while (m<2 || m>n*(n-1)/2); 
    for (int k=1; k<=m; k++)
    {
    cout<<"extremitatile: "; cin>>i>>j;
        a[i][j]=1;
        a[j][i]=1;
    }
}
void afisare ()
{
for (i=1; i<=n; i++)
{
         for (j=1; j<=n; j++)
                  cout<<a[i][j]<<" ";
         cout<<"\n";
}
}
//adiacenta
void noduri_adiacente(int x)
{
    for (int j=1; j<=n; j++)
        if(a[x][j]==1)
            cout<<j<<" ";
}
void liste_adiacenta ()
{
    for(i=1; i<=n; i++)
    {
        cout<<i<<": ";
        noduri_adiacente(i);
        cout<<endl;
    }
}
int grad (int x)
{
    int s=0;
    for (j=1;j<=n;j++)
       s=s+a[x][j];
    return s;
}
//grade
void grade(int n, int a[10][10])
{
    for(i=1;i<=n;i++)
      cout<<i<<": "<<grad(i)<<endl;
}

void vecini(int x)
{  for(int j=1; j<=n; j++)
    {if (a[x][j]==1)
     cout<<j<<" ";
    if (a[i][x]==1)
    cout<<i<<" ";
    }
    
}
void afisare_vecini ()
{
    for(int i=1; i<=n; i++)
    {
        cout<<i<<": "; 
        vecini(i);
        cout<<endl;
    }
}


void izolate(int n, int a[10][10])
{
    int i,j,z,k=0;
    for(i=1; i<=n; i++)
    {
        z=0;
      for(j=1; j<=n; j++)
        if(a[i][j]==0)
          z=z+1;
        if(z==n)
          k=1;
    }
    if(k=1)
    cout<<"are noduri izolate";
    else
        cout<<" nu are noduri izolate"; cout<<endl;
}
 
void terminale(int n, int a[10][10])
{
    int i,j,z,k=0;
    for(i=1; i<=n; i++)
     {
         z=0;
         for(j=1; j<=n; j++)
          if(a[i][j]==1)
           z=z+1;
          if(z==n-1)
            k=1;
     }
    if(k=1)
    cout<<"are noduri terminale";
    else
        cout<<" nu are noduri terminale";
    cout<<endl;
}
void grad_max(int n, int a[10][10])
{
    cout<<"cel mai mare grad: ";
    int i,j, k=0,m;
    for(i=1; i<=n; i++)
    {
     m=0;
     for(j=1; j<=n; j++)
        {
         m=m+a[i][j];
        }
        if(m==(n-1))
        {
         k=1;
         cout<<m<<", al nodului "<<i;
        }
    }
    if(k==0)
        cout<<"nu exista";
    cout<<endl;
}

void graf_complet(int n, int m, int a[10][10])
{
   int i,j;
   for (i=1; i<=n; i++)
       { for (j=i+1; j<=n; j++)
        if (a[i][j]==0)
         cout<<i<<" si "<<j<<endl;
       }
}
int main()
{
     int p;
     cout<<"de unde citesti graful? 1 din fisier, orice alta valoare de la tastatura  p=";cin>>p;
         if(p==1)
            matrice_adiacenta(n,m,a);
         else
            matrice_adiacenta_t(n,m,a);
    
    afisare();
    int x;
    do {cout<<"gradul nodului= "; cin>>x; } while (x<1 || x>n); 
    cout<<grad (x);       cout<<endl;
    
    int y;
    do {cout<<"vecinii nodului= "; cin>>y; } while (y<1 || y>n); 
    vecini(y);       cout<<endl;
    
    cout<<"lista de adiacenta: "<<endl;
    liste_adiacenta();    cout<<endl;
    
    cout<<"gradul nodurilor: "<<endl;
    grade(n,a);      cout<<endl;
    
    cout<<"vecinii nodului: "<<endl;
    afisare_vecini();
    
    
    
    izolate(n,a);
    terminale(n,a);
    grad_max(n,a);
   
    cout<<"trebuie adaugate muschii intre nodurile: "<<endl;
    graf_complet(n,m,a);

   
    return 0;
}
