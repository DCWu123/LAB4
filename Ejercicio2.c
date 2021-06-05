// int se borra la primera linea//main()//
#include <stdio.h> 
#include <stdlib.h>
// los include ambos tienen un espacio antes del .h
#define FALSE 0
#define TRUE 1
//#define a
int main() 
{
    int done = FALSE; 
    int j=0;
    while (!done) 
    {
        int n = 10;//pasa de ser 10000000 a solo 10
        int* a = (int*)malloc(n *sizeof(int));
        // Los asteriscos estan mal, es otro caracter
        int i;
        for (i=0; i < n; i++){
            
            //le falta un corchete
            a[i] = i;
        }
        j++; 
        if (!a){
            perror (NULL);
            exit(1);
        }
        // se separan los statements
        printf("%d\n", j);
        //se itera solo hasta 10
        if (j > n -1 ){
            done = TRUE;
        }
        //se hace la funcion para que se libere la memoria consumida
        free (a);
    }
    return 0; 
}


