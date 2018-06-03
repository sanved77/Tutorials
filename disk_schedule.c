#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int head, total, n;
int a[20], b[20];

void fcfs();
void sort();
//void sstf();

int main(){
	
	int i;
	
	system("cls");
	
	printf("\nEnter the head element - ");
	scanf("%d", &head);
	
	printf("\nEnter the total no of cylinders - ");
	scanf("%d", &total);
	
	printf("\nEnter no of elements - ");
	scanf("%d", &n);
	
	printf("\nEnter elements one by one - ");
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);

	sort();
	fcfs();
	//sstf();
	
}

void sort(){
	
	int i,j, temp;
	
	for(i = 0; i < n; i++) b[i] = a[i];
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(b[i] < b[j]){
				temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		}
	}
	
	for(i = 0; i < n; i++) printf("%d-", a[i]);
	
}

void fcfs(){
	
	int i,curr, total=0;
	
	curr = head; 
	
	for(i = 0; i < n; i++){
		total += abs(a[i] - curr);
		curr = a[i];
	}
	
	printf("FCFS - Total Cylinders - %d", total);
	
}

/*void sstf(){
	
	int curr, i = 0, visited = 0; 
	visited[20] = 0;
	
	while(1){
		if(b[i] == head){
			curr = head;
			break;
		}
		i++;
	}
	
	while(visited != n){
		if((b[i] - b[i-1]) < (a[i+1] - a[i])){
			
		}
		else{
			curr = a[i+1];
			
		}
	}
	
}*/
