#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char mt[3][3];

void tabuleiro()
{

    int l, c;

    for (l = 0; l < 3; l++)
    {
        for (c = 0; c < 3; c++)
        {
            mt[l][c] = ' ';
        }
    }
}

void mostrar_tabuleiro()
{

    int l, c;

    printf("\n\n");

    printf("\n   0      1      2\n\n");

    for (l = 0; l < 3; l++)
    {
        printf("%d ", l);

        for (c = 0; c < 3; c++)
        {
            printf("   %c", mt[l][c]);
            if (c < 2)
            {
                printf(" |");
            }
        }
        printf("\n");
    }
}

void vencedor()
{
    // Linhas X
    for (int i = 0; i < 3; i++)
    {
        if (mt[i][0] == 'X' && mt[i][1] == 'X' && mt[i][2] == 'X')
        {
            printf("\n\nParabens voce venceu!");
            exit(0);
        }
    }

    // Colunas X
    for (int j = 0; j < 3; j++)
    {
        if (mt[0][j] == 'X' && mt[1][j] == 'X' && mt[2][j] == 'X')
        {
            printf("\n\nParabens voce venceu!");
            exit(0);
        }
    }

    // diagonal principal X

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (mt[0][0] == 'X' && mt[1][1] == 'X' && mt[2][2] == 'X')
            {
                printf("\n\nParabens voce venceu!");
                exit(0);
            }
        }
    }

    // Linhas O
    for (int i = 0; i < 3; i++)
    {
        if (mt[i][0] == 'O' && mt[i][1] == 'O' && mt[i][2] == 'O')
        {
            printf("\n\nParabens voce venceu!");
            exit(0);
        }
    }

    // Colunas O
    for (int j = 0; j < 3; j++)
    {
        if (mt[0][j] == 'O' && mt[1][j] == 'O' && mt[2][j] == 'O')
        {
            printf("\n\nParabens voce venceu!");
            exit(0);
        }
    }

     // diagonal principal O

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (mt[0][0] == 'O' && mt[1][1] == 'O' && mt[2][2] == 'O')
            {
                printf("\n\nParabens voce venceu!");
                exit(0);
            }
        }
    }
}

int main()
{
    system("chcp 65001 > NUL");

    int e1, e2, e3, e4;
    int ganhou = 0;
    int l, c;
    int aux[3][3];

    tabuleiro();

    do
    {
        mostrar_tabuleiro();

        printf("\nprimeiro jogador:");
        printf("\nDigite em qual linha você deseja jogar: ");
        scanf("%d", &e1);
        printf("Digite em qual coluna você deseja jogar: ");
        scanf("%d", &e2);

        if (e1 >= 0 && e1 < 3 && e2 >= 0 && e2 < 3)
        {
            if (mt[e1][e2] == ' ')
            {
                mt[e1][e2] = 'X';
                mostrar_tabuleiro();
                vencedor();
            }
            else
            {
                printf("\nA posição %d%d já está ocupada. Perdeu a vez.\n", e1, e2);
            }
        }
        else
        {
            printf("\nPosição inválida. Perdeu a vez.\n");
        }

        printf("\nSegundo jogador:");
        printf("\nDigite em qual linha você deseja jogar: ");
        scanf("%d", &e3);
        printf("Digite em qual coluna você deseja jogar: ");
        scanf("%d", &e4);

        if (e3 >= 0 && e3 < 3 && e4 >= 0 && e4 < 3)
        {
            if (mt[e3][e4] == ' ')
            {
                mt[e3][e4] = 'O';
                vencedor();
            }
            else
            {
                printf("\nA posição %d%d já está ocupada. Perdeu a vez.\n", e3, e4);
            }
        }
        else
        {
            printf("\nPosição inválida. Perdeu a vez.\n");
        }

    } while (1);
}
