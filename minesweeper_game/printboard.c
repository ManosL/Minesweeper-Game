#include <stdio.h>

void print_hidden_board(int **hidden,int **board,int size){
  int i,j;
  printf("   ");
  for(i=0;i<size;i++){
    printf("%d ",i);
  }printf("\n");
  printf("  ");
  for(i=0;i<size;i++){
    printf("|-");
  }printf("|\n");
  for(i=0;i<size;i++){
    printf("%d ",i);
    for(j=0;j<size;j++){
      if(hidden[i][j]>=0 && hidden[i][j]!='F'){
        printf("|%d",hidden[i][j]);
      }
      if(hidden[i][j]=='F'){
        printf("|F");
      }
      if(hidden[i][j]<0)
      printf("|X");
    }printf("| %d\n",i);
  }
  printf("  ");
  for(i=0;i<size;i++){
    printf("|-");
  }printf("|\n");
  printf("   ");
  for(i=0;i<size;i++){
    printf("%d ",i);
  }printf("\n");
}

void print_real_board(int **board,int size){
  int i,j;
  for(i=0;i<size;i++){
    for(j=0;j<size;j++){
      if(board[i][j]>='*')
        printf("* ");
      else
        printf("%d ",board[i][j]);
      if(j==size-1){
        printf("\n");
      }
    }
}
}
