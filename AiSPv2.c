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
	struct S_studenti* next;
	struct S_studenti* prosli;
}studenti;

studenti* StvaranjeStud(studenti* prosli);
studenti* DodajNaPocetak(studenti* pokStart);
studenti* DodajNaKraj(studenti* pokStart);
studenti* Brisanje(studenti* pokStart);
int ciscMem(studenti* start);
int ispis(studenti* start);

int main()
{
	studenti* start = NULL;
	int unos = 0;
	int i = 0;

	do
	{
		printf("1.Dodati studenta na pocetak liste\n");
		printf("2.Dodati studenta na kraj liste\n");
		printf("3.Izbrisati iz liste\n");
		printf("4.Ispis liste\n");
		printf("5.Izlaz\n");
		printf("Vas odabir:");
		scanf(" %d", &unos);
		if (unos == 1)
		{
			start = DodajNaPocetak(start);
		}
		if (unos == 2)
		{
			start = DodajNaKraj(start);
		}
		if (unos == 3)
		{
			start = Brisanje(start);
		}
		if (unos == 4)
		{
			ispis(start);
		}
	} while (unos != 5);

	ciscMem(start);

	system("pause");

	return 0;
}

studenti* StvaranjeStud()
{
	printf("Ime , Prezime i godina rodenja : ");

	studenti* Novi = malloc(sizeof(studenti));
	scanf("%s %s %d", Novi->ime, Novi->prezime, &Novi->godina);
	printf("%s %s %d\n", Novi->ime, Novi->prezime, Novi->godina);

	Novi->next = NULL;
	Novi->prosli = NULL;

	return Novi;
}
int ciscMem(studenti* start)
{
	studenti* freeMem = start;
	studenti* zadrziMem = NULL;

	while (freeMem != NULL)
	{
		zadrziMem = freeMem->next;
		free(freeMem);
		freeMem = zadrziMem;
	}
	return 0;
}
int ispis(studenti* start)
{
	int brojac = 0;
	studenti* trenutni = start;
	studenti* sljedStud = NULL;
	studenti* prijStud = NULL;

	while (trenutni != NULL)
	{
		sljedStud = trenutni->next;
		prijStud = trenutni->prosli;

		brojac++;
		printf("Student:%d %s %s %d    ", brojac, trenutni->ime, trenutni->prezime, trenutni->godina);
		if (sljedStud == NULL)
			printf("Nema sljedeceg studenta    ");
		else
		{
			printf("Sljedeci student je %s %s %d    ", sljedStud->ime, sljedStud->prezime, sljedStud->godina);
		}
		if (prijStud == NULL)
			printf("Nema proslog studenta\n");
		else
		{
			printf("Prosli student je %s %s %d\n", prijStud->ime, prijStud->prezime, prijStud->godina);
		}
		trenutni = trenutni->next;
		sljedStud = NULL;
		prijStud = NULL;
	}
	return 0;
}
studenti* DodajNaPocetak(studenti* pokStart)
{
	studenti* noviStud = StvaranjeStud();
	if (pokStart != NULL)
	{
		pokStart->prosli = noviStud;
		noviStud->next = pokStart;
	}

	return noviStud;
}
studenti* DodajNaKraj(studenti* pokStart)
{
	studenti* povratni = pokStart;
	studenti* noviStud = NULL;

	if (pokStart == NULL)
	{
		noviStud = DodajNaPocetak(pokStart);
		povratni = noviStud;
	}
	else
	{
		studenti* indexStud = pokStart;
		while (indexStud->next != NULL)
		{
			indexStud = indexStud->next;
		}
		noviStud = StvaranjeStud();
		indexStud->next = noviStud;
		noviStud->next = NULL;
		noviStud->prosli = indexStud;
	}
	return povratni;
}
studenti* Brisanje(studenti* pokStart)
{
	char ime[20] = { '0' };
	char prezime[20] = { '0' };
	studenti* refStudent = pokStart;
	studenti* studZaBrisanje = NULL;

	printf("Unesite ime studenta kojeg zelite izbrisati: ");
	scanf("%s %s", ime, prezime);

	while (refStudent != NULL)
	{
		if (strcmp(ime, refStudent->ime) == 0 && strcmp(prezime, refStudent->prezime) == 0)
		{
			studZaBrisanje = refStudent;
			break;
		}
		refStudent = refStudent->next;
	}
	if (pokStart != NULL && studZaBrisanje == pokStart)
	{
		if (studZaBrisanje->next != NULL)
		{
			studZaBrisanje->next->prosli = NULL;
			pokStart = studZaBrisanje->next;
		}
		else
		{
			pokStart = NULL;
		}
	}
	else
	{
		if (studZaBrisanje->prosli != NULL)
		{
			if (studZaBrisanje != NULL)
			{
				studZaBrisanje->prosli->next = studZaBrisanje->next;
			}
			if (studZaBrisanje->next != NULL)
			{
				studZaBrisanje->next->prosli = studZaBrisanje->prosli;
			}
		}
	}
	if (studZaBrisanje != NULL)
	{
		studZaBrisanje = NULL;
		free(studZaBrisanje);
	}
	return pokStart;
}
