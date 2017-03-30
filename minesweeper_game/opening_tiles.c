#include <stdio.h>


void opening_tiles(int **board,int **hidden,int row,int column,int size){
  if(board[row][column]!=0){
    hidden[row][column]=board[row][column];
  }
  else if(board[row][column]==0){
      hidden[row][column]=board[row][column];
      if(row==0 && column==0){
        if(hidden[1][0]==-1)
          opening_tiles(board,hidden,1,0,size);
        if(hidden[0][1]==-1)
          opening_tiles(board,hidden,0,1,size);
        if(hidden[1][1]==-1)
          opening_tiles(board,hidden,1,1,size);
      }
      if(row==0 && column==size-1){
        if(hidden[0][size-2]==-1)
          opening_tiles(board,hidden,0,size-2,size);
        if(hidden[1][size-2]==-1)
          opening_tiles(board,hidden,1,size-2,size);
        if(hidden[1][size-1]==-1)
          opening_tiles(board,hidden,1,size-1,size);
      }
      if(row==size-1 && column==0){
        if(hidden[size-2][0]==-1)
          opening_tiles(board,hidden,size-2,0,size);
        if(hidden[size-2][1]==-1)
          opening_tiles(board,hidden,size-2,1,size);
        if(hidden[size-1][1]==-1)
          opening_tiles(board,hidden,size-1,1,size);
      }
      if(row==size-1 && column==size-1){
        if(hidden[size-1][size-2]==-1)
          opening_tiles(board,hidden,size-1,size-2,size);
        if(hidden[size-2][size-2]==-1)
          opening_tiles(board,hidden,size-2,size-2,size);
        if(hidden[size-2][size-1]==-1)
          opening_tiles(board,hidden,size-2,size-1,size);
      }
      if(row>0 && row<size-1 && column==0){
        if(hidden[row-1][column]==-1)
          opening_tiles(board,hidden,row-1,column,size);
        if(hidden[row-1][column+1]==-1)
          opening_tiles(board,hidden,row-1,column+1,size);
        if(hidden[row][column+1]==-1)
          opening_tiles(board,hidden,row,column+1,size);
        if(hidden[row+1][column+1]==-1)
          opening_tiles(board,hidden,row+1,column+1,size);
        if(hidden[row+1][column]==-1)
          opening_tiles(board,hidden,row+1,column,size);
      }
      if(column>0 && column<size-1 && row==0){
        if(hidden[row][column-1]==-1)
          opening_tiles(board,hidden,row,column-1,size);
        if(hidden[row+1][column-1]==-1)
          opening_tiles(board,hidden,row+1,column-1,size);
        if(hidden[row+1][column]==-1)
          opening_tiles(board,hidden,row+1,column,size);
        if(hidden[row+1][column+1]==-1)
          opening_tiles(board,hidden,row+1,column+1,size);
        if(hidden[row][column+1]==-1)
          opening_tiles(board,hidden,row,column+1,size);
      }
      if(column>0 && column<size-1 && row==size-1){
        if(hidden[row][column-1]==-1)
          opening_tiles(board,hidden,row,column-1,size);
        if(hidden[row-1][column-1]==-1)
          opening_tiles(board,hidden,row-1,column-1,size);
        if(hidden[row-1][column]==-1)
          opening_tiles(board,hidden,row-1,column,size);
        if(hidden[row-1][column+1]==-1)
          opening_tiles(board,hidden,row-1,column+1,size);
        if(hidden[row][column+1]==-1)
          opening_tiles(board,hidden,row,column+1,size);
      }
      if(row>0 && row<size-1 && column==size-1){
        if(hidden[row-1][column]==-1)
          opening_tiles(board,hidden,row-1,column,size);
        if(hidden[row-1][column-1]==-1)
          opening_tiles(board,hidden,row-1,column-1,size);
        if(hidden[row][column-1]==-1)
          opening_tiles(board,hidden,row,column-1,size);
        if(hidden[row+1][column-1]==-1)
          opening_tiles(board,hidden,row+1,column-1,size);
        if(hidden[row+1][column]==-1)
          opening_tiles(board,hidden,row+1,column,size);
      }
      if((row>0 && row<size-1) && (column>0 && column<size-1)){
        if(hidden[row-1][column-1]==-1)
          opening_tiles(board,hidden,row-1,column-1,size);
        if(hidden[row-1][column]==-1)
          opening_tiles(board,hidden,row-1,column,size);
        if(hidden[row-1][column+1]==-1)
          opening_tiles(board,hidden,row-1,column+1,size);
        if(hidden[row][column+1]==-1)
          opening_tiles(board,hidden,row,column+1,size);
        if(hidden[row+1][column+1]==-1)
          opening_tiles(board,hidden,row+1,column+1,size);
        if(hidden[row+1][column]==-1)
          opening_tiles(board,hidden,row+1,column,size);
        if(hidden[row+1][column-1]==-1)
          opening_tiles(board,hidden,row+1,column-1,size);
        if(hidden[row][column-1]==-1)
          opening_tiles(board,hidden,row,column-1,size);
      }
    }
}
