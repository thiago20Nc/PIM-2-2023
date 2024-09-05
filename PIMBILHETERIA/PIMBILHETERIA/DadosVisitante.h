#ifndef DADOS_VISITANTE_H
#define DADOS_VISITANTE_H

struct Visitante {//STRUCT PARA ARMAZENAR DADOS DAS VENDAS
    char nome[100];
    int idade; 
    char tipo_Ingresso;
    char dataVisita[11];
    char nomeExposicao[100];
    float valorIngresso; 
    char metodoPagamento[100]; 
   
};

// Função para gravar os dados da visita em um arquivo
void gravarDadosVisitaEmArquivo(struct Visitante visitante, int dia, int mes, int ano);

#endif
