#include <stdio.h>
#include <math.h>
#define MAX 100

void subir (int i, int n, int heap[n]){
    int aux;
    int p = i/2;
    if (p >= 1){
        if(heap[p]<heap[i]){
            aux = heap[p];
            heap[p] = heap[i];
            heap[i] = aux;
            subir(p,n,heap);
        }
    }
}

void descer(int i, int n, int heap[n]){
    int aux;
    int f = 2*i;

    if (f<=n){
        if (f<n){
            if(heap[f] < heap[f+1]){
                f = f+1;
            }
        }
        if (heap[i]< heap[f]){
            aux = heap[i];
            heap[i] = heap[f];
            heap[f] = aux;
            descer(f,n,heap);
        }
    }
}

void inserir(int n, int novo, int heap[n+1]){
    if (n < MAX){
        heap[n+1] = novo;
        n++;
        subir(n,n,heap);

        printf("\n HEAP:");
        imprimir(n,heap);

    }else{
        printf("Overflow");
    }

}

void remover(int n, int heap[n]){
    if (n>0){
        printf("O numero removido foi:%d",heap[1]);
        heap[1]=heap[n];
        n--;
        descer(1,n,heap);

        printf("\n HEAP:");
        imprimir(n,heap);

    }else{
        printf("Underflow");
    }

}

void construir(int n, int heap[n]){
    int i;
    for(i=n/2; i>0; i--){
        descer(i,n,heap);
    }
    printf("\n HEAP:");
    imprimir(n,heap);
}

void heapSort(int n, int heap[n]){
    int i;
    int aux;

    printf("\n HEAP:");
    imprimir(n,heap);
    //construir(n,heap);
    for(i=n; i>=2; i--){
        aux = heap[i];
        heap[i] = heap[1];
        heap[1] = aux;
        descer(1,i-1,heap);
    }
    printf("\n HEAP_SORT:");
    imprimir(n,heap);
}

void imprimir(int n, int heap[n]){
    int i;
    int aux=1;
    printf("\n");
    for(i=1;i<=n;i++){
        if (i == pow(2,(aux-1))){
            printf("\n");
            aux++;
        }
        printf("[%d]",heap[i]);
    }
}

int main(){
    int heap[MAX];
    int n=8;
    int opc = 1;
    int i;

    heap[0] = 0;
    heap[1] = 95;
    heap[2] = 60;
    heap[3] = 78;
    heap[4] = 39;
    heap[5] = 28;
    heap[6] = 66;
    heap[7] = 70;
    heap[8] = 33;


    while( opc!=6){
        printf("\n\n");
        printf("\n _____|MAXIMO|_____");
        printf("\n|                  |");
        printf("\n|  1 - Construir   |");
        printf("\n|  2 - Inserir     |");
        printf("\n|  3 - Remover     |");
        printf("\n|  4 - HeapSort    |");
        printf("\n|  5 - Imprimir    |");
        printf("\n|  6 - Sair        |");
        printf("\n|__________________|\n");

        scanf("%d",&opc);

        switch(opc){

            case 1:{
                int i;
                printf("\n Digite a quantidade de numeros ate 100");
                scanf("%d",&n);
                for (i=1;i<=n;i++){
                    printf("\n Digite o %d:",i);
                    scanf("%d",&heap[i]);
                }
                construir(n,heap);
                break;
            }
            case 2:{
                int novo;
                printf("\n Digite o novo numero");
                scanf("%d",&novo);
                inserir(n, novo, heap);
                n++;
                break;
            }
            case 3:{
                remover(n,heap);
                n--;
                break;
            }
            case 4:{
                heapSort(n,heap);
                break;
            }
            case 5:{
                imprimir(n,heap);
                break;
            }
            default:{
               //clescr();
               if(opc == 6){
                printf("\n Ate logo");
                continue;
               }
               printf("\n Digite uma das opções");
               break;
            }

        }
    }

}
