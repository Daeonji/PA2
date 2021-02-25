//File name: PA#2.cpp
//
// Author: Danny Pham
// Date: 2/21/21
// Assignment Number: 2
// CS 2308 Spring 2021

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Movie
{
	int ID;
	string name;
	string release_date;
	double rating;
};
void displayMenu();
void displayHeader();
void readMovies(ifstream& inputFile, Movie movies[], int& size);
void displayMovies(Movie movies[], int SIZE);
void sortByDateRating(Movie movies[], int SIZE);
void sortById(Movie movies[], const int SIZE);
int linearSearchByName(Movie movies[], int SIZE, string targetName);
int binarySearchById(Movie movies[], int SIZE, int targetId);

int main()
{
	ifstream inputFile;
	inputFile.open("movies.txt");
	Movie movies[100];
	int size = 0;
	int choice = 0;

	string searchName;
	int searchId;


	readMovies(inputFile, movies, size);

	displayMenu();
	displayHeader();
	displayMovies(movies, size);


	do
	{
		// Display the menu.
		/*cout << "\n\t\tHealth Club Membership Menu\n\n"
			<< "1. Display movies sorted by ID\n"
			<< "2. Display movies sorted by release date, then rating\n"
			<< "3. Lookup a release date given a name\n"
			<< "4. Lookup a movie by id\n"
			<< "5. Quit the program\n\n"
			<< "Enter your choice: "; */
		displayMenu();
		cin >> choice;

		// Validate the menu selection.
		while (choice < 1 || choice > 4)
		{
			cout << "Please enter 1, 2, 3, 4, or 5: ";
			cin >> choice;
		}

		// Validate and process the user's choice.
		if (choice != 5)
		{
			// Respond to the user's menu selection.
			switch (choice)
			{
			case 1:
				sortById(movies, size);
				displayHeader();
				displayMovies(movies, size);
				break;
			case 2:
				sortByDateRating(movies, size);
				displayHeader();
				displayMovies(movies, size);
				break;
			case 3:
				cout << "Please enter a movie name: ";
				getline(cin, searchName);
				linearSearchByName(movies, size, searchName);
				break;
			case 4:
				
				cout << "Please enter a movie ID: ";
				cin >> searchId;
				binarySearchById(movies, size, searchId);
				break;
			}

			cout << "Exiting the program...\n";
		}
	} while (choice != 4);


	return 0;
}

void displayMenu() {
	int choice;
	cout << "\nMenu\n"
		<< "1. Display movies sorted by id\n"
		<< "2. Display movies sorted by release date, then rating\n"
		<< "3. Lookup a release date given a name\n"
		<< "4. Lookup a movie by id\n"
		<< "5. Quit the Program\n"
		<< "Enter your choice:\n";
}
void displayHeader() {
	cout << left
		<< setw(3) << "ID"
		<< setw(26) << "Name"
		<< setw(12) << "Date"
		<< "Rating"
		<< endl;
}
void readMovies(ifstream& inputFile, Movie movies[], int& size)
{
	int number;
	string x, y;
	int numbers[100];
	string strings[100];
	int count = 0;
	double readRating = 0;

	

	while (inputFile >> number)
	{
		cout << number;
		inputFile >> ws;
		getline(inputFile, y);
		getline(inputFile, x);
		inputFile >> readRating;
		inputFile >> ws;
		movies[count].name = y;
		movies[count].rating = readRating;
		movies[count].ID = number;
		movies[count].release_date = x;
		count++;
		size++;

	}

	inputFile.close();
}
void displayMovies(Movie movies[], int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << setw(3) << movies[i].ID,
		cout << setw(26) << movies[i].name;
		cout << setw(12) << movies[i].release_date;
		cout << movies[i].rating << endl;
	}
}

void sortByDateRating(Movie movies[], int SIZE) {
	for (int i = 0; i < SIZE - 1; i++)
	{
		int indexSmallest = i;
		for (int j = i; j < SIZE; j++)
		{
			if (movies[j].release_date < movies[indexSmallest])
			{
				indexSmallest = j;
			}
		}
	}
}

void sortById(Movie movies[], const int SIZE) {

}
int linearSearchByName(Movie movies[], int SIZE, string targetName) {

	return -1;
}

int binarySearchById(Movie movies[], int SIZE, int targetId) {

	return -1;
}
