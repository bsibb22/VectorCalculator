//
// Created by Brandon Sibbitt on 3/1/23.
//

/*
 * COMMANDS:
 * store: store a Vector3
 * list: list all the stored Vectors
 * clear: clear the list of stored Vectors
 * add u v: find the addition of vectors u and v
 * sub u v: find the subtraction of v from u
 * dot u v: find the dot product of u and v
 * cross u v: return the cross product of u and v (u x v)
 * keep: store the last returned vector (if it is a vector), otherwise does nothing
 * help: prints a list of available commands
 */

#include "Vector3.h"
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void PrintCommands() {
    cout << "I can perform the following commands:\n" << setw(12) << left << "store:";
    cout << "store a Vector3 for future use\n" << setw(12) << left << "list: ";
    cout << "list all currently stored vectors and their index\n" << setw(12) << left << "clear:";
    cout << "clear the list of stored vectors\n" << setw(12) << left << "add:";
    cout << "add two stored vectors\n" << setw(12) << left << "sub:";
    cout << "subtract two stored vectors\n" << setw(12) << left << "dot:";
    cout << "get the dot product of two vectors\n" << setw(12) << left << "cross:";
    cout << "get the cross product of two vectors\n" << setw(12) << left << "keep:";
    cout << "store the previously returned vector\n" << setw(12) << left << "unit:";
    cout << "get the unit vector in the direction of a stored vector\n" << setw(12) << left << "help:";
    cout << "print command list\n" << setw(12) << left << "quit:";
    cout << "quit the calculator";
}
void PrintMenu() {
    cout << "Howdy! I'm the KX-11 Vector Calculator! <(￣︶￣)>\n\n";
    PrintCommands();
}

int main() {
    string choice;
    vector<Vector3> vectorBank;
    PrintMenu();

    cout << endl << endl;
    cout << "What would you like me to do to start? (Tip: you will probably want to try \"store\"-ing a vector first!)" << endl;
    cin >> choice;
    while (choice != "quit") {
        if (choice == "store") {
            double vecX, vecY, vecZ;
            cout << "Storing vector with coordinates:\nx: ";
            cin >> vecX;
            cout << "y: ";
            cin >> vecY;
            cout << "z: ";
            cin >> vecZ;
            Vector3 vecToStore(vecX, vecY, vecZ);
            cout << "I just stored the vector ";
            vecToStore.Print();
            cout << "!" << endl;

            vectorBank.push_back(vecToStore);
        }
        else if (choice == "list") {
            cout << setw(15) << left << "Index" << "|" << setw(15) << " Vector" << endl;
            cout << setw(30) << setfill('-') << "" << endl << setfill(' ');
            for (unsigned int i = 0; i < vectorBank.size(); i++) {
                cout << setw(15) << left << (i + 1) << "| ";
                vectorBank.at(i).Print();
                cout << endl;
            }
        }
        else if (choice == "amogus") {
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣤⣤⣤⣤⣤⣶⣦⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀ \n"
                    "⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⡿⠛⠉⠙⠛⠛⠛⠛⠻⢿⣿⣷⣤⡀⠀⠀⠀⠀⠀ \n"
                    "⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⠋⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⠈⢻⣿⣿⡄⠀⠀⠀⠀ \n"
                    "⠀⠀⠀⠀⠀⠀⠀⣸⣿⡏⠀⠀⠀⣠⣶⣾⣿⣿⣿⠿⠿⠿⢿⣿⣿⣿⣄⠀⠀⠀ \n"
                    "⠀⠀⠀⠀⠀⠀⠀⣿⣿⠁⠀⠀⢰⣿⣿⣯⠁⠀⠀⠀⠀⠀⠀⠀⠈⠙⢿⣷⡄⠀ \n"
                    "⠀⠀⣀⣤⣴⣶⣶⣿⡟⠀⠀⠀⢸⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣷⠀ \n"
                    "⠀⢰⣿⡟⠋⠉⣹⣿⡇⠀⠀⠀⠘⣿⣿⣿⣿⣷⣦⣤⣤⣤⣶⣶⣶⣶⣿⣿⣿⠀ \n"
                    "⠀⢸⣿⡇⠀⠀⣿⣿⡇⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠀ \n"
                    "⠀⣸⣿⡇⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠉⠻⠿⣿⣿⣿⣿⡿⠿⠿⠛⢻⣿⡇⠀⠀ \n"
                    "⠀⣿⣿⠁⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣧⠀⠀ \n"
                    "⠀⣿⣿⠀⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀⠀ \n"
                    "⠀⣿⣿⠀⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀⠀ \n"
                    "⠀⢿⣿⡆⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀ \n"
                    "⠀⠸⣿⣧⡀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠃⠀⠀ \n"
                    "⠀⠀⠛⢿⣿⣿⣿⣿⣇⠀⠀⠀⠀⠀⣰⣿⣿⣷⣶⣶⣶⣶⠶⠀⢠⣿⣿⠀⠀⠀ \n"
                    "⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⣿⣿⡇⠀⣽⣿⡏⠁⠀⠀⢸⣿⡇⠀⠀⠀ \n"
                    "⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⣿⣿⡇⠀⢹⣿⡆⠀⠀⠀⣸⣿⠇⠀⠀⠀ \n"
                    "⠀⠀⠀⠀⠀⠀⠀⢿⣿⣦⣄⣀⣠⣴⣿⣿⠁⠀⠈⠻⣿⣿⣿⣿⡿⠏⠀⠀⠀⠀ \n"
                    "⠀⠀⠀⠀⠀⠀⠀⠈⠛⠻⠿⠿⠿⠿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
            cout << "Why would you do this (┳Д┳)" << endl;
        }
        else {
            cout << "Uh-oh! I don't know how to handle that command. (ಥ﹏ಥ)" << endl;
        }
        cout << "What would you like me to do now?" << endl;
        cin >> choice;
    }

    cout << endl;
    cout << "Goodbye! Thank you for using the KX-11 Vector Calculator. ٩(◕‿◕｡)۶";

    return 0;
}