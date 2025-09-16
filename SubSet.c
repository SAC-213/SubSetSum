#include <stdio.h>
#include <stdlib.h>

int Matriz[101][10001];
int Ini(int *conjunto, int n, int k);
int Sum(int *conjunto, int n, int k);

int main(int argc, char const *argv[]) {

    int n = 0, i = 0, k = 0, num = 0, r, l = 1;
    int ConjuntoA[100];
    char Linea[201];

    fgets(Linea, sizeof(Linea), stdin);

    while (Linea[i] != '\n') {
        if (Linea[i] >= '0' && Linea[i] <= '9') { 
            num = 0;
            while (Linea[i] >= '0' && Linea[i] <= '9') { 
                num = num * 10 + (Linea[i] - '0');
                i++;
            }
            ConjuntoA[n++] = num;  
        } else {
            i++; 
        }
    }

    scanf("%d", &k); 

    if (Sum(ConjuntoA, n, k)) {
        printf("SI\n");
    } else {
        printf("NO\n");
    }

    return 0;
}

int Ini(int *conjunto, int n, int k) {
    // Casos base
    if (k == 0)
        return 1;
    if (n == 0)
        return 0;

    if (Matriz[n][k] != -1)
        return Matriz[n][k];

    if (conjunto[n - 1] > k) {
        return Matriz[n][k] = Ini(conjunto, n - 1, k);
    }

    return Matriz[n][k] = Ini(conjunto, n - 1, k) ||
                          Ini(conjunto, n - 1, k - conjunto[n - 1]);
}

int Sum(int *conjunto, int n, int k) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            Matriz[i][j] = -1;
        }
    }

    return Ini(conjunto, n, k);
}
