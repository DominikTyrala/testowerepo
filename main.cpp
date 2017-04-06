#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

class Question
{
    string pytanie;
    string a;
    string b;
    string c;
    string d;
    string poprawna;
public:
    void setPytanie(string pyt,string x,string y,string z,string q,string ok){
        pytanie=pyt;
        a=x;
        b=y;
        c=z;
        d=q;
        poprawna=ok;
    }

    void getPytanie(){
        cout<<pytanie<<endl;
        cout<<"a) "<<a<<endl;
        cout<<"b) "<<b<<endl;
        cout<<"c) "<<c<<endl;
        cout<<"d) "<<d<<endl;
    }
    string getPoprawna(){
        string odp;
        odp=poprawna;
        return odp;
    }
};

void PopUp(int wynik){
    system("cls");
    for(int i=0;i<=3;i++)
    {
        cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
        cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
        cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
        cout<<"$$$$$$$$$GRATULACJE$$$$$$$$$"<<endl;
        cout<<"$$$$$$$$$$WYGRALES$$$$$$$$$$"<<endl;
        cout<<"$$$$$$$$$"<<wynik<<"$$$$$$$$$$$"<<endl;
        cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
        cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
        Sleep(1000);
        system("cls");
        Sleep(1000);
    }
}

int wygrana(int &punkty)
{
    if(punkty<2){
        return 0;
    }else if(punkty>1 && punkty<8){
        return 1000;
    }else if(punkty >7){
        return 1000000;
    }
}
int main()
{
    int liniaPlik=0;
    int punkty=0;
    Question Pytanie;

    string pytanie,a,b,c,d;
    string poprawna;
    string odpowiedz;

    fstream plik;
    plik.open("quiz.txt");

    if (plik.is_open())
    {
        cout<<"Pobieram pytania:"<<endl;
        while(!plik.eof())
        {
            for(int i=0;i<=5;i++)
            {
                switch(i)
                {
                case 0:
                    getline(plik,pytanie);
                    break;
                case 1:
                    getline(plik,a);
                    break;
                case 2:
                    getline(plik,b);
                    break;
                case 3:
                    getline(plik,c);
                    break;
                case 4:
                    getline(plik,d);
                    break;
                case 5:
                    getline(plik,poprawna);
                    break;
                }
            }
            Pytanie.setPytanie(pytanie,a,b,c,d,poprawna);
            Pytanie.getPytanie();

            cout<<"Podaj swoja odpowiedz: ";
            cin>>odpowiedz;

            if(Pytanie.getPoprawna()==odpowiedz){
                cout<<"Poprawna odpowiedz! Plus jeden punkt!"<<endl;
                punkty++;
            }else{
                cout<<"Zla odpowiedz"<<endl;
                punkty=0;
                break;
            }

            Sleep(1000);
            system("cls");
        }
        plik.close();
    }else
    {
        cout<<"Nie mozna otworzyc pliku z pytaniami"<<endl;
    }

    cout<<"Calkowita liczba punktow: "<<punkty<<endl;

    cout<<"Dziekuje za gre!"<<endl;

    PopUp(wygrana(punkty));

    return 0;
}
