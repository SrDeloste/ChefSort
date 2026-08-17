#include <stdio.h>

struct Comanda
{
    char nomePrato[50];
    int numeroComanda;
};

void recursiveInsertionSort(struct Comanda comandas[], int n)
{
    // Caso base
    if (n <= 1)
    {
        return;
    }

    // Ordena recursivamente as n - 1 primeiras comandas
    recursiveInsertionSort(comandas, n - 1);

    // Guarda a última comanda como chave
    struct Comanda chave = comandas[n - 1];

    // Começa pelo elemento anterior à chave
    int j = n - 2;

    // Move para a direita as comandas com número maior que a chave
    while (j >= 0 &&
           comandas[j].numeroComanda > chave.numeroComanda)
    {
        comandas[j + 1] = comandas[j];
        j--;
    }

    // Coloca a chave na posição correta
    comandas[j + 1] = chave;
}

int main()
{
    struct Comanda comandas[5] = {
        {"Lasanha", 45},
        {"Salada", 12},
        {"Hamburguer", 30},
        {"Omelete", 8},
        {"Strogonoff", 27}
    };

    printf("=== COMANDAS ANTES DA ORDENACAO ===\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%s - Comanda %d\n",
               comandas[i].nomePrato,
               comandas[i].numeroComanda);
    }

    // Ordena as comandas pelo numero
    recursiveInsertionSort(comandas, 5);

    printf("\n=== COMANDAS DEPOIS DA ORDENACAO ===\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%s - Comanda %d\n",
               comandas[i].nomePrato,
               comandas[i].numeroComanda);
    }

    return 0;
}