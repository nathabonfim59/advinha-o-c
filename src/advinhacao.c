#include <stdio.h>
// #include <stdlib.h>

/*****************************
 * Advinha o Cê
 * ----------------------------
 * Um jogo de advinhação de números
 * 
 * @author nathabonfim59
 ****************************/

/* Loop principal do jogo */
int main() {
    while (1)
    {
        int pontos = 1000;
        int ganhou = 0;
        int escolhaMenu = menu();
        int numeroSecreto = gerarNumeroSecreto();
        int limiteDeTentativas = menuDificuldade();

        for (int tentativa = 1; tentativa < limiteDeTentativas; tentativa++) {
            int chute = chutarNumero(tentativa, limiteDeTentativas);

            if (chute == numeroSecreto) {
                menuGanhou(pontos);
                ganhou = 1;
                break;
            } else if (chute > numeroSecreto) {
                pontos = menuDistancia(1, pontos);
            } else {
                pontos = menuDistancia(0, pontos);
            }
        }

        if (!ganhou) {
            menuPerdeu();
        }
    }
}

/* Menu principal do jogo */
int menu() {
    int escolhaMenu = 0;
    
    // Enquanto uma opção não for válida, exiba o menu
    while (!escolhaMenu) {
        printf("=------------------------=\n");
        printf("=-    Advinha o Cê v1   -=\n");
        printf("=------------------------=\n");
        printf("=  (1) Iniciar jogo\n");
        printf("=  (2) Como jogar\n");
        printf("=  (3) Sair\n");
        printf("\\________________________/\n");
        scanf("%d", &escolhaMenu);

        switch (escolhaMenu) {
            case 1:
                break;
            case 2:
                menuInstrucoes();
                escolhaMenu = 0;
                break;

            case 3:
                exit(0);
            
            default:
                escolhaMenu = 0;
                break;
        }

        limpaTela();
    }

    return escolhaMenu;
}

/** 
 * Escolha da dificuldade do jogo
 * 
 * > Retorna quantidade de tentativas de
 * acordo com a dificuldade
 */
int menuDificuldade() {
    int escolhaDificuldade;
    int dificuldadeEscolhida = 0;

    while (!dificuldadeEscolhida) {
        printf("/===========================\n");
        printf("| Escolha a dificuldade:\n");
        printf("|---------------------------\n");
        printf("|  (1) Fácil\n");
        printf("|  (2) Médio\n");
        printf("|  (3) Difícil\n");
        printf("/===========================\n");

        scanf("%d", &escolhaDificuldade);

        switch (escolhaDificuldade) {
        case 1:
            dificuldadeEscolhida = 20;
            break;
        case 2:
            dificuldadeEscolhida = 10;
            break;
        case 3:
            dificuldadeEscolhida = 6;
            break;
        
        default:
            dificuldadeEscolhida = 0;
            break;
        }
        
        limpaTela();
    }

    return dificuldadeEscolhida;
}

/* Exibe as instruções do jogo para o usuário */
void menuInstrucoes() {
    int pause = 0;

    limpaTela();
    printf("/===========================\n");
    printf("|>>>      INSTRUÇÕES     <<<\n");
    printf("|---------------------------\n");
    printf("| COMO FUNCIONA\n");
    printf("| ‾‾‾‾‾‾‾‾‾‾‾‾‾\n");
    printf("| Você precisa advinhar um\n");
    printf("| número secreto que será\n");
    printf("| escolhido aleatóriamente\n");
    printf("| pelo computador.\n");
    printf("| \n");
    printf("| PONTUAÇÃO\n");
    printf("| ‾‾‾‾‾‾‾‾‾‾\n");
    printf("| Todo jogador começa com\n");
    printf("| 1000 pontos que são \n");
    printf("| deduzidos de acordo com\n");
    printf("| os chutes realizados\n");
    printf("/===========================\n");
    scanf("%d", &pause);
}

/* Gera um número secreto para o usuário */
int gerarNumeroSecreto() {

    int escolhaIntervalo = 0;
    int intervaloEscolhido = 0;

    while (!intervaloEscolhido) {
        printf("/===========================\n");
        printf("| Escolha o intervalo:\n");
        printf("|---------------------------\n");
        printf("|  (1) 0 - 10\n");
        printf("|  (2) 0 - 100\n");
        printf("|  (3) 0 - 1000\n");
        printf("/===========================\n");

        scanf("%d", &escolhaIntervalo);

        switch (escolhaIntervalo)
        {
        case 1:
            intervaloEscolhido = 10;
            break;
        case 2:
            intervaloEscolhido = 100;
            break;
        case 3:
            intervaloEscolhido = 1000;
        
        default:
            intervaloEscolhido = 0;
            break;
        }

        limpaTela();
    }

    return intervaloEscolhido;
}

/* Limpa a tela do usuário */
void limpaTela() {
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}

/* Recebe a tentativa do usuário

   Retorna o número chutado
*/
int chutarNumero(int tentativa, int limiteDeTentativas) {
    limpaTela();

    int chute = 0;

    printf("/---------------------------\n");
    printf("|  Tentativa %d de %d\n", tentativa, limiteDeTentativas);
    printf("|---------------------------\n");
    printf("|-> ");
    scanf("%d", &chute);

    return chute;
}