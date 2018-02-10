#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

typedef struct snakeBody{
	int i,j,food;
	struct snakeBody *back, *front;
}snakeBody;

int mat[50][50] = {0};
snakeBody *head, *tail;

int fi,fj;

char movement;

void paint();
void repaint(char);

int main(){
	
	mat[4][4] = 2;
	int endLoop = 0;
	char c;
	snakeBody *body1, *body2;
	movement = 'd';
	
	head = (snakeBody*)malloc(sizeof(snakeBody));
	body1 = (snakeBody*)malloc(sizeof(snakeBody));
	body2 = (snakeBody*)malloc(sizeof(snakeBody));
	
	head->i = 10;
	head->j = 10;
	head->food = 0;
	head->back = body1;
	head->front = NULL;
	
	body1->i = 10;
	body1->j = 9;
	body1->food = 0;
	body1->back = body2;
	body1->front = head;
	
	body2->i = 10;
	body2->j = 8;
	body2->food = 0;
	body2->back = NULL;
	body2->front = body1;
	
	tail = body2;
	
	paint();
	
	
	/*while(endLoop == 0){
		
		c = getch();
		
		if(c == ';') break;
		else if(c == 'w' ||c == 'a' ||c == 's' ||c == 'd') repaint(c);
		else continue;
		
	}*/
	
	while(1){
		
		if(kbhit()){
			c = getch();
			if(c == ';') break;
			else if(c == 'w' ||c == 'a' ||c == 's' ||c == 'd') repaint(c);
			else continue;
		}
		else repaint(movement);
		Sleep(100);
		
	}
	
}

void paint(){
	
	int i,j;
	snakeBody *ptr;
	
	ptr = head;
	
	while(ptr != NULL){
		if(ptr->food == 1) mat[ptr->i][ptr->j] = 3;
		else mat[ptr->i][ptr->j] = 1;
		ptr = ptr->back;
	}
	
	system("cls");
	for(i = 0; i < 50; i++){
		for(j = 0; j < 50; j++){
			if(mat[i][j] == 0)
				printf(" ");
			else if(mat[i][j] == 1)
				printf("O");
			else if(mat[i][j] == 2)
				printf("f");
			else if(mat[i][j] == 3)
				printf("@");
		}
		printf("\n");
	}
	
	//printf("\n\nUse W,A,S,D, to move. Press ';' to exit.");
	
}

void repaint(char c){
	
	snakeBody *ptr, *temp;
	ptr = tail;
	int tempi,tempj, i2,j2, flag=0;
	
	if(tail->food == 1){
		flag = 1;
		temp = (snakeBody*)malloc(sizeof(snakeBody));
		tail->food = 0;
		temp->i = tail->i;
		temp->j = tail->j;
		temp->food = 0;
		tail->food = 0;
		temp->front = tail;
		tail->back = temp;
		temp->back = NULL;
	}
	
	while(ptr->front != NULL){
		mat[ptr->i][ptr->j] = 0;
		ptr->i = ptr->front->i;
		ptr->j = ptr->front->j;
		ptr->food = ptr->front->food;
		ptr->front->food = 0;
		ptr = ptr->front;	
	}
	
	if(flag == 1) tail = temp;
	
	movement = c;
	
	switch(c){
			
		case 'w':
			ptr->i -= 1;
			break;
		case 'a':
			ptr->j -= 1;
			break;
		case 's':
			ptr->i += 1;
			break;
		case 'd':
			ptr->j += 1;
			break;
	}
	
	if(mat[ptr->i][ptr->j] == 2) {
		
		ptr->food = 1;
		while(1){
			srand(time(NULL));
			fi = rand() % 50;
			fj = rand() % 50;
			if(mat[fi][fj] == 0){
				mat[fi][fj] = 2;
				break;
			}
		}
		
	}
	
	paint();
}
	
	