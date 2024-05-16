#include <stdio.h>

void submulțime_minimă(int S[], int n, int submulțime[], int *m)
{

    int dp[n+1][n+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i-1][j];
            if (dp[i-1][j-1] + S[i-1] < dp[i][j]) {
                dp[i][j] = dp[i-1][j-1] + S[i-1];
            }
        }
    }


    int i = n, j = n;
    *m = 0;
    while (i > 0 && j > 0) {
        if (dp[i][j] != dp[i-1][j]) {
            submulțime[*m] = S[i-1];
            (*m)++;
            j--;
        }
        i--;
    }
}

int main()
{
    int n;
    printf("Introduceți numărul de elemente al mulțimii: ");
    scanf("%d", &n);

    int S[n];
    printf("Introduceți elementele mulțimii în ordine crescătoare:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }

    int submulțime[n];
    int m;

    submulțime_minimă(S, n, submulțime, &m);

    printf("Submulțimea cu suma minimă: ");
    for (int i = 0; i < m; i++) {
        printf("%d ", submulțime[i]);
    }
    printf("\n");

    return 0;
}
