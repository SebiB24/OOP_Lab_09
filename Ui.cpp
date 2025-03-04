#include "Ui.h"
#include <iostream>
#include <string.h>
#include <limits>
#include "ExcepValidareDate.h"
using namespace std;

Ui::Ui(){

}
Ui::Ui(Service &s){
        this -> serv = s;
}

Ui::Ui(Ui &u){
    this -> serv = u.serv;
}

void Ui::program() {


    cout << "MENIU\n"
            "1. Adauga produs\n"
            "2. Afisare lista produse\n"
            "3. Adauga bancnote/monezi\n"
            "4. Afisare lista bancnote/monede\n"
            "5. Cumpara produs\n"
            "0. Exit\n";

    bool run = true;
    int comanda;
    while (run) {
        try{
            cout << "Introduceti numarul comenzii:";
            cin >> comanda;
            if(cin.fail())
                throw ExcepValidareDate("comanda invalida");
            cout << endl;
            switch (comanda) {
                case 0:
                    run = false;
                    break;
                case 1:
                    this -> AddElem();
                    break;
                case 2:
                    this -> AfiseazaListaP();
                    break;
                case 3:
                    this -> AddBan();
                    break;
                case 4:
                    this -> AfiseazaListaB();
                    break;
                case 5:
                    this -> CumparaProdus();
                    break;
                default:
                    throw ExcepValidareDate("comanda nu exista");
            }
        }
        catch (ExcepValidareDate exc){
            cout<<"ERROR: "<<exc.what()<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
void Ui::AddElem(){
    int cod;
    char *nume = new char[30];
    float pret;

    try {
        cout << "Introduceti codul produsului:";
        cin >> cod;
        if(cin.fail())
            throw ExcepValidareDate("cod invalid");
        cin.ignore();
        cout<<"Introduceti numele:";
        cin.getline(nume, 20);
        if(cin.fail())
            throw ExcepValidareDate("nume invalid");
        cout<<"Introduceti pretul:";
        cin>>pret;
        if(cin.fail())
            throw ExcepValidareDate("pret invalid");
        this -> serv.AddItem(cod, nume, pret);
    }
    catch (ExcepValidareDate exc){
        cout<<"ERROR: "<<exc.what()<<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }


}

void Ui::AddBan(){
    float valoare;
    int numar;

    try{
        cout<<"Introduceti valoarea bancnotei/monedei:";
        cin>>valoare;
        if(cin.fail())
            throw ExcepValidareDate("valoare invalida");
        cin.ignore();
        cout<<"Introduceti numarul de bancnote/monede:";
        cin>>numar;
        if(cin.fail())
            throw ExcepValidareDate("numar invalid");
        this -> serv.AddBan(valoare, numar);
    }

    catch(ExcepValidareDate exc){
        cout<<"ERROR: "<<exc.what()<<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}


void Ui::AfiseazaListaP(){
    int n;
    Produs v[30];
    this -> serv.getAllProdus(n, v);
    if(n != 0)
        for(int i = 0; i < n; i++)
            cout << v[i]<<endl;
    else
        cout<<"!!Nu exista produse in lista!!"<<endl;
}

void Ui::AfiseazaListaB(){
    int n;
    Bani v[30];
    this -> serv.getAllBani(n, v);
    if(n != 0)
        for(int i = 0; i < n; i++)
            cout << v[i]<<endl;
    else
        cout<<"!!Nu exista bancnote/monede in lista!!"<<endl;
}


void Ui::CumparaProdus(){
    int n;
    float suma;
    int cod;
    cout<<"Introduceti cod produs: ";
    cin>>cod;
    cout<<"Introduceti suma: ";
    cin>> suma;
    Bani v[10];
    this ->serv.OferaRest(cod, suma, n, v);
    for(int i = 0; i < n; i++)
        cout << v[i]<<endl;

}

Ui::~Ui(){

}