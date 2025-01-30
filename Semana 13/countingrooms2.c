#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m;
char matriz[1000][1001];
int visitados[1000][1001];

void search(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m) return;
    if(matriz[x][y] == '#' || visitados[x][y]) return;

    visitados[x][y] = 1;

    search(x-1, y);
    search(x+1, y);
    search(x, y-1);
    search(x, y+1);
}

int main() {
    int cont = 0;
    memset(matriz, '#', sizeof(matriz));
    memset(visitados, 0, sizeof(visitados));
        
    scanf("%d %d", &n, &m);
    
    for(int i = 0; i < n; i++){
        scanf("%s", matriz[i]);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matriz[i][j] == '.' && !visitados[i][j]){
                cont++;
                search(i, j);
            }
        }
    }

    printf("%d\n", cont);
    return 0;
}
