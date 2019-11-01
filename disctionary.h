//
// Created by Younga on 30/10/2019.
//

#ifndef LAB6_DISCTIONARY_H
#define LAB6_DISCTIONARY_H

#include <iostream>
#include <map>


using namespace std;

class dictionary {
private:
    string word;
    string defi;
public:
    map<string, string> word_defi;

    dictionary();

    ~dictionary();

    void print_dictionary();

    void search();

    void add();

    void map();


};

#endif //LAB6_DISCTIONARY_H