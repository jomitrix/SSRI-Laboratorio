#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Riga {
	char *str;
	int len;
} Riga;

char *cifra (char (*str)[BUFSIZ], int k);
char *decifra (char (*str)[BUFSIZ], int k);
Riga leggiRiga(FILE *read, int maxLenght);
int cutlen(char *str);
void salvaSuFile(char *nomeFile, char *cifr);

int main(int argc, char *argv[]) {
	int menu;
	char nomeFile[50];
	FILE *read;
	int key = 0;
	int len = 0;
	Riga stringa;
	char totString[BUFSIZ] = "";
	int cifrato = 0;
	
	do {
		printf("Quale operazione si intende effettuare?\n1 - Seleziona file su cui leggere/scrivere.\n2 - Inserisci chiave di cifratura.\n3 - Leggi file e cifra/decifra.\n4 - Stampare file cifrato/decifrato a schermo.\n5 - Salva il file cifrato/decifrato.\n0 - Termina programma.\n> ");
		scanf(" %d", &menu);
		
		switch (menu) {
			case 1:
				printf("\nFile su cui interagire -> ");
				getchar(); //pulisco buffer
				fgets(nomeFile, 50, stdin);
				cutlen(nomeFile);
				break;
			case 2:
				printf("\nChiave di cifratura -> ");
				scanf(" %d", &key);
				break;
			case 3:
   				// Check if the file name has been set
   				if (strlen(nomeFile) == 0) {
   					printf("\nERRORE: File non selezionato. Usare opzione 1.\n");
       				break;
   				}

				if (key == 0) {
					printf("\nERRORE: La chiave di cifratura NON è valida. Usare opzione 2.\n");
					break;
				}
				
   				// Open the file
  				if ((read = fopen(nomeFile, "r")) == NULL) {
       				printf("\nERRORE: Il file NON esiste o non può essere aperto. Reinserire il nome tramite opzione 1.\n");
       				break;
   				}

   				// Read the first line to determine the line length
   				char buffer[50];
   				if (fgets(buffer, 50, read) == NULL) {
       				printf("\nERRORE: Lettura della lunghezza FALLITA.\n");
       				fclose(read);
       				break;
   				}
   				len = atoi(buffer);
				if (len == 0) {
					printf("\nERRORE: Valore lunghezza NON valido. Inserire file con lunghezza valda tramite opzione 1.\n");
					break;
				}

   				// Initialize totString to hold the concatenated result
   				totString[0] = '\0';

   				// Read and process lines
   				while (1) {
       				stringa = leggiRiga(read, len);
       				if (stringa.str == NULL) break;  // End of file or error

       				strcat(totString, stringa.str);  // Concatenate to total string
       				free(stringa.str);              // Free dynamically allocated memory
   				}

   				fclose(read);
   				printf("\nContenuto letto correttamente.\n");
				
				int opz;
				printf("\nCosa vuoi fare?\n1 - Cifra\n2 - Decifra\n> ");
				scanf(" %d", &opz);
				switch (opz) {
					case 1:
						cifra(&totString, key);
						cifrato = 1;
						break;
					case 2:
						decifra(&totString, key);
						cifrato = 1;
						break;
					default:
						printf("\nOperazione NON effettuata.\n");
						break;
				}
				if (cifrato == 0) break;
				printf("\nOperazione effettuata con successo.\n");
   				break;
			case 4:
				if (cifrato == 1) printf("\n%s\n", totString);
				else {
					printf("\nERRORE: Il file NON è stato letto/cifrato/decifrato. Usare opzione 3.\n");
				}
				break;
			case 5:
				if (cifrato == 1) getchar(), salvaSuFile(nomeFile, totString);
				else {
					printf("\nERRORE: Il file NON è stato letto/cifrato/decifrato. Usare opzione 3.\n");
				}
				break;
			default:
				printf("\nProgramma Terminato.");
		}

		printf("\n");
	} while (menu > 0 && menu <= 5);
}

int cutlen(char *str) {
	if (str == NULL) return 0;	
	int len = 0;
	while(str[len] != '\n' && str[len] != '\0') len++;
	str[len] = '\0', len++;
	return len;
}

char *cifra (char (*str)[BUFSIZ], int k) {
	for (int i = 0; i < strlen(*str); i++) {
		if (isalpha((*str)[i]) != 0) {
			for (int j = 0; j < k; j++) {
				if ((*str)[i] != 'z' && (*str)[i] != 'Z') { 
					(*str)[i]++;
				} else {
					(*str)[i] = islower((*str)[i]) != 0 ? 'a' : 'A';
				}
			}
		}
	}
}

char *decifra (char (*str)[BUFSIZ], int k) {
	for (int i = 0; i < strlen(*str); i++) {
		if (isalpha((*str)[i]) != 0) {
			for (int j = 0; j < k; j++) {
				if ((*str)[i] != 'a' && (*str)[i] != 'A') { 
					(*str)[i]--;
				} else {
					(*str)[i] = islower((*str)[i]) != 0 ? 'z' : 'Z';
				}
			}
		}
	}
}

Riga leggiRiga(FILE *read, int maxLenght) {
    Riga output = {NULL, 0}; // Initialize with NULL values
    char buffer[maxLenght];

    if (fgets(buffer, maxLenght, read) == NULL) {
        return output; // Return empty Riga if no more lines
    }

    int len = cutlen(buffer);
	strcat(buffer, "\n");
    char *out = (char *)malloc((len + 1) * sizeof(char));
    if (out == NULL) {
        printf("\nERRORE: Allocazione memoria FALLITA.\n");
        return output; // Return empty Riga on allocation failure
    }

    strcpy(out, buffer);
    output.str = out;
    output.len = len;

    return output;
}

void salvaSuFile(char *nomeFile, char *cifr) {
    FILE *write;

    if ((write = fopen(nomeFile, "r")) != NULL) { 
        printf("\nAttenzione! Il file '%s' è già esistente.\nSi intende sovrascriverlo? (y/N)\n> ", nomeFile);

        int risposta = getchar();
        getchar();

        if (risposta != 'y' && risposta != 'Y') {
            printf("\nOperazione Annullata.\n");
            fclose(write);
            return;
        }

        fclose(write);
    }

    if ((write = fopen(nomeFile, "w")) == NULL) {
        printf("\nERRORE: Apertura in scrittura del file FALLITA.\n");
        return;
    }

    if (fprintf(write, "%s\n", cifr) < 0) {
        printf("\nERRORE: Scrittura su file FALLITA.\n");
    } else {
        printf("\nScrittura su file completata con successo.\n");
    }

    fclose(write);
}

