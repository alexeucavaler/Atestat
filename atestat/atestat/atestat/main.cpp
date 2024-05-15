#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int lista[21], n, i, stiva[21], vf, coada[10], st = 1, dr = 0;
void citire_lista(int& n, int lista[21])
{
    ifstream f("lista.in");
    f >> n;
    for (int i = 1; i <= n; i++)
        f >> lista[i];
    f.close();
}
void afisare_lista(int n, int lista[42])
{
    if (n != 0)
    {
        cout << "lista este: \n";
        for (int i = 1; i <= n; i++)
            cout << lista[i] << " ";
    }
    else  cout << "lista este vida";
}
void adaugare(int& n, int lista[21])
{
    int e, k, i;
    do { cout << "adauga element pe pozitia: "; cin >> k; } while (k<1 || k>n + 1);
    cout << "elementul: "; cin >> e;
    for (i = n; i >= k; i--)
        lista[i + 1] = lista[i];
    lista[k] = e;
    n++;
    cout << "noua "; afisare_lista(n, lista);
}
void stergere(int& n, int lista[21])
{
    int y;
    do { cout << "sterge element de pe pozitia: "; cin >> y; } while (y<1 || y>n + 1);
    for (i = y; i <= n; i++)
        lista[i] = lista[i + 1];
    n--;
    cout << "noua "; afisare_lista(n, lista); cout << endl;
}
void citire_stiva(int& vf, int stiva[21])
{
    ifstream f("date.in");
    f >> vf;
    for (int i = 1; i <= vf; i++)
    {
        f >> stiva[i];
    }
    f.close();
}
void afisare_stiva(int vf, int stiva[21])
{
    cout << "\nstiva este: " << endl;
    for (int i = 1; i <= vf; i++)
    {
        cout << "stiva[" << i << "]=";
        cout << stiva[i];
        cout << endl;
    }
}
void citire_coada(int& n, int coada[10])
{
    ifstream f("date.in");
    f >> n;
    for (int i = 1; i <= n; i++)
        f >> coada[i];
    f.close();
}
void afisare_coada(int dr, int coada[10])
{
    if (dr != 0)
    {
        cout << "\ncoada este: ";
        {for (int i = st; i <= dr; i++)
            cout << coada[i] << " ";
        cout << endl; }
    }
    else
        cout << "coada este vida";
}
int suma(int n, int coada[10])
{
    int s = 0;
    for (int i = 1; i <= n; i++)
        s = s + coada[i];
    return s;
}
void stergere_coada(int& n, int coada[10])
{
    for (int i = 1; i <= n; i++)
        coada[i] = coada[i + 1];
    n--; afisare_coada(n, coada); cout << endl;
}
int main()
{
    system("cls");
    system("color 0E"); 
    int n, i, lista[21], k, y, stiva[10], e, p, vf, coada[10], minim = 100, maxim = 0, st, dr, nr = 0;
    char r;
    citire_lista(n, lista);
    citire_stiva(vf, stiva);
    citire_coada(n, coada);
    afisare_lista(n, lista); cout << endl;
    afisare_stiva(vf, stiva);
    afisare_coada(n, coada);
    cout << endl << "operatii ce pot fi efectuate cu lista:" << endl;
    cout << "1.  afisare lista" << endl;
    cout << "2.  adaugare element in lista" << endl;
    cout << "3.  stergere element in lista" << endl;
    cout << "4.  verificare daca lista este vida" << endl;
    cout << "5.  verificare daca lista este plina" << endl << endl;
    cout << "operatii ce pot fi efectuate cu stiva:" << endl;
    cout << "6.  afisare stiva" << endl;
    cout << "7.  adaugare element in stiva" << endl;
    cout << "8.  stergere element din stiva" << endl;
    cout << "9.  extragere element maxim din stiva" << endl;
    cout << "10. verificare daca stiva este vida" << endl;
    cout << "11. verificare daca stiva este plina" << endl << endl;
    cout << "operatii ce pot fi efectuate cu coada:" << endl;
    cout << "12. afisare coada" << endl;
    cout << "13. adaugare element in coada" << endl;
    cout << "14. stergere element din coada" << endl;
    cout << "15. suma elementelor din coada" << endl;
    cout << "16. elementul minim din coada" << endl << endl;
    cout << "17. incepe un test " << endl << endl;
    cout << "18. detalii despre autor" << endl << endl;
    do {
        cout << endl << "alege optiunea: "; cin >> p;
        switch (p)
        {
        case 0: return 0;
        case 1: {cout << endl; afisare_lista(n, lista); cout << endl; break; }
        case 2: {cout << endl; adaugare(n, lista);  cout << endl; break; }
        case 3: {stergere(n, lista);  cout << endl; break; }
        case 4: { if (n == 0)
            cout << "lista e vida";
              else
            cout << "lista nu e vida";
            cout << endl; break; }
        case 5: {if (n == 20)
            cout << "lista e plina";
              else
            cout << "lista nu e plina";
            cout << endl; break; }
        case 6: {cout << " stiva este: " << endl;
            afisare_stiva(vf, stiva); break; }
        case 7: {cout << "adauga element: ";
            if (vf == 20)
                cout << "stiva este plină";
            else {
                cin >> e;
                vf++;
                stiva[vf] = e;
            }
            afisare_stiva(vf, stiva); break; }
        case 8: { cout << "se sterge un element: "; cout << endl;
            if (vf == 0)
                cout << "stiva este vidă";
            else {
                e = stiva[vf];
                vf--;
            }
            afisare_stiva(vf, stiva); break; }
        case 9: {for (int i = 1; i <= vf; i++)
        {
            if (stiva[i] > maxim)
                maxim = stiva[i];
        }
              cout << "elementul maxim este:" << maxim;
              ; break; }
        case 10: { if (vf == 0)
            cout << "stiva  e vida";
               else cout << "stiva nu e vida";
            cout << endl; break; }
        case 11: {if (vf == 20)
            cout << "stiva e plina";
               else
            cout << "stiva nu e plina";
            cout << endl; break; }
        case 12: {afisare_coada(n, coada); break; }
        case 13: {
            if (n == 10)
                cout << "coada este plina";
            else
            {
                cout << "adaugare element: ";
                cin >> e;
                n++;
                coada[n] = e;
            }
            afisare_coada(n, coada); break; }
        case 14: {stergere_coada(n, coada);
            cout << endl; break; }
        case 15: {cout << "suma= " << suma(n, coada) << endl; break; }
        case 16: {for (int i = 1; i <= n; i++)
        {
            if (coada[i] < minim)
                minim = coada[i];
        }
               cout << "elementul minim este: " << minim;
               ; break; }
        case 17: { cout << "testul contine 5 intrebari" << endl;
            cout << "la acest test poti raspunde doar cu 'a'(adevarat) si 'f'(fals)" << endl << endl;
            cout << "intrebari: " << endl;
            cout << "1: ai afisat lista si stiva?" << endl;///1
            do { cout << "raspunsul tau: "; cin >> r; } while (r != 'a' && r != 'f');
            if (r == 'a')
            {
                nr++;
                cout << "raspuns corect" << endl;
            }
            else if (r == 'f')
            {
                cout << "raspuns gresit" << endl;
            }
            cout << "apasa ENTER ca sa continui\n";
            cin.ignore(20, '\n');
            cin.get();
            cout << "2: lista nu este vida?" << endl;///2
            do { cout << "raspunsul tau: "; cin >> r; } while (r != 'a' && r != 'f');
            if (r == 'a')
            {
                nr++;
                cout << "raspuns corect" << endl;
            }
            else
                if (r == 'f')
                {
                    cout << "raspuns gresit" << endl;
                }
            cout << "apasa ENTER ca sa continui\n";
            cin.ignore(20, '\n');
            cin.get();
            cout << "3: ai sters minim un element din stiva?" << endl;///3
            do { cout << "raspunsul tau: "; cin >> r; } while (r != 'a' && r != 'f');
            if (r == 'a')
            {
                nr++;
                cout << "raspuns corect" << endl;
            }
            else
                if (r == 'f')
                {
                    cout << "raspuns gresit" << endl;
                }
            cout << "apasa ENTER ca sa continui\n";
            cin.ignore(20, '\n');
            cin.get();
            cout << "4: ai adaugat un element in coada?" << endl;///4
            do { cout << "raspunsul tau: "; cin >> r; } while (r != 'a' && r != 'f');
            if (r == 'a')
            {
                nr++;
                cout << "raspuns corect" << endl;
            }
            else
                if (r == 'f')
                {
                    cout << "raspuns gresit" << endl;
                }
            cout << "apasa ENTER ca sa continui\n";
            cin.ignore(20, '\n');
            cin.get();
            cout << "5: ai calculat suma elementelor din coada?" << endl;///5
            do { cout << "raspunsul tau: "; cin >> r; } while (r != 'a' && r != 'f');
            if (r == 'a')
            {
                nr++;
                cout << "raspuns corect" << endl;
            }
            else
                if (r == 'f')
                {
                    cout << "raspuns gresit" << endl;
                }
            cout << "ai obtinut nota " << nr << " din 5"; break; }
        case 18: { cout << " elev: Cavaler Alexandru Cristian" << endl;
            cout << " clasa a XII-a A\n"; break; }
        default:cout << "valoare gresita!";
        }
    } while (p != 0);
    return 0;
}
