#include "Service.h"
#include <string.h>
Service::Service() {}

Service::Service(Repo<Produs> &r, Repo<Bani> &rb) : rep(r), repb(rb) {}

Service::Service(Service &s): rep(s.rep), repb(s.repb) {}

void Service::AddItem(int cod, char* nume, float pret) {
    Produs p(cod, nume, pret);
    this -> rep.AddItem(p);
}

void Service::AddBan(float valoare, int numar) {
    Bani b(valoare, numar);
    this -> repb.AddItem(b);
}

int Service::get_n_produs() {
    return this -> rep.get_n();
}

int Service::get_n_bani() {
    return this -> repb.get_n();
}

void Service::getAllProdus(int &n, Produs *v) {
    this -> rep.getAll(n, v);
}

void Service::getAllBani(int &n, Bani *v) {
    this -> repb.getAll(n, v);
}

Produs Service::getProdusAt(int pos) {
    return this -> rep.getElemPos(pos);
}

Bani Service::getBaniAt(int pos) {
    return this -> repb.getElemPos(pos);
}


void Service::OferaRest(int cod, int suma, int n, Bani *v) {
    /*
    int m;
    Produs f[30];
    float rest;
    this -> rep.getAll(m, f);
    for(int i = 0; i < m ; i++)
        if(f[i].get_cod() == cod)
        {
            rest = suma - f[i].get_pret();
            break;
        }

    Bani r[10];
*/
}


Service::~Service(){

};

/*
Service::Service(FileRepo* &r, FileRepoB* &rb) : rep(r), repb(rb) {}

Service::Service(Service &s): rep(s.rep), repb(s.repb) {}

void Service::AddItem(int cod, char* nume, float pret) {
    Produs p(cod, nume, pret);
    rep -> AddItem(p);
}

void Service::AddBan(float valoare, int numar) {
    Bani b(valoare, numar);
    repb -> AddItem(b);
}

int Service::get_n_produs() {
    return rep -> get_n();
}

int Service::get_n_bani() {
    return repb -> get_n();
}

void Service::getAllProdus(int &n, Produs *v) {
    rep -> getAll(n, v);
}

void Service::getAllBani(int &n, Bani *v) {
    repb -> getAll(n, v);
}

Produs Service::getProdusAt(int pos) {
    return rep -> getElemPos(pos);
}

Bani Service::getBaniAt(int pos) {
    return repb -> getElemPos(pos);
}

void Service::OferaRest(int cod, int suma, int n, Bani *v) {
    int m;
    Produs f[30];
    float rest;
    rep -> getAll(m, f);
    for(int i = 0; i < m ; i++)
        if(f[i].get_cod() == cod)
        {
            rest = suma - f[i].get_pret();
            break;
        }

    Bani r[10];

}


Service::~Service(){

};
*/

