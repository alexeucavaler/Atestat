#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
using namespace std;
int lista[21],n;
void creare_t()
{
cout<<"Introduceti numarul de elemente din lista: ";
cin>>n;
while (n<1 || n>21)
cin>>n;
for(int i=1; i<=n; i++)
{
cout<<"lista["<<i<<"]=";
cin>>lista[i];
}
}
void creare_f()
{
ifstream f("date.in");
f>>n;
for(int i=1; i<=n; i++)
{
f>>lista[i];
}
}
int e_vida()
{
if (n==0) return 1;
else return 0;
}
int e_plina()
{
if (n==20) return 1;
else return 0;
}
void afisare()
{
if (!e_vida())
{
cout<<" Elementele listei sunt: ";
for(int i=1; i<=n; i++)
cout<<lista[i]<<" ";
}
else cout<<"Lista este vida!";
}
void inserare()
{
int e,poz,i;
cout<<"Introduceti elementul de inserat: ";
cin>>e;
if (n==0)
{
lista[1]=e;
n=1;
}
else
{
cout<<"Introduceti pozitia unde doriti sa inserati elementul: ";
cin>>poz;
while (!(poz>=1&&poz<=n+1))
{
cout<<"Pozitia introdusa nu este valida!!";
cout<<endl<<"Introduceti pozitia valida:";
cin>>poz;
}
for(i=n; i>=poz; i--)
lista[i+1]=lista[i];
lista[poz]=e;
n++;
}
}
void stergere()
{
int e,poz,i;
cout<<"Introduceti pozitia elementului de sters: ";
cin>>poz;
while (!(poz>=1&& poz<=n))
{
cout<<"Pozitia introdusa nu exista in lista!!!";
cout<<endl<<" Introduceti o pozitie valida!";
cin>>poz;
}
for(i=poz; i<n; i++)
lista[i]=lista[i+1];
n--;
}
void meniu()
{
cout<<endl<<endl;
cout<<"==========================================================
==================================";
cout<<endl<<endl<<"Operatii cu liste! "<<endl<<endl;
cout<<endl<<endl;
cout<<"==========================================================
==================================";
cout<<endl<<endl;
if (!e_vida())
{
afisare();
cout<<endl<<endl;
}
cout<<"1.Creare lista de la tastatura.";
cout<<endl<<"2.Creare lista din fisier.";
cout<<endl<<"3.Afisare elementelor din lista.";
cout<<endl<<"4.Inserarea unui element in lista.";
cout<<endl<<"5.Stergerea unui element din lista.";
}
int st[21];
int vf;
int stiva_vida()
{
if (vf==0)
{
cout<<"Stiva este vida!!!"<<endl<<endl;;
return 1;
}
else return 0;
}
int stiva_plina()
{
if (vf==20)
{
cout<<"Stiva este plina!!!";
return 1;
}
else return 0;
}
void push(int x)
{
vf++;
st[vf]=x;
}
void pop()
{
vf--;
}
void afisare_stiva()
{
int i;
cout<<endl<<" Elementele stivei in ordinea introducerii in stiva sunt: ";
for(i=1; i<=vf; i++)
cout<<st[i]<<" ";
cout<<endl<<" Elementele stivei in ordinea iesirii din stiva sunt: ";
for(i=vf; i>=1; i--)
cout<<st[i]<<" ";
}
void meniu_stiva()
{
cout<<"==========================================================
==================================";
cout<<endl<<endl<<"Operatii cu stiva! "<<endl<<endl;
cout<<endl<<endl;
cout<<"==========================================================
==================================";
cout<<endl<<endl;
if (!stiva_vida())
{
afisare_stiva();
cout<<endl<<endl;
}
cout<<"1.Creare stiva de la tastatura.";
cout<<endl<<"2.Creare stiva din fisier.";
cout<<endl<<"3.Afisare elementelor din stiva.";
cout<<endl<<"4.Introducerea unui element in stiva.";
cout<<endl<<"5.Stergerea unui element din stiva.";
}
void creare_stiva_fisier()
{
int n,i,x;
ifstream fs("stiva.in");
fs>>n;
for(i=1; i<=n; i++)
{
fs>>x;
push(x);
}
}
void stiva()
{
int n,i,x,ops,ok=0;
meniu_stiva();
cout<<endl<<"Ce doriti sa faceti?";
cin>>ops;
while (ops>=1 && ops<=5)
{
switch(ops)
{
case 1:
if (ok==0) if (vf==0)
{
ok=1;
cout<<"introduceti valoarea elementului: ";
cin>>x;
push(x);
}
else cout<<"Stiva este creata. Apelati optiunile 3,4,5 ";
else cout<<"Stiva este creata. Apelati optiunile 3,4,5 ";
break;
case 2:
if (ok==0)
{
creare_stiva_fisier();
ok=1;
}
else cout<<"Stiva este creata. Apelati optiunile 3,4,5 ";
break;
case 3:
if (!stiva_vida()) afisare_stiva();
else cout<<"Stiva nu are elemente.E vida.";
break;
case 4:
if (!stiva_plina())
{
cout<<"introduceti valoarea elementului: ";
cin>>x;
push(x);
}
else cout<<"Stiva este plina.";
break;
case 5:
if (!stiva_vida()) pop();
else cout<<" Stiva este goala.";
break;
}
getch();
system("cls");
meniu_stiva();
cout<<endl<<"Ce doriti sa faceti?";
cin>>ops;
}
}
void meniu_la_meniu()
{
cout<<"==========================================================
=============================================";
cout<<endl<<endl<<" Operatii cu liste, stive, cozi!
"<<endl<<endl;
cout<<endl;
cout<<"==========================================================
=============================================";
cout<<endl<<endl;
cout<<"1.LISTA.";
cout<<endl<<"2.STIVA.";
cout<<endl<<"3.COADA.";
cout<<endl<<endl;
cout<<" Introduceti numarul corespunzator cerintei: ";
}
const int DIM = 21;
int Q[DIM], stc, dr;
int coada_vida()
{
if (stc>dr) {cout<<"Coada este vida!"<<endl<<endl;;return 1;}
else return 0;
}
int coada_plina()
{
if (dr==20) {cout<<"Coada este plina!";return 1;}
else return 0;
}
void pushc( int x)
{
dr++;
Q[dr]=x;
}
void popc()
{
for(int i=stc;i<dr;i++)
Q[i]=Q[i+1];
dr--;
}
void creare_coada_fisier(){
int x;
ifstream fc("coada.in");
fc>>n;
for(int i=1;i<=n;i++)
{
fc>>x;
pushc(x);
}
}
void afisare_coada()
{
if (!coada_vida())
{
cout<<endl<<" Elementele din coada sunt: ";
for(int i=stc;i<=dr;i++)
cout<<Q[i]<<" ";
}
else cout<<"Coada este vida!!!";
}
void meniu_coada()
{cout<<"=========================================================
===================================";
cout<<endl<<endl<<"Operatii cu coada! "<<endl<<endl;
cout<<endl<<endl;
cout<<"==========================================================
==================================";
cout<<endl<<endl;
cout<<endl<<endl;
if (!coada_vida())
{
afisare_coada();
cout<<endl<<endl;
}
cout<<"1.Creare coada de la tastatura.";
cout<<endl<<"2.Creare coada din fisier.";
cout<<endl<<"3.Afisare elementelor din coada.";
cout<<endl<<"4.Introducerea unui element in coada.";
cout<<endl<<"5.Stergerea unui element din coada.";
}
void coada()
{int n,i,x,ops,ok=0;
stc=1;dr=0;
meniu_coada();
cout<<endl<<"Ce doriti sa faceti?";
cin>>ops;
while (ops>=1 && ops<=5)
{
switch(ops)
{
case 1:
if (ok==0) if (stc>dr)
{
ok=1;
cout<<"introduceti valoarea elementului: ";
cin>>x;
pushc(x);
}
else cout<<"Coada este creata. Apelati optiunile 3,4,5 ";
else cout<<"Coada este creata. Apelati optiunile 3,4,5 ";
break;
case 2:
if (ok==0)
{
creare_coada_fisier();
ok=1;
}
else cout<<"Coada este creata. Apelati optiunile 3,4,5 ";
break;
case 3:
if (!coada_vida()) afisare_coada();
else cout<<"Coada nu are elemente.E vida.";
break;
case 4:
if (!coada_plina())
{
cout<<"introduceti valoarea elementului: ";
cin>>x;
pushc(x);
}
else cout<<"Coada este plina.";
break;
case 5:
if (!coada_vida()) popc();
else cout<<" Coada este goala.";
break;
}
getch();
system("cls");
meniu_coada();
cout<<endl<<"Ce doriti sa faceti?";
cin>>ops;
}
}
int main()///////////////////////////////////////////////////////////////////////////
{
int op,okt=0,okf=0,ok=0,po;
meniu_la_meniu();
cin>>po;
while (po>=1&&po<=3)
{ system("cls");
switch( po)
{
case 1:
{ vf=0;
meniu();
cout<<endl<<endl;
cout<<"Introduceti numarul operatiei: ";
cin>>op;
while (!(op<1 ||op>5))
{
switch (op)
{
case 1:
if (okt==0 ||okf==0)
{
creare_t();
okt=1;
okf=1;
ok=1;
}
else cout<<endl<<"Lista a fost creata ";
break;
case 2:
if (okt==0 &&okf==0)
{
creare_f();
okf=1;
okt=1;
ok=1;
}
else cout<<endl<<"Lista a fost creata ";
break;
case 3:
afisare();
break;
case 4:
if (ok==1) if (!e_plina()) inserare();
else cout<<"Lista este plina!!!Nu se mai poate insera!!!";
else cout<<"Lista nu a fost creata.Apelati operatia 1 sau 2!!!";
break;
case 5:
if (ok==1) if (!e_vida()) stergere();
else cout<<endl<<"Lista este vida!!!Nu se mai poate realiza stergerea!!!";
else cout<<"Lista nu a fost creata.Apelati operatia 1 sau 2!!!";
break;
}
getch();
system("cls");
meniu();
cout<<endl<<endl;
cout<<"Introduceti numarul operatiei: ";
cin>>op;
}
break;
}
case 2:n=0;
stiva();
break;
case 3:vf=0;n=0; coada();
break;
}
getch();
system("cls");
meniu_la_meniu();
cin>>po;
}
return 0;
}