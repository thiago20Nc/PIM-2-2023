#include <stdio.h>
#include "ArquivoGerencia.h" 
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    struct Exposicao exposicao;
    //No main, o programa apenas chama as funções
    lerInformacoesExposicao(&exposicao);//Ler as informações inseridas, com nome da exposição, data, quantidade de visitantes, notas
    calcularArrecadacao(&exposicao);//Calcula a arrecadação do dia inserido
    salvarDadosEmArquivo(&exposicao);//Salva em arquivo .txt

    return 0;
}
