#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct Node{
	int data;
	struct Node *next;
};


class LinkedList
{
	private:
		
	struct Node *start;
		
	public:
		
		LinkedList()
		{
			start=NULL;
		}
		struct Node *createNode(int);
		
		void deleteFirst();
		void deleteLast();
		void deleteData(int);
		void deleteAtPosition(int);
				
		void addFirst(struct Node*);
		void addLast(struct Node*);
		void adjustAdd(struct Node*);
		void addAfter(struct Node*,int);
		void addAtPosition(struct Node*,int);
		
		
		void displayList();	
};


void LinkedList::deleteAtPosition(int position)
{
	struct Node *prev;
	int pos=1;
	struct Node *trav;
	trav=start;
	while(pos<position)
	{
		prev=trav;
		trav=trav->next;
		pos++;
	}
	prev->next=trav->next;
	free(trav);
}
void LinkedList::deleteFirst()
{
	struct Node *trav;
	trav=start;
	start=start->next;
	free(trav);
}

void LinkedList::deleteLast()
{
	struct Node *trav,*prev;
	trav=start;
	while(trav->next!=NULL)
	{
		prev=trav;
		trav=trav->next;
	}
	prev->next=NULL;
	free(trav);
}

void LinkedList::deleteData(int data)
{
	struct Node *trav,*prev,*tmp;
	trav=start;
	while(trav->data!=data)
	{
		prev=trav;
		trav=trav->next;
	}
	tmp=trav;
	prev->next=trav->next;
	free(tmp);
}

void LinkedList::adjustAdd(struct Node *node)
{
	struct Node *trav,*prev;
	trav=start;
	while(trav!=NULL)
	{
		prev=trav;
		trav=trav->next;
		if(node->data>prev->data && node->data<trav->data)
		{
			prev->next=node;
			node->next=trav;
			
			break;
		}
	}
}
void LinkedList::addAfter(struct Node *node,int data)
{
	struct Node *trav,*prev;
	trav=start;
	while(trav->data!=data)
	{
		trav=trav->next;
	}
	node->next=trav->next;
	trav->next=node;
	}
struct Node* LinkedList::createNode(int data)
{
	struct Node *tmp;
	tmp=(struct Node*)malloc(sizeof(struct Node));
	tmp->data=data;
	tmp->next=NULL;
	return tmp;
}
void LinkedList::displayList()
{
	struct Node *trav;
	trav=start;
	while(trav!=NULL)
	{
		printf(" %d ",trav->data);
		trav=trav->next;
	}
}
void LinkedList::addFirst(struct Node *node)
{
	node->next=start;
	start=node;
}
void LinkedList::addLast(struct Node *node)
{
	struct Node *trav;
	trav=start;
	while(trav->next!=NULL)
	{
		trav=trav->next;
	}
	trav->next=node;
}
void LinkedList::addAtPosition(struct Node *node,int position)
{
	struct Node *trav,*prev;
	int i=1;
	trav=start;
	while(i<position)
	{
		prev=trav;
		trav=trav->next;
		i++;
	}
	prev->next=node;
	node->next=trav;
}
int main()
{
	LinkedList newLinkedList;
	
	LinkedList newLinkedList2;
	
	
	printf("\n\nLIST 1\n\n\n");
	
	
	newLinkedList2.addFirst(newLinkedList2.createNode(100));
	newLinkedList2.addLast(newLinkedList2.createNode(200));
	newLinkedList2.addLast(newLinkedList2.createNode(300));
	newLinkedList2.addLast(newLinkedList2.createNode(400));
	newLinkedList2.addLast(newLinkedList2.createNode(500));
	
	
	newLinkedList2.displayList();
	
	
		
	printf("\n\nLIST 2\n\n\n");
	

	
	newLinkedList.addFirst(newLinkedList.createNode(10));
	
	newLinkedList.addLast(newLinkedList.createNode(20));
	
	newLinkedList.addLast(newLinkedList.createNode(30));
	
	newLinkedList.addLast(newLinkedList.createNode(40));
	
	newLinkedList.addLast(newLinkedList.createNode(50));


	newLinkedList.adjustAdd(newLinkedList.createNode(35));
	
	newLinkedList.adjustAdd(newLinkedList.createNode(25));
	
	
	newLinkedList.displayList();
	
	
}
