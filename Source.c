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

studenti* StvaranjeStud();
studenti* DodajNaPocetak(studenti* pokStart);
studenti* DodajNaKraj(studenti* pokStart);
studenti* Brisanje(studenti* pokStart);
studenti* UbacivanjeIza(studenti* pokStart);
studenti* UbacivanjePrije(studenti* pokStart);
int UpisListeUFile(studenti* start);
studenti* CitajSljed(studenti* start, FILE* f_list);
studenti* CitanjeIzFilea(studenti* start);
int ciscMem(studenti* start);
int ispis(studenti* start);
int SortiranjeListe(studenti* start);

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

		printf("5.Ubacivanje iza odabranog studenta\n");

		printf("6.Ubacivanje prije odabranog studenta\n");

		printf("7.Upisivanje u file\n");

		printf("8.Citanje iz filea\n");

		printf("9.Sortiranje\n");

		printf("10.Izlaz\n");

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

		if (unos == 5)
		{
			start = UbacivanjeIza(start);
		}

		if (unos == 6)
		{
			start = UbacivanjePrije(start);
		}

		if (unos == 7)
		{
			start = UpisListeUFile(start);
		}

		if (unos == 8)
		{
			start = CitanjeIzFilea(start);
		}
		if (unos == 9)
		{
			start = SortiranjeListe(start);
		}
	} while (unos != 10);

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

studenti* UbacivanjeIza(studenti* pokStart)

{

	char ime[20] = { '0' };

	char prezime[20] = { '0' };

	int godina = 0;

	studenti* refStudent = pokStart;

	studenti* noviStud = NULL;



	printf("Unesite ime studenta iza kojeg zelite ubaciti novog: ");

	scanf("%s %s", ime, prezime);



	if (strcmp(ime, refStudent->ime) == 0 && strcmp(prezime, refStudent->prezime) == 0)

	{

		noviStud = StvaranjeStud();

	}

	else

	{

		while (refStudent->next != NULL)

		{

			refStudent = refStudent->next;

			if (strcmp(ime, refStudent->ime) == 0 && strcmp(prezime, refStudent->prezime) == 0)

			{

				noviStud = StvaranjeStud();

				break;

			}

		}

	}

	if (noviStud != NULL)

	{

		noviStud->next = refStudent->next;

		if (noviStud->next != NULL)

		{

			noviStud->next->prosli = noviStud;

		}

		refStudent->next = noviStud;

		noviStud->prosli = refStudent;

	}

	else

	{

		printf("Student nije pronaden\n!!!");

	}

	return pokStart;

}

studenti* UbacivanjePrije(studenti* pokStart)

{

	char ime[20] = { '0' };

	char prezime[20] = { '0' };

	int godina = 0;

	studenti* refStudent = pokStart;

	studenti* noviStud = NULL;



	printf("Unesite ime studenta prije kojeg zelite ubaciti novog: ");

	scanf("%s %s", ime, prezime);



	if (strcmp(ime, refStudent->ime) == 0 && strcmp(prezime, refStudent->prezime) == 0)

	{

		noviStud = StvaranjeStud();

	}

	else

	{

		while (refStudent->prosli != NULL)

		{

			refStudent = refStudent->prosli;

			if (strcmp(ime, refStudent->ime) == 0 && strcmp(prezime, refStudent->prezime) == 0)

			{

				noviStud = StvaranjeStud();

				break;

			}

		}

	}

	if (noviStud != NULL)

	{

		noviStud->prosli = refStudent->prosli;
		if (noviStud->next != NULL)
		{
			noviStud->prosli->next = noviStud;
		}
		refStudent->prosli = noviStud;
		noviStud->next = refStudent;
	}
	else
	{
		printf("Student nije pronaden\n!!!");
	}
	return pokStart;
}

int UpisListeUFile(studenti* pokStart)

{

	FILE* f_list = NULL;

	char imeFilea[20] = { '0' };

	printf("Unesite ime datoteke koju zelite otvoriti: ");

	scanf("%s", imeFilea);



	f_list = fopen(imeFilea, "wb");



	if (f_list == NULL)

	{

		printf("Greska pri otvaranju filea!!\n");

		return 0;

	}

	else

	{

		studenti* trenutniStud = pokStart;

		studenti* zadrSljed = NULL;

		studenti* zadrPreth = NULL;



		while (trenutniStud != NULL)

		{

			zadrSljed = trenutniStud->next;

			zadrPreth = trenutniStud->prosli;

			trenutniStud->next = NULL;

			trenutniStud->prosli = NULL;



			fseek(f_list, 0, SEEK_END);


			//fwrite(trenutniStud, sizeof(trenutniStud), 1, f_list);

			fprintf(f_list, "%s\t %s\t %d \n", pokStart->ime, pokStart->prezime, pokStart->godina);


			printf("Upisivanje %s %s %d u file\n", trenutniStud->ime, trenutniStud->prezime, trenutniStud->godina);



			trenutniStud->next = zadrSljed;

			trenutniStud->prosli = zadrPreth;



			zadrSljed = NULL;

			zadrPreth = NULL;



			trenutniStud = trenutniStud->next;

		}

		fclose(f_list);

	}

	return 0;

}

studenti* CitajSljed(studenti* start, FILE* f_list)

{

	studenti* indexStud = NULL;

	size_t returnValue;

	if (start == NULL)

	{

		start = malloc(sizeof(studenti));

		returnValue = fread(start, sizeof(studenti), 1, f_list);

		start->next = NULL;

		start->prosli = NULL;

	}

	else

	{

		studenti* indexStud = start;

		studenti* NoviStud = malloc(sizeof(studenti));



		while (indexStud->next != NULL)

		{

			indexStud = indexStud->next;

		}

		returnValue = fread(NoviStud, sizeof(studenti), 1, f_list);

		indexStud->next = NoviStud;

		NoviStud->next = NULL;

		NoviStud->prosli = indexStud;



	}

	return start;

}

studenti* CitanjeIzFilea(studenti* start)
{
	long filesize = 0;
	int brojUpisa = 0;
	FILE* f_list = NULL;
	char imeFilea[20] = { '0' };
	printf("Unesite ime datoteke koju zelite otvoriti: ");
	scanf("%s", imeFilea);

	f_list = fopen(imeFilea, "rb");

	if (f_list == NULL)
	{
		printf("Greska pri otvaranju filea!!\n");
		return 0;
	}
	else
	{
		ciscMem(start);
		start = NULL;

		fseek(f_list, 0, SEEK_END);
		filesize = ftell(f_list);
		rewind(f_list);

		brojUpisa = filesize / (sizeof(studenti));

		printf("Broj upisanih u listu: %d\n", brojUpisa);

		for (int i = 0; i < brojUpisa; ++i)
		{
			fseek(f_list, (sizeof(studenti) * i), SEEK_SET);
			start = CitajSljed(start, f_list);
		}
	}
	return start;
}

int SortiranjeListe(studenti* pokStart)
{
	studenti* point = NULL;
	studenti* pPoint = NULL;
	studenti* zPoint = NULL;
	studenti* temp = NULL;

	while (pokStart->next != zPoint)
	{
		point = pokStart->next;
		pPoint = pokStart;

		while (point->next != zPoint)
		{
			if (_strcmpi(point->prezime, point->next->prezime) > 0)
			{
				temp = point->next;
				point->next = temp->next;
				temp->next = point;
				pPoint->next = temp;

				point = temp;
			}
			pPoint = point;
			point = point->next;
		}
		pPoint = point;
	}

	printf("Lista je sortirana po prezimenu.\n");
	return 0;
}