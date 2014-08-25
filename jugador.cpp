#include "jugador.h"
#include<iostream>
    using namespace std;

jugador::jugador(){}



                       /************************** metodos de Ataque ******************************/
void jugador::Atacar        (int Xindicada, int Yindicada, casilla **tablero ,int DimX)
{

    /// atacar en X
    this->AtacarHrzt  ( Xindicada,  Yindicada, tablero, DimX );
    /// atacar en y
    this->AtacarVert  ( Xindicada,  Yindicada, tablero, DimX  );
    /// atacar diagonal Derecha
    this->AtacarDder  ( Xindicada,  Yindicada, tablero, DimX  );
    ///atacar diagonal Izquierda
    this->AtacarDizq  ( Xindicada,  Yindicada, tablero, DimX  );

       tablero[ Xindicada ][Yindicada].estado = Reina ;
}

/* atacar el eje X */
void jugador::AtacarHrzt    (int Xindicada, int Yindicada, casilla **tablero, int DimX)
{
    /// atacar todas la casilla del eje X
    for( int i = 0 ; i < DimX ; i++ )
        tablero[i][Yindicada].estado = Ataque;

}

/* atacar el eje Y */
void jugador::AtacarVert    (int Xindicada, int Yindicada, casilla **tablero,int DimX)
{
    /// atacar todas las casiillas en el eje Y
    for( int j = 0 ; j < DimX ; j++ )
         tablero[Xindicada][j].estado = Ataque;
}

/* atacar Diagonal Derecha */
void jugador::AtacarDder    (int Xindicada, int Yindicada, casilla **tablero,int DimX)
{
    int Xactual = Xindicada, Yactual = Yindicada;

    /// sube hasta donde puedas
    for(int i = 0 ; i < DimX  ; i++)
    {
        if( Xactual < DimX - 1 && Yactual >0 )
            Xactual++, Yactual--;

        /// llegaste hasta arriba
        else
            break;
    }

    /// Baja la diagonal y ataca!!!
    for( int i = 0 ; i < DimX  ; i++)
    {
            if( Xactual > -1 && Yactual < DimX )
            {
                    tablero[ Xactual ][ Yactual ].estado = Ataque;
                    Xactual--, Yactual++;
            }
            else
                break;
    }

}

/* atacar Diagonal Izquierda*/
void jugador::AtacarDizq    (int Xindicada, int Yindicada, casilla **tablero,int DimX)
{
    int Xactual = Xindicada, Yactual = Yindicada;

    /// sube hasta donde puedas
    for(int i = 0 ; i < DimX ; i++)
    {
        if( Xactual > 0 && Yactual > 0 )
            Xactual--, Yactual--;

        /// llegaste hasta arriba
        else
            break;

    }

    /// Baja la diagonal y ataca!!!
    for( int i = 0 ; i < DimX ; i++)
    {
           if( Xactual < DimX   && Yactual < DimX  )
              {
                 tablero[ Xactual ][ Yactual ].estado = Ataque;
                 Xactual++, Yactual++;
               }
                else
                    break;

    }
}


void jugador::ReeAtacar     (casilla **tablero, int DimX)
{
    /// recorrer todo el tablero buscando reinas y reestableciondo sus ataques
    for(int i = 0 ; i < DimX  ; i++)
    {
        for(int j = 0 ; j < DimX ; j ++)
        {
            if( tablero[j][i].estado == Reina)
            this->Atacar(j,i,tablero,DimX);
        }
    }



}



                   /// ************************* metodos de usuario **************************** ///
int jugador::BuscarReina    (int Yincial, casilla **tablero, int DimX)
{
    /// buscar a ala reina en la linea especificada
    for(int i = 0 ; i < DimX ; i++)
    {
        if( tablero[i][ Yincial ].estado == Reina )
            return i;
    }


    return 0;
}

void jugador::VerTablero    (casilla **tablero , int DimX)
{

    for(int i = 0 ; i < DimX ; i++)
    {
        cout<<endl;
        for(int j = 0 ; j < DimX ; j++)
            cout<<" "<<tablero[j][i].estado;
    }



}

int jugador::MoverPiesa     (int Xindicada, int Yindicada, casilla **tablero,int DimX)
{
  /// hay casillas libres en la linea indicada?
  while( Xindicada < DimX  )
  {
      /// la casilla indicada esta libre?
      if( tablero[ Xindicada ][Yindicada].estado == Libre )
      {
          this->Atacar( Xindicada, Yindicada, tablero,DimX );
          return 1;
      }

      /// sino esta libre, consigue otra casilla y ocupala
      else
         Xindicada++;
  }

  /// si ya no hay casillas libres en la lines indicada...avisame
    return -1;
}

int jugador::QuitarPiesa    (int Yactual, casilla **tablero, int DimX)
{


    int Xactual = this->BuscarReina( Yactual,tablero,DimX);

    /* suspender a al reina hayallada */
    this->Liberar(Xactual,Yactual,tablero,DimX);
    this->ReeAtacar(tablero,DimX);

    Xactual++;

    /* hay casillas libres en la linea donde estas? */
    while (Xactual < DimX)
    {
        /** la casilla indicada esta libre ?*/
        if ( tablero[Xactual][Yactual].estado == Libre )
        {
            /* si lo esta ocupala y ataca!!! */
            this->Atacar(Xactual,Yactual,tablero,DimX);

            /* si puedo cambiar mi posicion entonces
             regreso 1 para ir a la linea siguente */
            return 1;
        }
        /*** no lo esta, consigue la siguente casilla y veficala ***/
        else
            Xactual++;
    }
    return -1;
}




                  /************************** metodos de liberacion ***************************/

void jugador::Liberar       (int Xindicada, int Yindicada, casilla **tablero,int DimX)
{
    /// liberar en X
    this->FreeHrzt  ( Xindicada,  Yindicada, tablero , DimX );

    /// liberar en y
    this->FreeVert  ( Xindicada,  Yindicada, tablero  , DimX );

    /// liberar diagonal Derecha
    this->FreeDder  ( Xindicada,  Yindicada, tablero  , DimX );

    /// liberar diagonal Izquierda
    this->FreeDizq  ( Xindicada,  Yindicada, tablero  , DimX );

    tablero[ Xindicada ][ Yindicada ].estado = Libre;
}

void jugador::FreeHrzt       (int Xindicada, int Yindicada, casilla **tablero, int DimX)
{
    ///  liberar todas las casillas  en el eje X
    for( int i = 0 ; i < DimX ; i++ )
        tablero[i][Yindicada].estado = Libre;
}

void jugador::FreeVert       (int Xindicada, int Yindicada, casilla **tablero, int DimX)
{
    /// liberar todas las casillas en el eje Y
    for( int j = 0 ; j < DimX ; j++ )
        tablero[Xindicada][j].estado = Libre;
}

void jugador::FreeDder       (int Xindicada, int Yindicada, casilla **tablero ,int DimX)
{
    int Xactual = Xindicada, Yactual = Yindicada;
    /// sube hasta donde puedas
    for(int i = 0 ; i < DimX ; i++)
    {
        if( Xactual < DimX  && Yactual > 0 )
            Xactual++, Yactual--;
        else
            break;
    }

    /// Baja la diagonal y Libera!!!
    for( int i = 0 ; i < DimX ; i++)
    {
            if( Xactual > DimX && Yactual < DimX )
            {
                tablero[ Xactual ][ Yactual ].estado = Libre;
                Xactual--, Yactual++;
            }
            else
                break;
    }
}


void jugador::FreeDizq       (int Xindicada, int Yindicada, casilla **tablero ,int DimX)
{
    int Xactual = Xindicada, Yactual = Yindicada;
    /// sube hasta donde puedas
    for(int i = 0 ; i < DimX ; i++)
    {
        if( Xactual >  0 && Yactual > 0 )
            Xactual--, Yactual--;
        else
            break;
    }


    for( int i = 0 ; i < DimX ; i++)
    {
            if( Xactual <DimX  && Yactual <DimX )
                /// Baja la diagonal y libera!!!
            {
                tablero[ Xactual ][ Yactual ].estado = Libre;
                Xactual++, Yactual++;
            }
            else
                break;
    }
}

