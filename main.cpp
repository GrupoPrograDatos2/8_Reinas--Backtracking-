#include <iostream>
#include<allegro.h>
#include<stdio.h>
#include<allegro_native_dialog.h>
#include<allegro_image.h>
#include<allegro_ttf.h>
#include<allegro_font.h>
#include<allegro_primitives.h>
#include "Queen.h"
#include "QueenList.h"
#include "Background.h"
#define N 8
#include<stdio.h>

using namespace std;


int tam_cuadrito = 50;
int Xini1 = 0;
int Yini1 = 0;
int Xini2 = 50;
int Yini2 = 50;
//char a[8][8];
int n , num = 8;
int board[N][N] = { {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
    };



///prototipo de funcion

void MakeChess();
void MoveQueen();
void printmatrix();
int getmarkedcol(int row);
int ChekPos(int row, int col);
void nqueen(int row);
void printSolution(int board[N][N]);
bool isSafe(int board[N][N], int row, int col);
bool solveNQUtil(int board[N][N], int col);
void solveNQ();
void Nqueens(int board, Queen Queens);

///Main :D

int main(void){

    bool done = false;
    int cont = 0;
    const int FPS = 60;
    bool redraw = true;

    //Variables ALLEGRO
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_BITMAP *Queen_Image;
    ALLEGRO_BITMAP *Chess_Image;

    if (!al_init()){
        return -1;
    }

    display = al_create_display(400,400);

    if (!display){
            return -1;
    }


    al_init_primitives_addon();
    al_init_image_addon();

    Queen_Image = al_load_bitmap("Queen2.png");
    Chess_Image = al_load_bitmap("Chess_Image.png");

    timer = al_create_timer(1.0 / FPS);
    event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_display_event_source(display));



    //al_set_window_position(display, 100,10);
    al_set_window_title(display, "8 Reinas -Backtracking-");

    //MakeChess();

    //ALLEGRO_BITMAP *Queen_Imagen;

    //al_draw_bitmap(Queen_image, 13.0, 12.0, NULL);



    /*for(int i = 0; i < 8; i++){

        for(int j = 0; j < 8; j++){

            a[i][j] = '.';
        }
    }*/
    ///nqueen(0);
    solveNQ();

    Background BG(0, 0, 0, 1, 400,400, 1, 1, Chess_Image);
    Queen Reinas[8];
    QueenList Queen_List(Reinas, num, Queen_Image);



    al_start_timer(timer);

    while(!done){

        ALLEGRO_EVENT evento;
        al_wait_for_event(event_queue, &evento);


        if(evento.type == ALLEGRO_EVENT_TIMER)
        {
            redraw = true;
            Queen_List.StarQueen(Reinas, num);

            Queen_List.UpdateQueen(Reinas, num);



        }




        if (redraw && al_is_event_queue_empty(event_queue))
        {
                redraw = false;


                BG.DrawBackground();

                //Queen_List.DrawQueens(Reinas, num);

                    for ( int i = 0; i < 8; i++){
                        for ( int j = 0; i < 8; i++){
                            if (board[i][j] == 1){
                                Queen_List.DrawQueens(Reinas, num);
                        }



                    }
            }



                al_flip_display();

                al_clear_to_color(al_map_rgb(0,0,0));
        }




    }




    al_destroy_bitmap(Queen_Image);
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);
    //al_destroy_timer(timer);





    return 0;
}

/*void MakeChess(){

    int band = 1;
    ALLEGRO_COLOR Azul_Pichudo = al_map_rgb(44, 117, 255);

    for( int fila = 0; fila < 8; fila++){
            for (int col = 0; col < 8; col++){
                    if ( (fila % 2)== 0){
                        if (band == 1){
                            al_draw_filled_rectangle(Xini1, Yini1, Xini2 , Yini2, Azul_Pichudo);
                            Xini1 = Xini1 + tam_cuadrito;
                            Xini2 = Xini2 + tam_cuadrito;
                            band = 0;
                        }
                        else {
                            Xini1 = Xini1 + tam_cuadrito;
                            Xini2 = Xini2 + tam_cuadrito;
                            band = 1;
                        }
                    }
                    else{
                        if ( band ==1){
                            Xini1 = Xini1 + tam_cuadrito;
                            Xini2 = Xini2 + tam_cuadrito;
                            band = 0;

                        }
                        else{
                            al_draw_filled_rectangle(Xini1, Yini1, Xini2 , Yini2, Azul_Pichudo);
                            Xini1 = Xini1 + tam_cuadrito;
                            Xini2 = Xini2 + tam_cuadrito;
                            band = 1;
                        }
                    }

            }
            Yini1 = Yini1 + tam_cuadrito;
            Yini2 = Yini2 + tam_cuadrito;
            Xini1 = 0;
            Xini2 = 50;

    }


}*/


/*
void printmatrix() {

   int i, j;
   cout<<("\n");
   for (i = 0; i < 8; i++) {
      for (j = 0; j < 8; j++)
        cout<<("%c\t", a[i][j]);
      cout<<("\n\n");

   }

}

int getmarkedcol(int row) {


   for (int i = 0; i < 8; i++)
      if (a[row][i] == 'Q') {
         return (i);
         break;
      }
}

int ChekPos(int row, int col) {

   int i, tcol;
   for (i = 0; i < 8; i++) {
      tcol = getmarkedcol(i);
      if (col == tcol || abs(row - i) == abs(col - tcol))
         return 0;
   }
   return 1;
}

void nqueen(int row) {

   int j;
   if (row < 8)   {
      for (int i = 0; i < 8; i++) {
         if (ChekPos(row, i)) {
            a[row][i] = 'Q';

            nqueen(row + 1);
            a[row][i] = '.';


         }
      }
   } else {
      printf("\nThe solution is:- ");
      printmatrix();
   }
}*/
///NewN_Queen
/* A utility function to print solution */
void printSolution(int board[N][N])
{
    static  int k = 1;
    printf("%d-\n",k++);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int board[N][N], int row, int col)
{
    int i, j;

    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    /* Check upper diagonal on left side */
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;

    /* Check lower diagonal on left side */
    for (i=row, j=col; j>=0 && i<N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int board[N][N], int col)
{
    /* base case: If all queens are placed
    then return true */
    if (col == N )
    {
        printSolution(board);
        return true;
    }

    /* Consider this column and try placing
    this queen in all rows one by one */
    for (int i = 0; i < N; i++)
    {
        /* Check if queen can be placed on
        board[i][col] */
        if ( isSafe(board, i, col) )
        {
            /* Place this queen in board[i][col] */
            board[i][col] = 1;

            /* recur to place rest of the queens */
            //solveNQUtil(board, col + 1) ;

            // below commented statement is replaced
            // by above one
            if ( solveNQUtil(board, col + 1) )
                 return true;

            /* If placing queen in board[i][col]
            doesn't lead to a solution, then
            remove queen from board[i][col] */
            board[i][col] = 0; // BACKTRACK
        }
    }

    /* If queen can not be place in any row in
        this column col then return false */
    return false;
}

void solveNQ()
{



    if (solveNQUtil(board, 0))
    {
        printf("Solution does not exist");
        return ;
    }

    return ;
}


