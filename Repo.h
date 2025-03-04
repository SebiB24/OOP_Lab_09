#include "Produs.h"
#include "Bani.h"
#include "ExcepValidareDate.h"

template<class T>
class Repo{

    T x[30];
    int n;

public:

    Repo();
    Repo(int n, T x[]);
    Repo(const Repo<T> &r);

    void set_n(int n);
    int get_n();

    void AddItem(T p);
    void getAll(int& n, T x[]);
    T getElemPos(int pos);

    ~Repo();
};

template <class T>
Repo <T>::Repo() {
    this -> n = 0;
}

template <class T>
Repo <T>::Repo(int n, T x[]) {
    if(n < 0)
        throw ExcepValidareDate("valoare invalida pentru numarul de elemente din multime");
    this -> n = n;
    for(int i = 0; i < n; i++)
        this -> x[i] = x[i];
}

template <class T>
Repo <T>::Repo(const Repo<T> &r) {
    this -> n = r.n;
    for(int i = 0; i < n ;i++)
        this -> x[i] = r.x[i];
}

template <class T>
void Repo <T>::set_n(int n) {
    if(n < 0)
        throw ExcepValidareDate("valoare invalida pentru numarul de elemente din multime");
    this -> n = n;
}

template <class T>
int Repo <T>::get_n(){
    return this -> n;
}

template <class T>
void Repo <T>::AddItem(T p) {
    bool exista = false;
    int i;
    for(i = 0 ; i < this -> n; i++)
        if(this -> x[i] == p)
        {
            exista = true;
            break;
        }
    if(exista == false)
    {
        this -> x[this -> n] = p;
        this ->set_n(this -> n + 1);
    }
    else
    {
        this -> x[i] = p;
    }

}

template <class T>
void Repo <T>::getAll(int &n, T x[]) {
    n = this -> n;
    for(int i = 0 ; i < n ; i++)
        x[i] = this -> x[i];

}

template <class T>
T Repo <T>::getElemPos(int pos){
    return this -> x[pos];

}

template <class T>
Repo <T>::~Repo(){

}
