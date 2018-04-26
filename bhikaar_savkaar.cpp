/********************************
Bhikar Savkar Card game.
Author - Sanved Tapkeer
Under Creative Commons License 3.5
********************************/

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

using namespace std;

/*Future Usage*/
typedef unsigned long ulo; 
/*Future Usage*/

/*Init*/
//Card
typedef struct card{
	int rank, suit;
	struct card *next;
}card;
/*Init*/

/*Global*/
//Vars
card *df, *dr, *p1f, *p1r, *p2f, *p2r;
string suits[] = {"Heart","Diamond","Clubs","Spades"};
string ranks[] = {"1","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
bool game=true;
int p1c=26, p2c=26, dc=0; //Player cards

//Functions
void welcome();
void initVals();
void swap(int*, int*);
void distributeCards();
void enqueuep1(int);
void enqueuep2(int);
void startGame();
bool p1emp();
bool p2emp();
card rmp1();
card rmp2();
void enqueued(card);
void connectp1();
void connectp2();
void diss();
/*Global*/


/*Card ADT starts here
Card Range - 0 to 51
King-12
Queen-11
Jack-10
1 to 10 - 0 to 9
*/

//TOneverDO change name
int getRank(int val) {return val%13;}
int getSuit(int val) {return (int)val/13;}

//Card ADT ends here

int main(){
	
	bool playAgain = true;
	
	system("cls");
	initVals();
	welcome();
	distributeCards();
	startGame();
	
}

void initVals(){
	df = dr = p1f = p1r = p2f = p2r = NULL;
}

//TODO change time and text if needed be
void welcome(){
	cout<<"----------------------------------------\n";
	cout<<"Welcome to the game of Bhikar Savkar !!\n";
	cout<<"----------------------------------------\n";
	Sleep(1000);
	system("cls");
	cout<<"------------------------------------\n";
	cout<<"This is a 2 player interactive game\n";
	cout<<"------------------------------------\n";
	Sleep(1000);
	system("cls");
	cout<<"-------------------------------\n";
	cout<<"Developed by Sanved Softwares.\n";
	cout<<"-------------------------------\n";
	Sleep(1000);
	system("cls");
}

void distributeCards(){
	srand( time( NULL ) );
	int a, arr[26]={99},arr2[26]={99},i,j,n=0,flag=0,temp,flag2 =0,k=0;
	
	card *point = new card;
	
	while(1){
		a = rand() % 50;
		for(i=0;i<=n;i++){
			if(arr[i]==a){
				flag=1;
			}
		}
		if(flag == 0){
			arr[n++] = a;
		}
		if(n==25) break;
		flag = 0;
	}
	
	for(i=0; i<52;i++){
		for(j=0;j<26;j++){
			if(arr[j]==i){
				flag=1;
				break;
			}
		}
		if(flag==0){
			arr2[k++]=i;
		}
		flag = 0;
	}
	
	for (i=n; i>0;i--) {
        j = rand() % (i+1);
        swap(&arr2[i], &arr2[j]);
    }
	
	for(i=0;i<=n;i++){
		enqueuep1(arr[i]);
		enqueuep2(arr2[i]);
	}
	
	/*point = p2f;
	while(point){
		cout<<"  "<<ranks[point->rank]<<" of "<<suits[point->suit]<<endl;
		point=point->next;
	}
	
	point = p1f;
	while(point){
		cout<<"  "<<ranks[point->rank]<<" of "<<suits[point->suit]<<endl;
		point=point->next;
	}*/
	//Display
	//for(i=0;i<=n;i++) printf("%d\t%d\n", arr[i], arr2[i]); 
}

void diss(){
	char c;
	card *point = new card;
	point = p1f;
	cout<<"\nPlayer 1 cards - \n";
	while(point){
		cout<<"  "<<ranks[point->rank]<<" of "<<suits[point->suit]<<endl;
		point=point->next;
	}
	cout<<"\n\nPlayer 2 cards - \n";
	point = p2f;
	while(point){
		cout<<"  "<<ranks[point->rank]<<" of "<<suits[point->suit]<<endl;
		point=point->next;
	}
	cout<<"\n\nCards on the Deck - \n";
	point = df;
	while(point){
		cout<<"  "<<ranks[point->rank]<<" of "<<suits[point->suit]<<endl;
		point=point->next;
	}
	cout<<"\n\nPress Alphanumeric key to go back to the game ";
	cin>>c;
}

void startGame(){
	int choice,prevr,prevs,x=2,y=1;
	char c;
	card temp;
	
	while(game){
		cout<<"\nBhikar Savkar !";
		cout<<"\nCard game for noobs by Sanved";
		cout<<"\nPress Ctrl+C to exit the game. And Press any Alphanumeric key to look at the cards \n\n";
		
		Sleep(300);
	
		if(dc==52){//Nobody wins
			cout<<"Nobody wins !\n";
			cout<<"Wanna play again ? Press 1 for Yes: ";
			cin>>choice;
			if(choice==1){
				system("cls");
				df = dr = p1f = p1r = p2f = p2r = NULL;
				dc = 0;
				p1c = p2c = 26;
				cout<<"----------------------\n"<<"Distributing Cards"<<"\n----------------------";
				Sleep(1000);
				distributeCards();
				system("cls");
			}else{
				game = false;
			}
		}
		else if(p1c == 0){//Player 1 loses
			cout<<"Player 2 Wins !\n";
			cout<<"Wanna play again ? Press 1 for Yes: ";
			cin>>choice;
			if(choice==1){
				system("cls");
				df = dr = p1f = p1r = p2f = p2r = NULL;
				dc = 0;
				p1c = p2c = 26;
				cout<<"----------------------\n"<<"Distributing Cards"<<"\n----------------------";
				Sleep(1000);
				distributeCards();
				system("cls");
			}else{
				game = false;
			}
		}
		else if(p2c == 0){//Player 2 loses
			cout<<"Player 1 Wins !\n";
			cout<<"Wanna play again ? Press 1 for Yes: ";
			cin>>choice;
			if(choice==1){
				system("cls");
				df = dr = p1f = p1r = p2f = p2r = NULL;
				dc = 0;
				p1c = p2c = 26;
				cout<<"----------------------\n"<<"Distributing Cards"<<"\n----------------------";
				Sleep(1000);
				distributeCards();
				system("cls");
			}else{
				game = false;
			}
		}
		
		else{
			if(df==NULL){ //If deck is empty
				temp = rmp1(); //Take a card from p1
				prevr = temp.rank;
				prevs = temp.suit;
				enqueued(temp); // add it to the deck
				cout<<"\nPlayer 1 goes first\n-------------------\n"<<ranks[prevr]<<" of "<<suits[prevs]<<endl  <<"\n-------------------";
			}
			else{
				if(x==1){ //To take the cards alternatively
					temp = rmp1();
					x=2;
					y=1;
				}else if(x==2){
					temp = rmp2();
					x=1;
					y=2;
				}
				enqueued(temp);
				cout<<"Player "<<y<<" has entered a card\n";
				cout<<"-------------------\n";
				cout<<ranks[temp.rank]<<" of "<<suits[temp.suit]<<"\n      on\n";//Displays latest card
				cout<<ranks[prevr]<<" of "<<suits[prevs]<<endl; //Displays previous card
				cout<<"-------------------";
				if(temp.suit==prevs){
					cout<<"\nPlayer "<<y<<" wins this set\n";
					if(y==1) connectp1();
					else if(y==2) connectp2();
				}else{
					prevr=temp.rank;
					prevs=temp.suit;
				}
			}
		}			
		cout<<"\nScore - \n Player 1 - "<<p1c<<"\n Player 2 - "<<p2c<<"\n Deck - "<<dc<<"\n\n";
		cout<<"\nPress Enter to continue. ";
		if(cin.get()!='\n'){
			diss();
		}
		system("cls");
	}

	
}

void enqueuep1(int val){
	card ptr;
	ptr.rank=getRank(val);
	ptr.suit=getSuit(val);
	

	card *temp = new card;
	temp->rank=ptr.rank;
	temp->suit=ptr.suit;
	temp->next=NULL;
	
	if(p1f==NULL){
		p1f=temp;
		p1r=temp;	
	}
	else if(p1f!=NULL){
		p1r->next=temp;
		p1r=temp;
	}
	
}

void enqueuep2(int val){
	card ptr;
	ptr.rank=getRank(val);
	ptr.suit=getSuit(val);
	

	card *temp = new card;
	temp->rank=ptr.rank;
	temp->suit=ptr.suit;
	temp->next=NULL;
	
	if(p2f==NULL){
		p2f=temp;
		p2r=temp;	
	}
	else if(p2f!=NULL){
		p2r->next=temp;
		p2r=temp;
	}
	
}

void enqueued(card ptr){

	card *temp = new card;
	temp->rank=ptr.rank;
	temp->suit=ptr.suit;
	temp->next=NULL;
	
	if(df==NULL){
		df=temp;
		dr=temp;	
	}
	else if(df!=NULL){
		dr->next=temp;
		dr=temp;
	}
	
}

bool p1emp(){
	if(p1f==NULL) return true;
	else return false;
}

bool p2emp(){
	if(p2f==NULL) return true;
	else return false;
}

card rmp1(){
	card *temp;
	if(p1f==p1r){
		temp = p1f;
		p1f=p1r=NULL;
	}else{
		temp = p1f;
		p1f=p1f->next;
	}
	p1c--;
	dc++;
	return *temp;
}

card rmp2(){
	card *temp;
	if(p2f==p2r){
		temp = p1f;
		p2f=p2r=NULL;
	}else{
		temp = p2f;
		p2f=p2f->next;
	}
	p2c--;
	dc++;
	return *temp;
}

void connectp1(){
	p1r->next = df;
	p1r=dr;
	p1c = p1c + dc;
	dc=0;
	df=dr=NULL;
}

void connectp2(){
	p2r->next = df;
	p2r=dr;
	p2c = p2c + dc;
	dc=0;
	df=dr=NULL;
}

void swap (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

