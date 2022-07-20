#include <stdio.h>
#include <stdlib.h>
//Vitor Witt Martin

int Busca(int arr[], int menor, int maior, int pesquisa);
void Preencher( int arr[5] );
void Organizar( int arr[5] );
void Imprimir( int arr[5]  );
void Pesquisar( int arr[5], int pesquisa );
int menu();



int BuscaBinaria(int arr[], int menor, int maior, int pesquisa) 
{ 
    if (maior >= menor) { 
        int meio = menor + (maior - menor) / 2; 
  
        if (arr[meio] == pesquisa) 
            return meio; 
        
        if (arr[meio] > pesquisa)  // elemento no lado esquerdo
            return BuscaBinaria(arr, menor, meio - 1, pesquisa); 
  
        return BuscaBinaria(arr, meio + 1, maior, pesquisa);  // elemento no lado direito
    } 
   
    return -1; 
} 


void Preencher( int arr[5] ) {
	
	int i, j, a;
	
	printf("\n");
	
	do {
		for (i=0; i<5; i++) 
			{
		
			printf("Digite o valor para a posicao %d : : ", i+1);	
			scanf("%d", &arr[i]);
			fflush(stdin);
			
			printf("\n");
		
			}
		
		} while (5>i);
}



void Organizar( int arr[5] ){
	
	int i, j,temp;

	for (i=0; i<5; i++) 
            for (j = i + 1; j < 5; ++j)
            {
                if (arr[i] > arr[j]) 

                {
                    temp =  arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
}

void Imprimir( int arr[5]  ){
	
	int i;
	printf("\n");
	
	for (i=0; i<5; i++) 
		printf(" %03d ", arr[i]);

	printf("\n\n");

}

void Pesquisar( int arr[5], int pesquisa  ){

	do{
		printf("\n Digite um valor para procurar, ou 0 para sair: ");
    	scanf("%d", &pesquisa);
    	fflush(stdin);
    
    	int resultado = BuscaBinaria(arr, (0) , (5 - 1), pesquisa); 
    	(resultado == -1) ? printf("\n O elemento %d nao foi encontrado dentro do array !!\n\n\n",pesquisa) 
                   	   	  : printf("\n O elemento %d esta no index %d !!!\n\n\n",pesquisa, resultado); 

	} while (pesquisa != 0); 

}


int Menu() {
	int op;

	do {
		printf("\n\n\n *** MENU ***\n");
		printf(" 1. Imprimir Array\n");
		printf(" 2. Pesquisar\n");
		printf(" 3. Sair\n");
		printf("\n Digite uma opcao: ");
		scanf(" %d", &op);
		fflush(stdin);
	} while (op<1 || op>3);
	
	return op;
}

  
int main() 
{
int pesquisa,op;
int arr[5];	
	
	Preencher(arr);
	Imprimir(arr);
	Organizar(arr);
	Imprimir(arr);
		
		do {
			op = Menu();
	
			switch (op) {
				case 1:
					Imprimir(arr);
					break;
				case 2:
					Pesquisar(arr, pesquisa);
					break;
					
						}
					
			} while (op!=3);
    return 0;
}



