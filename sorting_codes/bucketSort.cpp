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

int maximo(int vector[], int size)
{
  int max = vector[0];
  for (int i = 1; i < size; i++)
  {
    if (vector[i] > max)
    {
      max = vector[i];
    }
  }
  return max;
}

void bucketSort(int vector[], int size)
{
  int max = maximo(vector, size);
  int intervalo = (max + 1)/size;

  // vetor de vetores de size vetores 
  int **buckets = (int **)malloc(size * sizeof(int *));
  // tamanho de cada bucket porque pode acontecer de todos os elementos caberem em um só
  int *sizeBucket = (int *)malloc(size * sizeof(int));


  // inicializa os buckets 
  for(int i = 0; i < size; i++)
  {
    buckets[i] = (int *)malloc(size * sizeof(int));
  }


  // intervalo do bucket é (max+1)/size, esse é o critério
  // critério é de i até i + intervalo, se vector[?] tiver nisso, encaixa
  // como faço isso? pego vector[i]/ intervalo e arredondo para inteiro, encaixa nesse bucket

  for (int i = 0; i < size; ++i) {
     int index = vector[i]/intervalo;
     buckets[index][sizeBucket[index]] = vector[i];
     // incrementa o sizeBucket pois adicionou elemento
     sizeBucket[index]++;
  }

  for (int i = 0; i < size; ++i) 
  {
    if(sizeBucket[i] > 0)
    {
      insertionSort(buckets[i], sizeBucket[i]);
    }
  }

  int index = 0;
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < sizeBucket[i]; j++)
    {
      vector[index++] = buckets[i][j];
    }
    free(buckets[i]);
  }

  free(buckets);
  free(sizeBucket);
}

int main()
{
    int v [] = {5, 2, 1, 0, 4, 3, 6};
    
    std::cout << "Original: " << std::endl;
    printVector(v, std::size(v));
    bucketSort(v, std::size(v));
    std::cout << "Ordenado: " << std::endl;
    printVector(v, std::size(v));
    return 0;
}
