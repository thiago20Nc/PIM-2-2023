#ifndef EXPOSICAO_H
#define EXPOSICAO_H

struct Exposicao{
    char nome_exposicao[100];
    char data_exposicao[20];
    int visitantes_gratuitos;
    int visitantes_meia_entrada;
    int visitantes_entrada_inteira;
    int valor_meia_entrada;
    int valor_entrada_inteira;
    int arrecadacao_total;
    int num_visitantes_total;
    int numero_obra[10];
    double notas[10];
};

void lerInformacoesExposicao(struct Exposicao* exposicao);
void calcularArrecadacao(struct Exposicao* exposicao);
void salvarDadosEmArquivo(const struct Exposicao* exposicao);

#endif
