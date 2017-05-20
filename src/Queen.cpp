#include "Queen.h"
#include <allegro.h>
#include <allegro_primitives.h>

Queen::Queen()
{
    //ctor
}

Queen::~Queen()
{
    //dtor
}

void Queen::setPosx(int pX){

    X = pX;
}

void Queen::setPosy(int pY){

    Y = pY;
}

void Queen::setImagen( ALLEGRO_BITMAP *Imagen){

    ImagenQ = Imagen;
}

void Queen::setDanger(bool danger){

    Danger = danger;
}



void Queen::DrawQueen(){
    if(draw==true){
        al_draw_bitmap(ImagenQ, X *25, Y * 25, 0);
        }
}

void Queen::UpdateQueen(){

    //X += 50;
}

int Queen::getPosX(){

    return X;
}

int Queen::getPosY(){

    return Y;
}

bool Queen::getDanger(){

    return Danger;
}



void Queen::setDraw(){
    if (draw == false)
        draw = true;
    else
        draw = false;
    }


bool Queen::getDraw(){
    return draw;
}
