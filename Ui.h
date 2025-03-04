#include "Service.h"
#include "RepoFile.h"

class Ui{

    Service serv;

public:

    Ui();
    Ui(Service &s);
    Ui(Ui &u);

    void program();
    void AddElem();
    void AddBan();
    void AfiseazaListaP();
    void AfiseazaListaB();
    void CumparaProdus();

    ~Ui();
};