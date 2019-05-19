# include <stdio.h>

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
    numeroSecreto = 42;

    /* Número de tentativas realizadas pelo usuário */
    int tentativas = 1;
    /* Verifica se o usuário advinhou o número secreto */
    int ganhou = 0;

    while (!ganhou) {

        /* Chute do usuário */
        int chute;

        printf("\n===============\n");
        printf("| Chute %d de %d\n", tentativas, NUMERO_DE_TENTATIVAS);
        printf("===============\n");
        printf("> Qual seu chute? ");
        scanf("%d", &chute);

        /* Verifica se o usuário chutou um valor negativo */
        int chuteNegativo = chute < 0;

        if (chuteNegativo) {
            printf("Você não pode chutar valores negativos");
            tentativas--;
            continue;
        }


        printf("\nVocê chutou o número %d \n\n", chute);

        /* Verifica se o usuário acertou o número secreto */
        int acertou = chute == numeroSecreto;
        /* Verifica se o chute é maior que o número secreto */
        int maior = chute > numeroSecreto;
        /* Verifica se o chute é menor que o número secreto */
        int menor = chute < numeroSecreto;

        if (acertou) {
            printf("Você acertou!\n");
            printf("\n-> Parabés! Obrigado por jogar.\n");
            
            ganhou = 1;
        } else if (maior) {
            printf("Seu chute foi maior que o número secreto\n");
        } else if (menor) {
            printf("Seu chute foi menor que o número secreto\n");
        }
        
        tentativas++;
    }

    printf("\n>>> Fim de jogo\n");
}
