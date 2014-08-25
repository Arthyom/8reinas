#include"casilla.h"
#include"jugador.h"
#include <iostream>

using namespace std;

int main()
{

                                /* declarar varaibles */
    int Xinicial = 3;       int Yinicial = 6;         int DimX = 8;       int DimY = 8;


    /* crear un nuevo tablero */
    casilla **tablero = new casilla* [DimX];

    for(int i = 0 ; i < DimY ; i++ )
        tablero[i] = new casilla [DimY];

    /* crear un nuevo jugador virtual */
    jugador jugadorV;



  /********************************************** empezar a jugar ********************************************/

        int reinas = 0, indicador = 0, iteracion = 0 ;

        /* mueve tu reina a la posicion inicial, indicada por mi*/
        reinas = jugadorV.MoverPiesa(Xinicial,Yinicial,tablero,DimX);

        /* mientras no se completen las 8 reinas */
        while ( reinas < DimX )
        {
            /* ir al principio */
            if ( iteracion == 0 )
            {
               indicador = jugadorV.MoverPiesa(0,0,tablero,DimX);
               reinas = 0;
            }
                else
                {
                    switch (indicador)
                    {
                        case 1:
                          reinas = reinas + indicador;
                          indicador = jugadorV.MoverPiesa(0,reinas,tablero,DimX);
                        break;


                        case -1:
                           reinas = reinas + indicador;
                           indicador = jugadorV.QuitarPiesa(reinas,tablero,DimX);
                        break;
                    }
                 }
            iteracion++;
        }


        cout<<endl<<"<---------------------------- estado final ------------------------------>"<<endl;
        jugadorV.VerTablero(tablero,DimX);


        cout<<endl<<endl;



    return 0;
}

