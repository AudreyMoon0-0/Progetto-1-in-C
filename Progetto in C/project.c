/*
Creazione di un programma in C che legga una matrice dal file matrice_input.txt e implementi un sistema di manipolazione 
della matrice, salvando poi le modifiche in un nuovo file chiamato matrice_output.txt.

Il programma deve:

1.aprire il file matrice_input.txt
2.determinare automaticamente numero di righe e colonne
3.allocare la matrice dinamicamente
4.avere un menu interattivo per scegliere cosa fare:

    -aggiungere una riga alla matrice
    -togliere una riga alla matrice
    -organizzare in ordine crescente la matrice
    -salvare in un nuovo file di testo la matrice modificata e chiudere il programma

*/
#include <stdio.h>
#include <stdlib.h>
#include "funzioni.c"

int main (int argc, char* argv[]){

    //Apriamo il file in modalità lettura
    FILE *fp;
    fp = fopen ("matrice_input.txt", "r");

    //In caso di errore:
    if (fp == NULL){
        fprintf(stderr, "%s: can't open %s\n", argv[0], "matrice_input.txt");
        exit(1);
    }

    //Iniziamo contando quante righe e colonne ha la matrice dentro il file di testo
    int r= 0, c = 0;
    conta_rigcol(&r, &c, fp);

    //Allochiamo la matrice
    int** matr = alloc_matr(r,c);

    //leggiamo i numeri nel file di testo input
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            fscanf(fp, "%d", &matr[i][j]);
        }
    }
    fclose(fp);

    // - Menu interattivo con scelta -

    int scelta;

    do {
        printf("\n1. Stampa Matrice\n 2. Aggiungi riga\n3. Togli riga\n4. Ordina matrice in ordine crescente\n5. Salva ed Esci\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1: 
                stampa_matr(matr, r, c); 
                break;
            case 2: 
                matr = aggiungi_riga(matr, &r, c); 
                break;
            case 3: 
                matr = togli_riga(matr, &r); 
                break;
            case 4: 
                ordina_matr(matr, r, c); 
                break;
            case 5: 
                printf("Salvataggio in corso e chiusura...\n"); 
                break;
            default: 
                printf("Non hai inserito un numero tra 1 e 4, riprova:\n");
                break;
        }
    } while (scelta != 5);

    salva_su_file("matrice_output.txt", matr, r, c);
    dealloc_matr(matr, r);

    return 0;
}
