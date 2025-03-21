﻿#include "../header/cinema.h"
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

int deleteSession() {
    // If the sessionlist is empty, there is no film and nothing to delete.
    if (sessionCount == 0) {
        cout << "Session list is empty. Nothing to delete.\n";
        return 1; // Return 1 for failure
    }

    // Get the session to be deleted from the user.
    string titleToDelete;
    cout << "Enter the title of the film for the session you want to delete: ";
    cin >> titleToDelete;

    // Find the session to delete in the sessionList.
    int i;
    for (i = 0; i < sessionCount; ++i) {
        if (sessionList[i].movieTitle == titleToDelete) {
            break; // Exit the loop when session is found.
        }
    }

    // If the session is found, delete it from the sessionList.
    if (i < sessionCount) {
        // Shift elements to delete the session
        for (int j = i; j < sessionCount - 1; ++j) {
            sessionList[j] = sessionList[j + 1];
        }
        sessionCount--;

        cout << "Session deleted successfully!\n";

        saveSessions(); // Save sessions to file after deletion

        return 0; // Return 0 for success
    }
    else {
        // Print an error message to the screen if the film was not found.
        cout << "Session not found.\n";
        return 1; // Return 1 for failure
    }
}


int categorizeGenre() {
    string type;
    cout << "Please enter the movie type: ";
    cin.ignore();
    getline(cin, type);

    bool movieFound = false;

    for (const auto& movie : movieList) {
        if (movie.genre == type) {
            movieFound = true;
            cout << "Movie: " << movie.title << endl << "Type: " << movie.genre << endl << endl;
        }
    }

    if (!movieFound) {
        cout << "Movie type not found.\n";
        return 1; // Return 1 for failure
    }

    return 0; // Return 0 for success
}

int rateMovie() {
    for (const auto& movie : movieList) {
        cout << "Movie: " << movie.title << endl << "Rating: " << movie.rating << endl << endl;
    }

    return 0; // Return 0 for success, assuming the function just displays the movies and ratings
}

int reviewMovie() {
    for (const auto& movie : movieList) {
        cout << "Movie: " << movie.title << endl << "Review: " << movie.review << endl << endl;
    }

    return 0; // Return 0 for success, assuming the function just displays the movie reviews
}

int createCleaningSchedule() {
    string days[] = {
        "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
    };

    string tasks[] = {
        "cleaning between movies",
        "nothing today",
        "main cleaning washing of seats",
        "corridor and toilet cleaning",
        "wiping all places and all areas",
        "nothing today",
        "General cleaning of all halls after the movie"
    };

    for (size_t i = 0; i < 7; ++i) {
        cout << "Day: " << days[i] << endl << "Task: " << tasks[i] << endl << endl;
    }

    return 0; // Return 0 for success, assuming the function just displays the cleaning schedule
}


int sellTicket() {
    if (sessionCount == 0) {
        cout << "No sessions available for ticket sale.\n";
        return 1; // Return 1 for failure
    }

    string movieTitle;
    cout << "Enter the movie title for which you want to buy tickets: ";
    cin.ignore();
    getline(cin, movieTitle);

    bool sessionFound = false;
    int selectedSessionIndex = -1;

    for (int i = 0; i < sessionCount; ++i) {
        if (sessionList[i].movieTitle == movieTitle) {
            sessionFound = true;
            selectedSessionIndex = i;
            break;
        }
    }

    if (!sessionFound || selectedSessionIndex == -1) {
        cout << "No session found for the entered movie title.\n";
        return 1; // Return 1 for failure
    }

    int numberOfTickets;
    cout << "Enter the number of tickets to buy: ";
    cin >> numberOfTickets;

    if (numberOfTickets > sessionList[selectedSessionIndex].availableSeats) {
        cout << "Not enough available seats for this session.\n";
        return 1; // Return 1 for failure
    }

    sessionList[selectedSessionIndex].availableSeats -= numberOfTickets;
    sessionList[selectedSessionIndex].reservedSeats += numberOfTickets;

    cout << "Tickets sold successfully!\n";
    saveSessions(); // Save session changes after selling tickets

    return 0; // Return 0 for success
}


// Function to make a reservation for a movie session
int makeReservation() {
    if (sessionCount == 0) {
        cout << "No sessions available for reservation.\n";
        return 1; // Return 1 for failure
    }

    string movieTitle;
    cout << "Enter the movie title for which you want to make a reservation: ";
    cin.ignore();
    getline(cin, movieTitle);

    bool sessionFound = false;
    int selectedSessionIndex = -1;

    for (int i = 0; i < sessionCount; ++i) {
        if (sessionList[i].movieTitle == movieTitle) {
            sessionFound = true;
            selectedSessionIndex = i;
            break;
        }
    }

    if (!sessionFound || selectedSessionIndex == -1) {
        cout << "No session found for the entered movie title.\n";
        return 1; // Return 1 for failure
    }

    int numberOfSeats;
    cout << "Enter the number of seats to reserve: ";
    cin >> numberOfSeats;

    if (numberOfSeats > sessionList[selectedSessionIndex].availableSeats) {
        cout << "Not enough available seats for this session.\n";
        return 1; // Return 1 for failure
    }

    sessionList[selectedSessionIndex].availableSeats -= numberOfSeats;
    sessionList[selectedSessionIndex].reservedSeats += numberOfSeats;

    cout << "Reservation made successfully!\n";

    return 0; // Return 0 for success
}

// Function to schedule a special screening for a movie session
int scheduleSpecialScreening() {
    if (sessionCount == 0) {
        cout << "No sessions available for scheduling a special screening.\n";
        return 1; // Return 1 for failure
    }

    string movieTitle;
    cout << "Enter the movie title for which you want to schedule a special screening: ";
    cin.ignore();
    getline(cin, movieTitle);

    bool sessionFound = false;
    int selectedSessionIndex = -1;

    for (int i = 0; i < sessionCount; ++i) {
        if (sessionList[i].movieTitle == movieTitle) {
            sessionFound = true;
            selectedSessionIndex = i;
            break;
        }
    }

    if (!sessionFound || selectedSessionIndex == -1) {
        cout << "No session found for the entered movie title.\n";
        return 1; // Return 1 for failure
    }

    // Check if it's already a special screening
    if (sessionList[selectedSessionIndex].isSpecialScreening) {
        cout << "This session is already scheduled as a special screening.\n";
        return 1; // Return 1 for failure
    }

    // Set this session as a special screening
    sessionList[selectedSessionIndex].isSpecialScreening = true;

    cout << "Special screening scheduled successfully!\n";
    saveSessions(); // Save session changes after scheduling a special screening

    return 0; // Return 0 for success
}

int generateSeasonalTrendsReport() {
    double point1, point2, point3;
    string date1, date2, date3;
    date1 = "2023-01-01";
    date2 = "2023-02-01";
    date3 = "2023-03-01";
    point1 = 100.0;
    point2 = 120.0;
    point3 = 80.0;
    cout << "Generate Seasonal Trends Report:\n";
    cout << "This score is " << point1 << " on " << date1 << endl;
    cout << "This score is " << point2 << " on " << date2 << endl;
    cout << "This score is " << point3 << " on " << date3 << endl;

    return 0;


}

int generateFilmsTrendsReport() {
    printf("1.Interstaller\n");
    printf("2.Inception\n");
    printf("3.The Prestige\n");
    printf("4.Titanic\n");
    printf("5.Avatar\n");

    return 0;
}


int seatMaintenance() {
    int seatNumber;

    cout << "Enter the seat number to perform maintenance: ";
    cin >> seatNumber;

    // Burada koltuk numarasına göre bakım veya onarım işlemleri gerçekleştirilebilir
    // Örneğin:
    // Eğer seatNumber belirli bir koltuk numarasına denk geliyorsa, o koltuğun durumu gösterilebilir veya bakım yapılabilir.

    // Örnek bir işlem:
    cout << "Maintenance completed for seat number " << seatNumber << ". Seat is in good condition.\n";

    return seatNumber; // Başarılı durumda 0 döndürülebilir
}

int accessibilityFeatures() {
    int choice;

    cout << "\n=== Accessibility Features ===\n";
    cout << "1. Wheelchair Access\n";
    cout << "2. Audio Description\n";
    cout << "3. Subtitling\n";
    cout << "4. Hearing Loop\n";
    cout << "5. Exit\n";
    cout << "Enter your choice [1-5]: ";

    cin >> choice;

    system("cls");

    switch (choice) {
    case 1:
        cout << "Wheelchair access is available." << endl << endl;
        cout << "Wide doors and ramps are available for wheelchair access." << endl;


        break;

    case 2:
        cout << "Audio description service is available." << endl << endl;
        cout << "Films for the hearing impaired have an audio description feature." << endl;

        break;

    case 3:
        cout << "Subtitling service is available." << endl << endl;
        cout << "Turkish subtitle option is offered for foreign films." << endl;

        break;

    case 4:
        cout << "Hearing loop system is available." << endl << endl;
        cout << "Salon içerisinde işitme engellilere yönelik yardımcı döngü sistemi bulunmaktadır." << endl;

        break;

    case 0:
        cout << "Exiting accessibility features." << endl;

        break;

    default:
        cout << "Invalid choice. Please enter a valid option." << endl;
        break;
    }

    return 0;
}

int generateBoxOfficeCollections() {
    // Burada box office koleksiyonları için gerekli verileri işleyebilirsiniz.
    // Örneğin:
    double totalRevenue = 350000.0; // Toplam gelir
    double expenses = 150000.0; // Harcamalar
    double netProfit = totalRevenue - expenses; // Net kar

    // Box office koleksiyonlarını raporlama
    cout << "\n=== Box Office Collections ===\n";
    cout << "Total Revenue: $" << totalRevenue << endl;
    cout << "Expenses: $" << expenses << endl;
    cout << "Net Profit: $" << netProfit << endl;

    return 0;
}