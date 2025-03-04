//
// Created by sebyc on 5/20/2024.
//

#ifndef OOP_LAB_09_REPOFILE_H
#define OOP_LAB_09_REPOFILE_H

#include "Repo.h"


class FileRepo : public Repo<Produs> {
private:
    char *fileName;
public:
    FileRepo(const char *);

    void saveToFile();

    ~FileRepo();
};

class FileRepoB : public Repo<Bani> {
private:
    char *fileName;
public:
    FileRepoB(const char *);

    void saveToFile();

    ~FileRepoB();
};
#endif //OOP_LAB_09_REPOFILE_H
