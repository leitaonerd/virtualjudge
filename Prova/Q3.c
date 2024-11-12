#include <stdio.h>

int main(){

    int dia1, hora1, min1, seg1;
    int dia2, hora2, min2, seg2;
    long long int total1, total2, total_final;
    
    scanf("%d %d:%d:%d", &dia1, &hora1, &min1, &seg1);
    scanf("%d %d:%d:%d", &dia2, &hora2, &min2, &seg2);

    total1 = (86400*dia1) + (3600*hora1) + (60*min1) + seg1;
    total2 = (86400*dia2) + (3600*hora2) + (60*min2) + seg2;
    total_final = total2 - total1;

    if(total_final <= 0){
        printf("Data invalida!\n");
        return 0;
    }

    printf("%lld dia(s)\n", total_final/86400);
    printf("%lld hora(s)\n", (total_final%86400)/3600);
    printf("%lld minuto(s)\n", ((total_final%86400)%3600)/60);
    printf("%lld segundo(s)\n", (((total_final%86400)%3600)%60));

    return 0;
}