/*
 * szablon do przedmiotu Podstawy Programowania 2019
 * do wykorzystania jedynie w zadaniu projektowym
 * oraz do prywatnych projektów związanych z nauką
 * autor: K.M. Ocetkiewicz
 */
#ifndef CONIO2_H
#define CONIO2_H

#include<cstdio>

#define BLACK		0	// dostępne kolory
#define BLUE		1
#define GREEN		2
#define CYAN		3
#define RED		4
#define MAGENTA		5
#define BROWN		6
#define LIGHTGRAY	7
#define DARKGRAY	8
#define LIGHTBLUE	9
#define LIGHTGREEN	10
#define LIGHTCYAN	11
#define LIGHTRED	12
#define LIGHTMAGENTA	13
#define YELLOW		14
#define WHITE		15

#define _NOCURSOR	0	// brak kursora
#define _SOLIDCURSOR	1	// pełen kursor
#define _NORMALCURSOR	2	// kursor w formie podkreślenia


extern int _wscroll;		// 1 = enable scroll
				// 0 = disable scroll

struct text_info {			// zob. funkcja gettextinfo
	unsigned char curx;		// współrzędna x kursora
	unsigned char cury;		// współrzędna y kursora
	unsigned short attribute;	// bieżący kolor tła i znaków (tło * 16 + znaki)
	unsigned short normattr;	// domyślny kolor tła i znaków
	unsigned char screenwidth;	// szerokość ekranu
	unsigned char screenheight;	// wysokość ekranu
	};


void gotoxy(int x, int y);		// przesunięcie kursora do pozycji (x,y)
int wherex(void);			// pobranie kolumny kursora
int wherey(void);			// pobranie wiersza kursora
void _setcursortype(int cur_t);		// ustawienie typu kursora: _NOCURSOR, _SOLIDCURSOR or _NORMALCURSOR

void textattr(int newattr);		// ustawienie koloru tła i tekstu: newattr = (kolor tekstu) + (kolor tła) * 16
void textbackground(int newcolor);	// ustawienie koloru tła dla nowych znaków
void textcolor(int newcolor);		// ustawienie koloru nowych znaków

void clrscr(void);			// wyczyszczenie całego ekranu

int getch(void);			// czekanie na naciśnięcie klawisza i zwrócenie naciśniętego klawisza
int getche(void);			// j.w. ale klawisz jest też wypisany na ekran
int kbhit(void);			// test czy klawisz został naciśnięty; zwraca wartość różną od zera
					// jeżeli tak; następne wywołanie funkcji getch na pewno nie będzie
					// czekało, tylko natychmiast zwróci kod ostatnio naciśniętego klawisza

int cputs(const char *str);		// wypisanie napisu na ekran w punkcie wskazanym kursorem
int putch(int c);			// wypisanie jednego znaku na ekran w punkcie wskazanym kursorem

// pobranie informacji o ekranie do struktury text_info
void gettextinfo(struct text_info *info);

// ustawienie tytułu okna konsoli
void settitle(const char *title);

#endif
