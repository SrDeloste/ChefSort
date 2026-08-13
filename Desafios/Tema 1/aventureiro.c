#include <stdio.h>
//criação da "ficha" do prato
struct Prato
{
    char nome[50];
    int quantidadeIngredientes;
};

int main()
{

    struct Prato pratos[5] = {
        {"Lasanha", 8},
        {"Salada", 4},
        {"Hamburguer", 6},
        {"Omelete", 3},
        {"Strogonoff", 7}};

    printf("=== PRATOS ANTES DA ORDENACAO ===\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%s - %d ingredientes\n",
               pratos[i].nome,
               pratos[i].quantidadeIngredientes);
    }

    // Selection Sort
    for (int i = 0; i < 4; i++)
    {

        int min_idx = i;

        for (int j = i + 1; j < 5; j++)
        {

            if (pratos[j].quantidadeIngredientes <
                pratos[min_idx].quantidadeIngredientes)
            {

                min_idx = j;
            }
        }

        if (min_idx != i)
        {

            struct Prato temp = pratos[i];
            pratos[i] = pratos[min_idx];
            pratos[min_idx] = temp;
        }
    }

    printf("\n=== PRATOS DEPOIS DA ORDENACAO ===\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%s - %d ingredientes\n",
               pratos[i].nome,
               pratos[i].quantidadeIngredientes);
    }

    return 0;
}