#include <stdio.h>

int main(){
    char dia[11];
    int horas;

    scanf("%s", dia);
    
    if(dia[8] == 'P'){
        horas = (dia[0]-'0')*10 + dia[1] - '0' + 12;
        if(horas == 24) horas = 12;
    }

    else{
        horas = (dia[0]-'0')*10 + dia[1] - '0';
        if(horas == 12) horas = 0;
    }

    dia[0] = horas/10 + '0';
    dia[1] = horas%10 + '0';
    dia[8] = '\0';
    dia[9] = '\0';

    printf("%s\n", dia);

    return 0;
}