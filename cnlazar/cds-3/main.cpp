#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
struct muchie {
int x,y; 
} v[45];
int n,m,a[20][20],b[20][20];


void citire_af()
{ ifstream f("date.in"); f>>n;
  int i,j;
  while(f>>i>>j)
     a[i][j]=1;
}
void citire_bf(int &n, int &m, muchie v[20])
{     int i,j;
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
void citire_cf()
{ ifstream f("date.in");
 int i,j;
 m=0;
f>>n; while(f>>i>>j)
       {  m++;
          b[i][m]=1; 
          b[j][m]=-1;
       }
}

void citire_a()
{  int i,j,k;
   cout<<"nr de noduri: ";cin>>n;
   cout<<"nr de arce: ";cin>>m;
   for(k=1;k<=m;k++)
    {
     cin>>i>>j;
     a[i][j]=1;
    }
}
void citire_b() 
{   int i,j,k;
    cout<<"nr de noduri: "; cin>>n;
    cout<<"nr de arce: "; cin>>m;
     for(k=1;k<=m;k++)
      cin>>v[k].x>>v[k].y;
}
void citire_c()
{    int i,j,k;
     cout<<"nr de noduri: ";cin>>n;
     cout<<"nr de arce: ";cin>>m;cout<<"extremitatile arcelor: "<<endl;
    for(k=1;k<=m;k++)
      {
        cin>>i>>j; 
        b[i][k]=1; 
        b[j][k]=-1;}
}

void afis_vector()
{
 for(int k=1;k<=m;k++)
    cout<<v[k].x<<" "<<v[k].y<<endl;
}
void afis_incidenta()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        cout<<setw(2)<<b[i][j]<<" ";
        cout<<"\n";
    }
}
void afis_adiacenta()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        cout<<setw(2)<<a[i][j]<<" ";
        cout<<endl;
    }
}

int grad_intern_a(int nod)
{ int nr=0;
    for(int j=1;j<=n;j++)
      nr=nr+a[j][nod];
      return nr;
}
int grad_extern_a(int nod)
{ int nr=0;
    for(int j=1;j<=n;j++)
      nr=nr+a[nod][j];
      return nr;
}

int grad_intern_b(int nod)
{ int g=0;
   for(int k=1;k<=m;k++)
   if(v[k].y==nod) 
   g++;
    return g; 
    
}
int grad_extern_b(int nod)
{  int g=0;
    for(int k=1;k<=m;k++)
    if(v[k].x==nod)
    g++;
    return g; 

}

int grad_intern_c(int nod) 
{   int g=0;
   for(int j=1;j<=m;j++)
    if(b[nod][j]==-1)
        g++;
    return g;
}

int grad_extern_c(int nod)
{   int g=0;
    for(int j=1;j<=m;j++)
    if(b[nod][j]==1)
        g++;
     return g;
}

void pred_a(int k)
{
    int ok=0;
    for(int j=1;j<=n;j++)
        if(a[j][k]==1)
        {
            cout<<j<<" ";
            ok=1;
        }
    if(ok==0)
        cout<<"nu are predcesori";
}

void predecesori_a(int k)
{

    cout<<"Nodul "<<k<<": ";
        pred_a(k);
        cout<<endl;
}

void suc_a(int k)
{
    int ok=0;
    for(int j=1;j<=n;j++)
        if(a[k][j]==1)
        {
            cout<<j<<" ";
            ok=1;
        }
    if(ok==0)
        cout<<"Nu are succesori";
}

void succesori_a(int k)
{

    cout<<"Nodul "<<k<<": ";
        suc_a(k);
        cout<<endl;
}


void pred_b(int k)
{      int ok=0;
for(int i=1;i<=m;i++)
   if(v[i].y==k)
    {cout<<v[i].x<<" ";
      ok++;}

    if(ok==0)
        cout<<"Nu are predesori";
}

void predecesori_b(int k)
{   cout<<"Nodul "<<k<<": ";
        pred_b(k);
        cout<<endl;
}

void suc_b(int k)
{
       int ok=0;
for(int i=1;i<=m;i++)
   if(v[i].x==k)
    {cout<<v[i].y<<" ";
      ok++;}

    if(ok==0)
        cout<<"Nu are succesori";
}

void succesori_b(int k)
{
    cout<<"Nodul "<<k<<": ";
        suc_b(k);

}

void pred_c(int k)
{
    int ok=0;
    for(int i=1;i<=m;i++)
       if(b[k][i]==-1)
        for(int j=1;j<=m;j++)
            if(b[j][i]==1)
                {cout<<j<<" ";
                 ok=1;}
    if(ok==0)
        cout<<"nu are predecesori";
}
void predecesori_c(int k)
{cout<<"nodul "<<k<<": ";
        pred_c(k);
        cout<<endl;

}

void suc_c(int k)
{
   int ok=0;
    for(int i=1;i<=m;i++)
       if(b[k][i]==1)
        for(int j=1;j<=m;j++)
            if(b[j][i]==-1)
                {cout<<j<<" ";
                 ok=1;}
    if(ok==0)
        cout<<"nu are succesori";
}

void succesori_c(int k)
{
     cout<<"Nodul "<<k<<": ";
        suc_c(k);
        cout<<endl;

}

int main()
{ 
    int o,u,k,p;
    cout<<"1. de la tastatura "<<endl;
    cout<<"2. din fisier "<<endl;
    cout<<endl<<"de unde citesti? alege optiunea: ";cin>>u;
switch(u)
   { case 1: 
    cout<<"1. construire matricea de adiacenta "<<endl;
    cout<<"2. construire vectorul de arce "<<endl;
    cout<<"3. construire matricea de incidenta "<<endl;
    cout<<"cum doresti sa reprezinti graful? alege optiunea: ";cin>>o;
    cout<<endl;
switch(o) {
    case 1: citire_a();
    do{
    cout<<endl;    
    cout<<"1. gradul extern al unui nod "<<endl;
    cout<<"2. gradul intern al unui nod "<<endl;
    cout<<"3. succesorii unui nod "<<endl;
    cout<<"4. predecesorii unui nod "<<endl;
    cout<<"5. gradul extern si intern al fiecarui nod ";cout<<endl;
    cout<<" alege optiunea: ";cin>>p;
    cout<<endl;
switch(p) {
    case 0: return 0;
    case 1: cout<<"nod= ";cin>>k; cout<<grad_extern_a(k)<<endl;break;
    case 2: cout<<"nod= ";cin>>k; cout<<grad_intern_a(k)<<endl;break;
    case 3: cout<<"nod= ";cin>>k; succesori_a(k);break;
    case 4: cout<<"nod= ";cin>>k; predecesori_a(k);cout<<endl;cout<<endl;break;}}while (p!=6);break;
case 2: citire_b();
    do{
    cout<<endl; 
    cout<<"1. gradul extern al unui nod"<<endl;
    cout<<"2. gradul intern al unui nod "<<endl;
    cout<<"3. succesorii unui nod"<<endl;
    cout<<"4. predecesorii unui nod"<<endl;
    cout<<"5. gradul intern si extern pentru fiecare";
    cout<<endl<<" alege optiunea: ";cin>>p;
    cout<<endl;
switch(p) {
    case 0: return 0;
    case 1: cout<<"nod= ";cin>>k; cout<<grad_extern_b(k)<<endl;break;
    case 2: cout<<"nod= ";cin>>k; cout<<grad_intern_b(k)<<endl;break;
    case 3: cout<<"nod= ";cin>>k; succesori_b(k);break;
    case 4: cout<<"nod= ";cin>>k; predecesori_b(k);break;
    case 5: cout<<"Gradele externe"<<endl;
     for(int k=1;k<=n;k++) cout<<"Nod "<<k<<": "<<grad_extern_b(k)<<"   ";cout<<endl;
     cout<<endl<<"Gradele interne"<<endl;
     for(int k=1;k<=n;k++) cout<<"Nod "<<k<<": "<<grad_intern_b(k)<<"   ";cout<<endl;cout<<endl;break;}}while (p!=6);break;
case 3:  citire_c();
    do{
    cout<<endl; 
    cout<<"1. gradul extern al unui nod"<<endl;
    cout<<"2. gradul intern al unui nod "<<endl;
    cout<<"3. succesorii unui nod"<<endl;
    cout<<"4. predecesorii unui nod"<<endl;
    cout<<"5. gradul intern si extern pentru fiecare"<<endl;
    cout<<endl<<" alege optiunea: ";cin>>p;
    cout<<endl;
switch(p) {
    case 0: return 0;
    case 1: cout<<"nod= ";cin>>k;cout<<grad_extern_c(k)<<endl;break;
    case 2: cout<<"nod= ";cin>>k;cout<<grad_intern_c(k)<<endl;break;
    case 3: cout<<"nod= ";cin>>k;succesori_c(k);break;
    case 4: cout<<"nod= ";cin>>k;predecesori_c(k);break;
    case 5: cout<<"gradele externe: "<<endl;
     for(int k=1;k<=n;k++) cout<<"Nod"<<k<<": "<<grad_extern_c(k)<<"   ";cout<<endl;
     cout<<endl<<"gradele interne: "<<endl;
     for(int k=1;k<=n;k++) cout<<"Nod"<<k<<": "<<grad_intern_c(k)<<"   ";cout<<endl;cout<<endl;break;}}while (p!=6);break;}
case 2: cout<<endl;
    cout<<"1. construire matricea de adiacenta"<<endl;
    cout<<"2. construire vectorul de arce"<<endl;
    cout<<"3. construire matricea de incidenta"<<endl;
    cout<<endl<<"cum doresti sa reprezinti graful? alege optiunea: ";cin>>o;
    cout<<endl;
switch(o) {
case 1: citire_af();afis_adiacenta();
    do{
    cout<<endl;     
    cout<<"1. gradul extern al unui nod"<<endl;
    cout<<"2. gradul intern al unui nod "<<endl;
    cout<<"3. succesorii unui nod"<<endl;
    cout<<"4. predecesorii unui nod"<<endl;
    cout<<"5. gradul intern si extern pentru fiecare"<<endl;cout<<endl;
    cout<<" alege optiunea: ";cin>>p;
    cout<<endl;
switch(p) {
    case 0: return 0;
    case 1: cout<<"nod=";cin>>k;cout<<grad_extern_a(k)<<endl;break;
    case 2: cout<<"nod=";cin>>k;cout<<grad_intern_a(k)<<endl;break;
    case 3: cout<<"nod=";cin>>k;succesori_a(k);break;
    case 4: cout<<"nod=";cin>>k;predecesori_a(k);break;
    case 5: cout<<"gradele externe: "<<endl;
     for(int k=1;k<=n;k++) cout<<"Nod"<<k<<": "<<grad_extern_a(k)<<"   ";cout<<endl;
     cout<<endl<<"gradele interne: "<<endl;
     for(int k=1;k<=n;k++) cout<<"Nod"<<k<<": "<<grad_intern_a(k)<<"   ";cout<<endl;break; }}while (p!=6);break; 
case 2: citire_bf(n,m,v); cout<<m<<endl;afis_vector();cout<<endl;
    do{
    cout<<endl;
    cout<<"1. gradul extern al unui nod"<<endl;
    cout<<"2. gradul intern al unui nod "<<endl;
    cout<<"3. succesorii unui nod"<<endl;
    cout<<"4. predecesorii unui nod"<<endl;
    cout<<endl<<" alege optiunea: ";cin>>p;
    cout<<endl;
switch(p) {
    case 0: return 0;
    case 1: cout<<"nod=";cin>>k;cout<<grad_extern_b(k)<<endl;break;
    case 2: cout<<"nod=";cin>>k;cout<<grad_intern_b(k)<<endl;break;
    case 3: cout<<"nod=";cin>>k;succesori_b(k);break;
    case 4: cout<<"nod=";cin>>k;predecesori_b(k);break;
    case 5: cout<<"gradele externe: "<<endl;
     for(int k=1;k<=n;k++) cout<<"Nod"<<k<<": "<<grad_extern_b(k);cout<<endl;
     cout<<endl<<"gradele interne: "<<endl;
     for(int k=1;k<=n;k++) cout<<"Nod"<<k<<": "<<grad_intern_b(k);cout<<endl;cout<<endl;break;}}while (p!=6);break; 
case 3: citire_cf();afis_incidenta();
    do{
    cout<<endl;
    cout<<"1. gradul extern al unui nod"<<endl;
    cout<<"2. gradul intern al unui nod "<<endl;
    cout<<"3. succesorii unui nod"<<endl;
    cout<<"4. predecesorii unui nod"<<endl;
    cout<<"5. gradul extern si intern al fiecarui nod"<<endl;cout<<endl;
    cout<<" alege optiunea: ";cin>>p;
    cout<<endl;
switch(p) {
    case 0: return 0;
    case 1: cout<<"nod=";cin>>k;cout<<grad_extern_c(k)<<endl;break;
    case 2: cout<<"nod=";cin>>k;cout<<grad_intern_c(k)<<endl;break;
    case 3: cout<<"nod=";cin>>k;succesori_c(k);break;
    case 4: cout<<"nod=";cin>>k;predecesori_c(k);break;
    case 5: cout<<"gradele externe: "<<endl;cout<<endl;
     for(int k=1;k<=n;k++) cout<<"Nod"<<k<<": "<<grad_extern_c(k)<<"   ";cout<<endl;
     cout<<endl<<"gradele interne: "<<endl;
     for(int k=1;k<=n;k++) cout<<"Nod"<<k<<": "<<grad_intern_c(k)<<"   ";cout<<endl;break;}}while (p!=6);break;
} ;break;}

return 0; 
    
}

