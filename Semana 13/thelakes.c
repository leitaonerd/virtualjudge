#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m;
int matriz[1000][1000];
int visitados[1000][1000];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int search(int x, int y, int total){
    if(x < 0 || x >= n || y < 0 || y >= m) return 0;
    if(matriz[x][y] == 0 || visitados[x][y] == -1) return 0;

    total += matriz[x][y];
    visitados[x][y] = -1;

    for(int i = 0; i < 4; i++){
        total += search(x + dx[i], y + dy[i], 0);
    }

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
                if(matriz[j][k] != 0 && visitados[j][k] == 0){
                    int soma = 0;
                    int a = search(j, k, soma);
                    if(a > maxdepth) maxdepth = a;
                }
            }
        }

        printf("%d\n", maxdepth);
    }    

    return 0;
}
