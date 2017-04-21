#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int a[10][10];
int i,j;
void display(int, int);


int main(){
	
	int endLoop = 0;
	char c;
	i = 5;
	j = 5;
	display(5,5);
	
	while(endLoop == 0){
		
		c = getch();
		
		switch(c){
			
			case 'w':
				i -= 1;
				display(i,j);
				break;
			case 'a':
				j -= 1;
				display(i,j);
				break;
			case 's':
				i += 1;
				display(i,j);
				break;
			case 'd':
				j += 1;
				display(i,j);
				break;
			case ';':
				endLoop = 1;
				break;
			
		}
	}
	
}

void display(int ipos, int jpos){
	
	int i,j;
	system("cls");
	
	for(i = 0; i < 10; i++){
		
		for(j = 0; j < 10; j++){
			
			if(i == ipos && j == jpos)	 printf("1");
			else printf(".");
			
		}
		printf("\n");
		
	}
	
	printf("\nPress W A S D to move, and ; to exit\n");
	
}