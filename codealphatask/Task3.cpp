#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<limits>
using namespace std;

const string DATABASE_FILE = "users.txt";

bool userExists(const string& username) {
    ifstream file(DATABASE_FILE);
    string line,storedUser,storedPass;
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, storedUser,',');
        getline(ss, storedPass,',');
        if (storedUser == username) {
            return true;
        }
    }
    return false;
}
void registerUser() {
    string username, password;
    cout << "Enter new username: ";
    cin >> username; 
    if (userExists(username)) {
        cout << "Username already exists. Try a different one." << endl;
        return;
    }
    cout << "Enter new password: ";
    cin >> password;

    ofstream file(DATABASE_FILE, ios::app);
    file << username << "," << password << endl;
    cout << "Registration successful!\n" << endl;
}

void loginUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "Enter password: ";
    getline(cin,password);

    ifstream file(DATABASE_FILE);
    string line,storedUser,storedPass;
    bool success = false;
    
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, storedUser,',');
        getline(ss, storedPass,',');
        if (storedUser == username && storedPass == password) {
            cout << "Login successful!Welcome, "<<username << ".\n";
            return;
        }
    }
    cout << "Invalid username or password.\n" << endl;
}

int main() {
    int choice;
    do {
        cout << "1. Register\n2. Login\n3. Exit\nChoose an option: ";
        cin >> choice;
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again.\n" << endl;
        }
    } while (choice != 3);
    return 0;
}