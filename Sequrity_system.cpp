#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int a, i = 0;
    string text, old, password1, password2, pass, name, password0, age, user, word, word1;
    string creds[2], cp[2];

    cout << "     Security System     " << endl << endl;
    cout << "|______________________________|" << endl;
    cout << "|        1. Register           |" << endl;
    cout << "|        2. Login              |" << endl;
    cout << "|        3. Change Password    |" << endl;
    cout << "|        4. End Program        |" << endl;
    cout << "|______________________________|" << endl << endl;

    do {
        cout << endl << endl;
        cout << "Enter your Choice: ";
        cin >> a;
        switch (a) {
            case 1: {
                cout << "|______________________________|" << endl << endl;
                cout << "|        1. Register           |" << endl;
                cout << "|______________________________|" << endl;
                cout << "Please Enter UserName: ";
                cin >> name;
                cout << "Please Enter The Password: ";
                cin >> password0;
                cout << "Enter Your Age: ";
                cin >> age;

                ofstream of1("file.txt");
                if (of1.is_open()) {
                    of1 << name << "\n";
                    of1 << password0 << "\n";
                    of1 << age;
                    of1.close();
                    cout << "Registration Successful" << endl;
                } else {
                    cout << "Error: Unable to open file for writing" << endl;
                }
                break;
            }
            case 2: {
                i = 0;
                cout << "|______________________________|" << endl << endl;
                cout << "|        2. Log in             |" << endl;
                cout << "|______________________________|" << endl;

                ifstream of2("file.txt");
                cout << "Please Enter The UserName: ";
                cin >> user;
                cout << "Please Enter The Password: ";
                cin >> pass;

                if (of2.is_open()) {
                    while (getline(of2, text)) {
                        istringstream iss(text);
                        iss >> word;
                        creds[i++] = word;
                    }
                    of2.close();

                    if (creds[0] == user && creds[1] == pass) {
                        cout << "Login Successful" << endl << endl;
                        cout << "Details" << endl;
                        cout << "UserName: " << name << endl;
                        cout << "Password: " << pass << endl;
                        cout << "Age: " << age << endl;
                    } else {
                        cout << "Incorrect Credentials" << endl;
                    }
                } else {
                    cout << "Error: Unable to open file for reading" << endl;
                }
                break;
            }
            case 3: {
                i = 0;
                cout << "|____________________________________|" << endl << endl;
                cout << "|         3. Change Password         |" << endl;
                cout << "|____________________________________|" << endl;

                ifstream of0("file.txt");
                cout << "Enter The Old Password: ";
                cin >> old;

                if (of0.is_open()) {
                    while (getline(of0, text)) {
                        istringstream iss(text);
                        iss >> word1;
                        cp[i++] = word1;
                    }
                    of0.close();

                    if (old == cp[1]) {
                        cout << "Enter Your New Password: ";
                        cin >> password1;
                        cout << "Enter Your Password Again: ";
                        cin >> password2;

                        if (password1 == password2) {
                            ofstream of1("file.txt");
                            if (of1.is_open()) {
                                of1 << cp[0] << "\n";
                                of1 << password1 << "\n";
                                of1 << age;
                                of1.close();
                                cout << "Password Changed Successfully" << endl;
                            } else {
                                cout << "Error: Unable to open file for writing" << endl;
                            }
                        } else {
                            cout << "Passwords do not match" << endl;
                        }
                    } else {
                        cout << "Please Enter a Valid Password" << endl;
                    }
                } else {
                    cout << "Error: Unable to open file for reading" << endl;
                }
                break;
            }
            case 4: {
                cout << "Thank You" << endl;
                break;
            }
            default: {
                cout << "Enter a Valid Choice" << endl;
                break;
            }
        }
    } while (a != 4);

    return 0;
}
