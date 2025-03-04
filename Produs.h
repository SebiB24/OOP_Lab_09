#include <iostream>
using namespace std;
class Produs{

private:
    int cod;
    char* nume;
    float pret;

public:
    Produs();
    Produs(int cod, char* nume, float pret);
    Produs(Produs &p);

    void set_cod(int cod);
    void set_nume(char* nume);
    void set_pret(float pret);
    void set_all(int cod, char* nume, float pret);

    int get_cod();
    char* get_nume();
    float get_pret();
    string toString();

    friend ostream& operator<<(ostream &, Produs &);
    Produs& operator=(const Produs& other);
    bool operator==(const Produs& other) const;

    ~Produs();
};