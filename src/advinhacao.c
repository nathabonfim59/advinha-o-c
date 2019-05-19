#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMERO_DE_TENTATIVAS 3

/*
 * Função principal do programa    
*/
int main() {
    printf("=======================================\n");
    printf("=-  Bem-vindo ao jogo de advinhação  -=\n");
    printf("=======================================\n");

    /* Número a ser advinhado pelo player */
    int numeroSecreto;

    int segundos = time(0);
    srand(segundos);

    /* Calcula um número na sequência informada */
    numeroSecreto = rand() % 100;

    /* Número de tentativas realizadas pelo usuário */
    int totalDeTentativas = 0;
    int dificuldade = 0;
    /* Verifica se o usuário advinhou o número secreto */
    int ganhou = 0;
    /* Quantidade de pontos do usuário */
    double pontos = 1000;

    printf("====================================\n");
    printf("=- Escolha a dificuldade do jogo\n");
    printf("====================================\n");
    printf("=  (1) Fácil  (2) Médio (3) Difícil\n");
    printf("------------------------------------\n");
    printf(">>> ");
    scanf("%d", &dificuldade);

    switch (dificuldade) {
        case 1:
            totalDeTentativas = 20;
            break;
        
        case 2:
            totalDeTentativas = 15;

        case 3: 
            totalDeTentativas = 6;
        default:
            totalDeTentativas = 6;
            break;
    }

    /* Verifica se o usuário acertou o número secreto */
    int acertou;

    for (int i = 1; i <= totalDeTentativas; i++) {

        /* Chute do usuário */
        int chute;

        printf("\n===============\n");
        printf("| Chute %d de %d\n", i, totalDeTentativas);
        printf("===============\n");
        printf("> Qual seu chute? ");
        scanf("%d", &chute);

        /* Verifica se o usuário chutou um valor negativo */
        int chuteNegativo = chute < 0;

        if (chuteNegativo) {
            printf("Você não pode chutar valores negativos");
            i--;
        }


        printf("\nVocê chutou o número %d \n\n", chute);

        acertou = chute == numeroSecreto;
        /* Verifica se o chute é maior que o número secreto */
        int maior = chute > numeroSecreto;
        /* Verifica se o chute é menor que o número secreto */
        int menor = chute < numeroSecreto;

        if (acertou) {
            printf("Você acertou!\n");
            printf("\n-> Parabés! Obrigado por jogar.\n");

            printf("Você fez %.2f pontos.", pontos);
            
            ganhou = 1;
        } else if (maior) {
            printf("Seu chute foi maior que o número secreto\n");
        } else if (menor) {
            printf("Seu chute foi menor que o número secreto\n");
        }

        /* Pontos perdidos por errar uma tentativa */
        int pontosPerdidos =  abs(chute - numeroSecreto) / (double)2;

        pontos = pontos - pontosPerdidos;
    }

    if (!acertou) {
        printf("|:'(|  Você perdeu, tente novamente.");
    }

    printf("\n>>> Fim de jogo\n");
}
