#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MAX 10
class Stack{
	private:
		int stack[10];
		int top;
	public:
		Stack()
		{
			top=-1;
		}
		
		void push(int);
		void pop();
		void peek();
		void display();
};

void Stack::push(int data)
{
	if(top==MAX-1)
	{
		printf("\n\nSTACK FULL!!");
	}
	else
	{
		stack[++top]=data;
	}
}

void Stack::pop()
{
	if(top==-1)
	{
		printf("\nSTACK EMPTY!!");
		
	}
	else
	{
		printf("POPPED: %d ",stack[top]);
		top--;
	}
}

void Stack::peek()
{
	if(top==-1)
	{
		printf("\nSTACK EMPTY!!\n\n");
	}
	else
	{
		printf("PEEK: %d",stack[top]);
	}
}
void Stack::display()
{
	int i=top;
	while(i!=-1)
	{
		printf(" %d ",stack[i]);
		i--;
	}
}
int main()
{
	Stack stck;
	stck.push(10);
	stck.push(20);
	stck.push(30);
	stck.push(40);
	stck.push(50);
	stck.push(60);
	
	
	
	stck.display();
	
	stck.pop();
	printf("AFTER\n\n");
	
	stck.display();
	
	
	return 0;
}
