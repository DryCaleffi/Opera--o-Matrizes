#include <stdio.h>
#include <stdlib.h>
// ATIVIDADE 4
//Operação com matrizes
// NOME 1: Adryelle caroline de souza Calefi

// uma função para perguntar ao usuário o tamanho da matriz
void pergunta(int *alinha, int *acoluna, int *blinha, int *bcoluna) {
    int a, b;
    printf(" Informe o número de linhas e colunas do vetor a: ");
    printf("\nLinha: ");
    scanf("%d", &a);
    printf("\nColunas: ");
    scanf("%d", &b);
    *alinha = a;
    *acoluna = b;
    printf("\n Informe o números de linhas e colunas do vetor b: ");
    printf("\nLinha: ");
    scanf("%d", &a);
    printf("\nColunas: ");
    scanf("%d", &b);
    *blinha = a;
    *bcoluna = b;
}
// depois de perhuntar , começar operações , soma 
// testar para ver se a soma é possivel
void somamatrizes(int alinha, int acoluna, int blinha, int bcoluna, int **veta, int **vetb) {
    int **soma = malloc(alinha * sizeof(int *));
    for (int i = 0; i < alinha; i++) {
        soma[i] = malloc(bcoluna * sizeof(int));
    }

    int i, j;
    if (alinha == blinha && acoluna == bcoluna) {
        for (i = 0; i < alinha; i++) {
            for (j = 0; j < bcoluna; j++) {
                soma[i][j] = veta[i][j] + vetb[i][j];
            }
        }
    } else {
        printf("\n A soma não pode ser realizada veriique o valores informados , para a realização da soma as matrizes devem ser quadradas.");
        return;
    }
    for (i = 0; i < alinha; i++) {
        for (j = 0; j < bcoluna; j++) {
            printf("%d |", soma[i][j]);
        }
        printf("\n");
    }


    for (i = 0; i < alinha; i++) {
        free(soma[i]);
    }
    free(soma);
}
//Subtração , teste para ver se é possivel , depois realizar conta 
void subv(int al, int ac, int bl, int bc, int **veta, int **vetb) {
    int **sub = malloc(al * sizeof(int *));
    for (int i = 0; i < al; i++) {
        sub[i] = malloc(bc * sizeof(int));
    }

    int i, j;
    if (al == bl && ac == bc) {
        for (i = 0; i < al; i++) {
            for (j = 0; j < bc; j++) {
                sub[i][j] = veta[i][j] - vetb[i][j];
            }
        }
    } else {
        printf("-1\n");
        return;
    }
    for (i = 0; i < al; i++) {
        for (j = 0; j < bc; j++) {
            printf("%d |", sub[i][j]);
        }
        printf("\n");
    }


    for (i = 0; i < al; i++) {
        free(sub[i]);
    }
    free(sub);
}
void multiplicacaov(int al, int ac, int bl, int bc, int **veta, int **vetb) {
    if (ac == bl) {
        int **res = malloc(al * sizeof(int *));
        for (int i = 0; i < al; i++) {
            res[i] = malloc(bc * sizeof(int));
        }

        for (int i = 0; i < al; i++) {
            for (int j = 0; j < bc; j++) {
                res[i][j] = 0;
                for (int k = 0; k < ac; k++) {
                    res[i][j] += veta[i][k] * vetb[k][j];
                }
            }
        }
        for (int i = 0; i < al; i++) {
            for (int j = 0; j < bc; j++) {
                printf("%d |", res[i][j]);
            }
            printf("\n");
        }


        for (int i = 0; i < al; i++) {
            free(res[i]);
        }
        free(res);
    } else {
        printf("-1\n");
    }

}


int main(void) {
    int al, ac, bl, bc, i, j, a, b, opcao;
    printf("Menu de operações com matrizes \n");
    printf("1 - Soma\n");
    printf("2 - Subtração\n");
    printf("3 - Multiplicação\n");
    printf("4 - Determinante\n");
    printf("5 - Sair\n");

    int **veta, **vetb; 

    do {
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("Soma\n");
            pergunta(&al, &ac, &bl, &bc);
            printf("Vetor a:\n");


            veta = malloc(al * sizeof(int *));
            for (i = 0; i < al; i++) {
                veta[i] = malloc(ac * sizeof(int));
            }

            for (i = 0; i < al; i++) {
                for (j = 0; j < ac; j++) {
                    veta[i][j] = rand() % 10;
                    printf("%d |", veta[i][j]);
                }
                printf("\n");
            }
            printf("\nVetor b:\n");


            vetb = malloc(bl * sizeof(int *));
            for (i = 0; i < bl; i++) {
                vetb[i] = malloc(bc * sizeof(int));
            }

            for (i = 0; i < bl; i++) {
                for (j = 0; j < bc; j++) {
                    vetb[i][j] = rand() % 10;
                    printf("%d |", vetb[i][j]);
                }
                printf("\n");
            }
            printf("\n------------------------\n");
            printf("Vetor a + b:\n");
            somamatrizes(al, ac, bl, bc, veta, vetb);


            for (i = 0; i < al; i++) {
                free(veta[i]);
            }
            free(veta);

            for (i = 0; i < bl; i++) {
                free(vetb[i]);
            }
            free(vetb);
            break;

        case 2:
            printf("Subtração\n");
            pergunta(&al, &ac, &bl, &bc);
            printf("\n------------------------\n");
            printf("Vetor a:\n");


            veta = malloc(al * sizeof(int *));
            for (i = 0; i < al; i++) {
                veta[i] = malloc(ac * sizeof(int));
            }

            for (i = 0; i < al; i++) {
                for (j = 0; j < ac; j++) {
                    veta[i][j] = rand() % 10;
                    printf("%d |", veta[i][j]);
                }
                printf("\n");
            }
            printf("\n------------------------");
            printf("\nVetor b:\n");


            vetb = malloc(bl * sizeof(int *));
            for (i = 0; i < bl; i++) {
                vetb[i] = malloc(bc * sizeof(int));
            }

            for (i = 0; i < bl; i++) {
                for (j = 0; j < bc; j++) {
                    vetb[i][j] = rand() % 10;
                    printf("%d |", vetb[i][j]);
                }
                printf("\n");
            }
            printf("\n------------------------\n");
            printf("Vetor a - b:\n");
            subv(al, ac, bl, bc, veta, vetb);


            for (i = 0; i < al; i++) {
                free(veta[i]);
            }
            free(veta);

            for (i = 0; i < bl; i++) {
                free(vetb[i]);
            }
            free(vetb);
            break;

        case 3:
            printf("Multiplicação\n");
            pergunta(&al, &ac, &bl, &bc);
            printf("\n------------------------\n");
            printf("Vetor a:\n");


            veta = malloc(al * sizeof(int *));
            for (i = 0; i < al; i++) {
                veta[i] = malloc(ac * sizeof(int));
            }

            for (i = 0; i < al; i++) {
                for (j = 0; j < ac; j++) {
                    veta[i][j] = rand() % 10;
                    printf("%d |", veta[i][j]);
                }
                printf("\n");
            }
            printf("\n------------------------");
            printf("\nVetor b:\n");


            vetb = malloc(bl * sizeof(int *));
            for (i = 0; i < bl; i++) {
                vetb[i] = malloc(bc * sizeof(int));
            }

            for (i = 0; i < bl; i++) {
                for (j = 0; j < bc; j++) {
                    vetb[i][j] = rand() % 10;
                    printf("%d |", vetb[i][j]);
                }
                printf("\n");
            }
            printf("\n------------------------\n");
            printf("Vetor a * b:\n");
            multiplicacaov(al, ac, bl, bc, veta, vetb);


            for (i = 0; i < al; i++) {
                free(veta[i]);
            }
            free(veta);

            for (i = 0; i < bl; i++) {
                free(vetb[i]);
            }
            free(vetb);
            break;

          case 4:
          printf("Determinante\n");
          printf("Não foi desenvolvido ");
  

        case 5:
            printf("Encerrando o programa.\n");
            break;

        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}
