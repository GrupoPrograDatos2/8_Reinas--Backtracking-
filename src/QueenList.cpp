#include "QueenList.h"
#include "Queen.h"

QueenList::QueenList(Queen Reinas[], int size, ALLEGRO_BITMAP *Imagen){
        int movex = 0;
        int margen = 50;

        for( int i = 0; i < size; i++){


        Reinas[i].setDanger(true);

        Reinas[i].setPosx(0);
        Reinas[i].setPosy(0);
        Reinas[i].setImagen(Imagen);
        //Reinas[i].setDraw();
        movex = movex + margen;
        }
}

QueenList::~QueenList()
{
    //dtor
}

void QueenList::DrawQueens(Queen Reinas[], int size){
    int cont = 0;
    while(cont < 1000){
        cont++;
    }
    if ( cont == 1000){
            for(int i = 0; i < size; i++){

            if(Reinas[i].getDanger()){

                Reinas[i].DrawQueen();
            }


        }

    }


}
//no necesito esto creo!!/
void QueenList::StarQueen(Queen Reinas[], int size){

    for( int i = 0; i < size; i++){

        if( !Reinas[i].getDanger()){
            if(rand() % 500 ==0){
                Reinas[i].setDanger(true);
                Reinas[i].setPosx(0);
                //Reinas[i].setPosy(20+rand() % (400 -20));

                break;
            }
        }
    }
}

void QueenList::UpdateQueen(Queen Reinas[], int size){

    for(int i = 0; i < size; i++){

        if ( Reinas[i].getDanger()== true){

            Reinas[i].UpdateQueen();
            /*if (Reinas[i].getPosX() > 400){
                Reinas[i].setDanger(false);
            }*/
        }

    }
}


