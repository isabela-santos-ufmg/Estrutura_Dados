#include <iostream> 

void printVector(int vector[], int size)
{
    for(int i = 0; i < size; i++)
    {
        std::cout << vector[i] << std::endl;
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b; 
    *b = temp;
};


void quickSort(int vector[], int begin, int end)
{
    int i, j, pivot;
    i = begin;
    j = end - 1;
    pivot = vector[(begin + end)/2];
    while(i <= j)
    {
        // no lado esquerdo se é menor está okay e vai para o próximo 
        while(vector[i] < pivot && i < end)
        {
            i++;
        }
        // no lado direito ao pivõ, se é maior, está okay e continua andando
        while(vector[j] > pivot && j > begin)
        {
            j--;
        }
        // como o i anda quando é menor e j quando é maior, se ele continua sendo menor, 
        // quer dizer que o vetor ainda é maior que o j e precisa ser trocado  
        if(i <= j)
        {
            // quando o while nao acontece e para quer dizer que i e j devem ser trocados 
            swap(&vector[i], &vector[j]);
            i++;
            j--;
        }
        // apos esse processo, até o i serão os menores que pivo e do fim até o j serão maiores que o pivô
        // isso quer dizer que podemos chamar recursivamente a função para lados direito e esquerdo

        //Se j for maior que begin, significa que há elementos no subarray à esquerda do pivô que precisam ser ordenados.
        if(j > begin)
        {
            quickSort(vector, begin, j + 1); // inicio até começar os maiores (lado direito)
        }
        if(i < end)
        {
            quickSort(vector, i, end); // do ultimo menor até o fim que são os maiores (lado esquerdo)
        }
    }

};

int main()
{
    int v [] = {5, 2, 1, 0, 4, 3, 5, 6};
    
    std::cout << "Original: " << std::endl;
    printVector(v, std::size(v));
    quickSort(v, 0, std::size(v) - 1);
    std::cout << "Ordenado: " << std::endl;
    printVector(v, std::size(v));
    return 0;
}