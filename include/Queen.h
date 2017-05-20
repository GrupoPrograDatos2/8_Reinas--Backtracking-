
/**
*@file Queen.h
*@date 18/5/2017
*@author Roy Acevedo, Pablo Esquivel, Marycruz Cespedes, Steven Vega
*@name Class Queen
*@brief CLase que me creara el objeto Reina
*/

#ifndef QUEEN_H
#define QUEEN_H
#include <allegro.h>
#include <allegro_primitives.h>

/**
*@brief Clase para crear la Reina
*/
class Queen
{
    public:
        Queen();
        virtual ~Queen();
        /**
        *@brief actualuza posicion de Reina
        */
        void UpdateQueen();
        /**
        *@brief Dibuja la Reina.
        */
        void DrawQueen();
        /**
        *@name Setters
        *@brief para construir por medio ed atributos la reina
        */
        void setPosx(int pX);
        void setPosy(int pY);
        void setDanger(bool danger);
        void setImagen(ALLEGRO_BITMAP *Imagen);
        void setDraw();

        //Getters
        int getPosX();
        int getPosY();
        bool getDanger();
        bool getDraw();



        ALLEGRO_BITMAP *ImagenQ;

    protected:

    private:
        int X;
        int Y;
        bool Danger;
        bool draw = false;

};

#endif // QUEEN_H
