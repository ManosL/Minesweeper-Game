#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "minesweeper_functions.h"

int main(void){
	int **hidden,**board,size,row=10000,column=10000,leitourgia=-1,available_flags,result,difficulty=-1;
	double percentage;
	int i,j;

	srand(time(NULL));
  printf("Welcome to my minesweeper game\n");
	while(difficulty!=1 && difficulty!=2 && difficulty!=3){
	printf("Choose difficulty(1=easy,2=medium,3=hard)\n");
	scanf("%d",&difficulty);
	if(difficulty!=1 && difficulty!=2 && difficulty!=3){
		printf("please give a right value\n");
	}
}
	printf("Enter the size of the board(board is squared,so give one number):");
	scanf("%d",&size);

  if(difficulty==1){
    available_flags=(15*(size*size))/100;
		percentage=0.15;
	}
	if(difficulty==2){
		available_flags=(30*(size*size))/100;
		percentage=0.3;
	}
	if(difficulty==3){
		available_flags=(60*(size*size))/100;
		percentage=0.6;
	}

	board=malloc(size*sizeof(int*));
	for(i=0;i<size;i++){
		board[i]=malloc(size*sizeof(int));
	}

	hidden=malloc(size*sizeof(int*));
	for(i=0;i<size;i++){
		hidden[i]=malloc(size*sizeof(int));
	}

	for(i=0;i<size;i++){      /*Filling hidden array*/
		for(j=0;j<size;j++){
			hidden[i][j]=-1;
		}
	}


    boardfill(board,size,available_flags,percentage);
		print_hidden_board(hidden,board,size);
	while(size>0){
		//print_real_board(board,size); /*this line was Only for testing*/
		while(leitourgia!=1 && leitourgia!=0 && leitourgia!=2){
		  printf("To open(=1),to put flag(=0) or to reset flag(=2)?\n");
		  scanf("%d",&leitourgia);
			if(leitourgia!=1 && leitourgia!=0 && leitourgia!=2){
				printf("Please give a right value\n");
			}
	}
    while(row>=size || column>=size){
		  printf("Available flags: %d\n",available_flags);
		  printf("Give the row,the column of the tile you want to <<open>>(e.g. 0 1)\n");
		  scanf("%d %d",&row,&column);
			if(row>=size || column>=size){
				printf("Please give a valid position of a box\n");
			}
		}
		if(leitourgia==1){
			if(hidden[row][column]=='F'){
				printf("\033[2J\033[1;1H");  /*Makes the illusion that the screen refreshes*/
				print_hidden_board(hidden,board,size);
				printf("You can't open a box which has already a flag\n");
				printf("Please give a position which hasn't any flag or reset the flag\n");
			}
			else{
				if(board[row][column]>='*'){
					printf("\033[2J\033[1;1H");
					printf("You lose!!!\n");
					print_real_board(board,size);
					return 1;
				}
				else{
					opening_tiles(board,hidden,row,column,size);
					printf("\033[2J\033[1;1H");
					print_hidden_board(hidden,board,size);
					result=check_win(board,hidden,size);
					if(result==1){
						printf("You won\n");
						return 1;
					}
				}
			}

		}
		if(leitourgia==0){
			if(available_flags==0){
				printf("\033[2J\033[1;1H");
				print_hidden_board(hidden,board,size);
				printf("No flags available\n");
				printf("Don't give other flag or reset at least one\n");
			}
			else{
			if(hidden[row][column]!='F'){
				if(hidden[row][column]>=0){
					printf("\033[2J\033[1;1H");
					print_hidden_board(hidden,board,size);
					printf("In these position there is an open box!\n");
					printf("Please give a position which isn't open.\n");
				}
				else{
					available_flags=available_flags-1;
					hidden[row][column]='F';
					printf("\033[2J\033[1;1H");
					print_hidden_board(hidden,board,size);
				}
				result=check_win(board,hidden,size);
				if(result==1){
					printf("You won\n");
					return 1;
				}
			}
			else{
				printf("\033[2J\033[1;1H");
				print_hidden_board(hidden,board,size);
				printf("In these position there is already a flag!\n");
				printf("Please give a position which hasn't any flag.\n");
			}
		}
		}
		if(leitourgia==2){
			if(hidden[row][column]=='F'){
				available_flags=available_flags+1;
			  hidden[row][column]=-1;
				printf("\033[2J\033[1;1H");
			  print_hidden_board(hidden,board,size);
			}
			else{
				printf("\033[2J\033[1;1H");
				print_hidden_board(hidden,board,size);
				printf("In these position there aren't any flags!\n");
				printf("Please give a position which has flag.\n");
			}
		}
		row=10000;
		column=10000;
		leitourgia=-1;
		difficulty=-1;
}
for(i=0;i<size;i++){
  free(board[i]);
	free(hidden[i]);
}
free(board);
free(hidden);
return 0;
}
