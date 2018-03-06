#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	
	system("cls"); // replace with clear if linux
	
	int i,j,k;
	int b[5][5];
	int a[5][5] = {
					  {0,0,1,0,0},
				    {0,1,0,1,0},
				    {1,1,1,1,1},
				    {1,0,0,0,1},
				    {1,0,0,0,1}
  };
	
	printf("\n\n");
	
	for(i = 0; i < 5; i++){
		for(j = 0; j<5;j++){
			if(a[i][j] == 1) printf("@");
			else printf(" ");
		}printf("\n");
	}
	printf("\n\n");
	for(i = 0; i < 5; i++){
		k = 4 - i;
		for(j = 0; j < 5; j++){
			b[j][k] = a[i][j];
		}
	}
	
	printf("\n\n");
	for(i = 0; i < 5; i++){
		for(j = 0; j<5;j++){
			if(b[i][j] == 1) printf("@");
			else printf(" ");
		}printf("\n");
	}
	printf("\n\n");
	
}

/*
Output - 
  @
 @ @
@@@@@
@   @
@   @




@@@
  @@
  @ @
  @@
@@@

*/
