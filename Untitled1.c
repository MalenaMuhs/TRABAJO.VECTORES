#include <stdio.h>
#include <stdlib.h>
#define N 5
void cargarVector( int []);
void mostrarVector( int [],int);
void mostrarElementosrepetidosVector( int [N]);
void mostrarsinrepetidosVector( int [N]);
void mostrarInntersecion(int [N],int [N]);
void mostrarUnion(int [N],int [N]);
void mostrardiferencia(int [N],int [N]);

int main(int argc, char *argv[]) {
	int op;
	int m1[N];
	int m2[N];

	printf("Seleccione una opcion:\n1-Mostrar vectores y elementos repetidos y cant de vcs repetidas\n2-Mostrar vectores sin elementos repetidos\n3-Mostrar Union\n4-Mostrar interseccion\n5-Mostrar v1-v2\n6-Mostrar v2-v1\n");
	scanf("%i",&op);
        	cargarVector(m1);
	        cargarVector(m2);
	switch(op){
	    case 1:
	        printf("\nvector 1\n");
	        mostrarVector(m1,N);
	        mostrarElementosrepetidosVector(m1);
	        printf("\nvector 2\n");
	        mostrarVector(m2,N);
	        mostrarElementosrepetidosVector(m2);
	    break;
	    case 2:
	        printf("\nvector 1\n");
	        mostrarVector(m1,N);
	        printf("\nv1 sin repetir\n\n");
	        mostrarsinrepetidosVector(m1);
	        printf("\nvector 2\n");
	        mostrarVector(m2,N);
	        printf("\nv2 sin repetir\n\n");
	        mostrarsinrepetidosVector(m2);
	    break;
	    case 3:
	    	
	        printf("\nvector 1\n");
	        mostrarVector(m1,N);
	        printf("\nvector 2\n");
	        mostrarVector(m2,N);
	        printf("\nUnion\n");
	        mostrarUnion(m1,m2);
	    break;
	    case 4:
	    	 printf("\nvector 1\n");
	        mostrarVector(m1,N);
	        printf("\nvector 2\n");
	        mostrarVector(m2,N);
	        printf("\nInterseccion\n");
	        mostrarInntersecion(m1,m2);
	    break;
	    case 5:
	        printf(" opcion 5");
	        printf("\nvector 1\n");
	        mostrarVector(m1,N);
	        printf("\nvector 2\n");
	        mostrarVector(m2,N);
	        printf("\nv1-v2\n");
	        mostrardiferencia(m1,m2);
	    break;
	    case 6:
	        printf(" opcion 6");
	        printf(" opcion 5");
	        printf("\nvector 1\n");
	        mostrarVector(m1,N);
	        printf("\nvector 2\n");
	        mostrarVector(m2,N);
	        printf("\nv2-v1\n");
	        mostrardiferencia(m2,m1);
	    break;
	    default: printf("Esta no es una opcion");
	}




	return 0;
}
//---------------------

void cargarVector( int m[N]){
	int i;
	for(i=0 ; i<N ; i++){
		m[i]=(rand()%15)+20;
	}
}
void mostrarVector( int m[N],int a){
	int i;
	for(i=0 ; i<a ; i++){
	 printf("\t%i\t-",m[i]);
	}
}
void mostrarElementosrepetidosVector( int m[N]){
	int i,j,cont=0,a;
	int vaux[N];
		for(i=0 ; i<N ; i++){
	for(j=N-1 ; j-i>=0 ; j--){
		if(m[i]==m[j]&& i!=j){
		    cont=cont+1;
		    vaux[cont-1]=m[i];
		}
	}}
	if(cont == 0) printf("no se repite ningun elemento");
	else {
            printf("se repite/n %i elemento/s",cont);

	printf("\nelementos repetidos\n");
	for( a=0;a<cont;a++){
        printf("\t%i\t-",vaux[a]);
	}
	}
}

void mostrarsinrepetidosVector( int m[N]){
int i,j,tam=N,k;
	for(i = 0; i < tam; i++){
		for(j = i+1; j < tam; j++){
			if(m[i] == m[j]){
				k = j;
				while(k < tam)
				{
					m[k] = m[k+1];
					++k;
				}
				--tam;
				--j;
			}
		}
	}
	mostrarVector(m,tam);
}


void mostrarInntersecion(int m[N],int v[N]){
    int i , j ;
    for(i=0 ; i<N ; i++){
		for(j=0 ; j<N ; j++){
		if((m[i]==v[j])){
		    printf("\t%i\t-",m[i]);
		}}}

}	
void mostrarUnion(int m[N],int v[N]){
	int i , j , cont =0 ,x=0 ;
    int a[N];
    int vx[N];
    mostrarVector(m,N);
    for(i=0 ; i<N ; i++){
		for(j=0 ; j<N ; j++){
		if((m[i]==v[j])){
		   a[cont]=m[i];
		   cont=cont+1;
		}
	}
	}
	cont=0;
	for(i=0 ; i<N ; i++){
		if(v[i]!=a[x]){
			vx[cont]=v[i];
			cont=cont+1;
		}
		else x=x+1;
		
	}
	mostrarVector(vx,cont);
	
	}

void mostrardiferencia(int m[N],int v[N]){
    int i , j , cont =0 ,x=0 ;
    int a[N];
    int vx[N];
    for(i=0 ; i<N ; i++){
		for(j=0 ; j<N ; j++){
		if((m[i]==v[j])){
		   a[cont]=m[i];
		   cont=cont+1;
		}
	}
	}
	cont=0;
	for(i=0 ; i<N ; i++){
		if(m[i]!=a[x]){
			vx[cont]=m[i];
			cont=cont+1;
		}
		else x=x+1;
		
	}
	
	mostrarVector(vx,cont);

}
