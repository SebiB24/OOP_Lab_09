#include "RepoBani.h"

RepoB::RepoB() {
    this -> n = 0;
}

RepoB::RepoB(int n, Bani x[]) {
    this -> n = n;
    for(int i = 0; i < n; i++)
        this -> x[i] = x[i];
}

RepoB::RepoB(RepoB &r) {
    this -> n = r.n;
    for(int i = 0; i < n ;i++)
        this -> x[i] = r.x[i];
}

void RepoB::set_n(int n) {
    this -> n = n;
}

int RepoB::get_n() {
    return this -> n;
}

void RepoB::AddItem(Bani p) {
    int pos = -1;
    for(int i = 0; i < this -> n; i++)
        if(x[i].get_valoare() == p.get_valoare())
            pos = i;
    if(pos == -1)
    {
        this -> x[this -> n] = p;
        this ->set_n(this -> n + 1);
    }
    else
        this -> x[pos].set_numar(p.get_numar());

}

void RepoB::getAll(int &n, Bani x[]) {
    n = this -> n;
    for(int i = 0 ; i < n ; i++)
        x[i] = this -> x[i];

}

Bani RepoB::getElemPos(int pos) {
    return this -> x[pos];

}

RepoB::~RepoB(){

}
