#include "../header/cinema.h"
#include <stdexcept>
#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace Coruh::Calculator;
using namespace std;

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