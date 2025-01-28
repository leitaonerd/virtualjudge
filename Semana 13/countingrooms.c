#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int dadoi;
    int dadoj;
    struct Node* next;
} Node;

typedef struct Grafo{
    int n_arestas;
    int n_vertices;
    Node** array;
} Grafo;

Node* criaNode(){
    Node* temp = (Node*)malloc(sizeof(Node));
    if(!temp) return NULL;

    temp -> next = NULL;
    temp -> dadoi = 0;
    temp -> dadoj = 0;

    return temp;
}

void appendNode(Node* vertice, int relacionadoi, int relacionadoj){
    Node* novo = criaNode();
    novo -> dadoi = relacionadoi;
    novo -> dadoj = relacionadoj;
    
    if(vertice -> next == NULL) vertice -> next = novo;
    else{
        novo -> next = vertice -> next;
        vertice -> next = novo;
    }
}

Grafo* criaGrafo(int tamanho){
    Grafo* temp = (Grafo*)malloc(sizeof(Grafo));
    if(!temp) return NULL;

    temp -> n_vertices = tamanho;
    temp -> n_arestas = 0;

    temp -> array = (Node**)malloc(sizeof(Node*) * tamanho);
    if(!temp -> array) return NULL;

    for(int i = 0; i < tamanho; i++){
        temp->array[i] = criaNode();
    }

    return temp;
}

int main(){

    int n, m, a, b, idxatual = 0, str = 1;
    scanf("%d %d", &n, &m);
    char array[n][m];

    Grafo* grafo = criaGrafo(n/2 * m/2);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%c", &array[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(array[i][j] == '.'){
                if(str == 1){
                    if(idxatual == 0){
                        grafo -> array[idxatual] -> dadoi = i;
                        grafo -> array[idxatual] -> dadoj = j;
                        str = 0;
                    }
                    else{
                        for(int k = 0; k < idxatual; k++){
                            Node* search = grafo -> array[idxatual];
                            while(search != NULL){
                                if(search -> dadoi == i && search -> dadoj == j){
                                    idxatual++;
                                    str = 1;
                                    break;
                                }
                                search = search -> next;
                            }
                        }
                    }
                }
                else{
                    int op = 0;
                    if(array[i-1][j] == '.' && i-1 >=0) op = 1;
                    else if(array[i+1][j] == '.' && i+1 < m) op = 3;
                    else if(array[i][j-1] == '.' && j-1 >= 0) op = 2;
                    else if(array[i][j+1] == '.' && j+1 < n) op = 4;

                    if(op != 0){
                        if(op == 1){
                            a = i-1;
                            b = j;
                        }
                        else if(op == 2){
                           a = i+1;
                           b = j; 
                        }
                        else if(op == 3){
                            a = i;
                            b = j-1;
                        }
                        else if(op == 4){
                            a = i;
                            b = j+1;
                        }
                        Node* busca = grafo -> array[idxatual];
                        int flag = 0;
                        while(busca != NULL){
                            if(busca -> dadoi == a && busca -> dadoj == b){
                                idxatual++;
                                str = 1;
                                flag = 1;
                                break;
                            }
                            busca = busca -> next;
                        }
                        if(flag != 1) appendNode(grafo -> array[idxatual], a, b);
                    }
                    else{
                        idxatual++;
                        str = 1;
                    }
                }
            }
        }
    }
    printf("%d\n", idxatual);

    return 0;
}