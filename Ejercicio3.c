#include <stdio.h>
#define True
#define False
//hacer funcion para leer el archivo


int fmenu (){
    FILE * ptrfile;
    ptrfile = fopen ("user_list.txt" , "w+");
    //se utiliza write para poder escribir en el file y el + es para poder leerlo después de escribir en el
    //se atrapan los errores con un if
    if (ptrfile == NULL){
        printf("No se puedo abrir %s", "user_list.txt");
        return 1;
    }
        int menu = True;
        int usuario, hora, datos, opcion, i;
        
        while (menu = True)
            {
            printf("Menu principal, por favor escoja una opcion\n");
            printf("1. Imprimir la lista de usuarios\n");
            printf("2. Imprimir la lista de usuario sy su condición\n");
            printf("3. Ordenar los usuarios por última hora de acceso\n");
            printf("4. Actualizar los datos de un usuario\n");
            printf("5. Salir\n");
            //se utiliza scanf para seleccionar las opciones
            scanf("%d", &opcion);
            //se utiliza el comando switch para ejecutar las opciones.
            int largo;// para el largo del array
            int *userArray = getUserN(ptrfile, & largo);
            int * horaArray = getUserT(ptrfile);
            switch (opcion){
                case 1: 
                    NombreUsuario (userArray, largo);
                case 2:
                    CondicionUsuario  (userArray, horaArray, largo);
                case 3:
                    OrdenarUsuario (userArray, horaArray, largo);
                case 4:
                    ActualizarUsuario (userArray,)
                case 5:
                    break;
            }
    fclose(ptrfile);
    free (getUserN);
    free(getUserT);
        }
    
}
int main (int argc, char* argv[]){
    fmenu();{
        file();
    }
    return 0;
}

//arrays
//nombre usuario
void NombreUsuario (char ** nombreA, int tamañoA){
    //hacer contador
    int i;
    //imprimir elemento
    for (i = 0; i < tamañoA -1; i++){
        printf("nombre de usuario %d, %s ", i, nombreA[i]);
    }
}
//condicion
void CondicionUsuario (char** nombreA, int*horaA, int tamañoA){
    //contador
    int i;
    //checkeo ultima hora
    for (i = 0; i < tamañoA - 1; i++){
        if (horaA[i] == 0){
            printf("%scondicion%d activo  ", nombreA[i],0 );
        }
        else if (horaA[i] > 0 && horaA[i] <=3){
            printf("%s condicion %d receinte",nombreA[i], 1 );
        }
        else {
            printf(" %s condicion %d inactivo", nombreA[i], 2);
        }
    }
}
//ordenar por hora
void OrdenarUsuario (char** nombreA, int*horaA, int tamañoA){
    //variable temporal
    int timepo = 0;
    //espacio de memoria temporal
    char nomb [50];
    int i, j, z;
    printf("usuarios por orden temporal del último accesado");
    for (i =0; i< tamañoA[i] - 1; i++){
        z = i ;
        for (j = i +1; j< tamañoA -1; j++){
            if (horaA[j] < horaA[z]){
                z=j;
                timepo = horaA[z];
                strcpy (nomb, nombreA[z]);
                horaA[z] = horaA[i];
                nombreA[z] = nombreA [i];
                horaA[i] = timepo;
                nombreA = nomb;
            }
            printf("usuario%s ultima vez conectado hace %d días", nombreA[i]);
        }
    }
}

void ActualizarUsuario (char** nombreA, int*horaA, int tamañoA){
    //array con los usuarios
    char** getUserN(FILE* prtfile, int *tamañoA)
{
    char ** NombreUsuario = malloc(20 * sizeof(char*));
    // guardar la info de los usuarios en cada linea
    char linea[60];
    // contador para array
    int cont = 0, i = 0;
    // loop hasta el final del archivo
    while(!feof(prtfile))
    {
        // 
        fgets(linea, 60, prtfile);
        // clasificar solo nombres
        if(cont%3 == 0)
        {
            // guardar espacio para str
            NombreUsuario[i] = malloc(60 * sizeof(char));
            // Save string in array
            NombreUsuario[i] = strndup(linea, 60);
            i++;
        }
        cont++;
    }
    fseek(prtfile, 0, SEEK_SET);
    *tamañoA = i;
    return NombreUsuario;
}

int * getUserT(FILE* fpointer)
{
    // array con horas
    int* horaA = malloc(21 * sizeof(int));
    // se vuelve a guardar por linea
    char linea[60];
    // contador para lineas
    int cont = 1, i = 0;
    // se vuelve a hacer un loop hasta el final
    while(!feof(ptrfile))
    {
        // guardar cada linea
        fgets(linea, 20, ptrfile);
        // clasificar solo la hora
        if(cont%3 == 0)
        {
            // guardar las horas como ints
            horaA[i] = atoi(linea);
            i++;
        }
        cont++;
    }
    fseek(prtfile, 0, SEEK_SET);
    return horaA;
}
}