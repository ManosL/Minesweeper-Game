#include <stdio.h>


int check_win(int **board,int **hidden,int size){
  int i,j,flag=0;
  for(i=0;i<size;i++){
    for(j=0;j<size;j++){
      
      if(board[i][j]!=hidden[i][j] && board[i][j]<'*')
        return 0;
    }
  }
  return 1;
}
