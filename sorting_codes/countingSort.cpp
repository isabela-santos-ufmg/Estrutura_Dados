#include <iostream>

void printVector(int vector[], int size)
{
    for(int i = 0; i < size; i++)
    {
        std::cout << vector[i] << std::endl;
    }
}

void countingSort(int vector[], int size, int max)
{
    int contador[max + 1] = {0};
    int ordenado[size] = {0};
    for(int i = 0; i < size; i++)
    {
        // o conteudo de indice igual ao valor do vetor é incrementado pois representa ocorrencia do index
        contador[vector[i]]++;
    }

    // acrescenta a partir do segundo elemento ocorrencia do anterior
    for(int j = 1; j < max + 1; j++)
    {
        contador[j] += contador[j - 1]; 
    }

    // posição do ordenado que é a ocorrencia do vetor olhado - 1 (para dar valor exato) será colocado o vetor olhado
    for(int k = size - 1; k >= 0; k--)
    {
        ordenado[contador[vector[k]] - 1] = vector[k];
        --contador[vector[k]];
    }
    // copiar do ordenado temporário para o vetor original 
    for(int l = 0; l < size; l++)
    {
        vector[l] = ordenado[l];
    }

}

int main()
{
    int v [] = {5, 2, 1, 0, 4, 3, 5, 6};
    int max = 6;

    std::cout << "Original: " << std::endl;
    printVector(v, std::size(v));
    countingSort(v, std::size(v), max);
    std::cout << "Ordenado: " << std::endl;
    printVector(v, std::size(v));
    return 0;
}