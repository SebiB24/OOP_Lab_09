#include "Bani.h"
class RepoB{

    Bani x[10];
    int n;

public:

    RepoB();
    RepoB(int n, Bani x[]);
    RepoB(RepoB &r);

    void set_n(int n);
    int get_n();

    void AddItem(Bani p);
    void getAll(int& n, Bani x[]);
    Bani getElemPos(int pos);

    ~RepoB();
};