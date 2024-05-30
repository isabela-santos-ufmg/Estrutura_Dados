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

// funçao que de fato compara elemento da direita com esquerda e coloca no vetor já ordenando 
// as divisões do mergeSort
void merge( int vector[], int esquerda, int meio, int direita)
{
    // separar tamanho dos subvetores temporários 
    int sizeEsq = meio - esquerda + 1;
    int sizeDir = direita - meio;

    // criação dos subvetores temporários usados para comparações
    int vectorEsq[sizeEsq];
    int vectorDir[sizeDir];

    // colocar em cada posição do subvetor o conteúdo do vetor original 
    for(int i = 0; i < sizeEsq; i++)
    {
        vectorEsq[i] = vector[esquerda + i];
    }
    for(int j = 0; j < sizeDir; j++)
    {
        vectorDir[j] = vector[meio + 1 + j];
    }

    // Agora que foi copiado, vamos comparar esq x dir e colocar no original 

        // para poder andar entre os subvetores e vetor original, iniciamos os index

    int indexDir = 0; int indexEsq = 0; int indexVec = esquerda;

    while(indexEsq < sizeEsq && indexDir < sizeDir)
    {
        // o da esquerda ganha
        if(vectorEsq[indexEsq] <= vectorDir[indexDir])
        {
             vector[indexVec] = vectorEsq[indexEsq];
            indexEsq++;
        }
        // direita ganha
        else
        {
            vector[indexVec] = vectorDir[indexDir];
            indexDir++;
        }
        indexVec++; // proxima competição 
    }

    // Caso sobre elementos no array da esquerda, ou seja, o número de esquerda e direita nao eram iguais e sobrou 
    // maiores na esquerda, então colocaremos eles no final do array original

    while(indexEsq < sizeEsq)  // se ainda nao atingiu todo o vector
    {
        vector[indexVec] = vectorEsq[indexEsq];
        indexEsq++;
        indexVec++;
    }
     
    // para o caso de sobrar no da direita 

    while(indexDir < sizeDir)  // se ainda nao atingiu todo o vector
    {
        vector[indexVec] = vectorDir[indexDir];
        indexDir++;
        indexVec++;
    }
}

// chama o merge para ordenar divisões "imaginárias" do vetor
void mergeSort(int vector[], int inicio, int fim)
{
if(inicio < fim){
    int meio = (inicio + fim)/2;
    mergeSort(vector, inicio, meio);
    mergeSort(vector, meio + 1, fim);
    merge(vector, inicio, meio, fim);

}
}

int main()
{
    int v [] = {5, 2, 1, 0, 4, 3, 5, 6};
    
    std::cout << "Original: " << std::endl;
    printVector(v, std::size(v));
    mergeSort(v, 0, std::size(v) - 1);
    std::cout << "Ordenado: " << std::endl;
    printVector(v, std::size(v));
    return 0;
}

