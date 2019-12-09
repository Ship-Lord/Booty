#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


struct node;
typedef struct node* Position;

struct node
{
	int element;
	int priority;
	Position next;
};

int GetRandom(int min, int max);
int Push(Position P, int);
int Pop(Position P);
int Print(Position P);

int main()
{
	struct node Red;
	int odabir = 0;

	Red.next = NULL;
	srand(time(NULL));

	do
	{
		printf("\r\n\t\t********************");
		printf("\r\n\t\t***   IZBORNIK   ***");
		printf("\r\n\t\t********************");
		printf("\r\n");
		printf("\r\n\t\t1.\tPush na stog");
		printf("\r\n\t\t2.\tPop sa stoga");
		printf("\r\n\t\t3.\tIspis");
		printf("\r\n\t\t4.\tIzlaz iz programa");
		printf("\r\n\r\nVas odabir : ");


		scanf(" %d", &odabir);

		if (odabir == 1)
		{
			Push(&Red, GetRandom(0, 100));
			Print(Red.next);
		}
		if (odabir == 2)
		{
			Pop(&Red);
			Print(Red.next);
		}
		if (odabir == 3)
		{
			Print(Red.next);
		}
	} while (odabir != 4);

	system("pause");
	return 0;
}

int GetRandom(int min, int max)
{
	int x = 0;
	x = rand() % (max - min) + min;
	return x;
}

int Push(Position P, int br_ele)
{
	Position q;

	q = (Position)malloc(sizeof(struct node));
	if (q == NULL)
	{
		printf("\r\nGreska pri alokaciji memorije!");
		return -1;
	}
	else if (q)
	{
		q->element = br_ele;
		q->priority = GetRandom(1, 5);
		printf("\r\nNa listu se sprema ( %d %d )", q->element, q->priority);

		while (P->next != NULL && P->next->priority >= q->priority)
			P = P->next;

		q->next = P->next;
		P->next = q;
	}
	return 0;
}

int Pop(Position P)
{
	Position temp;

	if (P->next != NULL)
	{
		temp = P->next;
		
		printf("\r\nSa liste se skida %d %d.", temp->element, temp->priority);

		P->next = temp->next;
		free(temp);

	}
	else
	{
		printf("\r\nLista je prazna.");
	}
	return 0;
}

Print(Position P)
{
	printf("\r\n\r\nU listi se nalaze :\r\n");
	while (P)
	{
		printf(" ( %d %d )", P->element, P->priority);
		P = P->next;
	}
}