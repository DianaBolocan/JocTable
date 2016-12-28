#include <iostream>
#include <string.h>

using namespace std;

//pop to be checked
void pop(stack *primulNod)
{
    stack *parcurgereNod = new stack;
    parcurgereNod = primulNod;
    while(parcurgereNod->urm->urm != nullptr)
    {
        parcurgereNod = parcurgereNod->urm;
    }
    parcurgereNod->urm = nullptr;
}

//push to be checked
void push(stack *primulNod, char piesa)
{
    stack *parcurgereNod = new stack;
    parcurgereNod = primulNod;
    while(parcurgereNod->urm != nullptr)
    {
        parcurgereNod = parcurgereNod->urm;
    }
    stack *adaugareNod = new stack;
    adaugareNod->inf = piesa;
    parcurgereNod->urm = adaugareNod;
    adaugareNod->urm = nullptr;
}

//sfarsitJoc must be checked
bool sfarsitJoc(short eliminate)
{
    if(eliminate == 15)
        return true;
    return false;
}

bool isMart(short eliminate)
{
    if(eliminate==0)
        return true;
    else return false;
}
void scorMart(player player1,player player2)
{
    if(sfarsitJoc(player1.eliminate)==1 && isMart(player2.eliminate)==1)
        player1.linii+=2;
    else
        if(sfarsitJoc(player2.eliminate)==1 && isMart(player1.eliminate)==1)
        player2.linii+=2;
}
void scor(short linii,short partide)
{
    if(linii==3)
        partide++;
        linii=0;
}
void castigatorJoc(player player1,player player2)
{
    if(player1.partide>player2.partide)
        cout<<"Felicitari ,"<<player1.nume<<", ai castigat!";
    else
    if(player2.partide>player1.partide)
        cout<<"Felicitari ,"<<player2.nume<<", ai castigat!";
}
//mesajMeniu checked and works fine
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

//resetZaruri checked and works fine
player resetZaruri(player playerNo)
{
    playerNo.zar1 = 0;
    playerNo.zar2 = 0;
    return playerNo;
}

//resetScor checked and works fine
player resetScor(player playerNo)
{
    playerNo.linii = 0;
    playerNo.partide = 0;
    return playerNo;
}

//addData checked and works fine.
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
    stack vectorStive[26];
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


