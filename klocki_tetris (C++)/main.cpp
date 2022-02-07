//POP_2019_12_09_projekt_1_Mech_Dariusz_EiT_7_180127.cpp/ c++ GCC GNU Compiler

#include<cstdio>
#include<ctype.h>
#include"conio2.h"

#define F 0
#define I 1
#define L 2
#define N 3
#define P 4
#define T 5
#define U 6
#define V 7
#define W 8
#define X 9
#define Y 10
#define Z 11

using namespace std;

const int SZEROKOSC = 40;       //Wymiary planszy
const int WYSOKOSC = 20;

const int ODSTEP_X = 1;         //Odstep w pionie(ilosc wierszy) od gory ekranu/konsoli
const int ODSTEP_Y = 1;

const char ZNAK_AKTYWNEGO_KLOCKA = '#';
const char ZNAK_NIEAKTYWNEGO_KLOCKA = ' ';

const int LICZBA_KLOCKOW = 12;
const int MAX_WYMIAR_KLOCKA = 5;

const short int KOLORY[LICZBA_KLOCKOW] = {1,2,3,4,5,6,7,8,9,10,11,12}; //wartosci kolorow powinny odpowiadac tym uzytym w tablicy klocki

const short int KLOCKI[LICZBA_KLOCKOW][MAX_WYMIAR_KLOCKA][MAX_WYMIAR_KLOCKA] = {
    {{1,1,0,0,0},
     {0,1,1,0,0},
     {0,1,0,0,0},
     {0,0,0,0,0},
     {0,0,0,0,0}},

    {{2,0,0,0,0},
     {2,0,0,0,0},
     {2,0,0,0,0},
     {2,0,0,0,0},
     {2,0,0,0,0}},

    {{0,3,0,0,0},
     {0,3,0,0,0},
     {0,3,0,0,0},
     {3,3,0,0,0},
     {0,0,0,0,0}},

    {{4,0,0,0,0},
     {4,0,0,0,0},
     {4,4,0,0,0},
     {0,4,0,0,0},
     {0,0,0,0,0}},

    {{0,5,5,0,0},
     {0,5,5,0,0},
     {0,0,5,0,0},
     {0,0,0,0,0},
     {0,0,0,0,0}},

    {{6,6,6,0,0},
     {0,6,0,0,0},
     {0,6,0,0,0},
     {0,0,0,0,0},
     {0,0,0,0,0}},

    {{7,0,7,0,0},
     {7,7,7,0,0},
     {0,0,0,0,0},
     {0,0,0,0,0},
     {0,0,0,0,0}},

    {{8,0,0,0,0},
     {8,0,0,0,0},
     {8,8,8,0,0},
     {0,0,0,0,0},
     {0,0,0,0,0}},

    {{9,0,0,0,0},
     {9,9,0,0,0},
     {0,9,9,0,0},
     {0,0,0,0,0},
     {0,0,0,0,0}},

    {{0,10,0,0,0},
     {10,10,10,0,0},
     {0,10,0,0,0},
     {0,0,0,0,0},
     {0,0,0,0,0}},

    {{0,11,0,0,0},
     {0,11,11,0,0},
     {0,11,0,0,0},
     {0,11,0,0,0},
     {0,0,0,0,0}},

    {{0,12,12,0,0},
     {0,12,0,0,0},
     {12,12,0,0,0},
     {0,0,0,0,0},
     {0,0,0,0,0}}
};



bool wiersz_jest_pusty(short int klocek[MAX_WYMIAR_KLOCKA][MAX_WYMIAR_KLOCKA], //Sprawdza czy wiersz jest pusty
    int wiersz)                                                                 //(zawiera same zera)
{
    for(int i = 0;i<MAX_WYMIAR_KLOCKA;i++)
    {
        if(klocek[i][wiersz] != 0)
            return false;
    }
    return true;
}

bool kolumna_jest_pusta(short int klocek[MAX_WYMIAR_KLOCKA][MAX_WYMIAR_KLOCKA], //Sprawdza czy kolumna jest pusta
    int kolumna)
{
    for(int i = 0;i<MAX_WYMIAR_KLOCKA;i++)
    {
        if(klocek[kolumna][i] != 0)
            return false;
    }
    return true;
}

int odstep_od_dolu(short int klocek[MAX_WYMIAR_KLOCKA][MAX_WYMIAR_KLOCKA]) //Odstep klocek od dolu jego tablicy
{                                                                           //(sprawdza ile jest pustych wierszy od dolu tablicy klocek)
    int odstep = 0;
    for(int i = MAX_WYMIAR_KLOCKA-1;i>=0;i--)
    {
        if(wiersz_jest_pusty(klocek,i)) odstep++;
    }
    return odstep;
}

int odstep_od_prawej(short int klocek[MAX_WYMIAR_KLOCKA][MAX_WYMIAR_KLOCKA]) //Odstep klocka od prawej strony jego tablicy
{
    int odstep = 0;
    for(int i = MAX_WYMIAR_KLOCKA-1;i>=0;i--)
    {
        if(kolumna_jest_pusta(klocek,i)) odstep++;
    }
    return odstep;
}

bool sprawdz_dostepne_miejsce(short int klocek[MAX_WYMIAR_KLOCKA][MAX_WYMIAR_KLOCKA], //Sprawdza czy w danym miejscu na planszy jest wolne miejsce
    int x, int y, short int plansza[SZEROKOSC][WYSOKOSC])                     //x,y powinny odpowiadac 0,0 klocka
{
    if(x >= SZEROKOSC || x<0) return false;
    if(y >= WYSOKOSC || y<0) return false;

    for(int i = 0;i<MAX_WYMIAR_KLOCKA;i++)
    {
        for(int j = 0;j<MAX_WYMIAR_KLOCKA;j++)
        {   //Sprwadzamy czy "pelne" pola z tablicy nie beda wystawac poza obrys planszy (z prawej lub z dolu). Zwracamy false jesli tak
            if(x+i>SZEROKOSC+odstep_od_prawej(klocek) || y+j > WYSOKOSC+odstep_od_dolu(klocek)) return false;
            if((plansza[x+i][y+j] != 0) && (klocek[i][j] != 0)) return false;
        }   //Sprawdzamy czy klocek nie bedzie kolidowal z innymi na planszy.
    }
    return true;

}

bool dodaj_klocek(short int klocek[MAX_WYMIAR_KLOCKA][MAX_WYMIAR_KLOCKA], //Wpisuje klocek do tablicy z plansza
    int x, int y, short int plansza[SZEROKOSC][WYSOKOSC])
{
    if(!sprawdz_dostepne_miejsce(klocek,x,y,plansza)) return false; //Zwraca false jesli w danym miejscu na planszy nie ma miejsca na klocek
    for(int i = 0;i<MAX_WYMIAR_KLOCKA;i++)
    {
        for(int j = 0;j<MAX_WYMIAR_KLOCKA;j++)
        {
            if(klocek[i][j] != 0 && x+i<SZEROKOSC && y+j<WYSOKOSC)
                plansza[x+i][y+j] = klocek[i][j];
        }
    }
    return true; //Zwraca true jesli klocek zostal poprawnie dodany
}
int numer_klocka_koloru(int kolor) //zwraca numer klocka na podstawie koloru
{                                   //numer odpowiada indeksowi klocka w tablicy KLOCKI
    for(int i = 0;i<LICZBA_KLOCKOW;i++)
    {
        if(KOLORY[i] == kolor) return i;
    }
    return -1;                      //zwraca -1 jesli nie znaleziono klcka o takim kolorze
}

void rysuj_plansze(short int plansza[SZEROKOSC][WYSOKOSC]) //wypisuje zawartosc planszy
{
    for(int i = 0;i<SZEROKOSC;i++)
    {
        for(int j = 0;j<WYSOKOSC;j++)
        {
            gotoxy(ODSTEP_X+i+1,ODSTEP_Y+j+1);  //przenosi kursor do odpowiedniego miejsca na ekranie
            textbackground(plansza[i][j]);      //ustawia kolor tla z komorki tablicy plansza
            putch(ZNAK_NIEAKTYWNEGO_KLOCKA);    //wypisuje spacje
        }
    }
}

int numer_klocka(char litera)                   //zwraca numer klocka na podstawie litery
{                                               //zwraca -1 jesli nie znalazla klocka o takiej literze
    litera = toupper(litera);
    switch(litera)
    {
        case 'F': return F;
        case 'I': return I;
        case 'L': return L;
        case 'N': return N;
        case 'P': return P;
        case 'T': return T;
        case 'U': return U;
        case 'V': return V;
        case 'W': return W;
        case 'X': return X;
        case 'Y': return Y;
        case 'Z': return Z;
        default: return -1;
    }
}

void rysuj_granice_planszy()                //Rysuje obrys planszy
{
    textbackground(BLACK);
    textcolor(7);
    for(int i = 1;i <= SZEROKOSC+ODSTEP_X+1; i++)
    {
        gotoxy(i,ODSTEP_Y);
        putch('X');
        gotoxy(i,WYSOKOSC+ODSTEP_Y+1);
        putch('X');
    }
    for(int i = 2;i <= WYSOKOSC+ODSTEP_Y; i++)
    {
        gotoxy(ODSTEP_X,i);
        putch('X');
        gotoxy(SZEROKOSC+ODSTEP_X+1,i);
        putch('X');
    }
}

void wyczysc_plansze(short int plansza[SZEROKOSC][WYSOKOSC]) //wypelnia plansze zerami
{
    for(int i = 0;i<SZEROKOSC;i++)
    {
        for(int j =0;j<WYSOKOSC;j++)
        {
            plansza[i][j] = 0;
        }
    }
}

void wyswietl_aktywny_klocek(short int klocek[MAX_WYMIAR_KLOCKA][MAX_WYMIAR_KLOCKA], //wypisuje aktywny klocek na ekran
    int x,int y,short int plansza[SZEROKOSC][WYSOKOSC])                              //x i y to wspolrzedne kursora
{
    for(int i = 0;i<MAX_WYMIAR_KLOCKA;i++)
    {
        for(int j = 0;j<MAX_WYMIAR_KLOCKA;j++)
        {
            gotoxy(x+i,y+j);                                            //przenosi kursor do odpowiedniego miejsca
            textbackground(plansza[x+i-ODSTEP_X-1][y+j-ODSTEP_Y-1]);    //pobiera odpowiedni kolor tla z plansz(efekt przezroczystosci aktywnego klocka)
            if(klocek[i][j] > 0)
                putch(ZNAK_AKTYWNEGO_KLOCKA);                           //wyswietla znak
        }
    }
}

void wymaz_aktywny_klocek(short int klocek[MAX_WYMIAR_KLOCKA][MAX_WYMIAR_KLOCKA], //wymazuje aktywny klocek z planszy
    int x,int y, short int plansza[SZEROKOSC][WYSOKOSC])
{
    for(int i = 0;i<MAX_WYMIAR_KLOCKA;i++)
    {
        for(int j = 0;j<MAX_WYMIAR_KLOCKA;j++)
        {
            gotoxy(x+i,y+j);
            if(klocek[i][j] > 0 && plansza[x-ODSTEP_X-1+i][y-ODSTEP_Y-1+j] == 0) //symbole aktywnego klocka nadpisuje spacja z czarnym tlem
            {                                                                    //ale tylko jesli w tym miejscu na planszy nie ma innego klocka
                textbackground(BLACK);                                           //jesli jest to pomija, bo wtedy symbol zostanie nadpisany przez funkcje rysuj plansze
                putch(ZNAK_NIEAKTYWNEGO_KLOCKA);
            }
        }
    }
}

bool usun_klocek_z_planszy(int kolor, short int plansza[SZEROKOSC][WYSOKOSC]) //usuwa klocek z planszy na podstawie koloru
{
    if(kolor <= 0) return false; //zabezpieczenie przed niepoprawnym kolorem oraz kolorem tla

    int ile_usunieto = 0;               //licznik nadpisanych pol
    for(int i = 0;i<SZEROKOSC;i++)
    {
        for(int j = 0;j<WYSOKOSC;j++)
        {
            if(plansza[i][j] == kolor) //jezeli kolor w tablic w plansza jest rowny naszemu kolorowi
            {
                plansza[i][j] = BLACK;  //zamienia go na czarny(tlo)
                ile_usunieto++;         //zwieksza licznik
            }
            if(ile_usunieto == 5) break; //jezeli licznik dojdzie do 5 przerywa, bo kazdy klocek ma tylko 5 czesci(optymalizacja)
        }
        if(ile_usunieto == 5) break;
    }
    return (ile_usunieto>0); //wyrazenie ile_usunieto>0 oznacza prawde jesli zmienna ile_usunieto jest wieksza od zera
                            //co oznacza ze funkcja zwroci true jesli klocek zostal usuniety i false jesli nie zostal
}
void kopiuj_klocek(short int klocek1[MAX_WYMIAR_KLOCKA][MAX_WYMIAR_KLOCKA], //kopiuje z klockek 1 do klocek 2
    short int klocek2[MAX_WYMIAR_KLOCKA][MAX_WYMIAR_KLOCKA])
{
    for(int i = 0;i<MAX_WYMIAR_KLOCKA;i++)
    {
        for(int j = 0;j<MAX_WYMIAR_KLOCKA;j++)
        {
            klocek2[i][j] = klocek1[i][j];
        }
    }
}


void przesun_klocek_w_gore(short int klocek[MAX_WYMIAR_KLOCKA][MAX_WYMIAR_KLOCKA]) //Przesuwa klocek o jesden wiersz w gore w tablicy
{
    for(int i = 0;i<MAX_WYMIAR_KLOCKA;i++)
    {
        for(int j = 0;j<MAX_WYMIAR_KLOCKA-1;j++)
        {
            klocek[i][j] = klocek[i][j+1]; //zamienia wartosc komorek wierszy z komorkami z wiersza nizej(o jeden wiekszy indeks)
        }
    }
    for(int i = 0;i<MAX_WYMIAR_KLOCKA;i++)  //wypelnia najnizszy wiersz zerami
        klocek[i][MAX_WYMIAR_KLOCKA-1] = 0;
}

void przesun_klocek_w_lewo(short int klocek[MAX_WYMIAR_KLOCKA][MAX_WYMIAR_KLOCKA]) //Przesuwa klocek o jesden wiersz w gore w tablicy
{
    for(int i = 0;i<MAX_WYMIAR_KLOCKA-1;i++)
    {
        for(int j = 0;j<MAX_WYMIAR_KLOCKA;j++)
        {
            klocek[i][j] = klocek[i+1][j];
        }
    }
    for(int i = 0;i<MAX_WYMIAR_KLOCKA;i++)
        klocek[MAX_WYMIAR_KLOCKA-1][i] = 0;
}

void obroc_klocek(short int klocek[MAX_WYMIAR_KLOCKA][MAX_WYMIAR_KLOCKA]) //obraca klocek w jego tablicy
{
    short int klocek_stary[MAX_WYMIAR_KLOCKA][MAX_WYMIAR_KLOCKA];
    kopiuj_klocek(klocek,klocek_stary);                 //tworzy kopie klocka
    for(int i = 0;i<MAX_WYMIAR_KLOCKA;i++)
    {
        for(int j = 0;j<MAX_WYMIAR_KLOCKA;j++)
        {
            klocek[i][j] = klocek_stary[j][MAX_WYMIAR_KLOCKA-1-i]; //przenosi wartosci z kopii do orginalu uwzgledniajac obrot
        }
    }

    while(wiersz_jest_pusty(klocek,0)) //do poki wiersz zero jest pusty
    {
        przesun_klocek_w_gore(klocek);  //przesuwa klocek w gore
    }

    while(kolumna_jest_pusta(klocek,0)) //do poki kolumna zero jest pusta
    {
        przesun_klocek_w_lewo(klocek); //przesuwa klocek w lewo
    }
}

bool sprawdz_x(bool aktywny,int x,short int klocek[MAX_WYMIAR_KLOCKA][MAX_WYMIAR_KLOCKA]) //sprawsza czy aktywny klocek nie wychodzi poza prawa granice planszy
{                                                                                           //zwraca true jesli nie wychodzi, false jesli wychodzi
    if(!aktywny) return true;
    int szer = 0;
    for(int i = 0;i < MAX_WYMIAR_KLOCKA;i++)
    {
        for(int j = 0; j< MAX_WYMIAR_KLOCKA;j++)
        {
            if(klocek[i][j] != 0 && szer<i) szer = i;
        }
    }
    if(x+szer-ODSTEP_X-1 >= SZEROKOSC) return false;
    else return true;
}

bool sprawdz_y(bool aktywny,int y,short int klocek[MAX_WYMIAR_KLOCKA][MAX_WYMIAR_KLOCKA]) //sprawsza czy aktywny klocek nie wychodzi poza dolna granice planszy
{
    if(!aktywny) return true;
    int wys = 0;
    for(int i = 0;i < MAX_WYMIAR_KLOCKA;i++)
    {
        for(int j = 0; j< MAX_WYMIAR_KLOCKA;j++)
        {
            if(klocek[i][j] != 0 && wys<j) wys = j;
        }
    }
    if(y+wys-ODSTEP_Y-1 >= WYSOKOSC) return false;
    else return true;
}

int main() {
	int znak = 0, x = 20, y = 10, attr = WHITE, back = 0; //x,y poczatkowa pozycja kursora
	bool aktywny = false;  //czy jest aktywny klocek
	int numer_aktywnego_klocka;  //numer odpowiadajacy indeksowi tablicy KLOCKI
	short int aktywny_klocek[MAX_WYMIAR_KLOCKA][MAX_WYMIAR_KLOCKA];
	bool wykorzystane[LICZBA_KLOCKOW] = {false}; //trzyma informacje ktore klocki zostaly wykorzystane
	bool zero = false;
	short int plansza[SZEROKOSC][WYSOKOSC];

	wyczysc_plansze(plansza);

	// ukrycie migającego kursora
	_setcursortype(_NOCURSOR);
	// ustawienie koloru tła na czarny
	// w pliku conio2.h są wymienione dostępne kolory
	textbackground(BLACK);
	// wyczyszczenie ekranu: wypełnienie go spacjami
	// z ustawionym wcześniej kolorem tła
	clrscr();

	do {
        while(!sprawdz_y(aktywny,y,aktywny_klocek)) //sprawdzamy czy aktywny klocek nie jest poza obszarem (tylko wysokosc)
        {
            y--;    //i zmniejszamy wsporzedna y az bedzie w obszarze
        }

        while(!sprawdz_x(aktywny,x,aktywny_klocek))
        {
            x--;
        }

		// często nie trzeba czyścić ekranu przed każdym rysowaniem
		// ekranu, ponieważ nowy rysunek po prostu nadpisze poprzedni;
		// jeżeli jednak jest to trudne można przed rysowaniem planszy
		// wyczyścić ekran czyli zawołać clrscr();

		// tu należy narysować planszę
		// stan programu trzeba pamiętać np. w tablicy
		rysuj_granice_planszy(); //rysujemy granice planszy
		rysuj_plansze(plansza); //


		// ustawienie koloru tekstu i tła
		textcolor(LIGHTGRAY);
		textbackground(BLACK);
		// przeniesienie kursora do 48 kolumny w 1 wierszu
		// wiersze i kolumny są numerowane od 1
		gotoxy(48, 1);
		// cputs wypisuje na ekran podany napis
		// po wypisaniu każdego znaku kursor przesuwa się o jeden
		// znak w prawo, tak jak na zwykłej konsoli
		cputs("Imie Nazwisko");
		gotoxy(48, 2);
		cputs("123456");

		gotoxy(48, 4);
		cputs("Pozycja: ");
		cputs("          ");
		char pozycja[10];
		sprintf(pozycja,"%d, %d",x,y);
		gotoxy(57, 4);
		cputs(pozycja);

		gotoxy(48, 6);
		cputs("Legenda:");
		gotoxy(48, 7);
		cputs("kursory - ruch");
		gotoxy(48, 8);
		cputs("esc - wyjscie");
		gotoxy(48, 9);
		cputs("spacja - wstawienie klocka");
		gotoxy(48, 10);
		cputs("r - obrot");
		gotoxy(48, 11);
		cputs("c - usuniecie klocka");

		gotoxy(48, 13);
		cputs("FILNPTUVXYWZ");
		if(aktywny)
        {
            gotoxy(48+numer_aktywnego_klocka,14);
            putch('^');                             //oznaczamy aktywny klocek
        }
        else
        {
            gotoxy(48+numer_aktywnego_klocka,14);
            putch(' ');                            //wymazujemy ostatnie oznaczenie
        }


		// narysowanie gwiazdki
		gotoxy(x, y);

		if(!aktywny) //wyswietlanie kursora
        {
            // kolory tekstu i tła są tak naprawdę liczbami z przedziału
            // 0..15, więc można je przechowywać w zmiennej typu int,
            // dodawać, odejmować itp.
            textcolor(attr);
            back = plansza[x-ODSTEP_X-1][y-ODSTEP_Y-1];
            textbackground(back);
            // putch wypisuje jeden znak i przesuwa kursor o jedną
            // pozycję w prawo
            putch('*');

            // getch czeka na naciśnięcie klawisza i zwraca naciśnięty
            // klawisz; w większości przypadków zwrócony będzie znak
            // odpowiadający klawiszowi, np. dla klawisza a zostanie
            // zwrócone 'a', dla 2 będzie zwrócone '2', dla + wynikiem
            // będzie '+'; w niektórych przypadkach, m.in. dla strzałek
            // pierwsze wołanie getch zwróci zero, a kolejne kod
            // klawisza, np. kod strzałki w górę to 'H'; żeby odróżnić
            // strzałkę w górę od Shift+h musimy pamiętać, czy pierwsze
            // wywołanie getch zwróciło zero
            zero = false;
            znak = getch();

            // wymazujemy gwiazdkę z ekranu nadpisując ją spacją
            gotoxy(x, y);
            textbackground(back);
            putch(' ');
        }
        else
        {
            wyswietl_aktywny_klocek(aktywny_klocek,x,y,plansza);
            zero = false;
            znak = getch();
            wymaz_aktywny_klocek(aktywny_klocek,x,y,plansza);
        }
		// może to wymazać znak z legendy, ale po każdym klawiszu
		// rysujemy legendę na nowo, więc odtworzymy usunięty znak;
		// wymazujemy przed obsługą klawiszy ponieważ chcemy skorzystać
		// z nie zmienionych współrzędnych

		if(znak == 0) {		// jeżeli pierwszym znakiem było zero
			zero = true;	// zapamiętujemy ten fakt
			znak = getch();	// i czytamy rzeczywisty kod klawisza
			};
		if(zero) {		// znaki poprzedzone zerem
			if(znak == 72 && (y > ODSTEP_Y+1)) y--;		// strzałka w górę
			else if(znak == 80 && (y < WYSOKOSC+ODSTEP_Y)) y++;	// strzałka w dół
			else if(znak == 75 && (x > ODSTEP_X+1)) x--;	// strzałka w lewo
			else if(znak == 77 && (x < SZEROKOSC+ODSTEP_X)) x++;	// strzałka w prawo
		} else {		// znaki bez poprzedzającego zera
            if(znak == ' ' && aktywny)
            {
                //Wstawienie klocka
                if(dodaj_klocek(aktywny_klocek,x-ODSTEP_X-1,y-ODSTEP_Y-1,plansza))
                {
                    aktywny = false;
                    wykorzystane[numer_aktywnego_klocka] = true;
                }
            }
            else if(znak == 'r' && aktywny)
            {
                //obrot klocka
                obroc_klocek(aktywny_klocek);
            }
            else if(znak == 'c' && aktywny)
                aktywny = false;
            else if(znak == 'c' && !aktywny)
            {
                int kolor = plansza[x-ODSTEP_X-1][y-ODSTEP_Y-1];
                if(usun_klocek_z_planszy(kolor,plansza))
                {
                    int nr = numer_klocka_koloru(kolor);
                    if(nr >= 0 && nr < LICZBA_KLOCKOW)
                        wykorzystane[nr] = false;
                }
            }
            else
            {
                int k = numer_klocka(znak);
                if(k != -1)
                {
                    if(wykorzystane[k] != true)
                    {
                        aktywny = true;
                        numer_aktywnego_klocka = k;
                        for(int i = 0;i<MAX_WYMIAR_KLOCKA;i++)
                        {
                            for(int j = 0;j<MAX_WYMIAR_KLOCKA;j++)
                            {
                                aktywny_klocek[i][j] = KLOCKI[k][i][j];
                            }
                        }
                        textbackground(BLACK);
                        clrscr();
                    }
                }
            }
        };

	} while (zero || znak != 27);

	_setcursortype(_NORMALCURSOR);	// pokazanie migającego kursora,
                                    // by był widoczny po zakończeniu programu
    textbackground(BLACK);
    textcolor(7);
	return 0;
}
