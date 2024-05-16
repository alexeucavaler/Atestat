#include <stdio.h>

int maxim_impar_rec(int v[], int st, int dr)
{
    if (st == dr) {
    
        if (v[st] % 2 == 1) {
            return v[st];
        } else {
            return -1;  
        }
    } else {
        
        int mijloc = (st + dr) / 2;
        int max_st = maxim_impar_rec(v, st, mijloc);
        int max_dr = maxim_impar_rec(v, mijloc + 1, dr);

       
        int rezultat = max_st;
        if (max_dr > rezultat) {
            rezultat = max_dr;
        }
        return rezultat;
    }
}

int main()
{
    int n;
    printf("Introduceți numărul de elemente din vector: ");
    scanf("%d", &n);

    int v[n];
    printf("Introduceți elementele vectorului: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    int rezultat = maxim_impar_rec(v, 0, n - 1);

    printf("Maximul dintre valorile impare din vector: %d\n", rezultat);

    return 0;
}
