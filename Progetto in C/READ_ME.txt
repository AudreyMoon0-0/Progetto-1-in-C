DESCRIZIONE
Questo progetto implementa un sistema completo per la manipolazione di matrici allocate dinamicamente. 
Il programma legge una matrice da un file di testo, ne determina automaticamente le dimensioni e 
permette all'utente di modificarla attraverso un menu interattivo, garantendo una gestione 
efficiente della memoria.

FUNZIONALITA' PRINCIPALI
* Lettura automatica di righe e colonne da file.
* Allocazione e deallocazione dinamica della memoria.
* Aggiunta e rimozione di righe in tempo reale (Utilizzo di realloc).
* Ordinamento globale della matrice (Bubble Sort)
* Salvataggio dei risultati su un file di output.

STRUTTURA
* project.c: Punto di ingresso del programma e gestione del menu interattivo.
* funzioni.c: Core logico contenente le funzioni di calcolo e gestione memoria, per una corretta pulizia generica/estetica del programma.
* matrice_input.txt: File di testo contenente i dati iniziali.

NOTE
Il programma gestisce la memoria assicurandosi che ogni blocco allocato con malloc/realloc venga correttamente liberato prima 
della chiusura del processo per evitare memory leak.


- Sviluppato da Giusy Varisco -