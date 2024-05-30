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

    // anda as ocorrências para frente, ao final, o conteúdo é onde o index começa no ordenado
    // está pecorrendo o original
    for(int k = size - 1; k >= 0; k--)
    {
        ordenado[contador[vector[k]] - 1] = vector[k];   // o conteudo do index anterior é a posição da ultima ocorrencia do numero do original
        --contador[vector[k]];                           // decrementa 1 pois será a posição da outra ocorrência (a anterior) até chegar na primeira ocorrência
    }
    // copiar do ordenado temporário para o vetor original 
    for(int l = 0; l < size; l++)
    {
        vector[l] = ordenado[l];
    }

}

int main()
{
    int v [] = {6, 1, 0, 1, 1, 2, 2, 4, 4, 4, 5};
    int max = 6;

    std::cout << "Original: " << std::endl;
    printVector(v, std::size(v));
    countingSort(v, std::size(v), max);
    std::cout << "Ordenado: " << std::endl;
    printVector(v, std::size(v));
    return 0;
}

/*a adição do anterior no numero de ocorrencias é uma forma de saber onde 
o numero vai começar no vetor final, onde estará a ultima ocorrencia

nao é esse valor exato da incrementação ainda.

vamos pecorrer esse vetor de ocorrencias ao contrario
e preencher o ordenado do maior para o menor 

Mas, no caso, o valor do indice escolhido será a ocorrencia do anterior 

agora sim, serão os index de onde começam 


por exemplo, o index max é o 3 e ficou com 4 no vetor ocorrencia
isso quer dizer que há 4 elementos antes dele então podemos pensar que no 
vetor de ocorrencias inicial, a soma das ocorrencias dos anteriores era 4

por isso a gente soma com o anterior e passa para frente 

---------

mas como colocar no vetor ordenado temporário?
pecorremos do inicio do vetor original analisando qual o index de onde começa(vetor de ocorrencia)

coloca no index do ordenado temporario e soma 1, então coloca o proximo na outra posição
incrementa até chegar no prox index do contador.e vai para o proximo elemento do vetor original */