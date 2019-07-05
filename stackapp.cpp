#include<stdio.h>
#include<string.h>
#include<string>
#include<conio.h>
#include<stdlib.h>
#define MAX 50
#define stack_txt_max 500

int stack[MAX];
char data[stack_txt_max];
int top;


void read_data() {
	FILE *fp;
	fp = fopen("stack.txt","r");
	if(fp == NULL) {
		printf("stack.txt cannot found. (for fix this isue create stack.txt)");
	} else {
		while(fgets(data, 100, fp) != NULL) {}
	}
	fclose(fp);
}
void write_data() {
	FILE *fp;
	fp = fopen("stack.txt","w");
	fputs(data,fp);
	fclose(fp);
}
int push(int state, int val)
{
	if(state == 0) {
		int item;
		char sitem[11];
		if(top==MAX-1)
		{
			printf("Stack is full!\n");
			return 0;
		}
		else
		{
			printf("Enter the element you want to push:");
			scanf("%d",&item);
			stack[top+1]=item;
			top++;
			itoa(item, sitem, 10);
			read_data();
			if(data[strlen(data)] != ',') data[strlen(data)] = ',';
			strcat(data,sitem);
			write_data();
		}
	}
	else {
		stack[top + 1] = val;
		top++;
	}
	
}
int pop()
{
	int removed;
	if(top==-1)
	{
		printf("Stack is empty\n");
		return 0;
	}
	else
	{
		char sn[10];
		char nstack[stack_txt_max];
		removed = stack[top];
		top--;
		for(int i = 0; i < top+1; i++) {
			sprintf(sn, "%d,",stack[i]);
			strcat(nstack,sn);
		}
		strcpy(data,nstack);
		write_data();
		memset(data, 0, sizeof data);
		printf("Removed element: %d\n",removed);
	}
}
void display()
{
	int i;
	printf("The number of elements in your stack: %d\n",top+1);
	for(i=0;i<=top;i++)
	{
		printf("%d\t",stack[i]);
	}
	printf("\n");
}
int bubbleSort()
{
	int temp;
	char sn[10];
	char nstack[stack_txt_max];
	for(int i=0;i<top+1;i++)
	{
		for(int j=i+1;j<top+1;j++)
		{
			if(stack[j]<stack[i])
			{
				temp=stack[i];
				stack[i]=stack[j];
				stack[j]=temp;
			}
		}
		sprintf(sn,"%d,",stack[i]);
		strcat(nstack,sn);		
	}
	strcpy(data,nstack);
	write_data();
}
int search()
{
	int target;
	int isHere;
	int k=0;
	printf("The element you want to search:");
	scanf("%d",&target);
	for(int i=0;i<top+1;i++)
	{
		if(stack[i]==target)
		{
			k=1;
			isHere=i;
		}
	}
	if(k==1) printf("The element you are looking for is element %d. of the stack.\n",isHere+1);
	else if(top==-1) printf("Stack is empty.\n");
	else printf("The element you are looking for is not in the stack.\n");

}
int push_filedata (char data[])
{
    char *pt;
    pt = strtok (data,",");
    while (pt != NULL) {
        int a = atoi(pt);
        push(1,a);
        pt = strtok (NULL, ",");
    }
    return 0;
}


int main()
{
	top = -1;
	int choise;
	int ans;
	
	read_data();
	push_filedata(data);
	while(ans)
	{
		system("cls");
		printf("\tWELCOME TO THE IMPROVED STACK IMPLEMENTATION\n");
		printf("Main Menu\n");
		printf(" 1.Add new elements to stack\n 2.Remove elements from stack\n 3.Display\n 4.Sort elements from small to large\n 5.Exit\n 6.Search the position of an element from the stack\n");
		printf("\nMade by -besimgurbuz-\n");
		printf("Type your choice:");
		scanf("%d",&choise);

		switch(choise)
		{
			case 1:
				push(0,0);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				bubbleSort();
				break;
			case 5:
				return 1;
			case 6:
				search();
				break;
		}
		fflush(stdin);
		printf("Do you wanna continue?   Y:1 N:0 -->");
		scanf("%d",&ans);
	}
	getch();
	return 0;
}
