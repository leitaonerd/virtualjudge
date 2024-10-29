#include <stdio.h>

void Troca(int* a, int* b);

int main(){

    int n, m, dif[101];

    scanf("%d", &n);
    getchar();
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] > arr[j]) Troca(&arr[i], &arr[j]); 
        }
    }

    scanf("%d", &m);
    getchar();
    int brr[m];
    for(int i = 0; i < m; i++){
        scanf("%d", &brr[i]);
    }
    for(int i = 0; i < m-1; i++){
        for(int j = i+1; j < m; j++){
            if(brr[i] > brr[j]) Troca(&brr[i], &brr[j]); 
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(brr[j] == arr[i]){
                brr[j] = -100000000;
                arr[i] = -100000000;
                break;
            }
        }
    }

    int k = 0;
    for(int i = 0; i < m; i++){
        if(brr[i] != -100000000){
            dif[k] = brr[i];
            k++;
        }
    }
    k--;
    for(int i = 0; i < k; i++){
        printf("%d ", dif[i]);
    }
    printf("%d\n", dif[k]);

    return 0;
}

void Troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}