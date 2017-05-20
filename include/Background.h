
/**
*@file Backtracking.h
*@date 18/5/2017
*@author Roy Acevedo, Pablo Esquivel, MArycruz cespedes, Steven Vega
*@name Class Background
*/

#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <allegro.h>
#include <allegro_image.h>

/**
*@brief Background es la clase que se encargara del fondo del tablero.
*@param Posiciones en donde hacer un situar el fondo de el tablero.
*@return Imágen de fondo.
*/
class Background
{
    public:
        Background();
        Background(float px, float py, float pvelX, float pvelY, int pwidth, int pheight, int pdirx, int pdiry, ALLEGRO_BITMAP *pimage);
        virtual ~Background();

        float x, y, velX, velY;
        int dirX, dirY;

        int width, height;

        ALLEGRO_BITMAP *image;


        /**
        *brief Metodo que coloca la imagen.
        */
        void DrawBackground();

    protected:

    private:
};

#endif // BACKGROUND_H
