#include <stdio.h>
#include "Questionario.h"

void LimparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//O question�rio coleta informa��es simples, como nome e idade, e pede que o usu�rio avalie as obras com uma nota de um a tr�s 
//As informa��es coletadas, s�o gravadas em um arquivo '.txt', que ser� utilizado para an�lise de gerenciamento
void RealizarQuestionario() {
    RespostasQuestionario respostas;

    printf("\n\nPreencha o question�rio:\n");
    printf("D� uma nota de 1 a 3.\nNota 1: N�o gostei.\nNota 2: Razo�vel.\nNota 3: Gostei.\n");

    printf("Nome: ");
    fgets(respostas.nome, sizeof(respostas.nome), stdin);
    respostas.nome[strcspn(respostas.nome, "\n")] = '\0';  // Remover o caractere de nova linha

    printf("Idade(APENAS N�MEROS): ");
    scanf("%d", &respostas.idade);
    LimparBufferEntrada();

    printf("Nota da Primeira obra (de 1 a 3): ");
    scanf("%d", &respostas.op_nota1);
    LimparBufferEntrada();

    printf("Nota da Segunda obra (de 1 a 3): ");
    scanf("%d", &respostas.op_nota2);
    LimparBufferEntrada();

    printf("Nota da Terceira obra (de 1 a 3): ");
    scanf("%d", &respostas.op_nota3);
    LimparBufferEntrada();

    printf("Nota da Quarta obra (de 1 a 3): ");
    scanf("%d", &respostas.op_nota4);
    LimparBufferEntrada();

    printf("Nota da Quinta obra (de 1 a 3): ");
    scanf("%d", &respostas.op_nota5);
    LimparBufferEntrada(); 

    printf("Nota da sexta obra (de 1 a 3): ");
    scanf("%d", &respostas.op_nota6);
    LimparBufferEntrada(); 
    
    printf("Nota da S�tima obra (de 1 a 3): ");
    scanf("%d", &respostas.op_nota7);
    LimparBufferEntrada(); 

    printf("Nota da Oitava obra (de 1 a 3): ");
    scanf("%d", &respostas.op_nota8);
    LimparBufferEntrada(); 

    printf("Nota da Nona obra (de 1 a 3): ");
    scanf("%d", &respostas.op_nota9);
    LimparBufferEntrada();  

    printf("Nota da D�cima obra (de 1 a 3): ");
    scanf("%d", &respostas.op_nota10);
    LimparBufferEntrada();

    printf("\n");
    printf("Obrigado pela Visita!\nVolte sempre!\n");

    // Salvar as respostas em um arquivo
    FILE* file = fopen("questionario.txt", "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para salvar as respostas.\n");
        return;
    }

    fprintf(file, "Nome: %s\n", respostas.nome);
    fprintf(file, "Idade: %d\n", respostas.idade);
    fprintf(file, "Nota da Primeira obra: %d\n", respostas.op_nota1);
    fprintf(file, "Nota da Segunda obra: %d\n", respostas.op_nota2);
    fprintf(file, "Nota da Terceira obra: %d\n", respostas.op_nota3);
    fprintf(file, "Nota da Quarta obra: %d\n", respostas.op_nota4);
    fprintf(file, "Nota da Quinta obra: %d\n", respostas.op_nota5); 
    fprintf(file, "Nota da Sexta obra: %d\n", respostas.op_nota6); 
    fprintf(file, "Nota da S�tima obra: %d\n", respostas.op_nota7); 
    fprintf(file, "Nota da Oitava obra: %d\n", respostas.op_nota8); 
    fprintf(file, "Nota da Nona obra: %d\n", respostas.op_nota9);
    fprintf(file, "Nota da D�cima obra: %d\n", respostas.op_nota10);
    fprintf(file, "----------------------\n");

    fclose(file);
}
