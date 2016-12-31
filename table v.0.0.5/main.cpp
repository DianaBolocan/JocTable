#include "proiect.h"
using namespace std;

void defaultTabla(char tabla[26][15])
{
    short linie,coloana;
    for(linie=0; linie<26; linie++)
        for(coloana=0; coloana<15; coloana++)
            tabla[linie][coloana] = ' ';
    for(linie=0; linie<26; linie++)
    {
        if(linie == 1)
        {
            for(coloana=0; coloana<2; coloana++)
                tabla[linie][coloana] = 'N';
        }
        else if(linie == 6 || linie == 13)
        {
            for(coloana=0; coloana<5; coloana++)
                tabla[linie][coloana] = 'A';
        }
        else if(linie == 8)
        {
            for(coloana=0; coloana<3; coloana++)
                tabla[linie][coloana] = 'A';
        }
        else if(linie == 24)
        {
            for(coloana=0; coloana<2; coloana++)
                tabla[linie][coloana] = 'A';
        }
        else if(linie == 12 || linie == 19)
        {
            for(coloana=0; coloana<5; coloana++)
                tabla[linie][coloana] = 'N';
        }
        else if(linie == 17)
        {
            for(coloana=0; coloana<3; coloana++)
                tabla[linie][coloana] = 'N';
        }
    }
}

short numarPiese(char tabla[26][15],short linie)
{
    short piese=0;
    for(short coloana=6;coloana<15;coloana++)
        if(tabla[linie][coloana]!=' ')
    {
        piese++;
    }
    return piese;
}

void afisareTabla(char tabla[26][15])
{
    short linie,coloana;
    cout<<"  24  23  22  21  20  19 ||  18  17  16  15  14  13 "<<endl;
    cout<<"=========================||========================="<<endl;
    for(coloana=0;coloana<=5;coloana++)
    {
        cout<<" ";
        for(linie=24;linie>=13;linie--)
        {
                if(coloana!=5)
                    cout<<" "<<tabla[linie][coloana]<<" ";
                else
                {
                    if(tabla[linie][6]!=' ')
                    {
                        short piese;
                        piese = numarPiese(tabla,linie);
                        cout<<tabla[linie][5]<<"+"<<piese;
                    }
                    cout<<" "<<tabla[linie][5]<<" ";
                }
            cout<<" ";
            if(linie==19)
                cout<<"|| ";
        }
        cout<<endl;
    }
    cout<<"                         ||"<<endl;
    for(coloana=5;coloana>=0;coloana--)
    {
        cout<<" ";
        for(linie=1;linie<=12;linie++)
        {
            if(coloana!=5)
                cout<<" "<<tabla[linie][coloana]<<" ";
            else
            {
                if(tabla[linie][5]!=' ')
                {
                    short piese;
                    piese = numarPiese(tabla,linie);
                    cout<<tabla[linie][5]<<"+"<<piese;
                }
                else
                    cout<<" "<<tabla[linie][coloana]<<" ";
            }
            cout<<" ";
            if(linie == 6)
                cout<<"|| ";
        }
        cout<<endl;
    }
    cout<<"=========================||========================="<<endl;
    cout<<"  1   2   3   4   5   6  ||  7   8   9   10  11  12 "<<endl;
}

short randomDices()
{
    short dice;
    dice =(rand() % 6) + 1;
    return dice;
}

int sumaZar(short zar1,short zar2)
{
    zar1 = randomDices();
    zar2 = randomDices();
    short suma;
    if(zar1 == zar2)
        suma = 4*zar1;
    else
        suma = zar1 + zar2;
    return suma;
}

short primulJucator(player player1,player player2)
{
    srand(time(nullptr));
    short suma1 = sumaZar(player1.zar1,player1.zar2);
    short suma2 = sumaZar(player2.zar1,player2.zar2);
    if(suma1 > suma2)
    {
        cout<<"Prima mutare va fi facuta de "<<player1.nume<<"."<<endl;
        return 1;
    }
    else
        if(suma2>suma1)
        {
            cout<<"Prima mutare va fi facuta de "<<player2.nume<<"."<<endl;
            return 2;
        }
    else primulJucator(player1,player2);
}

bool sfarsitJoc(short eliminate)
{
    if(eliminate == 15)
        return true;
    return false;
}

bool isMart(short eliminate)
{
    if(eliminate == 0)
        return true;
    return false;
}

void scorAdaugare(player &player1,player &player2)
{
    if(sfarsitJoc(player1.eliminate) && isMart(player2.eliminate))
        player1.linii+=2;
    else
        if(sfarsitJoc(player2.eliminate) && isMart(player1.eliminate))
        player2.linii+=2;
    else if(sfarsitJoc(player1.eliminate))
        player1.linii++;
    else
        if(sfarsitJoc(player2.eliminate))
        player2.linii++;
}

void scorTransformation(short &linii,short &partide)
{
    if(linii==3)
    {
        partide++;
        linii = 0;
    }
}

void castigatorJoc(player player1,player player2)
{
    if(player1.partide>player2.partide)
        cout<<player1.nume<<" a castigat!";
    else
    if(player2.partide>player1.partide)
        cout<<player2.nume<<" a castigat!";
}

void mesajMeniu()
{
    cout<<"Bine ati venit in meniul jocului de table."<<endl;
    cout<<"Va puteti alege modul de joc:"<<endl;
    cout<<"Pentru a putea juca table cu un prieten introduceti 1,altfel 2."<<endl;
}

//detMode checked and could be improved
char detMode(char &mode)
{
    //nr de mesaje = nr de  cuvinte (nu il ia in considerare pe spatiu ca facand parte dintr-un cuvant, daca apare 1 sau 2 separati ii ia ca mode)
    char verification[100];
    cin>>verification;
    if(strlen(verification) != 1)
    {
        cout<<"You can't fool us! Choose between 1 or 2!"<<endl;
        detMode(mode);
    }
    else if(verification[0] != '1' && verification[0] != '2')
    {
        cout<<"You can't fool us! Choose between 1 or 2!"<<endl;
        detMode(mode);
    }
    else
        mode = verification[0];
}

player resetZaruri(player playerNo)
{
    playerNo.zar1 = 0;
    playerNo.zar2 = 0;
    return playerNo;
}

player resetScor(player playerNo)
{
    playerNo.linii = 0;
    playerNo.partide = 0;
    return playerNo;
}

void addData(player &player1, player &player2, char mode)
{
    cout<<"Inainte de a incepe jocul vrem sa aflam cate ceva despre tine."<<endl;
    cout<<"Introduceti numele: ";
    cin>>player1.nume;
    player1 = resetScor(player1);
    player1.piesa = 'A';
    player1 = resetZaruri(player1);
    if(mode == '2')
        strcpy(player2.nume,"Computer");
    else
    {
        cout<<"Introduceti numele celui de-al doilea jucator: ";
        cin>>player2.nume;
    }
    player2 = resetScor(player2);
    player2 = resetZaruri(player2);
    player2.piesa = 'N';
}

void ojocTable()
{
    char mode;
    char tabla[26][15];
    short startJucator;
    player player1, player2;
    mesajMeniu();
    detMode(mode);
    addData(player1,player2,mode);
    system("cls");
    defaultTabla(tabla);
    startJucator = primulJucator(player1,player2);
    while(sfarsitJoc(player1.eliminate) == false && sfarsitJoc(player2.eliminate) == false)
    {
        char deLa, la;
        afisareTabla(tabla);
        if(startJucator == 1)
        {
            cout<<player1.nume;
        }
        else
            cout<<player2.nume;
        cout<<" introduce numarul liniei de unde vrei sa iei piesa si numarul liniei unde vrei s-o pui: ";
        cin>>deLa;
        cin>>la;
        cout<<deLa<<" "<<la;
        system("cls");
    }
    // More to come.
}

int main()
{
    ojocTable();
    return 0;
}

