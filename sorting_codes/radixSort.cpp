#include <iostream>

void printVector(int vector[], int size) 
{
    for(int i = 0; i < size; i++) 
    {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b; 
    *b = temp;
}

int numbits(int vector[], int l, int r) 
{
    int maximo = vector[l];
    for (int i = l + 1; i <= r; i++)
     {
        if (vector[i] > maximo) 
        {
            maximo = vector[i];
        }
    }
    
    // Calcula quantos bits são necessários para representar max_value
    int bits = 0;
    while (maximo > 0) {
        maximo >>= 1; // Desloca para a direita
        bits++;
    }
    
    return bits;
}

int bit(int i, int position) 
{
    return (i >> position) & 1;
}

void radixBits(int vector[], int l, int r, int position) 
{
    int i = l, j = r;
    
    if (r <= l || position < 0) return;
    
    while (j >= i) {
        while (i <= j && bit(vector[i], position) == 0) i++;
        while (i <= j && bit(vector[j], position) == 1) j--;
        
        if (i <= j) 
        {
            swap(&vector[i], &vector[j]);
            i++;
            j--;
        }
    }
    
    radixBits(vector, l, j, position - 1);
    radixBits(vector, i, r, position - 1);
}

void radixSort(int vector[], int l, int r)
{
    int bits = numbits(vector, l, r);
    radixBits(vector, l, r, bits - 1);
}

int main() 
{
    int v[] = {5, 2, 1, 0, 4, 3, 5, 6};
    int size = sizeof(v) / sizeof(v[0]);
    
    std::cout << "Original: ";
    printVector(v, size);
    
    radixSort(v, 0, size - 1);
    
    std::cout << "Ordenado: ";
    printVector(v, size);
    
    return 0;
}
