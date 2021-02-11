#include "huffman.h"
unsigned int identificador = 0;


void Error (char missatge_error[]){
    unsigned char i = 0;
    printf("ERROR!");
    while(i<40 && missatge_error[i] != '\0'){
        printf("%c", missatge_error[i]);
        i++;
    }
    printf("\n");
}

Llista Crear_llista()
{
    Llista l;

    Parella * p;

    p=(Parella *)malloc(sizeof(Parella));

    if (p==NULL)
    {
        Error("Error de memoria");
    }
    else
    {
        l.prim = p;
        l.ant = p;
        (*p).seg = NULL;
    }

    return l;
}

Llista Inserir_llista(Llista l, Parella *p_n)
{
    Parella *pdi;
    if (p_n==NULL)
        Error("No hi ha prou memoria");
    else
    {
        if((p_n->indentificador==-1))
        {   p_n->indentificador = identificador;
            identificador++;
        }
        pdi=(*l.ant).seg;
        (*l.ant).seg=p_n;
        (*p_n).seg=pdi;
        // l.ant=p_n;
    }
    return l;
}

Llista Ordena(Llista l)
{
    Llista llista_ordenada;
    llista_ordenada = Crear_llista();
    Parella * a;
    l = Principi_llista(l);
    a = (Parella *)malloc(sizeof(Parella));
    a->fill_d=l.ant->seg->fill_d;
    a->fill_e=l.ant->seg->fill_e;
    a->frecuencia=l.ant->seg->frecuencia;
    a->seg=l.ant->seg->seg;
    a->simbol=l.ant->seg->simbol;
    a->indentificador=l.ant->seg->indentificador;
    llista_ordenada = Inserir_llista(llista_ordenada, a);
    l = Seguent_llista(l);
    while (!EsFinal_llista(l))
    {
            llista_ordenada = Principi_llista(llista_ordenada);
            while (llista_ordenada.ant->seg && llista_ordenada.ant->seg->frecuencia <= l.ant->seg->frecuencia)
            {
                llista_ordenada = Seguent_llista(llista_ordenada);
            }
            a = (Parella *)malloc(sizeof(Parella));
            a->fill_d=l.ant->seg->fill_d;
            a->fill_e=l.ant->seg->fill_e;
            a->frecuencia=l.ant->seg->frecuencia;
            a->seg=l.ant->seg->seg;
            a->simbol=l.ant->seg->simbol;
            a->indentificador = l.ant->seg->indentificador;
            llista_ordenada = Inserir_llista(llista_ordenada, a);
            l = Seguent_llista(l);
    }
    return llista_ordenada;
}

char Actual_llista_simbols(Llista l)
{
    if (EsFinal_llista(l))
    {
        Error("PDI a la dreta");
        return -1;
    }
    else
    {
        return((*(*l.ant).seg).simbol);
    }
}

unsigned int Actual_llista_frecuencia(Llista l)
{
    if (EsFinal_llista(l))
    {
        Error("PDI a la dreta");
        return -1;
    }
    else
    {
        return((*(*l.ant).seg).frecuencia);
    }
}

Llista Principi_llista(Llista l)
{
    l.ant=l.prim;
    return l;
}

int EsFinal_llista(Llista l)
{
    return ((*l.ant).seg==NULL);
}

Llista Esborrar_llista(Llista l)
{
    Parella * pdi;

    if (EsFinal_llista(l))
    {
        Error("PDI a la dreta esborrant");
    }
    else
    {
        pdi = (*l.ant).seg;
        (*l.ant).seg=(*pdi).seg;
        free(pdi);
    }

    return l;
}

Llista Seguent_llista(Llista l)
{
    if (EsFinal_llista(l))
        Error("PDI a la dreta al passar d'element");
    else
        l.ant=(*l.ant).seg;
    return l;
}

int EsBuida_llista(Llista l)
{
    return ((*l.prim).seg==NULL);
}
void Print_llista_id(Llista l)
{
   l=Principi_llista(l);
   while(!EsFinal_llista(l))
   {
       printf("%i", l.ant->seg->indentificador);
       l=Seguent_llista(l);
   }
   printf("\n");
}

void Print_llista_simbols(Llista l)
{
   l=Principi_llista(l);
   while(!EsFinal_llista(l))
   {
       printf("%c", Actual_llista_simbols(l));
       l=Seguent_llista(l);
   }
   printf("\n");
}

void Print_arbre(Llista l)
{
   l=Principi_llista(l);
   while(!EsFinal_llista(l))
   {
       printf("%c:%d\t", l.ant->seg->simbol, l.ant->seg->frecuencia);
       if(l.ant->seg->fill_e) printf("FE=>%c:%d\t", l.ant->seg->fill_e->simbol, l.ant->seg->fill_e->frecuencia);
       if(l.ant->seg->fill_d) printf("FD=>%c:%d\n", l.ant->seg->fill_d->simbol, l.ant->seg->fill_d->frecuencia);
        printf("\n");
       l=Seguent_llista(l);
   }
   printf("\n");
}

void Print_llista_frecuencies(Llista l)
{
   l=Principi_llista(l);
   while(!EsFinal_llista(l))
   {
       printf("%d", Actual_llista_frecuencia(l));
       l=Seguent_llista(l);
   }
   printf("\n");
}
void Esborrar_tota_llista(Llista l)
{
    l=Principi_llista(l);
    while (!EsFinal_llista(l))
    {
        l=Esborrar_llista(l);
    }
}

Llista Frecuencia (char missatge [])
{
    Llista l;

    char simbol_actual;

    Parella * p;

    int i = 0;

    unsigned int repetit=0;

    l = Crear_llista();

    while (missatge[i]!= '\0')
    {
        repetit = 0;
        simbol_actual = missatge[i];
        l=Principi_llista(l);
        while(!EsFinal_llista(l))
        {
            if((*l.ant).simbol == simbol_actual)
            {
                (*l.ant).frecuencia = (*l.ant).frecuencia + 1;
                repetit = 1;
            }
            if(!EsFinal_llista(l))
                l = Seguent_llista(l);
        }
        if((*l.ant).simbol == simbol_actual)
        {

            (*l.ant).frecuencia = (*l.ant).frecuencia + 1;
            repetit = 1;
        }
        if(!repetit)
        {
            p = (Parella *)malloc(sizeof(Parella));
            p->frecuencia=1;
            p->simbol=missatge[i];
            p->indentificador=-1;
            p->fill_d = NULL;
            p->fill_e = NULL;
            l = Inserir_llista(l, p);
        }
        i++;
    }
    l = Ordena(l);
    return l;
}

Llista Crear_arbre (Llista l)
{
    Llista arbre;
    Parella * p;
    unsigned int pdi, pdi_si_final;
       /* Crear el arbol */
   arbre = l;
   arbre = Principi_llista(arbre);
   while(arbre.ant->seg && arbre.ant->seg->seg)
   {
      pdi_si_final = arbre.ant->seg->indentificador;
      p = (Parella *)malloc(sizeof(Parella));
      p->simbol = '0';
      p->fill_e = arbre.ant->seg;
      arbre = Seguent_llista(arbre);
      if (EsFinal_llista(arbre)) pdi = pdi_si_final;
      else pdi = arbre.ant->seg->indentificador;
      p->fill_d = arbre.ant->seg;
      arbre = Seguent_llista(arbre);

                /* Rama cero */
      p->frecuencia = p->fill_d->frecuencia +
                      p->fill_e->frecuencia;
      p->indentificador=-1;
      arbre = Inserir_llista(arbre, p);
      arbre = Ordena(arbre);
      arbre = Principi_llista(arbre);
      while(!EsFinal_llista(arbre) && pdi!=arbre.ant->seg->indentificador)
      {
          arbre=Seguent_llista(arbre);
      }
      arbre = Seguent_llista(arbre);/*vull anar a la psoicio seguent del fill dret*/
   }
   return arbre;
}


/* Buscar un caracter en la taula, retorna un puntero al element de la taula */
tipusTaula *BuscaCaracter(tipusTaula *Taula, char c)
{
   tipusTaula *t;

   t = Taula;
   while(t && t->lletra != c){t = t->sig;}
   return t;
}

void Codificar(Parella * arbre, char codi[])
{
    int len = strlen(codi);
    char string[1000];
    strcpy(string, codi);
    if(arbre->fill_e)
    {
        string[len] = '0';
        Codificar(arbre->fill_e, string);
    }
    if(arbre->fill_d)
    {
        string[len] = '1';
        Codificar(arbre->fill_d, string);
    }
    if(!arbre->fill_d && !arbre->fill_e)
        InsertarTaula(arbre->simbol, codi);
}

void Print_taula ()
{
    while(Taula)
    {
        printf("%c:%s\n",Taula->lletra, Taula->codificacio);
        Taula= Taula->sig;
    }
}

