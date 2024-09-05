#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <string.h>
#include "DadosVisitante.h"

int main() {
    setlocale(LC_ALL, "Portuguese");
    int dia, mes, ano;
    char continuarCompra = 'S';

    printf("Bem Vindo!\n\n");
    while (continuarCompra == 'S' || continuarCompra == 's') {
        struct Visitante visitante;

        
        printf("Qual � o seu nome?\n");//PEDE O NOME DO USU�RIO
        scanf(" %99[^\n]", visitante.nome);
        getchar(); // Limpar o buffer do teclado

        printf("Qual � a sua idade?(APENAS N�MEROS)\n");//PEDE A IDADE DO USU�RIO
        scanf("%d", &visitante.idade);

        //INFORMA��ES SOBRE FUNCIONAMENTO
        printf("\nHor�rios de funcionamento:\nSegunda a sexta das 9h00 �s 17h00\nS�bado e domingo das 9h00 �s 14h00.\n");
        printf("\nSegue nossa tabela de exposi��es:\n\n");
        printf("Domingo: Semana de Arte Moderna\n");
        printf("Segunda-feira: 150 anos de Santos Dumont\n");
        printf("Ter�a-feira: Jogos Ol�mpicos de Paris 2024\n");
        printf("Quarta-feira: Vida de Pel�\n");
        printf("Quinta-feira: 100 anos da Semana de Arte Moderna\n");
        printf("Sexta-feira: Jogos Ol�mpicos de Paris 2024\n");
        printf("S�bado: Vida de Pel�\n\n");

        printf("Estamos em novembro, escolha uma data entre 01/11/2023 e 30/11/2023.\n");//PEDE PARA O USU�RIO INSERIR A DATA QUE ELE DESEJA VISITAR
        printf("Digite a data que voc� deseja nos visitar (DD/MM/AAAA):\n");
        scanf("%d/%d/%d", &dia, &mes, &ano); 

        printf("\nTipos de ingresso:\n"); //TIPOS DE ENTRADA
        printf("'A'-Entrada gratuita, para crian�as at� 12 anos de idade e idosos a partir de 60 anos de idade, necess�rio comprovar;\n"); 
        printf("'B' - Meia entrada, para estudantes, necess�rio comprovar, valor R$20,00;\n"); 
        printf("'C'-Entrada inteira, para os demais, valor R$40,00;\n"); 


       //VALORES DAS ENTRADAS
        float valorInteira = 40.0;
        float valorMeia = 20.0;

        if (ano == 2023 && mes == 11 && dia >= 1 && dia <= 30) {
            int ingressosDisp = 150;
            int DiaDaSemana;
            struct tm data = { 0 };
            data.tm_year = ano - 1900;
            data.tm_mon = mes - 1;
            data.tm_mday = dia;
            mktime(&data);
            DiaDaSemana = data.tm_wday;

            char ExposicaoEscolhida = 'N';
            char nomeExposicao[100];

            switch (DiaDaSemana) { //COM BASE NA DATA ESCOLHIDA, O INGRESSO SER� COMPRADO PARA A RESPECTIVA EXPOS��O 
            case 0:
                ExposicaoEscolhida = 'A';//DOMINGO
                strcpy(nomeExposicao, "100 anos da Semana de Arte Moderna"); 
                strcpy(visitante.nomeExposicao, nomeExposicao);
                break;
            case 1:
                ExposicaoEscolhida = 'B';//SEGUNDA
                strcpy(nomeExposicao, "150 anos de Santos Dumont"); 
                strcpy(visitante.nomeExposicao, nomeExposicao);
                break;
            case 2:
                ExposicaoEscolhida = 'C';//TER�A
                strcpy(nomeExposicao, "Jogos Ol�mpicos de Paris 2024");
                strcpy(visitante.nomeExposicao, nomeExposicao);
                break;
            case 3:
                ExposicaoEscolhida = 'D';//QUARTA
                strcpy(nomeExposicao, "Vida de Pel�"); 
                strcpy(visitante.nomeExposicao, nomeExposicao);
                break;
            case 4:
                ExposicaoEscolhida = 'A';//QUINTA
                strcpy(nomeExposicao, "100 anos da Semana de Arte Moderna");
                strcpy(visitante.nomeExposicao, nomeExposicao);
                break;
            case 5:
                ExposicaoEscolhida = 'C';//SEXTA
                strcpy(nomeExposicao, "Jogos Ol�mpicos de Paris 2024");
                strcpy(visitante.nomeExposicao, nomeExposicao);
                break;
            case 6:
                ExposicaoEscolhida = 'D'; //S�BADO
                strcpy(nomeExposicao, "Vida de Pel�");
                strcpy(visitante.nomeExposicao, nomeExposicao);
                break;
            }

            if (ExposicaoEscolhida != 'N') {
                printf("\nVoc� est� comprando um ingresso para o dia %d/%d/%d. A exposi��o escolhida �: %s.\n", dia, mes, ano, nomeExposicao);

                printf("Escolha o tipo de ingresso (A/B/C):\n");//PEDE QUE O USU�RIO ESCOLHA O TIPO DE INGRESSO
                scanf(" %c", &visitante.tipo_Ingresso);
                
                

                if (visitante.tipo_Ingresso == 'A' || visitante.tipo_Ingresso == 'a') {
                    if ((visitante.idade < 12 || visitante.idade > 60) && ingressosDisp > 0) {
                        ingressosDisp--;
                        printf("\nIngresso de Entrada Gratuita adquirido com sucesso! Apresente seu documento Esperamos que curta a visita!\n");
                    }
                    else if (visitante.idade >= 12 && visitante.idade <= 60) {
                        printf("Voc� n�o tem direito a entrada gratuita.\n");
                    }
                    else {
                        printf("Desculpe, ingressos esgotados para este tipo de ingresso.\n");
                    }
                }
                else if (visitante.tipo_Ingresso == 'B' || visitante.tipo_Ingresso == 'b') {
                    char respostaEstudante;
                    printf("\nVoc� � estudante?\nSIM: DIGITE 'S'\nN�O: DIGITE 'N'\n");
                    scanf(" %c", &respostaEstudante);
                    if (respostaEstudante == 'S' || respostaEstudante == 's') {
                        char metodoPagamento;//AQUI O USU�RIO DEVE ESCOLHER O M�TODO DE PAGAMENTO, DEPOIS PAGAR NA MAQUININHA AO LADO DO TERMINAL
                        printf("\nEscolha o m�todo de pagamento e efetue o pagamento na 'maquininha' ao lado:\n");
                        printf("Digite 'D' para Cart�o de D�bito\n");
                        printf("Digite 'C' para Cart�o de Cr�dito\n");
                        printf("Digite 'P' para PIX\n");
                        scanf(" %c", &metodoPagamento);

                        if (metodoPagamento == 'D' || metodoPagamento == 'd') {
                            strcpy(visitante.metodoPagamento, "Cart�o de D�bito");
                        }
                        else if (metodoPagamento == 'C' || metodoPagamento == 'c') {
                            strcpy(visitante.metodoPagamento, "Cart�o de Cr�dito");
                        }
                        else if (metodoPagamento == 'P' || metodoPagamento == 'p') {
                            strcpy(visitante.metodoPagamento, "PIX");
                        }
                        else {
                            printf("Op��o de m�todo de pagamento inv�lida.\n");
                        }

                        printf("Ap�s realizar o pagamento, pressione 'enter'\n");
                        int c;
                        while ((c = getchar()) != '\n' && c != EOF); // Limpa o buffer do teclado

                        getchar();

                        if (respostaEstudante == 'S' || respostaEstudante == 's') {
                            if (ingressosDisp > 0) {
                                ingressosDisp--;
                                visitante.valorIngresso = valorMeia;
                                printf("\nIngresso de meia-entrada comprado com sucesso! Apresente seu comprovante! Valor total: R$%.2f. Esperamos que curta a visita!\n", visitante.valorIngresso);
                            }
                            else {
                                printf("Desculpe, quantidade de ingressos indispon�vel.\n");
                            }
                        }
                        else {
                            printf("Desculpe, ingressos de meia-entrada dispon�veis apenas para estudantes. Se voc� desejar, pode iniciar uma nova compra. \n");
                            return 0;
                        }
                    }
                }
                else if (visitante.tipo_Ingresso == 'C' || visitante.tipo_Ingresso == 'c') {
                    if (ingressosDisp > 0) {
                        ingressosDisp--;
                        visitante.valorIngresso = valorInteira;
                        char metodoPagamento;//AQUI O USU�RIO DEVE ESCOLHER O M�TODO DE PAGAMENTO, DEPOIS PAGAR NA MAQUININHA AO LADO DO TERMINAL
                        printf("\nEscolha o m�todo de pagamento e efetue o pagamento na 'maquininha' ao lado:\n");
                        printf("Digite 'D' para Cart�o de D�bito\n");
                        printf("Digite 'C' para Cart�o de Cr�dito\n");
                        printf("Digite 'P' para PIX\n");
                        scanf(" %c", &metodoPagamento);

                        if (metodoPagamento == 'D' || metodoPagamento == 'd') {
                            strcpy(visitante.metodoPagamento, "Cart�o de D�bito");
                        }
                        else if (metodoPagamento == 'C' || metodoPagamento == 'c') {
                            strcpy(visitante.metodoPagamento, "Cart�o de Cr�dito");
                        }
                        else if (metodoPagamento == 'P' || metodoPagamento == 'p') {
                            strcpy(visitante.metodoPagamento, "PIX");
                        }
                        else {
                            printf("Op��o de m�todo de pagamento inv�lida.\n");
                        }
                        // 
                        printf("Ap�s realizar o pagamento, pressione 'enter'\n");
                        int c;
                        while ((c = getchar()) != '\n' && c != EOF); // Limpa o buffer do teclado

                        getchar();
                        
                        printf("\nIngresso inteira comprado com sucesso! Valor total: R$%.2f. Esperamos que curta a visita!\n", visitante.valorIngresso);
                    }
                    else {
                        printf("Desculpe, quantidade de ingressos indispon�vel.\n");
                    }
                }
                else {
                    printf("Op��o de ingresso inv�lida.\n");
                }

                gravarDadosVisitaEmArquivo(visitante, dia, mes, ano);

                //AQUI PERGUNTA PARA O USU�RIO SE ELE DESEJA COMPRAR OUTRO INGRESSO OU FINALIZAR A COMPRA
                printf("\nVoc� deseja comprar outro ingresso?\nSIM: DIGITE 'S'\nN�O: DIGITE 'N'\n");
                scanf(" %c", &continuarCompra);
                
                if (continuarCompra != 'S' && continuarCompra != 's') {
                    break;
                }
            }
            else {
                printf("Data fora do intervalo permitido ou exposi��o n�o dispon�vel. Esperamos que consiga vir numa pr�xima vez!\n");
            }
        }
        else {
            printf("Data fora do intervalo permitido. Esperamos que consiga vir numa pr�xima vez!\n");
        }
    }

    return 0;
}
