#include <stdio.h>

int main(){

    int matrix[6][6], maxsum = -63;

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            int sum = 0;

            sum += matrix[i][j] + matrix[i][j+1] + matrix[i][j+2];
            sum += matrix[i+1][j+1];
            sum += matrix[i+2][j] + matrix[i+2][j+1] + matrix[i+2][j+2];

            if(sum > maxsum) maxsum = sum;
        }
    }

    printf("%d\n", maxsum);

    return 0;
}