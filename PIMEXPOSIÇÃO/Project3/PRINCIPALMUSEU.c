#include <stdio.h> 
#include <string.h> 
#include <locale.h> 
#include <time.h> 
#include "ExpoParis2024.h" 
#include "ExpoPele.h" 
#include "ExpoSAModerna.h" 
#include "ExpoSantosDumond.h"
#include "Questionario.h"

struct Visitante {  //Struct do question�rio
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
        
        printf("\nEssa � a nossa tabela de exposi��es:\n\n"); //Entrada das exposi��es, com a tabela do respectivo dia
        printf("Domingo: 100 anos da Semana de Arte Moderna\n");
        printf("Segunda-feira: 150 anos de Santos Dumont\n");
        printf("Ter�a-feira: Jogos Ol�mpicos de Paris 2024\n");
        printf("Quarta-feira: Vida de Pel�\n");
        printf("Quinta-feira: 100 anos da Semana de Arte Moderna\n");
        printf("Sexta-feira: Jogos Ol�mpicos de Paris 2024\n");
        printf("S�bado: Vida de Pel�\n\n");
        printf("Estamos em Novembro(M�S 11). As datas v�lidas est�o 01/11/2023 e 30/11/2023.\n"); //Orienta o usu�rio � inserir uma data v�lida
        printf("Insira a data do seu ingresso (DD/MM/AAAA):\n");
        scanf("%d/%d/%d", &dia, &mes, &ano); 
        printf("\n");
        
        
        if (ano == 2023 && mes == 11 && dia >= 1 && dia <= 30) { //Se a data inserida for compat�vel o programa continua e entra na exposi��o do dia
            int DiaDaSemana;
            struct tm data = { 0 };
            data.tm_year = ano - 1900;
            data.tm_mon = mes - 1;
            data.tm_mday = dia;
            mktime(&data);

            DiaDaSemana = data.tm_wday;
            char ExposicaoEscolhida = 'N';
            char nomeExposicao[100];

            switch (DiaDaSemana) {   //Uma exposi��o por dia, com base na data escolhida o programa chama a fun��o da respectiva exposi��o
            case 0:                 //Cada exposi��o tem uma fun��o e biblioteca
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
                ExposicaoEscolhida = 'C';//TER�A
                strcpy(nomeExposicao, "Jogos Ol�mpicos de Paris 2024");
                exposicaoParis2024();
                break;
            case 3:
                ExposicaoEscolhida = 'D';//QUARTA
                strcpy(nomeExposicao, "Vida de Pel�");
                exposicaoPele();
                break;
            case 4:
                ExposicaoEscolhida = 'A';//QUINTA
                strcpy(nomeExposicao, "100 anos da Semana de Arte Moderna");
                exposicaoSemanaArteModerna();
                break;
            case 5:
                ExposicaoEscolhida = 'C';//SEXTA
                strcpy(nomeExposicao, "Jogos Ol�mpicos de Paris 2024");
                exposicaoParis2024();
                break;
            case 6:
                ExposicaoEscolhida = 'D';//S�BADO
                strcpy(nomeExposicao, "Vida de Pel�");
                exposicaoPele();
                break;
            }

            if (ExposicaoEscolhida != 'N') {//INFORMA��ES SOBRE A VISITA
                printf("\nVoc� est� visitou a exposi��o no dia %d/%d/%d. A exposi��o escolhida foi: %s.\n", dia, mes, ano, nomeExposicao);
                
                RealizarQuestionario();// Chame a fun��o de question�rio ap�s a visualiza��o das obras
            }
            else {
                printf("Data fora do intervalo permitido ou exposi��o n�o dispon�vel. Esperamos que consiga vir numa pr�xima vez!\n");
            }
        }
        else {
            printf("Data fora do intervalo permitido. Esperamos que consiga vir numa pr�xima vez!\n");
        }
        
    return 0;
}