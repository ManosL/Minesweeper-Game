#ifndef MINESWEEPER_FUNCTIONS_H_INCLUDED
#define MINESWEEPER_FUNCTIONS_H_INCLUDED

 void boardfill(int**,int,int,double);
 void print_real_board(int**,int);
 void print_hidden_board(int**,int**,int);
 int check_win(int**,int**,int);
 void opening_tiles(int**,int**,int,int,int);

#endif // MINESWEEPER_FUNCTIONS_H_INCLUDED
