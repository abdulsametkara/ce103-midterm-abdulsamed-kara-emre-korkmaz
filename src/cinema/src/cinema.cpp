#include "../header/cinema.h"
#include <stdexcept>
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>

#define MAX_SESSIONS 100 // Maksimum oturum sayýsý


using namespace Coruh::Calculator;
using namespace std;

// Movie struct for representing movie information
struct Movie {
	string title;
	string genre;
	int rating;
	string review;
};

// Session struct for representing session information
struct Session {
	string movieTitle;
	string time;
	int availableSeats;
	int reservedSeats;
	bool isSpecialScreening;
};

// Movie and Session arrays to store movie and session data
Movie movieList[100];
Session sessionList[100];
int movieCount = 0;
int sessionCount = 0;



int screenmenu() {
	cout << "\n====== Cinema Ticketing and Screening Management ======\n";
	cout << "1. Movie Management\n";
	cout << "2. Session Planning\n";
	cout << "3. Auditorium and Seating Arrangements\n";
	cout << "4. Reporting\n";
	cout << "5. Integrations\n";
	cout << "0. Exit to Program\n";

	return 0; // An int value can be extended here, but this makes no functional sense
}

// Function to add a new movie
int addMovie() {
	Movie newMovie;
	cout << "Enter movie title: ";
	cin.ignore();
	getline(cin, newMovie.title);
	cout << "Enter movie genre: ";
	getline(cin, newMovie.genre);
	cout << "Enter movie rating: ";
	cin >> newMovie.rating;
	cout << "Enter movie review: ";
	cin.ignore();
	getline(cin, newMovie.review);

	movieList[movieCount++] = newMovie;
	cout << "Movie added successfully!\n";
	return 0;
}

// Function to save movies to file
int saveMovies() {
	ofstream file("movies.txt");
	if (file.is_open()) {
		for (int i = 0; i < movieCount; i++) {
			file << movieList[i].title << "\n";
			file << movieList[i].genre << "\n";
			file << movieList[i].rating << "\n";
			file << movieList[i].review << "\n";
		}
		file.close();
		return 0;
	}
	else {
		cout << "Unable to open the file for saving.\n";
		return 1;
	}
}