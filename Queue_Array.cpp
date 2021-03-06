//////////////////////////////////////////////////////////////////////////////////////////
//
//			Implementation of Queue using Array
//
//////////////////////////////////////////////////////////////////////////////////////////

/*
-----------------------------------------------------------------------------------
Queue is abstract data types (ADT)
Queue is a FIFO data structure. First-in-ﬁrst-out.
We can implement Queue in two ways
	1.Arrays
	2.Linked lists

Basic operations on Queue:
	enqueue(element): Add element to the end of the queue
	dequeue() Returns the element from the front of the queue, removing it
	isEmpty() Returns true if queue empty
	isFull() Returns true if queue full

Applications of Queues :
	Waiting lists
	Access to shared resources (e.g., printer)
	Multiprogramming
-----------------------------------------------------------------------------------
*/
#include<stdio.h>
#include<malloc.h>

# define MAX 10

int front = 0;
int rare = -1;
int Queue[MAX];

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	IsQueueEmpty
//
//	Description:
//		This function checks whether queue is empty or not.
//
///////////////////////////////////////////////////////////////////////////////////////////
int IsQueueEmpty()
{
	if(rare == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	IsQueueFull
//
//	Description:
//		This function checks whether queue is full or not.
//
///////////////////////////////////////////////////////////////////////////////////////////
int IsQueueFull()
{
	if(rare == MAX )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display
//
//	Description:
//		This function displays contents of queue.
//
///////////////////////////////////////////////////////////////////////////////////////////
void Display()
{
	int i = 0;

	for(i = front; i != rare + 1; i++)
	{
		printf("| %d |-> ",Queue[i]);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	dequeue
//
//	Description:
//		This function remove element from queue.
//
///////////////////////////////////////////////////////////////////////////////////////////
int dequeue()
{
	int no = 0;

	if(IsQueueEmpty())
	{
		return -1;
	}
	else
	{
		return Queue[front++];
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	enqueue
//
//	Description:
//		This function add element in queue.
//
///////////////////////////////////////////////////////////////////////////////////////////
void enqueue(int no)
{
	if(IsQueueFull( ))
	{
		return;
	}
	Queue[++rare] = no;
}

int main(int argc, char *argv[])
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);

	printf("Contents of Queue are :\n");
	Display();
	
	printf("\n%d\n",dequeue());
	printf("\n%d\n",dequeue());
	
	printf("Contents of Queue are :\n");
	Display();
	
	return 0;
}

/*
	Important points about implementaion of Queue by using Array or LinkedList

	Array
	• Simple and efficient
	• Assume a fixed capacity for array
	• If capacity is too small, can reallocate, but expensive
	• If capacity is too large, space waste

	Linked Lists
	• No size limitation
	• Extra space per element

	When know the maximum number of element, use arrays
*/