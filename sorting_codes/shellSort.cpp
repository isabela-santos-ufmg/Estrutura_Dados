#include <iostream> 

void printVector(int vector[], int size)
{
    for(int i = 0; i < size; i++)
    {
        std::cout << vector[i] << std::endl;
    }
}

void shellSort(int vector[], int size)
{
// vamos fazer as ordenações na forma do insertion usando gaps que irão reduzindo nesse
// for de fora 
    for(int gap = size/2; gap > 0; gap /=2)
    {
        // para cada elemento a partir do gap para frente
        for(int i = gap; i < size; i++)
        {
            // fazemos um insertion sort
                // definindo a carta que iremos começar
            int temp = vector[i];
            int j;
            // se o elemento que está a uma distância gap do atual(temp), então trocamaos as posições 
            // j seria para analisar o elemento atual e j-gap o elemento que compararemos, mas usamos j pra conseguir pecorrer o vetor
            for(j = i; j >= gap && vector[j - gap] > temp; j-= gap)
            {
                vector[j] = vector[j - gap];

            }
            vector[j] = temp;
        }
    }
}

int main()
{
    int v [] = {5, 2, 1, 0, 4, 3, 5, 6};
    
    std::cout << "Original: " << std::endl;
    printVector(v, std::size(v));
    shellSort(v, std::size(v));
    std::cout << "Ordenado: " << std::endl;
    printVector(v, std::size(v));
    return 0;
}