#ifndef CASILLA_H
#define CASILLA_H

const char Reina    =  'R';
const char Ataque   =  '#';
const char Libre    =  '_';

    struct casilla
{
    public:
        bool  color;
        char  estado;


        casilla();
};

#endif // CASILLA_H
