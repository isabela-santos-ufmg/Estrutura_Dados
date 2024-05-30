#include <iostream>

void printVector(int vector[], int size)
{
    for(int i = 0; i < size; i++)
    {
        std::cout << vector[i] << std::endl;
    }
};

void insertionSort(int vector[], int size)
{
    for(int i = 1; i < size; i++)
    {
        int aux = vector[i];
        int j = i - 1;
        while( j >= 0 && aux < vector[j])
        {
            vector[j + 1] = vector[j];
            j--;
        }
        vector[j + 1] = aux;
    }
};

int main()
{
    int v [] = {5, 2, 1, 0, 4, 3, 6};
    
    std::cout << "Original: " << std::endl;
    printVector(v, std::size(v));
    insertionSort(v, std::size(v));
    std::cout << "Ordenado: " << std::endl;
    printVector(v, std::size(v));
    return 0;
}