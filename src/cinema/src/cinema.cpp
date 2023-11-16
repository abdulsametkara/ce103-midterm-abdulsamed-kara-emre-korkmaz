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


int updateMovie() {
    if (movieCount == 0) {
        cout << "Movie list is empty. No movies to update.\n";
        return 1;
    }

    string updateTitle;
    cout << "Enter the title of the movie you want to update: ";
    cin.ignore();
    getline(cin, updateTitle);

    bool movieFound = false;
    for (int i = 0; i < movieCount; ++i) {
        if (movieList[i].title == updateTitle) {
            // Update movie details
            cout << "Enter the updated movie title: ";
            getline(cin, movieList[i].title);
            cout << "Enter the updated movie genre: ";
            getline(cin, movieList[i].genre);
            cout << "Enter the updated movie rating: ";
            cin >> movieList[i].rating;
            cin.ignore();
            cout << "Enter the updated movie review: ";
            getline(cin, movieList[i].review);

            cout << "Movie updated successfully!\n";
            movieFound = true;
            break;
        }
    }

    if (!movieFound) {
        cout << "Movie not found.\n";
        return 1;
    }

    saveMovies(); // Save changes to file
    return 0;
}



// Function to load movies from a file
int loadMoviesFromFile() {
    ifstream file("movies.txt");
    if (file.is_open()) {
        Movie movie;
        while (getline(file, movie.title)) {
            getline(file, movie.genre);
            file >> movie.rating;
            file.ignore();
            getline(file, movie.review);

            movieList[movieCount++] = movie; // Add loaded movie to the movie list
        }
        file.close();
        return 0;
    }
    else {
        cout << "Unable to open the file.\n";
        return 1;
    }
}

// Function to list movies
int listMovies() {
    if (movieCount == 0) {
        cout << "Movie list is empty.\n";
        return 1;
    }

    cout << "Movie List:\n";
    for (int i = 0; i < movieCount; ++i) {
        cout << "Title: " << movieList[i].title << endl;
        cout << "Genre: " << movieList[i].genre << endl;
        cout << "Rating: " << movieList[i].rating << endl;
        cout << "Review: " << movieList[i].review << endl << endl;
        cout << "======================\n";
    }

    return 0;
}

// Function to delete a movie
int deleteMovie() {
    if (movieCount == 0) {
        cout << "Movie list is empty. No movies to delete.\n";
        return 1;
    }

    string deleteTitle;
    cout << "Enter the title of the movie you want to delete: ";
    cin.ignore();
    getline(cin, deleteTitle);

    bool movieFound = false;
    for (int i = 0; i < movieCount; ++i) {
        if (movieList[i].title == deleteTitle) {
            // Found the movie to delete from the list
            for (int j = i; j < movieCount - 1; ++j) {
                movieList[j] = movieList[j + 1];
            }
            movieCount--;

            cout << "Movie deleted successfully!\n";
            movieFound = true;
            break;
        }
    }

    if (!movieFound) {
        cout << "Movie not found.\n";
        return 1;
    }

    saveMovies(); // Save changes to file
    return 0;
}


int createSession() {
    Session newSession;

    cin.ignore();
    cout << "Enter movie title: ";
    getline(cin, newSession.movieTitle);

    cout << "Enter screening time: ";
    getline(cin, newSession.time);

    cout << "Enter available seats: ";
    cin >> newSession.availableSeats;

    cout << "Is this a special screening? (1 for yes, 0 for no): ";
    cin >> newSession.isSpecialScreening;

    newSession.reservedSeats = 0;

    if (sessionCount < 100) {
        sessionList[sessionCount++] = newSession;
        cout << "Session created successfully!\n";
    }
    else {
        cout << "Impression creation limit reached.\n";
    }

    return 0;
}



int listSessions() {
    if (sessionCount == 0) {
        cout << "No sessions available.\n";
        return 1; // Hata durumunda 1 döndürülebilir
    }
    else {
        cout << "Sessions:\n";
        for (int i = 0; i < sessionCount; ++i) {
            cout << "Title Of The Movie: " << sessionList[i].movieTitle << endl;
            cout << "Time: " << sessionList[i].time << endl;
            cout << "Available Seats: " << sessionList[i].availableSeats << endl;
            cout << "Reserved Seats: " << sessionList[i].reservedSeats << endl;
            cout << "Is Special Screening: " << (sessionList[i].isSpecialScreening ? "Yes" : "No") << endl;
            cout << "======================\n";
        }
        return 0; // Başarılı durumda 0 döndürülebilir
    }
}

int saveSessions() {
    ofstream file("sessions.txt"); // Seans bilgilerini kaydedeceğiniz dosya
    if (file.is_open()) {
        if (sessionCount == 0) {
            cout << "No sessions available to save.\n";
            file.close();
            return 1; // Oturum yoksa 1 döndürülebilir
        }

        for (int i = 0; i < sessionCount; ++i) {
            file << sessionList[i].movieTitle << endl;
            file << sessionList[i].time << endl;
            file << sessionList[i].availableSeats << endl;
            file << sessionList[i].reservedSeats << endl;
            file << sessionList[i].isSpecialScreening << endl;
        }
        file.close();
        return 0; // Başarılı durumda 0 döndürülebilir
    }
    else {
        cout << "Unable to open the file for saving sessions.\n";
        return 1; // Dosya açılamadıysa 1 döndürülebilir
    }
}

int loadSessions() {
    ifstream file("sessions.txt");
    if (file.is_open()) {
        int sessionCount = 0; // Oturum sayacı

        Session session;
        while (sessionCount < MAX_SESSIONS &&
            getline(file, session.movieTitle)) {
            getline(file, session.time);
            file >> session.availableSeats;
            file >> session.reservedSeats;
            file >> session.isSpecialScreening;
            file.ignore();

            sessionList[sessionCount++] = session;
        }
        file.close();
        return 0; // Başarılı durumda 0 döndürülebilir
    }
    else {
        cout << "No existing sessions file found.\n";
        return 1; // Oturumlar yüklenemediyse 1 döndürülebilir
    }
}