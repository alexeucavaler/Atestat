#include<iostream> 
#include<fstream>
#include<iomanip>
using namespace std;
ifstream f("date.in"); 
int n,m,i,j,a[10][100],k,x;
void construire_matrice(int &n, int &m, int a[10][100]) 
{
    f>>n>>m;
    for(int k=1;k<=m;k++) 
    {
     f>>i>>j; 
     a[i][k]= 1;
     a[j][k]=-1;
    } 
}
void afisare() 
{
     for(int i=1;i<=n;i++) 
    {for(int j=1;j<=m;j++)
      cout<<setw(2)<<a[i][j]<<" ";//am cautat pe net comanda stew sa arate frumos
      cout<<endl; 
    }
}
void grad_extern(int n, int a[10][100])
{
    int g=0;
    for(int x=1; x<=n; x++)
    {
      g=0;
    for(int j=1; j<=n; j++)
      if(a[x][j]==1)
       g++;
    cout<<"gradul extern al nodului "<<x<<" este: "<<g<<endl;
    }
}

void grad_intern(int n, int a[10][100])
{
    int g=0;
    for(int x=1; x<=n; x++)
    { 
     g=0;
    for(int i=1; i<=n; i++)
      if(a[i][x]==1)
       g++;
    cout<<"gradul intern al nodului "<<x<<" este: "<<g<<endl;
    }
}

void succesori(int n, int a[10][100])
{
    int k;
    for(int x=1; x<=n; x++)
    { 
    k=0;
        cout<<"succesorii nodului "<<x<<" sunt: ";
    for(int j=1; j<=n; j++)
      if(a[x][j]==1)
      {
        cout<<j<<", ";
       k++;
      }
    if(k==0)
        cout<<"nu are succesori"<<endl;
        else
    cout<<endl;
    }
}
void predecesori(int n, int a[10][100])
{
    int k;
    for(int x=1; x<=n; x++)
    { k=0;
        cout<<"predecesorii nodului "<<x<<" sunt: ";
    for(int i=1; i<=n; i++)
      if(a[i][x]==1)
      {
        cout<<i<<", ";
       k++;
      }
    if(k==0)
        cout<<"nu are predecesori"<<endl;
        else
    cout<<endl;
    }
}


int main() 
{
    construire_matrice(n,m,a); cout<<endl;
    afisare();                 cout<<endl;
    grad_extern(n,a);          cout<<endl;
    grad_intern(n,a);          cout<<endl;
    succesori(n,a);            cout<<endl;
    predecesori(n,a);          cout<<endl;

        f.close();
        return 0; 
} 

