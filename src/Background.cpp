#include "Background.h"

Background::Background()
{
    //ctor
}

Background::Background( float px, float py, float pvelX, float pvelY, int pwidth, int pheight, int pdirx, int pdiry, ALLEGRO_BITMAP *pimage)
{
    x = px;
    y = py;
    velX = pvelX;
    velY = pvelY;
    width = pwidth;
    height = pheight;
    dirX = pdirx;
    dirY = pdiry;
    image = pimage;
}

Background::~Background()
{
    //dtor
}

void Background::DrawBackground()
{
    al_draw_bitmap(image, x, y, 0);
    //al_draw_bitmap(image, x, y-height, 0);

}
