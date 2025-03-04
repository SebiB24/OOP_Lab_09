//
// Created by sebyc on 5/20/2024.
//

#include "RepoFile.h"
#include <fstream>
#include <sstream>
#include <string.h>

FileRepo ::FileRepo (const char * file):Repo() {

    fileName = (char*)file;
    ifstream f(fileName);

    char * nume = new char [15];
    int cod;
    float pret;
    while(f>>cod>>nume>>pret){
        Produs p(cod, nume, pret);
        AddItem(p);
    }


    string line;
    while (getline(f, line)) {
        istringstream ss(line);
        string cod_str, nume_str, pret_str;

        if (getline(ss, cod_str, ',') &&
            getline(ss, nume_str, ',') &&
            getline(ss, pret_str, ',')) {

            char * nume = new char [15];
            strcpy(nume, nume_str.c_str());
            int cod = stoi(cod_str);
            float pret = stof(pret_str);
            Produs p(cod, nume, pret);
            AddItem(p);
        }
    }

    delete[] nume;

    f.close();
}


void FileRepo::saveToFile() {
    ofstream fout(fileName);
    for (int i = 0; i < get_n(); i++ ){
        fout << getElemPos(i).toString();
        fout << endl;
    }

    fout.close();
}

FileRepo::~FileRepo() {

}

FileRepoB ::FileRepoB (const char * file):Repo() {

    fileName = (char*)file;
    ifstream f(fileName);

    float valoare;
    int numar;
    while(f>>valoare>>numar){
        Bani b(valoare, numar);
        AddItem(b);
    }

    string line;
    while (getline(f, line)) {
        istringstream ss(line);
        string valoare_str, numar_str;

        if (getline(ss, valoare_str, ',') &&
            getline(ss, numar_str, ',')) {

            float valoare = stof(valoare_str);
            int numar = stoi(numar_str);
            Bani b(valoare, numar);
            AddItem(b);
        }
    }

    f.close();
}

void FileRepoB::saveToFile() {
    ofstream fout(fileName);
    for (int i = 0; i < get_n(); i++ ){
        fout << getElemPos(i).toString();
        fout << endl;
    }

    fout.close();
}

FileRepoB::~FileRepoB() {

}