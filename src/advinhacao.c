# include <stdio.h>

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


    for (int i = 1; i <= 3; i++) {

        /* Chute do usuário */
        int chute;

        printf("\n===============\n");
        printf("| Chute %d de %d\n", i, 3);
        printf("===============\n");
        printf("> Qual seu chute? ");
        scanf("%d", &chute);

        printf("\nVocê chutou o número %d \n\n", chute);

            
        /* Verifica se o usuário acertou o número secreto */
        int acertou = chute == numeroSecreto;
        
        if (acertou) {
            printf("Você acertou!\n");
        } else {
            /* Avalia se o chute é maior que o número secreto */
            int maior = chute > numeroSecreto;
            
            if (maior) {
                printf("Seu chute foi maior que o número secreto\n");
            } else {
                printf("Seu chute foi menor que o número secreto\n");
            }
        }
    }

    printf("\n-> Fim de jogo\n");
}
