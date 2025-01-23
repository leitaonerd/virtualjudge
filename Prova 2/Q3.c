#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isValid(char* s) {
    int verify = 1;
    Stack* pilha = createStack();
    
    int i = 0;
    while(s[i] != ')' && s[i] != ']' && s[i] != '}'){
        push(pilha, s[i]);
        i++;  
    }
    while(s[i] == ')'||s[i] == ']'||s[i] == '}'){
        if(s[i] == ')'){
            if(isEmpty(pilha) == 1 || pilha -> top -> value != '('){
                verify = 0;
                break;
            }
            else{
                pop(pilha);
                i++;
            }
        }
        else if(s[i] == ']'){
            if(isEmpty(pilha) == 1 || pilha -> top -> value != '['){
                verify = 0;
                break;
            }
            else{
                pop(pilha);
                i++;
            }
        }
        else if(s[i] == '}'){
            if(isEmpty(pilha) == 1 || pilha -> top -> value != '{'){
                verify = 0;
                break;
            }
            else{
                pop(pilha);
                i++;
            }
        }
    }

    return verify;
}