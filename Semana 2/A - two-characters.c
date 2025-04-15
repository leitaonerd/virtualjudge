#include <stdio.h>
#include <string.h>

int main() {
    int n, contagem_max = 0;
    scanf("%d", &n);
    
    char vetor[n+1];
    scanf("%s", vetor);
    
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            if(i == j) continue;
            
            char a = 'a' + i;
            char b = 'a' + j;
            int contagem = 0;
            char ultima_letra = 0;
            int eh_alternada = 1;
            
            for(int k = 0; k < n; k++) {
                if(vetor[k] == a || vetor[k] == b) {
                    if(vetor[k] == ultima_letra) {
                        eh_alternada = 0;
                        break;
                    }
                    ultima_letra = vetor[k];
                    contagem++;
                }
            }
            
            if(eh_alternada && contagem > contagem_max) {
                contagem_max = contagem;
            }
        }
    }
    
    printf("%d\n", contagem_max > 1 ? contagem_max : 0);
    return 0;
}