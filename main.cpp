#include "tests.h"
#include "Ui.h"
int main() {
    test_Bani();
    test_Produs();
    test_Repo();
    testService();
/*
    Repo<Produs> repP;
    Repo<Bani> repB;

    FileRepo *frepoP = new FileRepo("produse.txt");
    FileRepoB *frepoB = new FileRepoB("bancnote_monede.txt");
    */

    Ui ui;
    ui.program();

    return 0;
}
