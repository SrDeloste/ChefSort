#include <stdio.h>
//criação da "ficha" do prato
struct Prato
{
//criando o modelo do prato
    char nome[50];
    int quantidadeIngredientes;
};

int main()
{
//Prato e quantidade de ingredientes
    struct Prato pratos[5] = {
        {"Lasanha", 8},
        {"Salada", 4},
        {"Hamburguer", 6},
        {"Omelete", 3},
        {"Strogonoff", 7}};

    printf("=== PRATOS ANTES DA ORDENACAO ===\n");
//Apenas pra mostrar os pratos
    for (int i = 0; i < 5; i++)
    {
        printf("%s - %d ingredientes\n",
               pratos[i].nome,
               pratos[i].quantidadeIngredientes);
    } 

    // Selection Sort
    for (int i = 0; i < 4; i++)
    {
//i escolhe a posição → min_idx lembra o menor → j procura → if compara → troca.
        int min_idx = i;
        //Guarda temporariamente o prato com menos ingredientes na primeira verificação

        for (int j = i + 1; j < 5; j++)
//Procura o Menor
        {
            if (pratos[j].quantidadeIngredientes <
                pratos[min_idx].quantidadeIngredientes)
            {

                min_idx = j;
            }
        }

        if (min_idx != i) //troca
        {

            struct Prato temp = pratos[i]; //Compara a quantidade, movimenta o prato inteiro.
            pratos[i] = pratos[min_idx];
            pratos[min_idx] = temp;
        } //Variavel temporaria
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
