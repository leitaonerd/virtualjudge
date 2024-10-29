#include <stdio.h>

int main(void) {

  int a, n, m, arr[10000], brr[10000];
  memset(arr, 0, sizeof(arr));
  memset(brr, 0, sizeof(brr));
  
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &a);
    arr[a]++;
  }

  scanf("%d", &m);
  for(int i = 0; i < m; i++){
    scanf("%d", &a);
    brr[a]++;
  }
  
  for(int i = 0; i < 10000; i++){
      if(arr[i] != brr[i]) printf("%d ", i);
  }
  printf("\n");

  return 0;
}
