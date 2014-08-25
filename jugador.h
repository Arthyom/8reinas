#ifndef  JUGADOR_H
#define  JUGADOR_H

#include "casilla.h"


    class jugador
{
        public:

             jugador();


             int  MoverPiesa    (int, int, casilla **,int);
             int  QuitarPiesa   (int, casilla **, int );


                         /* Metodos de ataque */
             void  Atacar       (int, int, casilla **,int);

             void  AtacarVert   (int, int, casilla **,int);
             void  AtacarHrzt   (int, int, casilla **,int);
             void  AtacarDizq   (int, int, casilla **,int);
             void  AtacarDder   (int, int, casilla **,int);

             void  ReeAtacar    (casilla **,int );



                      /* Metodos de liberacion */
             void  Liberar      (int, int, casilla **,int);

             void  FreeVert     (int, int, casilla **,int);
             void  FreeHrzt     (int, int, casilla **,int);
             void  FreeDizq     (int, int, casilla **,int);
             void  FreeDder     (int, int, casilla **,int);

             int   BuscarReina  (int,casilla**,int);


             void  VerTablero (casilla **, int);
};

#endif // JUGADOR_H
