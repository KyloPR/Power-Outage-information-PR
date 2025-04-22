#include <iostream>
using namespace std;

void UserEntry(int& date, int& month, int& year, int& hour, string& place) {

    cout << "Insert the date of the outage: ";
    cin >> date;

    cout << "Insert the month: ";
    cin >> month;

    cout << "Insert the year: ";
    cin >> year;

    cout << "Insert how many hours it has been without power: ";
    cin >> hour;

    cout << "Insert the place without power: ";
    cin >> place;
}

int main() {
    int option;

    int date, hour, month, year;
    string place;

    do {
        cout << "Enter an option (1-5): ";
        cin >> option;

        switch (option) {
            //User Entry of the info
        case 1:

            UserEntry(date, month, year, hour, place);
            break;


        case 2://See users data entry 

            cout << "2 has been executed\n";
            break;

        case 3://The place with most hours 

            cout << "3 has been executed\n";
            break;

        case 4://The place mentioned the most times 

            cout << "4 has been executed\n";
            break;

        case 5://Exit option
            cout << "5 Thank you for using this software...\n";
            break;

        default:

            cout << "Invalid option, please try again" << "\n";
        }
    } while (option != 5);

    return 0;
}