#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registeruser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    if (file.is_open()) {
        file << username << " " << password << endl;
        file.close();
        cout << "Registration successful\n";
    } else {
        cout << "Error opening file.\n";
    }
}

void loginuser() {
    string username, password, u, p;
    bool loginsuccess = false;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    if (file.is_open()) {
        while (file >> u >> p) {
            if (u == username && p == password) {
                loginsuccess = true;
                break;
            }
        }
        file.close();
        if (loginsuccess)
            cout << "Login successful. Welcome, " << username << "!\n";
        else
            cout << "Login failed. Invalid username or password.\n";
    } else {
        cout << "Error opening file.\n";
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\n=== Login system ===\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registeruser();
                break;
            case 2:
                loginuser();
                break;
            case 3:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}