#include <stdio.h> 
#include <string.h> 
#include <locale.h> 
#include <time.h> 
#include "ExpoParis2024.h" 
#include "ExpoPele.h" 
#include "ExpoSAModerna.h" 
#include "ExpoSantosDumond.h"
#include "Questionario.h"

struct Visitante {  //Struct do questionário
    char nome[100];
    int idade;
    char tipoIngresso;
    char dataVisita[11];
    char exposicao[100];
    float valorIngresso;
};

int main() {
    setlocale(LC_ALL, "Portuguese");
    int dia, mes, ano;
    char continuarCompra = 'S';

    printf("Bem Vindo!\n");
        struct Visitante visitante;
        
        printf("\nEssa é a nossa tabela de exposições:\n\n"); //Entrada das exposições, com a tabela do respectivo dia
        printf("Domingo: 100 anos da Semana de Arte Moderna\n");
        printf("Segunda-feira: 150 anos de Santos Dumont\n");
        printf("Terça-feira: Jogos Olímpicos de Paris 2024\n");
        printf("Quarta-feira: Vida de Pelé\n");
        printf("Quinta-feira: 100 anos da Semana de Arte Moderna\n");
        printf("Sexta-feira: Jogos Olímpicos de Paris 2024\n");
        printf("Sábado: Vida de Pelé\n\n");
        printf("Estamos em Novembro(MÊS 11). As datas válidas estão 01/11/2023 e 30/11/2023.\n"); //Orienta o usuário à inserir uma data válida
        printf("Insira a data do seu ingresso (DD/MM/AAAA):\n");
        scanf("%d/%d/%d", &dia, &mes, &ano); 
        printf("\n");
        
        
        if (ano == 2023 && mes == 11 && dia >= 1 && dia <= 30) { //Se a data inserida for compatível o programa continua e entra na exposição do dia
            int DiaDaSemana;
            struct tm data = { 0 };
            data.tm_year = ano - 1900;
            data.tm_mon = mes - 1;
            data.tm_mday = dia;
            mktime(&data);

            DiaDaSemana = data.tm_wday;
            char ExposicaoEscolhida = 'N';
            char nomeExposicao[100];

            switch (DiaDaSemana) {   //Uma exposição por dia, com base na data escolhida o programa chama a função da respectiva exposição
            case 0:                 //Cada exposição tem uma função e biblioteca
                ExposicaoEscolhida = 'A';//DOMINGO
                strcpy(nomeExposicao, "100 anos da Semana de Arte Moderna"); 
                exposicaoSemanaArteModerna();
                break;
            case 1:
                ExposicaoEscolhida = 'B';//SEGUNDA
                strcpy(nomeExposicao, "150 anos de Santos Dumont");
                exposicaoSantosDumont();
                break;
            case 2:
                ExposicaoEscolhida = 'C';//TERÇA
                strcpy(nomeExposicao, "Jogos Olímpicos de Paris 2024");
                exposicaoParis2024();
                break;
            case 3:
                ExposicaoEscolhida = 'D';//QUARTA
                strcpy(nomeExposicao, "Vida de Pelé");
                exposicaoPele();
                break;
            case 4:
                ExposicaoEscolhida = 'A';//QUINTA
                strcpy(nomeExposicao, "100 anos da Semana de Arte Moderna");
                exposicaoSemanaArteModerna();
                break;
            case 5:
                ExposicaoEscolhida = 'C';//SEXTA
                strcpy(nomeExposicao, "Jogos Olímpicos de Paris 2024");
                exposicaoParis2024();
                break;
            case 6:
                ExposicaoEscolhida = 'D';//SÁBADO
                strcpy(nomeExposicao, "Vida de Pelé");
                exposicaoPele();
                break;
            }

            if (ExposicaoEscolhida != 'N') {//INFORMAÇÕES SOBRE A VISITA
                printf("\nVocê está visitou a exposição no dia %d/%d/%d. A exposição escolhida foi: %s.\n", dia, mes, ano, nomeExposicao);
                
                RealizarQuestionario();// Chame a função de questionário após a visualização das obras
            }
            else {
                printf("Data fora do intervalo permitido ou exposição não disponível. Esperamos que consiga vir numa próxima vez!\n");
            }
        }
        else {
            printf("Data fora do intervalo permitido. Esperamos que consiga vir numa próxima vez!\n");
        }
        
    return 0;
}