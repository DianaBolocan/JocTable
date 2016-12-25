#include <iostream>
#include <string.h>
#include "proiect.h"
using namespace std;

void mesajMeniu()
{
    cout<<"Bine ati venit in meniul jocului de table."<<endl;
    cout<<"Va puteti alege modul de joc:"<<endl;
    cout<<"Pentru a putea juca table cu un prieten introduceti 1,altfel 2."<<endl;
}
char detMode(char &mode)
{
    //nr de mesaje = nr de  cuvinte (nu il ia in considerare pe spatiu ca facand parte dintr-un cuvant)
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

void addData(player player1, player player2, char mode)
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
    player player1, player2;
    mesajMeniu();
    detMode(mode);
    addData(player1,player2,mode);
    // More to come.
}

int main()
{
    ojocTable();
    return 0;
}
