#include <iostream>

void printVector(int vector[], int size)
{
    for(int i = 0; i < size; i++)
    {
        std::cout << vector[i] << std::endl;
    }
};

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
};

void selectionSort( int vector[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        int min = i;
        for(int j = i + 1; j < size; j++)
        {
            if(vector[min] > vector[j])
            {
                min = j;
            }
        }
        if (i != min)
        {
            swap(&vector[i], &vector[min]);
        }
    }
};

int main()
{
    int v [] = {5, 2, 1, 0, 4, 3, 6};
    
    std::cout << "Original: " << std::endl;
    printVector(v, std::size(v));
    selectionSort(v, std::size(v));
    std::cout << "Ordenado: " << std::endl;
    printVector(v, std::size(v));
    return 0;
}