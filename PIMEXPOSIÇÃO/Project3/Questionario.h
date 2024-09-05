#ifndef NOMEQUEST_H
#define NOMEQUEST_H

// struct para armazenar as respostas do questionário
typedef struct {
    char nome[100];
    int idade;
    int op_nota1; 
    int op_nota2; 
    int op_nota3; 
    int op_nota4; 
    int op_nota5; 
    int op_nota6; 
    int op_nota7; 
    int op_nota8; 
    int op_nota9; 
    int op_nota10;
} RespostasQuestionario;

// Nome da função para realizar o questionário
void RealizarQuestionario();

#endif
