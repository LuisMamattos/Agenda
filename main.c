#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void *pBuffer;
int n_pessoas = 0;
int tamanho = 0;
int tamanho_inicial = (sizeof(char)*10 + sizeof(int) + sizeof(int));

//pBuffer = malloc(sizeof(char)*10 + sizeof(int) + sizeof(int));

void leitura();
void apaga();
void escrita();

void main(){
    int opcao;
    do{
    //printf("tamanho: %d\n", tamanho);
    printf("\tQual operacao desejas fazer?\n");

    printf("\t\t-1. Inserir pessoa\n");
    printf("\t\t-2. Apagar pessoa\n");
    printf("\t\t-3. Ver pessoas\n");
    printf("\t\t-4. Sair\n");
    scanf("%i",&opcao);
    switch(opcao){
        case 1:
            leitura();
        break;
        case 2:
            apaga();
        break;
        case 3:
            escrita();
        break;
        case 4:
            return;
        break;
        default:
            printf("digite novamente\n");
            break;
    }
}while(opcao != 4);
}
void leitura(){

    tamanho += tamanho_inicial;
    pBuffer = realloc(pBuffer,(tamanho));

    printf("nome: ");
    scanf("%s", (char*)(pBuffer + n_pessoas*tamanho_inicial));
    printf("idade: ");
    scanf("%i", (int*)(pBuffer + n_pessoas*tamanho_inicial + (sizeof(char)*10)));
    printf("telefone: ");
    scanf("%i", (int*)(pBuffer + n_pessoas*tamanho_inicial + (sizeof(char)*10) + (sizeof(int))));

    n_pessoas++;

    ////main();
}
void apaga(){
    char pessoa_apagada [10]; //void *new_point;
    printf("Qual pessoa desejas apagar?  ");
    scanf("%s", pessoa_apagada);
    printf("tentando apagar : %s\n", pessoa_apagada);
    int x=0;int n;int y;
    for(n = 0;n < n_pessoas;n++){
        while((pessoa_apagada[x]!= '\0')&&(*((char*)pBuffer + x + n*tamanho_inicial)!='\0')&&(pessoa_apagada[x] == *((char*)pBuffer + x + n*tamanho_inicial))){
           x++; y=x;
        }
        x=0;

        if((pessoa_apagada[y]== '\0')&&(*((char*)pBuffer + y + n*tamanho_inicial)=='\0')){
            for(int k = n; k < n_pessoas; k++){
                *((char*)pBuffer + k) = *((char*)(pBuffer + k + tamanho_inicial));
                *((int*)pBuffer + k + (sizeof(char)*10)) = *((int*)(pBuffer + k + tamanho_inicial + (sizeof(char)*10)));
                *((int*)pBuffer + k + (sizeof(char)*10) + sizeof(int)) = *((int*)(pBuffer + k + tamanho_inicial + (sizeof(char)*10) + sizeof(int)));
            }
            n_pessoas--;
            tamanho -= tamanho_inicial;
            pBuffer = realloc(pBuffer, tamanho);
        }
    }
}
void escrita(){
    for(int x=0; x < n_pessoas; x++){
        printf("\t\t%s\n", (char*)(pBuffer + x * tamanho_inicial));
        printf("Idade: %i\n", *((int*)(pBuffer + x * tamanho_inicial + (sizeof(char)*10))));
        printf("Telefone: %i\n", *((int*) (pBuffer + x * tamanho_inicial + (sizeof(char)*10)+sizeof(int))));
        printf("-------------------------------------------\n");
    }
    //main();
}
