#include <iostream>
#include "disctionary.h"

int main() {
    dictionary d;
    d.map();
    int menu;
    while (menu != 4) {
        cout << "\nPress Number to start\n\n1 - Print entire dictionary\n2 - Find word definition\n" <<
             "3 - Enter new word and definition\n4 - Exit" << endl;
        cin >> menu;
        switch (menu) {
            case 1:
                d.print_dictionary();
                break;
            case 2:
                d.search();
                break;
            case 3:
                d.add();
                break;
            case 4:
                cout << "Good Bye";
                exit(0);
            default:
                cout << "please type 1, 2 ,3 or 4" << endl;
                cin.clear();
               cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                //cin.ignore(4,'\n'); // ignore next 4 line
                break;
        }

    }

    return 0;
}

