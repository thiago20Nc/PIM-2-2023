#include <stdio.h>
#include "ArquivoGerencia.h" 
#include <locale.h>

#define MAX_OBRAS 10
#define MAX_CARACTERES 100 

void lerInformacoesExposicao(struct Exposicao* exposicao) {
    printf("Nome da Exposição: ");
    fgets(exposicao->nome_exposicao, sizeof(exposicao->nome_exposicao), stdin);
    exposicao->nome_exposicao[strcspn(exposicao->nome_exposicao, "\n")] = '\0'; // Remove o \n se presente

    printf("Data da Exposição: ");
    fgets(exposicao->data_exposicao, sizeof(exposicao->data_exposicao), stdin);
    exposicao->data_exposicao[strcspn(exposicao->data_exposicao, "\n")] = '\0'; // Remove o \n se presente

    printf("Número de visitantes que adquiriram ingressos gratuitos: ");
    scanf("%d", &exposicao->visitantes_gratuitos);

    printf("Número de visitantes que compraram ingressos de meia-entrada: ");
    scanf("%d", &exposicao->visitantes_meia_entrada);

    printf("Número de visitantes que compraram ingressos de entrada inteira: ");
    scanf("%d", &exposicao->visitantes_entrada_inteira);

    exposicao->valor_meia_entrada = 20;
    exposicao->valor_entrada_inteira = 40;

    while (getchar() != '\n');

    int total_visitantes = exposicao->visitantes_gratuitos + exposicao->visitantes_meia_entrada + exposicao->visitantes_entrada_inteira;

    for (int i = 0; i < MAX_OBRAS; i++) {
        printf("Número da obra %d: ", i + 1);
        scanf("%d", &exposicao->numero_obra[i]);

        exposicao->notas[i] = 0.0;
        for (int j = 0; j < total_visitantes; j++) {
            double nota;
            printf("Nota dada pelo visitante %d (obra %d - 0 a 3): ", j + 1, i + 1);
            scanf("%lf", &nota);
            exposicao->notas[i] += nota;
        }
        exposicao->notas[i] /= total_visitantes;
    }
}

void calcularArrecadacao(struct Exposicao* exposicao) {
    exposicao->arrecadacao_total = (exposicao->visitantes_meia_entrada * exposicao->valor_meia_entrada) +
        (exposicao->visitantes_entrada_inteira * exposicao->valor_entrada_inteira);

    exposicao->num_visitantes_total = exposicao->visitantes_gratuitos + exposicao->visitantes_meia_entrada + exposicao->visitantes_entrada_inteira;
}

void encontrarObraMaiorMenorNota(const struct Exposicao* exposicao, int* obra_maior, int* obra_menor) {
    double maior_nota = exposicao->notas[0];
    double menor_nota = exposicao->notas[0];
    *obra_maior = 1;
    *obra_menor = 1;

    for (int i = 1; i < MAX_OBRAS; i++) {
        if (exposicao->notas[i] > maior_nota) {
            maior_nota = exposicao->notas[i];
            *obra_maior = i + 1;
        }
        if (exposicao->notas[i] < menor_nota) {
            menor_nota = exposicao->notas[i];
            *obra_menor = i + 1;
        }
    }
}

void salvarDadosEmArquivo(const struct Exposicao* exposicao) {
    FILE* arquivo = fopen("Gerencia.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }

    fprintf(arquivo, "Informações da Exposição:\n");
    fprintf(arquivo, "Nome da Exposição: %s\n", exposicao->nome_exposicao);
    fprintf(arquivo, "Data da Exposição: %s\n", exposicao->data_exposicao);
    fprintf(arquivo, "Número de visitantes que adquiriram entrada gratuita: %d\n", exposicao->visitantes_gratuitos);
    fprintf(arquivo, "Número de visitantes que compraram meia-entrada: %d\n", exposicao->visitantes_meia_entrada);
    fprintf(arquivo, "Número de visitantes que compraram entrada inteira: %d\n", exposicao->visitantes_entrada_inteira);
    fprintf(arquivo, "Arrecadação total: R$%d\n", exposicao->arrecadacao_total);
    fprintf(arquivo, "Número total de visitantes: %d\n\n", exposicao->num_visitantes_total);

    int obra_maior, obra_menor;
    encontrarObraMaiorMenorNota(exposicao, &obra_maior, &obra_menor);

    fprintf(arquivo, "Obra com a maior nota: Obra %d - Nota: %.0lf\n", obra_maior, exposicao->notas[obra_maior - 1]);
    fprintf(arquivo, "Obra com a menor nota: Obra %d - Nota: %.0lf\n", obra_menor, exposicao->notas[obra_menor - 1]);

    fclose(arquivo);

    printf("Dados armazenados no arquivo 'Gerencia.txt'.\n");
}

