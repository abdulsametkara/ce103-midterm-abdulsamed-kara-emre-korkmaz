
/**
 * @file cinemaapp.cpp
 * @brief A simple program to demonstrate the usage of the cinema model class.
 *
 * This program process infix notations and calculate operations
 *
 */

 // Standard Libraries
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>
#include "../../cinema/header/cinema.h"  // Adjust this include path based on your project structure
#include "../../cinemaapp/header/cinemaapp.h"

using namespace Coruh::Calculator;
using namespace std;
int main() {

    loadMoviesFromFile();
	loadSessions();

	

	int choice;
	int choice2;
	int choice3;
	int choice4;
	int choice5;
	int choice6;

	do {
		screenmenu();
		cout << "Enter your choise [0-5] ";
		cin >> choice;
		system("cls");

		switch (choice) {
			// open to Movie Management menu
		case 1:
			cout << "\n==== Movie Management ====\n";
			cout << "1. Add Movie\n";
			cout << "2. Update Movie\n";
			cout << "3. Delete Movie\n";
			cout << "4. Categorize Genre\n";
			cout << "5. Rate Movie\n";
			cout << "6. Review Movie\n";
			cout << "7. List Movie\n";

			cout << "Enter your choise [0-7] ";
			cin >> choice2;
			system("cls");

			switch (choice2) {

				// open to Add movie menu
			case 1:
				cout << "\n=== Add Movie ===\n";
				addMovie();
				saveMovies();

				break;
				// open to Update Movie menu

			case 2:
				cout << "\n === Update Movie ===\n";
				
				 updateMovie();
				 saveMovies();

				break;
				// open to Delete Movie menu

			case 3:
				cout << "\n=== Delete Movie ===\n";
				deleteMovie();
				saveMovies();
				break;
				// open to Categorize Genre menu

			case 4:
				cout << "\n=== Categorize Genre ===\n";
				


				break;
				// open to Rate Movie menu

			case 5:
				cout << "\n=== Rate Movie ===\n";

				break;
				// open to Review Movie menu

			case 6:
				cout << "\n=== Review Movie ===\n";

				break;

			case 7:
				cout << "\n=== List Movie ===\n";
				listMovies();

				break;

			case 0:
				cout << "Returned To Main Menu!\n";


				break;

			default:
				cout << "Invalid choice. Please enter a valid option.\n";

				break;


			}
			break;

			// open to Session Planning menu
		case 2:
			cout << "\n==== Session Planning ====\n";
			cout << "1. Sell Ticket\n";
			cout << "2. Make a Reservation\n";
			cout << "3. Session Creation\n";
			cout << "4. Delete Session\n";
			cout << "5. View Sessions\n";
			cout << "6. Schedule Special Screening\n";



			cout << "Enter your choise [0-6] ";
			cin >> choice3;
			system("cls");



			switch (choice3) {

				// open to Sell Ticket 
			case 1:
				cout << "\n=== Sell Ticket ===\n";

				break;

				// open to Make a Reservatin menu
			case 2:
				cout << "\n=== Make a Reservation ===\n";

				break;

				// open to Schedule Special Sreening 
			case 3:
				cout << "\n=== Session Creation ===\n";
				createSession();
				saveSessions();

				break;


			case 4:
				cout << "\n=== Delete Session ===\n";
				

				break;


			case 5:
				cout << "\n ==== View Sessions ====\n";
				listSessions();

				break;


			case 6:
				cout << "\n ==== Schedule Special Screening ====\n";


				break;


			case 0:
				cout << "Returned To Main Menu!\n";

				break;

			default:
				cout << "Invalid choice. Please enter a valid option.\n";

				break;
			}
			break;


			// open to Auditorium and Seating Arrangements menu
		case 3:
			cout << "\n==== Auditorium and Seating Arrangements ====\n";
			cout << "1. Create Cleaning Schedule\n";
			cout << "2. Seat Maintenance\n";
			cout << "3. Accessibility Features\n";

			cout << "Enter your choise [0-3] ";
			cin >> choice4;
			system("cls");



			switch (choice4) {
				// open to Create Cleaning Schedule menu

			case 1:
				cout << "\n=== Create Cleaning Schedule ===\n";
				
				break;

				// open to Seat Maintenance menu

			case 2:
				cout << "\n=== Seat Maintenance ===\n";
				

				break;

				// open to Accessibility Features menu 
			case 3:
				cout << "\n=== Accessibility Features ===\n";

				break;

			case 0:
				cout << "Returned To Main Menu!\n";

				break;

			default:
				cout << "Invalid choice. Please enter a valid option.\n";

				break;
			}
			break;




			// open to Reporting menu
		case 4:
			cout << "\n==== Reporting ====\n";
			cout << "1. Generate Box Office Collections\n";
			cout << "2. Generate Popular Movies Report\n";
			cout << "3. Generate Seasonal Trends Report\n";

			cout << "Enter your choise [0-3] ";
			cin >> choice5;
			system("cls");


			switch (choice5) {

				// open to Generate Box Office Collections menu
			case 1:
				cout << "\n=== Generate Box Office Collections ===\n";
				

				break;

				// open to Generate Popular Movies Report menu
			case 2:
				cout << "\n=== Generate Popular Movies Report ===\n";

				break;

				// open to Generate Seasonal Trends Report menu
			case 3:
				cout << "\n=== Generate Seasonal Trends Report ===\n";
				

				break;

			case 0:
				cout << "Returned To Main Menu!\n";

				break;

			default:
				cout << "Invalid choice. Please enter a valid option.\n";

				break;
			}
			break;

			// open to Integrations menu
		case 5:
			cout << "\n==== Integrations ====\n";
			cout << "1. Integrate Online Booking\n";
			cout << "2. Integrate Snack Bar POS\n";

			cout << "Enter your choise [0-3] ";
			cin >> choice6;
			system("cls");


			switch (choice6) {
				// open to Integrate Online Booking 

			case 1:
				cout << "\n=== Integrate Online Booking  ===\n";

				break;
				// open to Integrate Snack Bar POS menu

			case 2:
				cout << "\n=== Integrate Snack Bar POS ===\n";

				break;

			case 0:
				cout << "Returned To Main Menu!\n";

				break;

			default:
				cout << "Invalid choice. Please enter a valid option.\n";

				break;
			}
			break;

		case 0:
			cout << "Exiting the program. See you!\n";

			break;

		default:
			cout << "Invalid choice. Please enter a valid option.\n";

			break;

		}
	} while (choice != 0);

	return 0;

}
