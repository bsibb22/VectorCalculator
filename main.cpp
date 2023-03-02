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

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

#include "Vector3.h"

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

void GetIndex(int& storeIn, vector<Vector3>& vectors) {
    int tempIndex = -1;
    while (storeIn == -1) {
        cin >> tempIndex;
        if (tempIndex > vectors.size() - 1 or tempIndex < 0) {
            cout << "Error: that index is out of bounds (minimum index: 0, maximum index: " << vectors.size() - 1 << ")" << endl;
        }
        else {
            storeIn = tempIndex;
        }
    }
}

void PrintOperation(Vector3& lhs, char operation, Vector3& rhs) {
    cout << "The result of ";
    lhs.Print();
    cout << " " << operation << " ";
    rhs.Print();
    cout << " is: ";
}

int main() {
    string choice;
    vector<Vector3> vectorBank;
    Vector3 prevVector;
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

            prevVector = vecToStore;
            vectorBank.push_back(vecToStore);
        }
        else if (choice == "list") {
            cout << setw(15) << left << "Index" << "|" << setw(15) << " Vector" << endl;
            cout << setw(30) << setfill('-') << "" << endl << setfill(' ');
            for (unsigned int i = 0; i < vectorBank.size(); i++) {
                cout << setw(15) << left << (i) << "| ";
                vectorBank.at(i).Print();
                cout << endl;
            }
        }
        else if (choice == "clear") {
            vectorBank.clear();
            cout << "All stored vectors have been erased. Rest in peace. (*꒦ິ⌓꒦ີ)" << endl;
        }
        else if (choice == "add") {
            if (vectorBank.size() < 2) {
                cout << "Error: there aren't enough stored Vectors to perform this operation. Try storing " << (2 - vectorBank.size()) << " more!" << endl;
            }
            else {
                int index1 = -1;
                int index2 = -1;
                cout << "Type the index of the first vector to add: ";
                GetIndex(index1, vectorBank);
                cout << "Type the index of the second vector to add: ";
                GetIndex(index2, vectorBank);
                Vector3 addition = vectorBank.at(index1) + vectorBank.at(index2);
                cout << "The result of ";
                vectorBank.at(index1).Print();
                cout << " + ";
                vectorBank.at(index2).Print();
                cout << " is: ";
                addition.Print();
                cout << "." << endl;
                prevVector = addition;
            }
        }
        else if (choice == "sub") {
            if (vectorBank.size() < 2) {
                cout << "Error: there aren't enough stored Vectors to perform this operation. Try storing " << (2 - vectorBank.size()) << " more!" << endl;
            }
            else {
                int index1 = -1;
                int index2 = -1;
                cout << "Type the index of the vector from which you will subtract: ";
                GetIndex(index1, vectorBank);
                cout << "Type the index of the vector you will be subtracting by: ";
                GetIndex(index2, vectorBank);
                Vector3 subtraction = vectorBank.at(index1) - vectorBank.at(index2);
                PrintOperation(vectorBank.at(index1), '-', vectorBank.at(index2));
                subtraction.Print();
                cout << endl;
                prevVector = subtraction;
            }
        }
        else if (choice == "dot") {
            if (vectorBank.size() < 2) {
                cout << "Error: there aren't enough stored Vectors to perform this operation. Try storing " << (2 - vectorBank.size()) << " more!" << endl;
            }
            else {
                int index1 = -1;
                int index2 = -1;
                cout << "Enter the index of the first operand vector: ";
                GetIndex(index1, vectorBank);
                cout << "Enter the index of the vector to dot with: ";
                GetIndex(index2, vectorBank);
                double dotResult = vectorBank.at(index1).dot(vectorBank.at(index2));
                cout << "The result of ";
                vectorBank.at(index1).Print();
                cout << " · ";
                vectorBank.at(index2).Print();
            }
        }
        else if (choice == "keep") {
            cout << "Stored the last vector ";
            prevVector.Print();
            cout << "." << endl;
            vectorBank.push_back(prevVector);
        }
        else if (choice == "help") {
            cout << "We can all use some help now and then! ";
            PrintCommands();
            cout << endl;
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