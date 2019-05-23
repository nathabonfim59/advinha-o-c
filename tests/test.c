#include <stdio.h>
#include <stdlib.h>



double menuDistancia(int maior, double pontos, int numeroSecreto, int chute) {
    char *comparacao = "";
    
    if (maior) {
        comparacao = "maior";
    } else {
        comparacao = "menor";
    }

    // limpaTela();
    printf("\n/---------------------------------------------------\n");
    printf("| O número informado é %s que o número secreto  |\n", comparacao);
    printf("\\---------------------------------------------------\n");
    printf(" |\n");
    printf(" |\n");
    printf("_|__\n\n");
    
    double pontosParaDeduzir = (double)abs(numeroSecreto - chute) / 2;
    pontos = pontos - pontosParaDeduzir;

    int pause = 0;
    scanf("%d", &pause);

    return pontos;
}

int main() {
    printf("%.2f", menuDistancia(1, 1000, 42, 5));
}
