#include <stdio.h>

void Troca(int *a, int *b);

int main(void) {

  int t, k, n;

  scanf("%d", &t);
  for(int i = 0; i < t; i++){
    scanf("%d", &k);
    scanf("%d", &n);
    getchar();

    int cost[n];
    for(int j = 0; j < n; j++){
      scanf("%d", &cost[j]);
    }
    for(int j = 0; j < n-1; j++){
      for(int l = j+1; l < n; l++){
        if(cost[j] + cost[l] == k) printf("%d %d\n", j+1, l+1);
      }
    }
  }

  return 0;
}
