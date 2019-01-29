#include <iostream>
#include <fstream>																					//dla zapisu
#include <cstdlib>      																			//dla exita
#include <string>


using namespace std;

void dodawanie(int nralb, string imie, string nazw);
void usuwanie (int nralb, string imie, string nazw);
void wyswietl (int nralb, string imie, string nazw);


int i;
int nralb;
string imie, nazw;



int main()
{
    for(i=0; ;i++)      																		//nieskonczona
    {
        cout<<"Menu"<<endl;
        cout<<"1-Dodawanie albumu"<<endl;
        cout<<"2-Usuwanie albumu"<<endl;
        cout<<"3-Wyswietlanie"<<endl;
        cout<<"5-Koniec "<<endl;

        cin>>i;

        switch(i)
        {
            case 1: cout<<"Dodawanie albumu do bazy: "<<endl;

                    cout<<"Podaj imie: ";       cin>>imie;
                    cout<<"Podaj nazwisko: ";   cin>>nazw;
                    cout<<"Podaj nr albumu: ";  cin>>nralb;

                    dodawanie(nralb, imie, nazw);

                    break; continue;

            case 2: cout<<"Usuwanie albumu z bazy! "<<endl;
					
					usuwanie ( nralb, imie, nazw);

            break; continue;


            case 3: cout<<"Wyswietlanie: "<<endl;

                   wyswietl ( nralb, imie, nazw);

            break; continue;


            case 5: cout<<" KONIEC PRACY PROGRAMU "<<endl;

            exit(0);

        }
    }


    system("pause");
    return 0;
}


void dodawanie(int nralb, string imie, string nazw)
{
    fstream plik;

    plik.open("Baza Albumow.txt", ios::out | ios::app);

    plik << imie << endl;
    plik << nazw << endl;
    plik << nralb << endl;
   

    plik.close();
    plik.clear();


}


void usuwanie (int nralb, string imie, string nazw)
{
	fstream plik;
	plik.open("Baza Albumow.txt", ios::out | ios::trunc);
	
	if(plik.good()==true)
	{
		plik<<"";
	
	
	plik.close();
	plik.clear();
	}
	system("pause");
}


void wyswietl (int nralb, string imie, string nazw)

{
    fstream plik;
    

    plik.open("Baza Albumow.txt", ios::in);
    
    if (plik.peek()) {std::ifstream::traits_type::eof();}												//sprawdza czy jest pusty


    if (plik.good()==false)																				//czy istnieje
    {
        cout<<"Plik nie istnieje"<<endl;

        //exit(0);
        system("pause");
    }

    string linia; 																						//dla odczytu spacji w pliku
    int nrlinii=1;
    
    if (plik.peek()) {std::ifstream::traits_type::eof();
	}
   


    while(getline(plik,linia))
    {
        switch(nrlinii)
        {
            case 1: imie= linia; break;
            case 2: nazw = linia; break;
            case 3: nralb = atoi(linia.c_str());break; 													//przekonwertowanie nr na text

        }

       if (nrlinii==3) {nrlinii=0; }
       nrlinii++;
   		}
    	
    

   	do
    {
    	getline(plik,linia);

    cout << imie << endl;
    cout << nazw << endl;
    cout << nralb << endl;
    
    
	}
	while(linia != "");

	plik.close();
	plik.clear();
}

