#include <stdio.h>
#include <math.h>
#define MAX 100

struct Array{
    int chave;
    int estado;
    int pont;
};

struct Array* T[MAX];
int a;
int end;
int j;
int dig1;
int dig2;

int h(int met, int chave){
    switch(met){
        case 1:{
            return div(chave);
            break;
        }
        case 2:{
            return dob(met,chave);
            break;
        }
        case 3:{
            return dob(met,chave);
            break;
        }
        case 4:{
            return dob(met,chave);
            break;
        }
        case 5:{
            return dob(met,chave);
            break;
        }
        case 6:{
            return mul(chave);
            break;
        }
        case 7:{

            return ana(met,chave);
            break;
        }
        case 8:{
            return ana(met,chave);
            break;
        }

        default:{

            break;
        }
    }


}

int div(int chave){
    return chave % MAX;
}

int dob(int met,int chave){
    int d = 2;
    int x = chave;
    int tam = 1;

    while (x>0){
        x = x/10;
        tam++;
    }
    x = chave;
    int v[tam];
    int i = tam-1;
    while(i>0){
        v[i] = x % 10;
        x = x / 10;
        i--;
    }

    switch(met){
        case 2:{
            i = 5;
            while(i<tam){
                printf("\n%d e %d ==",v[i],v[i-4]);
                v[i] = (v[i] && v[i-4]);
                printf("\nv[%d]=%d",i,v[i]);
                i++;
            }
            break;
        }
        case 3:{
            i = 5;
            while(i<tam){
                printf("\n%d ou %d ==",v[i],v[i-4]);
                v[i] = v[i] || v[i-4];
                printf("\nv[%d]=%d",i,v[i]);
                i++;
            }
            break;
        }
        case 4:{
            i = 5;
            while(i<tam){
                printf("\n%d oux %d ==",v[i],v[i-4]);
                v[i] = v[i] ^ v[i-4];
                printf("\nv[%d]=%d",i,v[i]);
                i++;
            }
            break;

        }

        default:{
            i = 3;
            while(i<tam){
                v[i] = (v[i]+v[i-1])%10;
                if (i==tam-1){
                    v[i-1] = v[i];
                    v[i] = v[i-2];
                    i++;
                }else{
                    i++;
                    v[i] = (v[i]+v[i-3])%10;
                    i++;
                }

            }
            chave = v[tam - 2] * 10;
            chave =  chave + v[tam-1];

            return chave;
            break;
        }
    }
    chave = (v[tam-1]*1) + (v[tam-2]*2) + (v[tam-3]*4) +(v[tam-4]*8);
    return chave;


}

int mul(int chave){
    int tam = 1;
    int quad = chave * chave;
    int x = quad;
    while (x>0){
        x = x/10;
        tam++;
    }
    int v[tam];
    int i = tam-1;
    x = quad;
    while(i>0){
        v[i] = x % 10;
        x = x / 10;
        i--;
    }
    i = (tam-3)/2;
    chave = v[i+1] * 10;
    chave =  chave + v[i+2];

    return chave;

}

int ana(int met,int num){
    return reduz(num);
}

int reduz(int num){
        int vchave[5];
        vchave[4]=num%10;
        num =num/10;
        vchave[3]=num%10;
        num =num/10;
        vchave[2]=num%10;
        num =num/10;
        vchave[1]=num%10;
        num =num/10;
        vchave[0]=num%10;

        num=vchave[dig1] *10;
        num = num+vchave[dig2];

        return num;

}

int calculaDigito(int met, int vetor[]){
    int d1[10];
    int d2[10];
    int d3[10];
    int d4[10];
    int d5[10];

    int i = 0;
    while(i<10){
        d1[i]=0;
        d2[i]=0;
        d3[i]=0;
        d4[i]=0;
        d5[i]=0;
        i++;
    }

    i=0;
    int m=0;
    while(i<10){
            m++;
            int x = vetor[i];
            d5[x%10]++;
            x =x/10;
            d4[x%10]++;
            x =x/10;
            d3[x%10]++;
            x =x/10;
            d2[x%10]++;
            x =x/10;
            d1[x%10]++;

        i++;
    }

    int x[5];
    x[0]=0;
    x[1]=0;
    x[2]=0;
    x[3]=0;
    x[4]=0;

        switch(met){
            case 7:{
                int j;
                for (j=0;j<10;j++){
                    x[0] = x[0] +(d1[j] - m/10)*(d1[j] - m/10);
                    x[1] = x[1] +(d2[j] - m/10)*(d2[j] - m/10);
                    x[2] = x[2] +(d3[j] - m/10)*(d3[j] - m/10);
                    x[3] = x[3] +(d4[j] - m/10)*(d4[j] - m/10);
                    x[4] = x[4] +(d5[j] - m/10)*(d5[j] - m/10);
                }

                break;
            }
            default:{
                int j;
                for (j=0;j<10;j++){
                    x[0] = x[0] + abs(d1[j] - m/10);
                    x[1] = x[1] + abs(d2[j] - m/10);
                    x[2] = x[2] + abs(d3[j] - m/10);
                    x[3] = x[2] + abs(d4[j] - m/10);
                    x[4] = x[2] + abs(d5[j] - m/10);
                }
                break;
            }

        }
        printf("x[0]=%d x[1]=%d x[2]=%d x[3]=%d x[4]=%d\n",x[0],x[1],x[2],x[3],x[4]);
        int menor1=x[0];
        dig1=0;
        int menor2=x[1];
        dig2=1;

        for(i=2;i<5;i++){
            if(x[i]<menor1){
                menor1=x[i];
                dig1=i;
            }else if(x[i]<menor2){
                menor2=x[i];
                dig2=i;
            }

        }

        if(dig2<dig1){
            int aux=dig2;
            dig2=dig1;
            dig1=aux;
        }
        printf("dig1=%d\n",dig1+1);
        printf("dig2=%d\n",dig2+1);
}

int buscar(int met,int x){
    int n=MAX;
    a = 0;
    int fh = h(met,x);
    end = fh;
    j = -1;
    while(a==0){
        if (T[end]->estado == 0){
            j  = end;
        }
        if (T[end]->chave == x && T[end]->estado == 1){
            a  = 1;
        }else{
            end = T[end]->pont;
            if (end == fh){
                a = 2;
                end=j;
            }
        }
    }
}

int insert(int met,int x){
    int i;
    buscar(met,x);
    int fh = h(met,x);
    if(a ==1){
        printf("elemento existe");
        return 1;
    }else if(end != -1){
            j = end;
        }else{
            i = 1;
            j = fh;
            while(i<=MAX){
                if(T[j]->estado == 1){
                    j = (j+1)%MAX;
                    i = i+1;
                }else{
                    i = MAX+2;
                }
            }
        if(i == MAX+1){
            printf("NÃO TEM ESPAÇO");
        }else{

            int aux = T[fh]->pont;
            T[fh]->pont = T[j]->pont;
            T[j]->pont = aux;
        }
        }
        T[j]->chave=x;
        T[j]->estado=1;

        return 0;
}

void imprimir(int n){
    int i;
    for(i=0; i<n; i++){
        if(i%10 == 0){
            printf(" \n");
        }
        if(i<10){
            //printf("0%d-(%d)->%d  ", i, T[i]->chave, T[i]->pont);
            printf("0%d-(%d)   ", i, T[i]->chave);
            continue;
        }
        if(T[i]!= -1 ){
            //printf("%d-(%d)->%d  ", i, T[i]->chave,  T[i]->pont);
            printf("%d-(%d)   ", i, T[i]->chave);
        }else{
            printf("%d(-)   ", i);
        }
    }

}

void iniciar(){
    int i;
    for (i=0; i<MAX; i++){
        struct Array *hashArray = (struct Array*) malloc(sizeof(struct Array));
        hashArray->chave = -1;
        hashArray->estado = 0;
        hashArray->pont =i;
        T[i] = hashArray;
    }
}

int main(){
    int n=MAX;
    int met = 1;
    int opc = 1;
    int chave;
    int i;
    iniciar();

    while( met!=9){
        met = 1;
        printf("\n\n");
        printf("\n ______________|INTERIOR|______________");
        printf("\n|                                      |");
        printf("\n|  1 - Metodo da divisao               |");
        printf("\n|  2 - Metodo da dobra : e             |");
        printf("\n|  3 - Metodo da dobra : ou            |");
        printf("\n|  4 - Metodo da dobra : oux           |");
        printf("\n|  5 - Metodo da dobra : num           |");
        printf("\n|  6 - Metodo da Multiplicacao         |");
        printf("\n|  7 - Metodo da analise de digitos I  |");
        printf("\n|  8 - Metodo da analise de digitos II |");
        printf("\n|  9 - Sair                            |");
        printf("\n|______________________________________|\n");

        scanf("%d",&met);

        opc=1;

        while( opc!=5){
            printf("\n\n");
            printf("\n ___|INTERIOR|___");
            printf("\n|                |");
            printf("\n|  1 - Buscar    |");
            printf("\n|  2 - Inserir   |");
            printf("\n|  3 - Remover   |");
            printf("\n|  4 - Imprimir  |");
            printf("\n|  5 - Voltar    |");
            printf("\n|________________|\n");

            scanf("%d",&opc);

            switch(opc){

                case 1:{
                    int i;
                    printf("\n Digite a chave");
                    scanf("%d",&chave);
                    buscar(met,chave);
                    if(a==2){
                        printf("Chave nao encontrada!");
                    }else{
                        printf("Chave ta na posicao %d",end);
                    }
                    break;
                }
                case 2:{
                    int i;
                    if (met!=7 && met!=8){
                        printf("\n Digite a chave");
                        scanf("%d",&chave);
                        insert(met,chave);
                    }else{
                        int tam=10;
                        int vetor[tam];
                        vetor[0]=681;
                        vetor[1]=724;
                        vetor[2]=347;
                        vetor[3]=459;
                        vetor[4]=481;
                        vetor[5]=324;
                        vetor[6]=747;
                        vetor[7]=659;
                        vetor[8]=885;
                        vetor[9]=342;

                        calculaDigito(met,vetor);
                        int y=0;
                        for(y=0;y<tam;y++){
                            insert(met,vetor[y]);
                        }

                    }
                    imprimir(n);
                    break;
                }
                case 3:{
                    int i;
                    printf("\n Digite a chave");
                    scanf("%d",&chave);
                    buscar(met,chave);
                    if(a==2){
                        printf("Chave nao encontrada!");
                    }else{
                        T[end]->estado = 0;
                        T[end]->chave = -1;
                        printf("Chave da posicao %d foi deletada",end);
                    }
                    imprimir(n);
                    break;
                }
                case 4:{
                    imprimir(n);
                    break;
                }
                default:{
                   //clescr();

                   if(opc == 5){
                    iniciar();
                    continue;
                   }
                   printf("\n Digite uma das opções");
                   break;
                }

        }

        }

    }


}




