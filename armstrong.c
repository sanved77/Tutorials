#include<stdio.h>

int main(){
	
	int n, num,i, ctr=0, num2;
	
	scanf("%d", &n);
	
	num = n;
	
	while(num){
		num2=num%10;
		ctr += num2*num2*num2;
		num/=10;
	}
	
	printf("%d", ctr);
	
	if(ctr==n) printf("\nYes");
	else printf("no");
	
}
