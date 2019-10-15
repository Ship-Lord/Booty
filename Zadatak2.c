#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct S_studenti
{
	char ime[20];
	char prezime[20];
	int godina;
	struct S_studenti *next;
}studenti;

studenti *Dodavanje();

int main()
{

	studenti *start = NULL;

	if(start == NULL)
		start = Dodavanje();


	system("pause");
	return 0;

}

studenti *Dodavanje()
{
	printf("Ime , Prezime i godina rodenja : ");

	studenti *Novi = malloc(sizeof(studenti));
	scanf("%s %s %d", Novi->ime, Novi->prezime, &Novi->godina);

	printf("%s %s %d\n", Novi->ime, Novi->prezime, Novi->godina);

	return 0;
}