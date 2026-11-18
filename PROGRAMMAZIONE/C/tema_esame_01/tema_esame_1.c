#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct Nodo {
    int val;
    struct Nodo *next;
} Nodo;

Nodo *creaNodo();
int inserisciInTesta(Nodo** head, int val);
int inserisciInCoda(Nodo** head, int val);
int rimuoviInTesta(Nodo **head);
int rimuoviInCoda(Nodo **head);
int cancella(Nodo **head);
void salva(Nodo *head, char nomeFile[SIZE]);
void carica(Nodo **head, char nomeFile[SIZE]);
void stampa(Nodo *head);
int rimuovi(Nodo **head, int val);
void stampaRicorsiva(Nodo *head);

int main(int argc, char *argv[]) {
	Nodo* head = NULL;
	int scelta;
	int val;
	char app[BUFSIZ];

	do {
		printf("Che operazione si vuole effetture?\n1 Aggiungi un elemento in testa (inserito dall’utente)\n2 Rimuovi un elemento dalla testa\n3 Aggiungi un elemento in coda (inserito dall’utente)\n4 Rimuovi un elemento dalla coda\n5 Rimuovi un elemento in lista (inserito dall’utente)\n6 Carica lista da file\n7 Salva lista su file\n8 Stampa\n9 Stampa la lista in ordine inverso\n10 Cancella gli elementi di una lista.\n0 Esci dal programma\n> ");
		scanf(" %d", &scelta);
		switch (scelta) {
			case 1:
				printf("\nElemento da aggiungere in testa -> ");
				scanf(" %d", &val);
				inserisciInTesta(&head, val);
				break;
			case 2:
				if(rimuoviInTesta(&head) == 0) printf("\nElemento rimosso.\n");
				else printf("\nERRORE: La lista e' vuota.\n");
				break;
			case 3:
				printf("\nElemento da aggiungere in coda -> ");
				scanf(" %d", &val);
				inserisciInCoda(&head, val);
				break;
			case 4:
				if(rimuoviInCoda(&head) == 0) printf("\nElemento rimosso.\n");
				else printf("\nERRORE: La lista e' vuota.\n");
				break;
			case 5:
				printf("\nNome elemento da rimuovere dalla lista -> ");
				scanf(" %d", &val);
				if (rimuovi(&head, val) == -1) printf("\n\nERRORE: Elemento NON trovato.\n");
				else { printf("\n\nOperazione completata con successo.\n"); }
				break;
			case 6:
				printf("\nNome file da cui caricare la lista -> ");
				getchar();	//svuoto buffer
				fgets(app, BUFSIZ, stdin);
				carica(&head, app);
				break;
			case 7:
				printf("\nNome file su cui copiare la lista -> ");
				getchar();	//svuoto buffer
				fgets(app, BUFSIZ, stdin);
				salva(head, app);
				break;
			case 8:
				printf("\nLista:\n");
				stampa(head);
				break;
			case 9:
				printf("\nLista Invertita:\n");
				stampaRicorsiva(head);
				printf("\n");
				break;
			case 10:
				printf("\nLista Svuotata.\n");
				cancella(&head);
				break;
			default:
				printf("\nProgramma Terminato\n");
		}
		printf("\n");
	} while (scelta > 0 && scelta < 11);

    return 0;
}

Nodo *creaNodo(int val) {
	Nodo *newNodo;
	newNodo = (Nodo *) malloc(sizeof(Nodo));
	if (newNodo == NULL) { printf("\nERRORE: Memoria Insufficiente.\n"); return NULL; }

	newNodo->val = val;
	newNodo->next = NULL;

	return newNodo;
}

int inserisciInTesta(Nodo** head, int val) {
	Nodo *newNodo = creaNodo(val);

	if (*head == NULL) {
		*head = newNodo;
		return val;
	} else {
		newNodo->next = *head;
		*head = newNodo;
		return val;
	}

	return -1;
}

int inserisciInCoda(Nodo **head, int val) {
	Nodo *newNodo = creaNodo(val);
	
	if (*head == NULL) {
		*head = newNodo;
		return val;
	} else {
		Nodo* temp = *head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNodo;
		return val;
	}
	return -1;
}

int rimuoviInTesta(Nodo **head) {
	if (*head == NULL) return -1;
	else {
		Nodo *temp = *head;
		*head = (*head)->next;
		free(temp);
		return 0;
	}
}

int rimuoviInCoda(Nodo **head) {
	if (*head == NULL) return -1;
	else if ((*head)->next == NULL) { 
			free(*head);
			*head = NULL;
	} else {
		Nodo* temp = *head;
		while (temp->next->next != NULL) {
			temp = temp->next;
		}
		free(temp->next);
		temp->next = NULL;
		return 0;
	}
}

int cancella(Nodo **head) {
	while (rimuoviInTesta(head) == 0);
	return 0;
}

void salva(Nodo *head, char nomeFile[SIZE]) {
	Nodo* temp = head;
	FILE *write;
	
	if ((write = fopen(nomeFile, "r")) != NULL) {
		printf("\nAttenzione! Il file indicato esiste gia'!\nSi intende sovrascriverlo? (y/N)? -> ");
		if (getchar() != 'y') { printf("\nOperazione Annullata.\n"); fclose(write); return; }
	}
	fclose(write);
	
	if ((write = fopen(nomeFile, "w"))) {
		while (temp != NULL) {
			if (fprintf(write, "%d\n", temp->val) == EOF) {  printf("\nERRORE: Scrittura su file NON riuscita o riuscita parzialmente.\n\n"); fclose(write); return; }		
			temp = temp->next;
		}

		printf("\nOperazione Completata con successo.\n\n");
		fclose(write);
		return;
	} else {
		 printf("\nERRORE: Apertura file in scrittura NON riuscita.\n\n"); return; 
	}
}

void carica(Nodo **head, char nomeFile[SIZE]) {
	FILE *read;
	
	if ((read = fopen(nomeFile, "r")) == NULL) { ("\nERRORE: Il file indicato NON esiste.\n\n"); return; }
	
	char buffer[BUFSIZ];
	while ((fgets(buffer, BUFSIZ, read)) != NULL) {
		inserisciInTesta(head, atoi(buffer));
	}
	fclose(read);
	printf("\nOperazione Completata.\n\n");
	return;
}


void stampa(Nodo *head) {
	Nodo* temp = head;
	
	while (temp != NULL) {
		printf("%d -> ", temp->val);		
		temp = temp->next;
	}

	printf("END\n");
}

int rimuovi(Nodo **head, int val) {
	if (*head == NULL) return -1;
	else if ((*head)->val == val) {
		rimuoviInTesta(head);
	} else {
		Nodo* temp = *head;
		while (temp->next != NULL && temp->next->val != val) {
			temp = temp->next;
		}
		if (temp->next == NULL) { printf("\nERRORE: Valore NON trovato.\n\n"); return -1; }
		Nodo* lib = temp->next;
		temp->next = temp->next->next;
		free(lib);
		return 0;
	}
	return val;
}

void stampaRicorsiva(Nodo *head) {
	Nodo* temp = head;
	
	if (temp == NULL) { printf("END"); return; }
	
	stampaRicorsiva(temp->next);
	printf(" -> %d", temp->val);
}
