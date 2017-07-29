#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define MAX 10
class Queue
{
	private:
		int queue[MAX];
		int front,rear;
	public:
		Queue()
		{
			front=-1,rear=-1;
		}
		void insert(int);
		void delet();
		void display();
		
};
void Queue::insert(int data)
{
	
	if(front==-1)
	{
		front=0;
	}
	if(rear==MAX-1)
	{
		printf("\n\nQueue is full!!");
	}
	else
	{
		rear++;
		queue[rear]=data;
	}
}
void Queue::delet()
{
	if(front==-1)
	{
		printf("\n\nQueue is empty!!");
	}
	else
	{
		printf("DELETED: %d",queue[front]);
		front++;
		
	}
}

void Queue::display()
{
	int i=front;
	printf("\nQUEUE is\n\n");
	while(i<=rear)
	{
		printf(" %d ",queue[i]);
		i++;
	}
}
int main()
{
	Queue q;
	
	q.insert(10);
	
	q.insert(20);
	q.insert(30);
	q.insert(40);
	q.insert(50);
	q.insert(60);
	
	q.display();
	
	return 0;
}

