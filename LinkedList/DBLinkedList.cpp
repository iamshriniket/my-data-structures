#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct Node{
	struct Node *prev;
	int data;
	struct Node *next; 
};
struct Node *start;

class DBLinkedList{
	private:
				
	public:
		DBLinkedList()
		{
				//do nothing
		}		
		
		struct Node *createNode(int);
		
		void addFirst(struct Node*);
		void addLast(struct Node*);
		void addAfter(struct Node*,int);
		void addAtPosition(struct Node*,int);
		void adjustAdd(struct Node*);
		
		
		void deleteFirst();
		void deleteLast();
		void deleteData(int);
		void deleteAtPosition(int);
		
		
		void displayList();
		
		

		
};
void DBLinkedList::deleteFirst()
{
	struct Node *trav;
	trav=start;
	start=start->next;
	free(trav);
}

void DBLinkedList::deleteLast()
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

void DBLinkedList::deleteData(int data)
{
	struct Node *trav,*prev;
	trav=start;
	while(trav->data!=data)
	{
		prev=trav;
		trav=trav->next;
	}
	prev->next=trav->next;
	trav->next->prev=prev;
	free(trav);
}
void DBLinkedList::deleteAtPosition(int position)
{
	struct Node *trav,*prev;
	trav=start;
	int pos=1;
	while(pos<position)
	{
		prev=trav;
		trav=trav->next;
		pos++;
	}
	prev->next=trav->next;
	trav->next->prev=prev;
	free(trav);

}
void DBLinkedList::displayList()
{
	struct Node *trav;
	trav=start;
	while(trav!=NULL)
	{
		printf(" %d ",trav->data);
		trav=trav->next;
	}
	
}
struct Node* DBLinkedList::createNode(int data)
{
	struct Node *tmp;
	tmp=(struct Node*)malloc(sizeof(struct Node));
	tmp->prev=NULL;
	tmp->next=NULL;
	tmp->data=data;
	return tmp;
}
void DBLinkedList::addFirst(struct Node *node)
{
	struct Node *trav;
	trav=start;
	node->next=trav;
	trav->prev=node;
	
	start=node;
}
void DBLinkedList::addLast(struct Node *node)
{
	struct Node *trav;
	trav=start;
	while(trav->next!=NULL)
	{
		trav=trav->next;
	}
	trav->next=node;
	node->prev=node;
}
void DBLinkedList::addAfter(struct Node *node,int data)
{
	struct Node *trav,*prev;
	trav=start;
	while(trav->data!=data)
	{
		prev=trav;
		trav=trav->next;
	}
	node->prev=trav;
	node->next=trav->next;
	trav->next=node;
}

void DBLinkedList::addAtPosition(struct Node *node,int position)
{
	struct Node *trav,*prev;
	int pos=1;
	trav=start;
	while(pos<position)
	{
		prev=trav;
		trav=trav->next;
		pos++;
	}
	prev->next=node;
	node->prev=prev;
	node->next=trav;
	trav->prev=node;
}

void DBLinkedList::adjustAdd(struct Node *node)
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
			node->prev=prev;
			node->next=trav;
			trav->prev=node;
		}
	}

}
int main()
{
	DBLinkedList dbl;
	
	start=NULL;
	
	if(start==NULL)
	{
		start=dbl.createNode(10);
	}
	

	printf(" \n\nBEFORE DELETE\n\n");
	
	
	dbl.addLast(dbl.createNode(34));
	dbl.addFirst(dbl.createNode(23));
	dbl.addFirst(dbl.createNode(238));
		
		
	dbl.addLast(dbl.createNode(455));
	
	dbl.addAtPosition(dbl.createNode(390),4);
		
		
	dbl.addAfter(dbl.createNode(3667),10);
	
	
	dbl.adjustAdd(dbl.createNode(15));
	
	dbl.adjustAdd(dbl.createNode(13));
	
	
	dbl.displayList();
	
	
	printf(" \n\nAFTER DELETE\n\n");
	
	
	dbl.deleteFirst();
	
	dbl.deleteFirst();
	
	dbl.deleteLast();
	
	
	dbl.deleteLast();
	
	dbl.deleteData(15);
	
	
	dbl.deleteData(13);
	
	
	dbl.adjustAdd(dbl.createNode(25));
	dbl.adjustAdd(dbl.createNode(13));
	
	
	
	dbl.deleteAtPosition(2);
	
	dbl.deleteAtPosition(2);
	


	dbl.displayList();
	
	
	printf("REVERSE LIST!!!!");
	
	dbl.displayReverseList();
	
	
	return 0;
}
