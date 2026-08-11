#include <stdio.h>
#include <string.h>

int main()
{
    char ingredientes[4][20] = {
        "Tomate",
        "Cebola",
        "Alho",
        "Cenoura"
    };

    char temporario[20];

    int comparacoes = 0;
    int trocas = 0;

    printf("Ingredientes antes da ordenacao:\n");

    for (int i = 0; i < 4; i++)
    {
        // Sem comparação, apenas imprime os ingredientes
        printf("%s\n", ingredientes[i]);
    }

    for (int passagem = 0; passagem < 3; passagem++)
    {
        for (int i = 0; i < 3 - passagem; i++)
        {
            // Conta toda comparação entre dois ingredientes vizinhos
            comparacoes++;

            if (strcmp(ingredientes[i], ingredientes[i + 1]) > 0)
            {
                // Troca os ingredientes de posição
                strcpy(temporario, ingredientes[i]);
                strcpy(ingredientes[i], ingredientes[i + 1]);
                strcpy(ingredientes[i + 1], temporario);

                // Conta apenas quando uma troca realmente acontece
                trocas++;
            }
        }
    }

    printf("\nIngredientes depois da ordenacao:\n");

    for (int i = 0; i < 4; i++)
    {
        printf("%s\n", ingredientes[i]);
    }

    printf("\nTotal de comparacoes: %d\n", comparacoes);
    printf("Total de trocas: %d\n", trocas);

    return 0;
}   
