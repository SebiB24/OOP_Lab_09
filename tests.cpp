#include "tests.h"
#include "Service.h"
#include <assert.h>
#include <string.h>

void test_Bani(){
    Bani p;
    assert(p.get_valoare() == 0.0);
    assert(p.get_numar() == 0);

    Bani p2(5.0, 3);
    assert(p2.get_valoare() == 5.0);
    assert(p2.get_numar() == 3);

    Bani p3(p2);
    assert(p3.get_valoare() == 5.0);
    assert(p3.get_numar() == 3);

    p3.set_valoare(10.0);
    p3.set_numar(2);

    assert(p3.get_valoare() == 10.0);
    assert(p3.get_numar() == 2);

    p3.set_all(50.0, 5);
    assert(p3.get_valoare() == 50.0);
    assert(p3.get_numar() == 5);
}

void test_Produs(){
    Produs p;
    assert(p.get_cod() == 0);
    assert(p.get_nume() == NULL);
    assert(p.get_pret() == 0);

    Produs p2(10, "cola", 5.5);
    assert(p2.get_cod() == 10);
    assert(strcmp(p2.get_nume(), "cola") == 0);
    assert(p2.get_pret() == 5.5);
    //
    Produs p3(p2);
    assert(p3.get_cod() == 10);
    assert(strcmp(p3.get_nume(), "cola") == 0);
    assert(p3.get_pret() == 5.5);

    p3.set_cod(23);
    p3.set_nume("fanta");
    p3.set_pret(4.5);

    assert(p3.get_cod() == 23);
    assert(strcmp(p3.get_nume(), "fanta") == 0);
    assert(p3.get_pret() == 4.5);

    p3.set_all(111, "corn 7 days", 4.0);
    assert(p3.get_cod() == 111);
    assert(strcmp(p3.get_nume(), "corn 7 days") == 0);
    assert(p3.get_pret() == 4.0);
}


void test_Repo(){

    Repo<Produs> r;
    assert(r.get_n() == 0);

    Produs x[3];
    x[0].set_all(234, "apa dorna", 2.5);
    x[1].set_all(34523, "baton proteic", 10.5);
    x[2].set_all(6984, "cipsuri chio", 4.3);

    Repo<Produs> r2(3, x);
    assert(r2.get_n() == 3);

    Repo<Produs> r3(r2);
    assert(r3.get_n() == 3);

    Produs p(532, "apa minerala", 3.5);
    r3.AddItem(p);
    assert(r3.get_n() == 4);

    int n;
    Produs v[4];
    r3.getAll(n ,v);
    assert(n == 4);
    assert(v[0].get_cod() == 234);
    assert(v[1].get_cod() == 34523);
    assert(v[2].get_cod() == 6984);
    assert(v[3].get_cod() == 532);

    Repo<Bani> rb;
    assert(rb.get_n() == 0);

    Bani y[3];
    y[0].set_all(0.5, 20);
    y[1].set_all(1.0, 30);
    y[2].set_all(20.0, 15);
    Repo<Bani> rb2(3, y);
    assert(rb2.get_n() == 3);

    Repo<Bani> rb3(rb2);
    assert(rb3.get_n() == 3);

    Bani b(100.0, 3);
    rb3.AddItem(b);
    assert(rb3.get_n() == 4);

    int m;
    Bani f[4];
    rb3.getAll(n ,f);

    assert(n == 4);
    assert(f[0].get_valoare() == 0.5);
    assert(f[1].get_valoare() == 1.0);
    assert(f[2].get_valoare() == 20.0);
    assert(f[3].get_valoare() == 100.0);
}

void testService()
{
    Produs p(241, "sprite", 5.6);
    Bani b(20.0, 10);
    Repo<Produs> r;
    Repo<Bani> rb;
    r.AddItem(p);
    rb.AddItem(b);

    Service s(r,rb);
    assert(s.getProdusAt(0).get_cod() == 241);

    s.AddItem(75, "covrig", 3.7);
    assert(s.getProdusAt(1).get_cod() == 75);

    Service s2(s);
    assert(s2.getProdusAt(0).get_cod() == 241);
    assert(s2.getProdusAt(1).get_cod() == 75);

    Produs v[10];
    int n;
    s.getAllProdus(n, v);
    assert(n == 2);
    assert(v[0].get_cod() == 241);
    assert(v[1].get_cod() == 75);


}