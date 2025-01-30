#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m;
char matriz[1000][1000];
int visitados[1000][1000];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void search(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m) return;
    if(matriz[x][y] == '#' || visitados[x][y]) return;

    visitados[x][y] = 1;

    for(int i = 0; i < 4; i++){
        search(x + dx[i], y + dy[i]);
    }
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
