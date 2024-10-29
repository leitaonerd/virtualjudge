#include <stdio.h>

void Troca(int *a, int *b);

int main(void) {

  int t, k, n;
  
  scanf("%d", &t);
  for(int i = 0; i < t; i++){
    scanf("%d", &k);
    scanf("%d", &n);
    getchar();
    
    int cost[n], cpy[n];
    for(int j = 0; j < n; j++){
      scanf("%d", &cost[j]);
      cpy[j] = cost[j];
    }
    for(int j = 0; j < n-1; j++){
      for(int k = j+1; k < n; k++){
        if(cost[j] > cost[k]) Troca(&cost[j], &cost[j]);
      }
    }
  
    int a = 0, b = n-1;
    while((cost[a]+cost[b]) != k){
      if(cost[a]+cost[b] > k) b--;
      else if(cost[a]+cost[b] < k) a++;
    }
    
    a = cost[a];
    b = cost[b];

    for(int j = 0; j < n; j++){
      if(cpy[j] == a) printf("%d ", j+1);
    }
    for(int j = 0; j < n; j++){
      if(cpy[j] == b) printf("%d\n", j+1);
    }
  }

  return 0;
}

void Troca(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}
