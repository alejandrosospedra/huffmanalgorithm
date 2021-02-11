#ifndef HUFFMAN_H_INCLUDED
#define HUFFMAN_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Parella Parella;

struct Parella
{
    char simbol;

    unsigned int frecuencia;

    unsigned int indentificador;

    Parella * seg;

    Parella * fill_e;
    Parella * fill_d;

    char codificacio[1000];

};

typedef struct
{
    Parella * prim;

    Parella * ant;

} Llista;

typedef struct taula
{
   char lletra;
   char codificacio[10000];
   struct taula *sig;     /* Siguiente elemento de la tabla */
} tipusTaula;
/*Variables globals*/
tipusTaula *Taula;
Llista l;

/*Funcions*/
void Error (char missatge[]);
Llista Crear_llista();
Llista Inserir_llista(Llista l, Parella *p_n);
char Actual_llista_simbols(Llista l);
unsigned int Actual_llista_frecuencia(Llista l);
Llista Principi_llista(Llista l);
Llista Esborrar_llista(Llista l);
Llista Seguent_llista(Llista l);
int EsFinal_llista(Llista l);
int EsBuida_llista(Llista l);
void Print_llista_simbols(Llista l);
void Print_llista_frecuencies(Llista l);
void Esborrar_tota_llista(Llista l);
Llista Frecuencia (char missatge[]);
Llista Ordena(Llista l);
void Print_llista_id(Llista l);
void Print_arbre(Llista l);
void Codificar(Parella * arbre, char codi[]);
void InsertarTaula(char c, char codi[]);
tipusTaula *BuscaCaracter(tipusTaula *Taula, char c);
void Print_taula();
Llista Crear_arbre(Llista l);
#endif // HUFFMAN_H_INCLUDED
