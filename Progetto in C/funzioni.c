#include <stdio.h>
#include <stdlib.h>

void conta_rigcol(int *r, int *c, FILE *fp){

    int temp;
    char ch;

    *r = 0;
    *c = 0;

    while (fscanf(fp, "%d%c", &temp, &ch) == 2) {
        if (*r == 0) (*c)++;
        if (ch == '\n') (*r)++;
    }

    //Spostiamo la testina dopo dalla fine del file all'inizio
    rewind(fp);
}


int **alloc_matr(int r, int c){

    //Creazione di uno spazio di memoria dinamico di grandezza righe * grandezza in byte di un puntatore a int.

    int **matr = (int**) malloc (r * sizeof(int*));

    //per ogni riga creiamo spazio per allocare dinamicamente le colonne che puntano a int.

    for (int i = 0; i < r; i++){
        matr[i] = (int*) malloc (c * sizeof(int));
    }

    //restituiamo la matrice

    return matr;
}


void dealloc_matr(int **matr, int r){

    //liberiamo lo spazio allocato dinamicamente con free()

    for(int i = 0; i < r; i++){
        free(matr[i]);
    }
    free (matr);
}


void stampa_matr(int **matr, int r, int c){

    for(int i = 0; i < r; i++){

        for(int j = 0; j < c; j++){
            printf("%d ", matr[i][j]);
        }
        printf("\n");

    }
}


int **aggiungi_riga(int **matr, int *r, int c){

    //aumentiamo il n di righe di 1

    (*r)++;

    //aggiungiamo dinamicamente lo spazio per una riga in più 

    matr = (int**) realloc(matr,(*r) * sizeof(int*));
    matr[*r - 1] = (int*) malloc (c * sizeof(int));

    printf ("Inserisci i numeri da aggiungere alla nuova riga:\n");

    for(int j = 0; j < c; j++){
        scanf("%d", &matr[*r - 1][j]);
    }

    return matr;
}


int **togli_riga(int **matr, int *r){

    //se il n di righe è uguale a zero non possiamo più togliere nessuna riga

    if (*r == 0) return matr;

    (*r)--;

    free(matr[*r]);

    matr = (int **)realloc(matr, (*r) * sizeof(int *));


    return matr;
}


void ordina_matr(int **m, int r, int c){

    int i, j, k, temp;
    int tot = r * c;
    k = 0;

    //creazione di un array temporaneo per prendere tutti i valori della matrice e ordinarli comodamente.

    int *arrtemp = (int *)malloc(tot * sizeof(int));

    for (int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            arrtemp[k] = m[i][j];
            k++;
        }
    }

    //Bubble sort sull'array temporaneo

    for(i = 0; i < tot - 1; i++){
        for(j = 0; j < tot - i - 1; j++){

            if (arrtemp[j] > arrtemp[j+1]){

                temp = arrtemp[j];
                arrtemp[j] = arrtemp[j+1];
                arrtemp[j+1] = temp;

            }

        }
    }

    //Inseriamo i numeri ordinati nella matrice

    k = 0;

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            m[i][j] = arrtemp[k++];
        }
    }

    //Liberiamo la memoria 

    free(arrtemp);

}


void salva_su_file(char *nome, int **matr, int r, int c){

    //Apriamo il file in modalità scrittura

    FILE *fp = fopen(nome, "w");

    for (int i = 0; i < r; i++) {

        for (int j = 0; j < c; j++){
            fprintf(fp, "%d ", matr[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);    

}