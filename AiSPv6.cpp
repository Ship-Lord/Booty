#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MIN 0
#define MAX 100

struct node;
typedef struct node* position;

struct node {
	int element;
	position next;
};

int GetRandom(int max, int min);
int PushStog(position P, int value);
int PushNiz(position P, int value);
int Pop(position P);
int Print(position P);

int main()
{
	int odabir = 0;
	node stog, niz;
	stog.next = NULL;
	niz.next = NULL;

	do
	{
	printf("1. Push na stog\n");
	printf("2. Pop na stog\n");
	printf("3. Push na niz\n");
	printf("4. Pop na niz\n");
	printf("5. Izlaz\n");
	printf("Vas odabir:");
	scanf_s(" %d", &odabir);

	if (odabir == 1)
	{
		PushStog(&stog, GetRandom(MIN, MAX));
		Print(stog.next);
	}
	if (odabir == 2)
	{
		Pop(&stog);
		Print(stog.next);
	}
	if (odabir == 3)
	{
		PushNiz(&niz, GetRandom(MIN, MAX));
		Print(niz.next);

	}
	if (odabir == 4)
	{
		Pop(&niz);
		Print(niz.next);
	}
	} while (odabir != 5);

	system("pause");
	return 0;
}
int GetRandom(int max,int min)
{
	int value = 0;
	value = rand() % (max - min) + min;

	return value;
}
int PushStog(position P, int value)
{
	position temp = NULL;
	temp = (position)malloc(sizeof(node));
	if (temp == NULL)
	{
		printf("Greska pri alokaciji memorije!!!\n");
		return 0;
	}
	else if (temp)
	{
		temp->element = value;
		temp->next = P->next;
		P->next = temp;

		printf("Spremanje vrijednosti %d\n ", value);
	}
	return 0;
}
int PushNiz(position P, int value)
{
	position temp = NULL;
	static position zadnji;

	if (P->next == NULL)
	{
		zadnji = P;
	}
	temp = (position)malloc(sizeof(node));
	if (temp == NULL)
	{
		printf("Greska pri alokaciji memorije!!!\n");
		return 0;
	}
	else if (temp)
	{
		temp->element = value;
		temp->next = zadnji->next;
		zadnji->next = temp;
		zadnji = temp;

		printf("Sprema se vrijednost %d\n", value);
	}
	return 0;
}
int Pop(position P)
{
	position temp = NULL;

	if (P->next != NULL)
	{
		temp = P->next;
		printf("Izbacena vrijednost je: %d\n", temp->element);

		P->next = temp->next;

		free(temp);
	}
	return 0;
}
int Print(position P)
{
	printf(" Spremljene vrijednosti: \n");
	while (P)
	{
		printf(" %d\n", P->element);
		P = P->next;
	}
	return 0;
}