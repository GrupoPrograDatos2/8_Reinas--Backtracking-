
/**
*@file QueenList.h
*@date 18/5/2017
*@author Roy Acevedo, Pablo Esquivel, MArycruz cespedes, Steven Vega
*@name Class QueenList
*/

#ifndef QUEENLIST_H
#define QUEENLIST_H
#include "Queen.h"

/**
*@brief Clase para alamacear las Reinas
*/
class QueenList
{
    public:
        /**
        *@brief Constructor de la lista
        */
        QueenList(Queen Reinas[], int size, ALLEGRO_BITMAP *Imagen);
        /**
        *@brief Metodo para Dibujar las Reinas
        */
        void DrawQueens(Queen Reinas[], int size);
        /**
        *@brief Metodo para inicializar a la reina(not used)
        */
        void StarQueen(Queen Reinas[], int size);
        /**
        *@brief Metodo para Actualizar la lista de reinas( not used)
        */
        void UpdateQueen(Queen Reinas[], int size);


        virtual ~QueenList();


    protected:

    private:
};

#endif // QUEENLIST_H
