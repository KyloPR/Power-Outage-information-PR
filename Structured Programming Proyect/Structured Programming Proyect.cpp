#include <iostream>
#include <string>//added the <string> library to handle and manipulate text data in a more flexible way. L.C.M.
#include <map> //added <map> library to count occurrences of each unique location entered by the user in option 4. L.C.M.
#include <fstream> // Added for file handling M.P.V
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
	//L.C.M. modified
	cin.ignore(); // Avoids skipping input data
	getline(cin, place);
	
//M.P.V
// Code obtained with the help of Copilot:
// This snippet saves the user's input to a text file (outage_data.txt)
// using append mode to avoid overwriting previous records.

	ofstream outFile("outage_data.txt", ios::app); // Open file in append mode
	if (outFile) {
		outFile << date << "," << month << "," << year << "," << hour << "," << place << "\n"; // Write data
		outFile.close(); // Close file to save changes
		cout << "Outage data saved successfully!" << endl; // Confirmation message
	}
	else {
		cout << "Error opening file for writing." << endl; // Error handling
	}
}
//Ends Copilot code 

//M.P.V
//Function Option 2: Outputs the history of the user entry
void DisplayOutageHistory(int date[], int month[], int year[], int hour[], string place[], int size) {

	if (size == 0) {

		cout << "No outage data recorded yet" << "\n";

	}
	else {

		cout << "The Outage History: " << "\n";

		for (int i = 0; i < size; i++) {

			cout << "Date: " << " " << date[i] << "/ " << month[i] << "/ " << year[i] << "\n";
			cout << "Duration: " << " " << hour[i] << "hrs, Place:  " << place[i] << "\n";
		}
	}
}
//L.C.M.
//Function Option 3: Find the place with the longest outage 
string PlaceWMHours(int hour[], string place[], int size) {

	if (size == 0)
		return "No outage data found.";


	int LongestHours = hour[0];
	string PlaceMostHours = place[0];

	for (int i = 1; i < size; i++) {

		if (hour[i] > LongestHours) {
			LongestHours = hour[i];
			PlaceMostHours = place[i];
		}
	}
	return "Place: " + PlaceMostHours + ", Duration: " + to_string(LongestHours) + " hours.";
}
//L.C.M.
//Function Option 4: Find the most frequently mentioned place
string MostMentionedPlace(string Place[], int size) {
	if (size == 0)
		return "No outage data found.";
	//copy Copilot
	map<string, int> frequency;
	string mostFrequent;
	int maxCount = 0;
	//end copy

	for (int i = 0; i < size; i++) {

		frequency[Place[i]]++;

		if (frequency[Place[i]] > maxCount) {
			maxCount = frequency[Place[i]];
			mostFrequent = Place[i];
		}
	}
	return "Place: " + mostFrequent + ", Mentioned: " + to_string(maxCount) + " times.";
}


int main() {
	int option;
	//L.C.M. modified
	const int LIMIT = 100; // Limits of array that can be saved.
	int date[LIMIT], month[LIMIT], year[LIMIT], hour[LIMIT], size = 0;
	string place[LIMIT];

	//M.P.V
	//Menu of option so the user can input their choice
	

		cout << " *****************************************************" << "\n";
		cout << " * Welcome to the Power Outage information Simulator * " << "\n";
		cout << " *****************************************************" << "\n";

		cout << "\n";
do {
		cout << "1. Data entry for Outage" << "\n";
		cout << "2. See all Outage's history" << "\n";
		cout << "3. See Place with most hours without power" << "\n";
		cout << "4. See most frequently mentioned place" << "\n";
		cout << "5. Exit" << "\n";

		cout << "Enter an option (1-5): ";
		cin >> option;

		switch (option) {
			//User Entry of the info
		case 1:

			if (size < LIMIT) {
				UserEntry(date[size], month[size], year[size], hour[size], place[size]);
				size++;
			}
			else {
				cout << "Records at full capacity.\n";
			}
			break;

			//M.P.V
		case 2://See users data entry
			DisplayOutageHistory(date, month, year, hour, place, size);
			break;

		case 3://The place with most hours
			//L.C.M.
			cout << PlaceWMHours(hour, place, size) << endl;
			break;
			//L.C.M.
		case 4://The place mentioned the most times

			cout << MostMentionedPlace(place, size) << endl;
			break;

		case 5://Exit option
			cout << " Thank you for using this software...\n";
			break;

		default:

			cout << "Invalid option, please try again" << "\n";
		}
	} while (option != 5);

	return 0;
}
