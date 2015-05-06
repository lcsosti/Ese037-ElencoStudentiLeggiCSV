#include <stdio.h>
#include <stdlib.h>

#define MAX_STRLEN 30
#define MAX_FNAMELEN 255

struct s_studente {
    char nome[MAX_STRLEN+1];
    char cognome[MAX_STRLEN+1];
    int eta;
    char classe[MAX_STRLEN+1];
};
typedef struct s_studente studente;

int main(int argc, char** argv) {
studente s;
    int i;
    FILE *inf;
    char fileName[MAX_FNAMELEN+1];
    
    printf("Inserisci il nome del file da cui devo leggere i dati: ");
    scanf("%s", fileName);
    
    inf = fopen(fileName, "r");
    if(inf == NULL) {
        fprintf(stderr, "ERRORE: Impossibile aprire il file\n", fileName);
        exit(1);
    }
    
    fscanf(inf, "%[^;];%[^;];%[^;];%[^;\n]\n", s.nome, s.cognome, s.nome, s.classe);
    
    i=0;
    fscanf(inf, "%[^;];%[^;];%d;%[^;\n]\n", s.nome, s.cognome, &(s.eta), s.classe);
    while(!feof(inf)) {
        i++;
        printf("Studente %d\nNome: %s\nCognome: %s\nEta': %d\nClasse: %s\n\n",
                i,
                s.nome,
                s.cognome,
                s.eta,
                s.classe);
        fscanf(inf, "%[^;];%[^;];%d;%[^;\n]\n", s.nome, s.cognome, &(s.eta), s.classe);
    }
    fclose(inf);
    
    return (EXIT_SUCCESS);
}

