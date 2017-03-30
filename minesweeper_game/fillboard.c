#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void boardfill(int **board,int size,int available_flags,double percentage){
  double number;
  int i,j;

  while(available_flags>0){
	  for(i=0;i<size;i++){
		  for(j=0;j<size;j++){
        if(available_flags>0){
			    number=(((double)rand())/((double) RAND_MAX));
              if(number<=percentage && board[i][j]!='*'){
            	  board[i][j]='*';
                available_flags=available_flags-1;
              }
        }
		  }
	  }
  }

  for(i=0;i<size;i++){
    for(j=0;j<size;j++){
      if(board[i][j]!='*'){
        board[i][j]=0;
      }
    }
  }
    for(i=0;i<size;i++){
    	for(j=0;j<size;j++){
    		if(board[i][j]>='*'){
    			if(i==0 && j==0){
    				board[1][0]+=1;
    				board[0][1]+=1;
    				board[1][1]+=1;
					}
    			if(i==0 && j==size-1){
    				board[0][size-2]+=1;
    				board[1][size-2]+=1;
    			  board[1][size-1]+=1;
    			}
    			if(i==size-1 && j==0){
            board[size-2][0]+=1;
    				board[size-2][1]+=1;
    	      board[size-1][1]+=1;
    			}
    			if(i==size-1 && j==size-1){
    				board[size-1][size-2]+=1;
    				board[size-2][size-2]+=1;
    				board[size-2][size-1]+=1;
    			}
    			if(i>0 && i<size-1 && j==0){
						board[i-1][j]+=1;
    			  board[i-1][j+1]+=1;
    				board[i][j+1]+=1;
						board[i+1][j+1]+=1;
						board[i+1][j]+=1;
					}
					if(j>0 && j<size-1 && i==0){
						board[i][j-1]+=1;
    				board[i+1][j-1]+=1;
    				board[i+1][j]+=1;
						board[i+1][j+1]+=1;
						board[i][j+1]+=1;
					}
					if(j>0 && j<size-1 && i==size-1){
						board[i][j-1]+=1;
    				board[i-1][j-1]+=1;
    				board[i-1][j]+=1;
						board[i-1][j+1]+=1;
						board[i][j+1]+=1;
					}
					if(i>0 && i<size-1 && j==size-1){
						board[i-1][j]+=1;
    				board[i-1][j-1]+=1;
    				board[i][j-1]+=1;
						board[i+1][j-1]+=1;
						board[i+1][j]+=1;
					}
					if((i>0 && i<size-1) && (j>0 && j<size-1)){
						board[i-1][j-1]+=1;
    				board[i-1][j]+=1;
    				board[i-1][j+1]+=1;
						board[i][j+1]+=1;
						board[i+1][j+1]+=1;
						board[i+1][j]+=1;
    				board[i+1][j-1]+=1;
						board[i][j-1]+=1;
					}
    		}
    	}
    }
}
