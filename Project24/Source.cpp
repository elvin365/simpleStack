#include "stdio.h"
#include "stdlib.h"
#include <conio.h>
struct Node
{
	int Value;
	Node *Next, *Prev;
};

Node* Push_Stack(Node* Head, int Value)
{
	Node *a = (Node*)malloc(sizeof(Node));
	a->Value = Value;
	a->Next = Head;
	a->Prev = NULL;
	if(Head!=NULL)
	Head->Prev = a;
	return a;
}

void Delete(Node **Head, Node *del)
{
	if (*Head == del)
	{
		(*Head) = (*Head)->Next;
		(*Head)->Prev = NULL;
		free(del);
		return;
	}

	if (del->Next == NULL)
	{
		del->Prev->Next = NULL;
		free(del);
		return;
	}

	Node *Prev = del->Prev, *Next = del->Next;

	Prev->Next = Next;
	Next->Prev = Prev;
	free(del);
	return;
}

int main()
{
	Node* a = NULL;
	int i = 0;
	for(i=0;i<5;i++)
	a = Push_Stack(a, i);
	getchar();
	system("PAUSE");
	return 0;
}