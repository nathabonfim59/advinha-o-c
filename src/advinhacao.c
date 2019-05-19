# include <stdio.h>

/*
 * Função principal do programa    
*/
int main() {
    printf("=======================================\n");
    printf("=-  Bem-vindo ao jogo de advinhação  -=\n");
    printf("=======================================\n");

    int numeroSecreto;
    numeroSecreto = 42;

    /* Chute do usuário */
    int chute;

    printf("Qual seu chute? ");
    scanf("%d", &chute);
    printf("\nVocê chutou o número %d \n", chute);
}