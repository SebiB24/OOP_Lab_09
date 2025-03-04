//
// Created by sebyc on 5/25/2024.
//

#ifndef OOP_LAB_09_EXCEPVALIDAREDATE_H
#define OOP_LAB_09_EXCEPVALIDAREDATE_H

#include <stdexcept>
class ExcepValidareDate: public runtime_error{
private:
    char* mesaj;
public:
    ExcepValidareDate(char* mesaj): runtime_error(mesaj), mesaj(mesaj){}
    char* what(){
        return mesaj;
    }
};


#endif //OOP_LAB_09_EXCEPVALIDAREDATE_H
