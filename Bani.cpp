#include "Bani.h"
#include <sstream>
#include "ExcepValidareDate.h"

Bani::Bani() {
    this -> valoare = 0.0;
    this -> numar = 0;
}

Bani::Bani(float valoare, int numar) {
    if(valoare <= 0)
        throw ExcepValidareDate("valoare invalida");
    if(numar < 0)
        throw ExcepValidareDate("numar invalid");
    this -> valoare = valoare;
    this -> numar = numar;
}

Bani::Bani(Bani &p) {
    this -> valoare = p.valoare;
    this -> numar = p.numar;
}

void Bani::set_valoare(float valoare) {
    if(valoare <= 0)
        throw ExcepValidareDate("valoare invalida");
    this -> valoare = valoare;
}

void Bani::set_numar(int numar) {
    if(numar < 0)
        throw ExcepValidareDate("numar invalid");
    this -> numar = numar;
}

void Bani::set_all(float valoare, int numar){
    if(valoare <= 0)
        throw ExcepValidareDate("valoare invalida");
    if(numar < 0)
        throw ExcepValidareDate("numar invalid");
    this -> valoare = valoare;
    this -> numar = numar;
}

float Bani::get_valoare(){
    return this -> valoare;
}

int Bani::get_numar(){
    return this -> numar;
}

string Bani::toString() {
    ostringstream oss;
    oss <<this->valoare
        << ", " << this->numar;
    return oss.str();
}

ostream& operator<<(ostream &out, Bani &p){
    out<<"Valoare: "<<p.get_valoare()<<" Numar: "<<p.get_numar();
    return out;
}

Bani& Bani::operator=(const Bani& other) {
    if (this != &other) {
        this -> valoare = other.valoare;
        this -> numar = other.numar;
    }
    return *this;
}

bool Bani::operator==(const Bani& other) const {
    return (this -> valoare == other.valoare);
}

Bani::~Bani(){

}