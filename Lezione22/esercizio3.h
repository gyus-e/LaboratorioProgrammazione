#ifndef ESERCIZIO3_H_
#define ESERCIZIO3_H_

#define MAX_SIZE_DESCRIPTION 30
#define NOME_FILE "agenda.txt"

struct data {
    unsigned int gg;
    unsigned int mm;
};

struct appuntamento {
    unsigned int hh;
    char descrizione [MAX_SIZE_DESCRIPTION];
};

struct descrizioni {
    char descrizione [MAX_SIZE_DESCRIPTION];
    struct descrizioni * next;
};

struct descrizioni * creaNodo (const char *);
void stampaLista (struct descrizioni *);
void distruggiLista (struct descrizioni *);
FILE * apriFile (const char *);
int chiudiFile (FILE *);
struct descrizioni * controllaAppuntamenti (const unsigned int, const unsigned int, const unsigned int, const unsigned int);
int stampaAgenda (const char*);

#endif