#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;
bool loginUser() {
    string username, password, fileUsername, filePassword;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream inFile("database.txt");
    if (inFile.is_open()) {
        while (inFile >> fileUsername >> filePassword) {
            if (username == fileUsername && password == filePassword) {
                inFile.close();
                return true;
            }
        }
        inFile.close();
    } else {
        cerr << "Error opening file!" << endl;
    }
    return false;
}
void registerUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ofstream outFile("database.txt", ios::app);
    if (outFile.is_open()) {
        outFile << username << " " << password << endl;
        outFile.close();
        cout << "Registration successful!" << endl;
    } else {
        cerr << "Error opening file!" << endl;
    }
}



int main() {
    int choice;
    cout << "1. Register\n2. Login\nEnter choice: ";
    cin >> choice;

    if (choice == 1)
        registerUser();
    else if (choice == 2){
        if (loginUser())
            cout << "Login successful!" << endl;
        else
            cout << "Invalid username or password!" << endl;}
    else 
        cout << "Invalid choice!" << endl;

    system("pause");
    return 0;
}
