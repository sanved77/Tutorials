
//Roll no 287


#include<stdio.h>

int ctr = 0;

typedef struct node
{
	int id, comments, date, month, year;
	char name[20];
	struct node *next;
}node;

typedef struct rootnode
{
	int ctr;
	struct node *users[100];
}rootnode;

node *getnode()
{
	node *p=NULL;
	p=(node*)malloc(sizeof(node));
	printf("Give ID\n");
	scanf("%d",p->id);
	printf("Enter name\n");
	scanf("%s",p->name);
	p->next=NULL;
	return(p);
}

node *getRootNode()
{
	int i;
	rootnode *p=NULL;
	p=(rootnode*)malloc(sizeof(rootnode));
	p->ctr = 0;
	for(i=0;i<100;i++) p->users[i]=NULL;
	return(p);
}// getnode

node *create(rootnode *start,int n)
{
	node *p=NULL,*t=NULL;
	int i;
	for(i=0;i<n;i++)
	{
		p=getnode();
		printf("\npuk");
		start->users[ctr] = p;
		ctr++;
	}//for
	return(start);
}//create

int display(node *start)
{
	node *p=NULL;
	printf("\nFacebook console:");
	printf("\nStart->");
	p=start;
	while(p!=NULL)
	{
		printf("%s->",p->name);
		p=p->next;
	}//while
	printf("NULL");
}// display


int displayNet(rootnode *start)
{
	int i;
	node *p=NULL;
	printf("\nFacebook console:");
	printf("\nUsers->");
	p=start;
	for(i=0;i<ctr;i++){
		printf("--%s", start->users[i]->name);
	}
	printf(".");
}// display


int search(int num, rootnode *start)
{
	int i,loc=0;
	struct rootnode *p;
	p=start;
	
	for(i=0;i<ctr;i++){
		if(p->users[i]->id == num){
			return i;
		}
	}
	return 0;
}

void addFriend(rootnode *root){
	
	int i,id,fid,res,fres;
	node *p=NULL;
	
	printf("\nEnter the id of the user, to which you want to assign this friend");
	scanf("%d", id);
	res = search(id, root);
	if(res==0){
		printf("\nID doesn't exist");
	}else{
		printf("\nEnter friend ID");
		scanf("%d", fid);
		fres = search(id, root);
		if(fres==0){
			printf("\nID doesn't exist");
		}else{
			p = getnode();
			p->id = root->users[fres]->id;
			strcpy(p->name, root->users[fres]->name);
			p->next = NULL;
			
			//Assigning friend
			root->users[res]->next = p;
		}
	}
	
}

int main()
{
	int num,ch;
	node * start=NULL;
	rootnode *root;
	root = getRootNode();
	system("cls");
	
	printf("\n\nLet's create a user list first, enter number of users - ");
	scanf("%d",&num);
	root=create(root,num);
	displayNet(root);
	
	while(1)
	{
		printf("\n -1 Add User\n -2 Add Friends to ID\n -3 Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			root=create(root,1);
			displayNet(root);
			break;
			
			case 2: 
			addFriend(root);
			break;
			
			case 4:
			display(root->users[0]);
			break;
			
			/*
			case 4: 
			start=reverse(start);
			display(start);
			break;
			case 5:
			revert(start);
			printf("NULL");
			break;
			case 6:   
			printf("\nEnter the number of node:");
			scanf("%d",&num);
			search(num,start);
			
			break; */
			
			case 3: 
			exit(0);
			
		}//switch
	}//while
	return(0);
}
