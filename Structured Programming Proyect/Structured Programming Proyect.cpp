#include <iostream>

using namespace std;

int main() {
    int option;

    do {
        cout << "Enter an option (1-5): ";
        cin >> option;

        switch (option) {
        case 1:
            cout << "1 has been executed\n";
            break;

        case 2:
            cout << "2 has been executed\n";
            break;

        case 3:
            cout << "3 has been executed\n";
            break;

        case 4:
            cout << "4 has been executed\n";
            break;

        case 5:
            cout << "5 Thank you for using this software...\n";
            break;

        default:

            cout << "Invalid option, please try again" << "\n";
        }
    } while (option != 5);

    return 0;
}