#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){

	int i=0,key;

	char str[10];
	char str2[10];
	int flag = 1;
	
	printf("Enter the key\t");
	scanf("%d", &key);
	printf("\nEnter the text\t");
	scanf("%s", &str);

	while(str[i]!='\0'){
		if(str[i] >= 97 && str[i] <= 122){
			str[i] = str[i] - 32;
		}
		i++;
	}
	i = 0;
	memset(&str2, 0, sizeof(str2));
	while(flag == 1){
	
		if(str[i] >= 65 && str[i] <= 90){
			str2[i] = str[i]+key;
			if(str2[i] > 90){
				str2[i] = (str2[i] - 90) + 64;
			}
			i++;
		}else if(str[i] == '\0'){
			printf("\nEncrypted text - %s", str2);
			flag = 0;
		}else{
			printf("\nNon alphabetic characters not allowed!");
			flag = 0;
		}
		
	}

}
