#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m;
int matriz[1000][1000];
int visitados[1000][1000];

int search(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m) return 0;
    if(matriz[x][y] == 0 || visitados[x][y]) return 0;

    int total = matriz[x][y];
    visitados[x][y] = 1;

    total += search(x-1, y);
    total += search(x+1, y);
    total += search(x, y-1);
    total += search(x, y+1);

    return total;
}

int main() {
    int t, maxdepth;

    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        maxdepth = 0;
        memset(matriz, 0, sizeof(matriz));
        memset(visitados, 0, sizeof(visitados));

        scanf("%d %d", &n, &m);

        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                scanf("%d", &matriz[j][k]);
            }
        }

        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                if(visitados[j][k] == 0 && matriz[j][k] != 0){
                    int a = search(j, k);
                    if(a > maxdepth) maxdepth = a;
                }
            }
        }

        printf("%d\n", maxdepth);
    }    

    return 0;
}
