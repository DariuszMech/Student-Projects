//POP_2020_01_13_projekt_2_Mech_Dariusz_EIT_7_180127/ c++ GCC GNU Compiler
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

    //string plikdane = "dane.txt" , plikwejscia = "wejscie.txt" , plikwyjscia = "wyjscie.txt" ;
    string plikdane, plikwejscia, plikwyjscia;
    string wartosc1, wartosc2, wartosc3;
    fstream dane, wejscie, wyjscie;
    string linia, liniad;
    int Q, pozycja1, pozycja2, roznica;
    string wariant1, wariant2, wariant3;
    string do_wklejenia, szukane1, szukane2;
    string linia2;
    string t2, t3, t4;
    string DUZYWyraz, MALYWyraz;
    string liniaN;
    int o;

    int ASCII = 34;
    char cds = ( char )ASCII;
    string cudzyslow;
    int ASCII2 = 92;
    char ukos = ( char )ASCII2;
    string ukosnik;
    int ASCII3 = 39;
    char apost = ( char )ASCII3;
    string apostrof;

    void znakiASCII()
    {
        cudzyslow = cds;
        ukosnik = ukos;
        apostrof = apost;
    }

    void wpisywaniePlikow()
    {
        cout<<"Ktory plik wejscia otworzyc? ";cin>>plikwejscia;
        cout<<"Z ktorego pliku pobrac dane? ";cin>>plikdane;
        cout<<"Do jakiego pliku zapisac wynik koncowy? ";cin>>plikwyjscia;
        cout<<endl;
    }

    void koniecPetli()
    {
        cout<<endl<<endl<<"Kliknij:"<<endl
        <<" x - aby zakonczyc program"<<endl<<" dowolny inny klawisz - aby wykonac operacje na innych plikach"<<endl
        <<"a nastepnie zatwierdz swoj wybor klikajac enter"<<endl<<endl; cin.get();
        if(cin.get()=='x')
        {
            exit(0);
        }
    }

    bool liczenieKlamer()
    {
        o=0;                                 //ZLICZA ILE JEST MIEJSC W 1 LINIJCE, W KTÓRYCH MUSI WSTAWIC ODPOWIEDNIE WARTOSCI
        for(int Y=0; Y<linia.length(); Y++)
        {
            if(linia[Y]=='{')
                {
                    if((linia[Y]=='{') && (linia[Y-1]=='{'))  //ARGUMENTY Z PODWÓJNYMI KLAMRAMI POMIJA I ZAMIENIA PO SKOCZENIU
                    {                                         //                                     PĘTLI, ABY UNIKNĄC BŁĘDÓW
                        linia[Y-1]='@';
                        linia[Y]='@';
                    }
                    o++;
                }
        }
         for(int Y=linia.length(); Y>0; Y--)
        {

            if(linia[Y]=='}')
                {
                    if((linia[Y]=='}') && (linia[Y-1]=='}'))
                    {
                        linia[Y-1]='%';
                        linia[Y]='%';
                        o=o-2;
                    }
                }
        }return o ;
    }

    void startoweParametry()
    {
        Q = linia.length();
        wariant1 = "", wariant2 = "", wariant3= "";
        liniaN = linia;
    }

    void szukanieNazwyKlamry()
    {
            szukane1="{";
            pozycja1=liniaN.find(szukane1)+1;
            szukane2="}";
            pozycja2=liniaN.find(szukane2)-1;

            roznica=pozycja2-pozycja1+1;

            linia2 = liniaN;
            t2 = linia2.insert( 0, linia2, pozycja1, pozycja2 );
            t3 = t2.erase(roznica, Q + 3 );
            t4 = t3;
            t3 = t4.erase(roznica, t4.length()-roznica);   // t3 = NAZWA ZAWARTA MIĘDZY KLAMRAMI

            if(t3[0]==cds || t3[0]=='^' || t3[0]=='_' || t3[0]=='?')
            {
                t3.erase(0,1);
            }

            if(t4[0]=='?')
            {
                int liczba_poworzen = t4.length(), i = 0;
                int poz[3];
                for(int t=0; t<=liczba_poworzen; t++)
                {
                    if(t4[t]==':')
                    {
                        poz[i]=t;
                        i++;
                    }
                }
                wariant1 = wariant1.insert(0, t4, 1, poz[0]-1 );
                wariant2 = wariant2.insert(0, t4, poz[0]+1, poz[1]-poz[0]-1);
                wariant3 = wariant3.insert(0, t4, poz[1]+1, poz[2]-poz[0]-1);
                t3 = wariant2;
            }
    }

    void podmianaZawartosci()
    {
                    if(t4[0]=='?')
                    {
                        int miejsce1 = liniad.find(wariant1);
                        int miejsce2 = liniad.find(wariant2);
                        int miejsce3 = liniad.find(wariant3);

                        if(miejsce1==0)
                        {
                            wartosc1 = liniad.erase(0,wariant1.length()+1);
                        }
                        if(miejsce2==0)
                        {
                            wartosc2 = liniad.erase(0,wariant2.length()+1);
                        }
                        if(miejsce3==0)
                        {
                            wartosc3 = liniad.erase(0,wariant3.length()+1);
                        }

                        if(wartosc1=="")
                        {
                            do_wklejenia = wartosc3;
                        }
                        else
                        {
                            do_wklejenia = wartosc2;
                        }
                    }

                    int miejsce = liniad.find(t3);

                    if(miejsce==0)
                    {
                        do_wklejenia = liniad.erase(0,t3.length()+1);

                        if(t4[0]=='^')
                        {
                            DUZYWyraz = do_wklejenia;
                            for(int a=0;a<DUZYWyraz.length();a++)
                            {
                                DUZYWyraz[a]=toupper(DUZYWyraz[a]);
                            }
                            do_wklejenia = DUZYWyraz;
                        }

                        if(t4[0]=='_')
                        {
                            MALYWyraz = do_wklejenia;
                            for(int a=0;a<MALYWyraz.length();a++)
                            {
                                MALYWyraz[a]=tolower(MALYWyraz[a]);
                            }
                            do_wklejenia = MALYWyraz;
                        }

                        if(t4[0]==cds)
                        {
                            int* pozycja = new int [Q];
                            int j=0;

                            for(int a=0; a<=do_wklejenia.length();a++)         // sprawdza na jakich pozycjach stringa leza poszukiwane znaki (ukosnik)
                            {
                                if(do_wklejenia[a]==ukos)
                                {
                                    pozycja[j]=a;
                                    j++;
                                }
                            }
                            int k=0;
                            for(int a=0; a<j;a++)       // dodaje ukoœnik przed poszukiwanym znakiem
                            {
                                do_wklejenia.insert(pozycja[k]+a,ukosnik);
                                k++;
                            }

                            j=0;
                            k=0;
                            for(int a=0; a<=do_wklejenia.length();a++)      // sprawdza na jakich pozycjach stringa le¿¹ poszukiwane znaki (cudzys³ów)
                            {
                                if(do_wklejenia[a]==cds)
                                {
                                    pozycja[j]=a;
                                    j++;
                                }
                            }
                            k=0;
                            for(int a=0; a<j;a++)        // dodaje ukoœnik przed poszukiwanym znakiem
                            {
                                do_wklejenia.insert(pozycja[k]+a,ukosnik);
                                k++;
                            }

                            k=0;
                            j=0;
                            for(int a=0; a<=do_wklejenia.length();a++)         // sprawdza na jakich pozycjach stringa le¿¹ poszukiwane znaki (apostrof)
                            {
                                if(do_wklejenia[a]==apost)
                                {
                                    pozycja[j]=a;
                                    j++;
                                }
                            }
                            k=0;
                            for(int a=0; a<j;a++)         // dodaje ukoœnik przed poszukiwanym znakiem
                            {
                                do_wklejenia.insert(pozycja[k]+a,ukosnik);
                                k++;
                            }
                            delete[] pozycja;
                            do_wklejenia=cudzyslow+do_wklejenia+cudzyslow;
                        }
                    }
    }

    void wklejenieNowejZawartosci()
    {
        liniaN.erase(pozycja1-1, roznica+2);
        liniaN.insert(pozycja1-1,do_wklejenia);
        Q = Q + do_wklejenia.length()-roznica;
    }

    void zamianaPodwojnychKlamer()
    {
        for(int Z=0; Z<liniaN.length(); Z++)
        {
            if(liniaN[Z]=='@')
            {
                liniaN.erase(Z, 2);
                liniaN.insert(Z,"{");
            }
            if(liniaN[Z]=='%')
            {
                liniaN.erase(Z, 2);
                liniaN.insert(Z,"}");
            }
        }
    }

int main ( )
{
    znakiASCII();
    for(;;){
        for(;;){
            system("cls");
            wpisywaniePlikow();
            if(plikwyjscia==plikwejscia)
            {
                cout<<"Plik wyjscia nie moze byc taki sam jak plik wejscia"<<endl;
                koniecPetli();
                break;
            }
            if(plikwyjscia==plikdane)
            {
                cout<<"Plik wyjscia nie moze byc taki sam jak plik danych"<<endl;
                koniecPetli();
                break;
            }
            wejscie.open(plikwejscia.c_str(), ios::in);
            if(wejscie.good()==false)
            {
                cout<<"Plik nie istnieje! (PLIK WEJSCIA)";
                koniecPetli();
                break;
            }
            dane.open(plikdane.c_str(), ios::in);
            if(dane.good()==false)
            {
                cout<<"Plik nie istnieje! (PLIK DANYCH)";
                koniecPetli();
                break;
            }
            dane.close();
            wyjscie.open(plikwyjscia.c_str(), ios::out);
            while(getline(wejscie,linia))
            {
                liczenieKlamer();       // ZWRACA   o   - LICZBĘ KLAMER ( MIEJSC DO PODMIANY )
                startoweParametry();
                for(int P=0; P<o; P++)
                {
                    szukanieNazwyKlamry();
                    dane.open(plikdane.c_str(), ios::in);
                    while(getline(dane,liniad))
                    {
                        podmianaZawartosci();
                    }
                    dane.close();
                    wklejenieNowejZawartosci();
                }
                zamianaPodwojnychKlamer();
                cout<<liniaN<<endl;
                wyjscie<<liniaN<<endl;
            }
            wyjscie.close();
            wejscie.close();
            cout<<endl<<"-----Operacja zakonczona pomyslnie-----"<<endl<<endl;
            koniecPetli();
        }
    }
return 0;
}


/*WERSJA BEZ VIOD-ów
int main ( )
{
    cudzyslow = cds;
    ukosnik = ukos;
    apostrof = apost;
for(;;){
for(;;){
    system("cls");
    cout<<"Ktory plik wejscia otworzyc? ";cin>>plikwejscia;
    cout<<"Z ktorego pliku pobrac dane? ";cin>>plikdane;
    cout<<"Do jakiego pliku zapisac wynik koncowy? ";cin>>plikwyjscia;
    cout<<endl;
    if(plikwyjscia==plikwejscia)
    {
        cout<<"Plik wyjscia nie moze byc taki sam jak plik wejscia"<<endl;
        cout<<endl<<endl<<"Kliknij:"<<endl
        <<" x - aby zakonczyc program"<<endl<<" dowolny inny klawisz - aby wykonac operacje na innych plikach"<<endl
        <<"a nastepnie zatwierdz swoj wybor klikajac enter"<<endl<<endl; cin.get();
        if(cin.get()=='x')
        {
            exit(0);
        }
        break;
    }
    if(plikwyjscia==plikdane)
    {
        cout<<"Plik wyjscia nie moze byc taki sam jak plik danych"<<endl;
        cout<<endl<<endl<<"Kliknij:"<<endl
        <<" x - aby zakonczyc program"<<endl<<" dowolny inny klawisz - aby wykonac operacje na innych plikach"<<endl
        <<"a nastepnie zatwierdz swoj wybor klikajac enter"<<endl<<endl; cin.get();
        if(cin.get()=='x')
        {
            exit(0);
        }
        break;
    }
    wejscie.open(plikwejscia.c_str(), ios::in);
    if(wejscie.good()==false)
    {
        cout<<"Plik nie istnieje! (PLIK WEJSCIA)";
        cout<<endl<<endl<<"Kliknij:"<<endl
        <<" x - aby zakonczyc program"<<endl<<" dowolny inny klawisz - aby wykonac operacje na innych plikach"<<endl
        <<"a nastepnie zatwierdz swoj wybor klikajac enter"<<endl<<endl; cin.get();
        if(cin.get()=='x')
        {
            exit(0);
        }
        break;
    }
    dane.open(plikdane.c_str(), ios::in);
    if(dane.good()==false)
    {
        cout<<"Plik nie istnieje! (PLIK DANYCH)";
        cout<<endl<<endl<<"Kliknij:"<<endl
        <<" x - aby zakonczyc program"<<endl<<" dowolny inny klawisz - aby wykonac operacje na innych plikach"<<endl
        <<"a nastepnie zatwierdz swoj wybor klikajac enter"<<endl<<endl; cin.get();
        if(cin.get()=='x')
        {
            exit(0);
        }
        break;
    }
    dane.close();
    wyjscie.open(plikwyjscia.c_str(), ios::out);
    while(getline(wejscie,linia))
    {
        o=0;                                            //ZLICZA ILE JEST MIEJSC W 1 LINIJCE, W KTÓRYCH MUSI WSTAWIC ODPOWIEDNIE WARTOSCI
        for(int Y=0; Y<linia.length(); Y++)
        {
            if(linia[Y]=='{')
                {
                    if((linia[Y]=='{') && (linia[Y-1]=='{'))  //ARGUMENTY Z PODWÓJNYMI KLAMRAMI POMIJA I ZAMIENIA PO SKOCZENIU
                    {                                         //                                     PĘTLI, ABY UNIKNĄC BŁĘDÓW
                        linia[Y-1]='@';
                        linia[Y]='@';
                    }
                    o++;
                }
        }
         for(int Y=linia.length(); Y>0; Y--)
        {

            if(linia[Y]=='}')
                {
                    if((linia[Y]=='}') && (linia[Y-1]=='}'))
                    {
                        linia[Y-1]='%';
                        linia[Y]='%';
                        o=o-2;
                    }
                }
        }                                                   ////////////////////////////////////////////////////////////////////////////////

        Q = linia.length();
        wariant1 = "", wariant2 = "", wariant3= "";
        liniaN = linia;

        for(int P=0; P<o; P++)
        {
            szukane1="{";
            pozycja1=liniaN.find(szukane1)+1;
            szukane2="}";
            pozycja2=liniaN.find(szukane2)-1;

            roznica=pozycja2-pozycja1+1;

            linia2 = liniaN;
            t2 = linia2.insert( 0, linia2, pozycja1, pozycja2 );
            t3 = t2.erase(roznica, Q + 3 );
            t4 = t3;
            t3 = t4.erase(roznica, t4.length()-roznica);   // t3 = NAZWA ZAWARTA MIĘDZY KLAMRAMI

            if(t3[0]==cds || t3[0]=='^' || t3[0]=='_' || t3[0]=='?')
            {
                t3.erase(0,1);
            }

            if(t4[0]=='?')
            {
                int liczba_poworzen = t4.length(), i = 0;
                int poz[3];
                for(int t=0; t<=liczba_poworzen; t++)
                {
                    if(t4[t]==':')
                    {
                        poz[i]=t;
                        i++;
                    }
                }
                wariant1 = wariant1.insert(0, t4, 1, poz[0]-1 );
                wariant2 = wariant2.insert(0, t4, poz[0]+1, poz[1]-poz[0]-1);
                wariant3 = wariant3.insert(0, t4, poz[1]+1, t4.length()-poz[0]-1);
                t3 = wariant2;
            }

            dane.open(plikdane.c_str(), ios::in);
            while(getline(dane,liniad))
            {
                    if(t4[0]=='?')
                    {
                        int miejsce1 = liniad.find(wariant1);
                        int miejsce2 = liniad.find(wariant2);
                        int miejsce3 = liniad.find(wariant3);

                        if(miejsce1==0)
                        {
                            wartosc1 = liniad.erase(0,wariant1.length()+1);
                        }
                        if(miejsce2==0)
                        {
                            wartosc2 = liniad.erase(0,wariant2.length()+1);
                        }
                        if(miejsce3==0)
                        {
                            wartosc3 = liniad.erase(0,wariant3.length()+1);
                        }

                        if(wartosc1=="")
                        {
                            do_wklejenia = wartosc3;
                        }
                        else
                        {
                            do_wklejenia = wartosc2;
                        }
                    }

                    int miejsce = liniad.find(t3);

                    if(miejsce==0)
                    {
                        do_wklejenia = liniad.erase(0,t3.length()+1);

                        if(t4[0]=='^')
                        {
                            DUZYWyraz = do_wklejenia;
                            for(int a=0;a<DUZYWyraz.length();a++)
                            {
                                DUZYWyraz[a]=toupper(DUZYWyraz[a]);
                            }
                            do_wklejenia = DUZYWyraz;
                        }

                        if(t4[0]=='_')
                        {
                            MALYWyraz = do_wklejenia;
                            for(int a=0;a<MALYWyraz.length();a++)
                            {
                                MALYWyraz[a]=tolower(MALYWyraz[a]);
                            }
                            do_wklejenia = MALYWyraz;
                        }

                        if(t4[0]==cds)
                        {
                            int* pozycja = new int [Q];
                            int j=0;
                            for(int a=0; a<=do_wklejenia.length();a++)         // sprawdza na jakich pozycjach stringa le¿¹ poszukiwane znaki (ukosnik)
                            {
                                if(do_wklejenia[a]==ukos)
                                {
                                    pozycja[j]=a;
                                    j++;
                                }
                            }
                            int k=0;
                            for(int a=0; a<j;a++)       // dodaje ukoœnik przed poszukiwanym znakiem
                            {
                                do_wklejenia.insert(pozycja[k]+a,ukosnik);
                                k++;
                            }

                            j=0;
                            k=0;
                            for(int a=0; a<=do_wklejenia.length();a++)      // sprawdza na jakich pozycjach stringa le¿¹ poszukiwane znaki (cudzys³ów)
                            {
                                if(do_wklejenia[a]==cds)
                                {
                                    pozycja[j]=a;
                                    j++;
                                }
                            }
                            k=0;
                            for(int a=0; a<j;a++)        // dodaje ukoœnik przed poszukiwanym znakiem
                            {
                                do_wklejenia.insert(pozycja[k]+a,ukosnik);
                                k++;
                            }

                            k=0;
                            j=0;
                            for(int a=0; a<=do_wklejenia.length();a++)         // sprawdza na jakich pozycjach stringa le¿¹ poszukiwane znaki (apostrof)
                            {
                                if(do_wklejenia[a]==apost)
                                {
                                    pozycja[j]=a;
                                    j++;
                                }
                            }
                            k=0;
                            for(int a=0; a<j;a++)         // dodaje ukoœnik przed poszukiwanym znakiem
                            {
                                do_wklejenia.insert(pozycja[k]+a,ukosnik);
                                k++;
                            }
                            delete[] pozycja;
                            do_wklejenia=cudzyslow+do_wklejenia+cudzyslow;
                        }
                    }
            }
            dane.close();
            liniaN.erase(pozycja1-1, roznica+2);
            liniaN.insert(pozycja1-1,do_wklejenia);
            Q = Q + do_wklejenia.length()-roznica;
        }

        for(int Z=0; Z<liniaN.length(); Z++)
        {
            if(liniaN[Z]=='@')
            {
                liniaN.erase(Z, 2);
                liniaN.insert(Z,"{");
            }
            if(liniaN[Z]=='%')
            {
                liniaN.erase(Z, 2);
                liniaN.insert(Z,"}");
            }
        }
        cout<<liniaN<<endl;
        wyjscie<<liniaN<<endl;
    }
    wyjscie.close();
    wejscie.close();
    cout<<endl<<"-----Operacja zakonczona pomyslnie-----"<<endl<<endl;
    cout<<endl<<endl<<"Kliknij:"<<endl
    <<" x - aby zakonczyc program"<<endl<<" dowolny inny klawisz - aby wykonac operacje na innych plikach"<<endl
    <<"a nastepnie zatwierdz swoj wybor klikajac enter"<<endl<<endl; cin.get();
    if(cin.get()=='x')
    {
        exit(0);
    }
}}
return 0;
}
*/
