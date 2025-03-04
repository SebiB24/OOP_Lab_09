#include "RepoFile.h"

class Service {

    Repo<Produs> rep;
    Repo<Bani> repb;

public:
    Service();
    Service(Repo<Produs>& r, Repo<Bani>& rb);
    Service(Service& s);

    int get_n_produs();
    int get_n_bani();
    void AddItem(int cod, char* nume, float pret);
    void AddBan(float valoare, int numar);
    void getAllProdus(int& n, Produs v[]);
    void getAllBani(int& n, Bani v[]);
    Produs getProdusAt(int pos);
    Bani getBaniAt(int pos);
    void OferaRest(int cod, int suma, int n ,Bani v[]);

    ~Service();
};

/*
class Service {

    FileRepo* rep;
    FileRepoB* repb;

public:
    Service(FileRepo*& r, FileRepoB*& rb);
    Service(Service& s);

    int get_n_produs();
    int get_n_bani();
    void AddItem(int cod, char* nume, float pret);
    void AddBan(float valoare, int numar);
    void getAllProdus(int& n, Produs v[]);
    void getAllBani(int& n, Bani v[]);
    Produs getProdusAt(int pos);
    Bani getBaniAt(int pos);
    void OferaRest(int cod, int suma, int n ,Bani v[]);

    ~Service();
};
 */