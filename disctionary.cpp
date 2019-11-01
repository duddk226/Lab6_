//
// Created by Younga  on 30/10/2019.
//

#include "disctionary.h"
#include <map>
#include <iterator>
#include <fstream>

using namespace std;

dictionary::dictionary() {
    this->word = "";
    this->defi = "";

}

dictionary::~dictionary() {
    cout << "\n\ndestroying dictionary" << endl;
}

void dictionary::map() {
    string line, word, defi;
    ifstream file;
    file.open("../dictionary.txt");
    while (getline(file, line)) {
        int pos = line.find('-');
        if (pos != string::npos) {
            word = line.substr(0, pos);
            defi = line.substr(pos + 1);
            word_defi.insert(make_pair(word, defi));
        }
    }
}

void dictionary::print_dictionary() {
    for (auto it = word_defi.begin(); it != word_defi.end(); ++it) {
        cout << it->first << " - " << it->second << endl;
    }
}

void dictionary::search() {
    string search;
    cout << "What would you like to search? (ex: Human)";
    cin >> ws >> search;//search Human

    ::map<string, string>::iterator it;
    it = word_defi.find(search);
    if (it != word_defi.end()) {
        cout << "\nDefinition: " << it->second << endl;
    } else {
        cout << "The word does not exist in our dictionary. \nPress 2 to search" << endl;
    }
}

void dictionary::add() {
    string newWord;
    string newDefi;
    ofstream my_file{"../dictionary.txt", ios::app};
    cout << "what would you like to add?";
    getline(cin >> ws, newWord);

    ::map<string, string>::iterator it;
    it = word_defi.find(newWord);
    if (it != word_defi.end()) {
        cout << "The word does exit in our dictionary \n" << endl;
        add();
    } else {
        cout << "what does it mean?";
        getline(cin >> ws, newDefi);
        my_file << "\n" << newWord << "-" << newDefi;
        cout << "\n\nThe word is successfully added into dictionary" << endl;
    }
}