#include <iostream> 

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b; 
    *b = temp;
}

void bubbleSort(int vector[], int size)
{
    // passa pelo vetor (subtrai um porque nao precisa ver o ultimo)
    for(int i = 0; i < size - 1; i++)
    {
        // passa por todos o anterior e subtrai o que já verificou no for anterior
        for(int j = 1; j < size - i; j++)
        {
            // se o elemento for menor que o anterior, trocamos
            if(vector[j] < vector[j - 1])
            {
                swap(&vector[j], &vector[j - 1]);
            }
        }
    }
}

int main()
{
    int v [] = {5, 2, 1, 0, 4, 3, 5, 6};
    
    std::cout << "Original: " << std::endl;
    for(int i = 0; i < std::size(v); i++)
    {
        std::cout << v[i] << std::endl;

    }
    bubbleSort(v, std::size(v));
    std::cout << "Ordenado: " << std::endl;
    for(int i = 0; i < std::size(v); i++)
    {
        std::cout << v[i] << std::endl;

    }
    return 0;
}