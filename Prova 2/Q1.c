typedef struct{
    int codigo;
    char* nome;
} Profissao;

Profissao* aloca_profissao(unsigned int tamanho_nome){
    Profissao* temp = (Profissao*)malloc(sizeof(Profissao));

    free(temp -> nome);
    temp -> nome = (char*)malloc(sizeof(char) * tamanho_nome);

    return temp;
}