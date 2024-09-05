#include <stdio.h>
#include "ArquivoGerencia.h" 
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    struct Exposicao exposicao;
    //No main, o programa apenas chama as fun��es
    lerInformacoesExposicao(&exposicao);//Ler as informa��es inseridas, com nome da exposi��o, data, quantidade de visitantes, notas
    calcularArrecadacao(&exposicao);//Calcula a arrecada��o do dia inserido
    salvarDadosEmArquivo(&exposicao);//Salva em arquivo .txt

    return 0;
}
