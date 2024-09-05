#include "DadosVisitante.h"
#include <stdio.h>
#include <string.h>

void gravarDadosVisitaEmArquivo(struct Visitante visitante, int dia, int mes, int ano) { //Arquivo para gravar dados da compra
    FILE* arquivo = fopen("registro_visitas.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de registro de visitas.\n");
        return;
    }

    // Grava os dados no arquivo
    fprintf(arquivo, "Nome: %s\n", visitante.nome);
    fprintf(arquivo, "Idade: %d\n", visitante.idade); 
    fprintf(arquivo, "Tipo de ingresso: %c\n", visitante.tipo_Ingresso);
    fprintf(arquivo, "Data da visita: %d/%d/%d\n", dia, mes, ano);
    fprintf(arquivo, "Exposição: %s\n", visitante.nomeExposicao);
    fprintf(arquivo, "Valor do ingresso: %.2f\n", visitante.valorIngresso); 
    fprintf(arquivo, "Método de pagamento: %s\n", visitante.metodoPagamento); 
    fprintf(arquivo, "----------------------------------------------------------------------\n\n");
    // Fecha o arquivo
    fclose(arquivo);
}
