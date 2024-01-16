
  //**************************************
  //**			 LAU YAN KAI			**
  //**			 A23CS0098				**
  //**			 12 / 12 / 2023 		**
  //**************************************

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

void getInput(string &state, string &highest_state, int &highest_cases, int &total_cases, int &new_cases, int &total_death, int &total_recovered, int &active_cases);
string dispStatus(int active_cases);
void dispOutput(int active_cases);
void calcAverage(string highest_state, int highest_cases, int active_cases, int totActive_cases, int ave_active, int cnt_state);

int main() {
	char RESTARTchoice;
	string state, highest_state;
	int total_cases, new_cases, total_death, total_recovered, active_cases;
	int highest_cases = 0;
	int totActive_cases = 0;
	int ave_active =0;
	int cnt_state = 0;
	
	do {
		cout << "\n <<<<<<<<<<<<<<<<<< DATA >>>>>>>>>>>>>>>>> \n" << endl;
		getInput(state, highest_state, highest_cases, total_cases, new_cases, total_death, total_recovered, active_cases);
		cnt_state += 1; 		// To add 1 to the state counter
		
		cout << "\n <<<<<<<<<<<<<<<< SUMMARY >>>>>>>>>>>>>>>> \n" << endl;
		dispOutput(active_cases);
		totActive_cases += active_cases; 		// To add active cases into total cases
		
		cout << "\n Press <ENTER> to continue...";
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		RESTARTchoice = cin.get(); 			// Read only a single character
		system("cls");
	
	} while (RESTARTchoice != 'n' && RESTARTchoice != 'N'); 
	
	calcAverage(highest_state, highest_cases, active_cases, totActive_cases, ave_active, cnt_state);
	return 0;
}

string dispStatus(int active_cases) {
	if (active_cases > 40)
		return "Red";
	else if (active_cases > 20 && active_cases <= 40)
		return "Orange";
	else if (active_cases >= 1 && active_cases <= 20)
		return "Yellow";
	else
		return "Green";
}

void getInput(string &state, string &highest_state, int &highest_cases, int &total_cases, int &new_cases, int &total_death, int &total_recovered, int &active_cases) {
	cout << left << setw(16) << "State name" << ": ";
	getline(cin, state);

	cout << left << setw(16) << "Total cases" << ": ";
	cin >> total_cases;

	cout << left << setw(16) << "New cases" << ": ";
	cin >> new_cases;

	cout << left << setw(16) << "Total death" << ": ";
	cin >> total_death;

	cout << left << setw(16) << "Total recovered" << ": ";
	cin >> total_recovered;
	
	// Calculate active cases
	active_cases = (total_cases + new_cases) - (total_death + total_recovered);
	
	// Find the highest active cases state 
	if (active_cases > highest_cases) {
		highest_state = state;
		highest_cases = active_cases; 
	}
}

void dispOutput(int active_cases) {
	cout << left << setw(16) << "Active cases" << ": " << active_cases << endl;
	cout << left << setw(16) << "Status" << ": " << dispStatus(active_cases) << " Zone"<< endl;
}

void calcAverage(string highest_state, int highest_cases, int active_cases, int totActive_cases, int ave_active, int cnt_state) {

	// calculate average number of active cases per state
	ave_active = totActive_cases / cnt_state;
	
	cout << left << setw(25) << "\n Total Active Cases" << ": " << totActive_cases << endl;
	cout << left << setw(25) << "\n Highest Cases" << ": " << highest_cases << " (" << highest_state << ")"<< endl;
	cout << "\n Average for " << cnt_state << left << setw(10) << " state(s)" << ": " << ave_active << endl;
}