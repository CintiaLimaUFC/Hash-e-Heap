#include <stdio.h>
#include <math.h>
#define MAX 100

struct Array{
    int chave;
    int estado;
    struct Array *pont;
};

typedef struct Array ArrayV;

struct ArrayV* T[MAX];
int a;
int end;
int j;
int dig;

void iniciar(){
    int i;
	for(i=0; i<MAX; i++)
		 T[i]=NULL;
}

int h(int met, int num){
    switch(met){
        case 1:{
            return div(num);
            break;
        }
        case 2:{
            return dob(met,num);
            break;
        }
        case 3:{
            return dob(met,num);
            break;
        }
        case 4:{
            return dob(met,num);
            break;
        }
        case 5:{
            return dob(met,num);
            break;
        }
        case 6:{
            return mul(num);
            break;
        }
        case 7:{
            return ana(met,num);
            break;
        }
        case 8:{
            return ana(met,num);
            break;
        }

        default:{
            break;
        }
    }


}

int div(int num){
    return num % MAX;
}

int dob(int met,int num){
    int d = 2;
    int x = num;
    int tam = 1;

    while (x>0){
        x = x/10;
        tam++;
    }
    x = num;
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
            num = v[tam - 2] * 10;
            num =  num + v[tam-1];

            return num;
            break;
        }
    }
    num = (v[tam-1]*1) + (v[tam-2]*2) + (v[tam-3]*4) +(v[tam-4]*8);
    return num;


}

int mul(int num){
    int tam = 1;
    int quad = num * num;
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
    num = v[i+1] * 10;
    num =  num + v[i+2];

    return num;
}

int ana(int met,int num){
    return reduz(num,dig);
}

int calculaDigito(int met, int vetor[]){
    int d1[10];
    int d2[10];
    int d3[10];

    int i = 0;
    while(i<10){
        d1[i]=0;
        d2[i]=0;
        d3[i]=0;
        i++;
    }

    i=0;
    int m=0;
    while(i<10){
            m++;
            int x = vetor[i];
            d3[x%10]++;
            x =x/10;
            d2[x%10]++;
            x =x/10;
            d1[x%10]++;

        i++;
    }

    int x[3];
    x[0]=0;
    x[1]=0;
    x[2]=0;

        switch(met){
            case 7:{
                int j;
                for (j=0;j<10;j++){
                    x[0] = x[0] +(d1[j] - m/10)*(d1[j] - m/10);
                    x[1] = x[1] +(d2[j] - m/10)*(d2[j] - m/10);
                    x[2] = x[2] +(d3[j] - m/10)*(d3[j] - m/10);
                }

                break;
            }
            default:{
                int j;
                for (j=0;j<10;j++){
                    x[0] = x[0] + abs(d1[j] - m/10);
                    x[1] = x[1] + abs(d2[j] - m/10);
                    x[2] = x[2] + abs(d3[j] - m/10);
                }
                break;
            }

        }
        if(x[0]>x[1] && x[0]>x[2]){
            return 0;
        }else if (x[1]>x[0] && x[1]>x[2]){
            return 1;
        }else{
            return 2;
        }
}

int reduz(int num,int d){
    int vchave[3];
    vchave[2]=num%10;
    num =num/10;
    vchave[1]=num%10;
    num =num/10;
    vchave[0]=num%10;
    if(d==0){
        num = vchave[1] *10;
        num = num+vchave[2];
    }else if (d==1){
        num = vchave[0] *10;
        num = num+vchave[2];
    }else{
        num = vchave[0] *10;
        num = num+vchave[1];
    }
    return num;

}


int insert(int met,int num){
    int i;
    int fh = h(met,num);

    if (T[fh]!=NULL) {
		if (buscalista(met, num)) {
			printf("Elemento já existe");
			return;
		}
	}
	inserelista(met,num,fh);

    return 0;
}

int buscalista(int met, int num) {
	int fh = h(met,num);
	ArrayV *lista = T[fh];
	while (lista != NULL) {
		if (num == lista->chave){
             return 1;
		}
		lista = lista->pont;
	}
	return 0;
}

void inserelista(int met, int num, int fh) {

	ArrayV **lista = &T[fh];

	if (*lista == NULL) {
		*lista = (ArrayV *) malloc(sizeof(ArrayV));
  		if (*lista == NULL) {
			printf("\nErro");
			exit(1);
  		}
  		(*lista)->chave=num;
  		(*lista)->pont=NULL;

 	}else {
	    ArrayV *guarda= T[fh];

		while ((*lista)->pont != NULL){
			*lista=(*lista)->pont;
		}

		(*lista)->pont=(ArrayV *) malloc(sizeof(ArrayV));
		if ((*lista)->pont == NULL) {
			printf("\nErro");
			exit(1);
  		}

		*lista=(*lista)->pont;
  		(*lista)->chave=num;
  		(*lista)->pont=NULL;

  		T[fh]=guarda;
	}

}

void remover(int met, int num) {
	int fh = h(met,num);
	if (!buscalista(met,num)) {
		printf("\nNao Encontrado");
		return;
 	}

	 ArrayV **lista = &T[fh];
	 ArrayV *anterior = *lista;
	 ArrayV *prox = (*lista)->pont;
	 ArrayV *guarda = T[fh];

	 while (*lista!=NULL) {
		if ((*lista)->chave == num) {
			if (*lista == anterior) {
				if ((*lista)->pont==NULL) {
					free(*lista);
					T[fh]=NULL;
				}
				else {
					(*lista)->pont=prox->pont;
					(*lista)->chave=prox->chave;
					T[fh]=guarda;
				}
			}
			else {
				anterior->pont=prox;
				free(*lista);
				T[fh]=guarda;
			}
			return;
	 	}
		anterior = *lista;
		*lista = (*lista)->pont;
		prox = (*lista)->pont;
	 }
	 T[fh]=guarda;
	 free(anterior);
	 free(prox);
	 free(guarda);
}

void imprimir(){
	int i;
	printf("");
	for (i=0; i<MAX; i++) {
        if (T[i]!=NULL){
           printf("\n[%d] ->",i);
           percorrelista(i);
        }

	}

}

void percorrelista(int pos) {
	ArrayV *lista = T[pos];
	while (lista != NULL) {
		printf(" %d ->",lista->chave);
		lista = lista->pont;
	}
	printf(" NULL");
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
            printf("\n ___|EXTERIOR|___");
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
                    int a=buscalista(met,chave);
                    if(a==0){
                        printf("Chave nao encontrada!");
                    }else{
                        printf("Chave encontrada");
                    }
                    imprimir();
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
                        vetor[0]=123;
                        vetor[1]=456;
                        vetor[2]=789;
                        vetor[3]=931;
                        vetor[4]=131;
                        vetor[5]=489;
                        vetor[6]=756;
                        vetor[7]=923;
                        vetor[8]=242;
                        vetor[9]=914; //1
                        //vetor[9]=340; //2
                        //vetor[9]=343; //3
                        dig=calculaDigito(met,vetor);
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
                    remover(met,chave);
                    imprimir();
                    break;
                }
                case 4:{
                    imprimir();
                    break;
                }
                default:{
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




