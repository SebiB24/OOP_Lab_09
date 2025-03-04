#include <iostream>
using namespace std;
class Bani{

private:
    float valoare;
    int numar;

public:
    Bani();
    Bani(float valoare, int numar);
    Bani(Bani &p);

    void set_valoare(float valoare);
    void set_numar(int numar);
    void set_all(float valoare, int numar);

    int get_numar();
    float get_valoare();
    string toString();

    friend ostream& operator<<(ostream &, Bani &);
    Bani& operator=(const Bani& other);
    bool operator==(const Bani& other) const;

    ~Bani();
};