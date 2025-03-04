#include "Produs.h"
#include <string.h>
#include <sstream>
#include "ExcepValidareDate.h"

Produs::Produs() {
    this -> cod = 0;
    this -> nume = NULL;
    this -> pret = 0;
}

Produs::Produs(int cod, char* nume, float pret) {
    if(cod <= 0)
        throw ExcepValidareDate("cod invalid");
    if(strlen(nume) == 0)
        throw ExcepValidareDate("nume invalid");
    if(pret <= 0)
        throw ExcepValidareDate("pret invalid");
    this -> cod = cod;
    this -> nume = new char[strlen(nume)+1];
    strcpy(this -> nume, nume);
    this -> pret = pret;
}

Produs::Produs(Produs &p) {
    this -> cod = p.cod;
    this -> nume = new char[strlen(p.nume)+1];
    strcpy(this -> nume, p.nume);
    this -> pret = p.pret;
}

void Produs::set_cod(int cod) {
    if(cod <= 0)
        throw ExcepValidareDate("cod invalid");
    this -> cod = cod;
}

void Produs::set_nume(char *nume) {
    if(strlen(nume) == 0)
        throw ExcepValidareDate("nume invalid");
    this -> nume = new char[strlen(nume)+1];
    strcpy(this -> nume, nume);
}

void Produs::set_pret(float pret) {
    if(pret <= 0)
        throw ExcepValidareDate("pret invalid");
    this -> pret = pret;
}

void Produs::set_all(int cod, char* nume, float pret){
    this -> cod = cod;
    this -> nume = new char[strlen(nume)+1];
    strcpy(this -> nume, nume);
    this -> pret = pret;
}

int Produs::get_cod() {
    return this -> cod;
}

char* Produs::get_nume() {
    return this -> nume;
}

float Produs::get_pret() {
    return this -> pret;
}

string Produs::toString() {
    ostringstream oss;
    oss << this->cod
        << ", " << this->nume
        << ", " << this->pret;
    return oss.str();
}

ostream& operator<<(ostream &out, Produs &p){
    char *nume;
    nume = p.get_nume();
    out<<"Cod: "<<p.get_cod()<<" Nume: "<<nume<<" Pret: "<<p.get_pret();
    return out;
}

Produs& Produs::operator=(const Produs& other) {
    if (this != &other) {
        this -> cod = other.cod;
        this -> pret = other.pret;
        this -> nume = new char[strlen(other.nume)+1];
        strcpy(this -> nume, other.nume);
    }
    return *this;
}

bool Produs::operator==(const Produs& other) const {
    return (this -> cod == other.cod);
}

Produs::~Produs(){
    if(this -> nume != NULL){
        delete[] this -> nume;
        this -> nume = NULL;
    }

}
