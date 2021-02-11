#include <stdio.h>
#include <stdlib.h>
#include "huffman.h"


int main()
{
    tipusTaula *t;
    Parella * arrel;
    Parella * aux;
    t=Taula;
    char missatge[100000]="BON ESTIU CLARA!";
    char missatge_codificat[1000000]="";
    char missatge_descodificat[100000]="";
    int i = 0;

    if(missatge[0] == '\0')
        Error(" Missatge buid");
    else{
    l = Frecuencia(missatge);
    l = Crear_arbre(l);
    //Print_llista_simbols(l);
    //Print_llista_frecuencies(l);
    l = Principi_llista(l);
    /*apuntar al final de la llista per agafar l'arrel*/
    while(!EsFinal_llista(l))
    {
        l = Seguent_llista(l);
    }
    arrel = l.ant;
    Codificar(arrel, "");
    while(missatge[i]!='\0')
    {
        t = BuscaCaracter(Taula, missatge[i]);
        //missatge_codificat[strlen(missatge_codificat)]= t->codificacio;
        strcat(missatge_codificat, t->codificacio);
        i++;
    }
    i=0;
    printf("TAULA DE TRADUCCIO\n");
    printf("___________________\n");
    Print_taula();
    printf("___________________\n");
    printf("---------------CODIFICACIO---------------\n");
    printf("El missatge '%s' codificat es '%s'\n", missatge, missatge_codificat);
    printf("-----------------------------------------\n");
    //Print_taula();
    //Print_arbre(l);
    aux=arrel;
    while(missatge_codificat[i]!='\0')
    {
        if(!aux->fill_d && !aux->fill_e)
        {
            missatge_descodificat[strlen(missatge_descodificat)]= aux->simbol;
            aux=arrel;
        }
        if(missatge_codificat[i]=='0') aux = aux->fill_e;
        if(missatge_codificat[i]=='1') aux = aux->fill_d;

       i++;
    }
    /*tractament de l'ultim caracter*/
    if(!aux->fill_d && !aux->fill_e)
    {
        missatge_descodificat[strlen(missatge_descodificat)]= aux->simbol;
        aux=arrel;
    }
    if(missatge_codificat[i]=='0') aux = aux->fill_e;
    if(missatge_codificat[i]=='1') aux = aux->fill_d;
    printf("---------------DESCODIFICACIO---------------\n");
    printf("El resultat de descodificar '%s' es '%s'\n", missatge_codificat, missatge_descodificat);
    printf("--------------------------------------------\n");
    /*Esborrar la taula de traduccio*/
    while(Taula)
   {
      t = Taula;
      Taula = t->sig;
      free(t);
   }


    Esborrar_tota_llista(l);
    }
    return 0;
}

/*Funcio per instertar en la taula de traduccio un simbol i la seva codifiacio*/
void InsertarTaula(char c, char codi[])
{
   tipusTaula *t, *p, *a;

   t = (tipusTaula *)malloc(sizeof(tipusTaula));
   t->lletra = c;
   strcpy(t->codificacio, codi);

   if(!Taula)
   {
      Taula = t;
      Taula->sig = NULL;
   }
   else
   {

       p = Taula;
       a = NULL;
       while(p && p->lletra < t->lletra)
       {
          a = p;
          p = p->sig;
       }
      t->sig = p;
       if(a) a->sig = t;
       else Taula = t;
    }
}
