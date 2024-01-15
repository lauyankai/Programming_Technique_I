#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

const int MAX_STUDENT = 15;
const int MAX_QUESTION = 20;
const int MAX_IDSIZE = 9;
const int MAX_SKEMASIZE = 1;

char answer[MAX_STUDENT][MAX_QUESTION];
char skema[MAX_SKEMASIZE][MAX_QUESTION];
string name[MAX_STUDENT];
string id[MAX_STUDENT];
int percents[MAX_STUDENT];
char grades[MAX_STUDENT];
int miss_each[MAX_STUDENT];

//----------------------------------- Function prototypes ----------------------------------------------------------
void readFile(int &, string[], string[], char[][MAX_QUESTION], char skema[][MAX_QUESTION]);
int compareAnswer(char skema[][MAX_QUESTION], char ans[][MAX_QUESTION], int search);
void printMissQuestion(char skema[][MAX_QUESTION], char ans[][MAX_QUESTION], int search);
double coutpercentage(int miss);
char coutgrade(double percent);
void printReport(int);
//------------------------------------------------------------------------------------------------------------------

int main()
{
	string ids;
	int count = 0;
	readFile(count, name, id, answer, skema);
	bool StudentFound = false;

	int search = 0;
	int miss;
	int percent;
	char grade;

	//--- Input Student ID --
	cout << "Enter the student ID: ";
	getline(cin, ids);

	for (int i = 0; i < MAX_STUDENT; i++)
	{
		if (ids == id[i])
		{
			StudentFound = true;
			search = i;
		}
	}

	if (StudentFound)
	{
		// --- If student ID is found --
		miss = compareAnswer(skema, answer, search);
		percent = coutpercentage(miss);
		grade = coutgrade(percent);

		cout << endl;
		cout << "EXAM RESULT" << endl
			 << endl;
		cout << setw(27) << left << "Name"
			 << ":  " << name[search] << endl;
		cout << setw(27) << left << "Student ID"
			 << ":  " << id[search] << endl;
		cout << setw(27) << left << "Number of questions missed"
			 << ":  " << miss << endl
			 << endl;
		printMissQuestion(skema, answer, search);
		cout << setw(11) << "\nPercentage"
			 << ": " << percent << "%, Grade: " << grade << endl
			 << endl;

		//--- For all student --
		for (int i = 0; i < MAX_STUDENT; i++)
		{
			miss_each[i] = compareAnswer(skema, answer, i);
			percents[i] = coutpercentage(miss_each[i]);
			grades[i] = coutgrade(percents[i]);
		}

		printReport(count);
	}
	else
	{
		cout << "\n Student ID not found in the System! \n";
	}
}

//----------------------------------- Reading Info from Input File -------------------------------------------------
void readFile(int &count, string name[], string id[], char answer[][MAX_QUESTION], char skema[][MAX_QUESTION])
{
	fstream infile("StudentAnswers.dat", ios::in);

	if (!infile)
	{
		cout << endl // Show error if failed to open
			 << "An error encoutered while opening the Student Answers Data." << endl;
	}

	while (!infile.eof())
	{
		infile >> name[count]; // Read the Name
		infile >> id[count];   // Read the Student ID
		for (int i = 0; i < 20; i++)
		{
			infile >> answer[count][i];
		}
		count++;
	}

	infile.close();

	fstream inputfile("CorrectAnswers.txt", ios::in);
	int x = 0;

	if (!inputfile)
	{
		cout << endl // Show error if failed to open
			 << "An error encoutered while opening the Correct Answers Data." << endl;
	}

	while (!inputfile.eof())
	{
		for (int i = 0; i < 20; i++)
		{
			inputfile >> skema[x][i];
		}
		x++;
	}

	inputfile.close();
}
//------------------------------------------------------------------------------------------------------------------

//----------------------------------- Export Summary Result to Output File -----------------------------------------
void printReport(int count)
{
	fstream outfile("Exam_Result.txt", ios::out);

	outfile << "LIST OF STUDENTS AND GRADES" << endl
			<< endl;

	outfile << setw(20) << left << "NAME"
			<< setw(20) << left << "ID"
			<< setw(20) << left << "PERCENTAGE"
			<< setw(20) << left << "GRADE" << endl
			<< setw(20) << left << "=========="
			<< setw(20) << left << "=========="
			<< setw(20) << left << "=========="
			<< "==========" << endl;

	for (int i = 0; i < count - 1; i++)
	{
		outfile << setw(20) << left << name[i] << setw(20) << left << id[i] << setw(20) << left << percents[i] << setw(20) << left << grades[i] << endl;
	}

	outfile.close();
}
//------------------------------------------------------------------------------------------------------------------

//----------------------------------- Compare Student answer with Correct answer -----------------------------------
int compareAnswer(char skema[][MAX_QUESTION], char ans[][MAX_QUESTION], int search)
{
	int num = 0;

	for (int i = 0; i < MAX_QUESTION; i++)
	{
		if (skema[0][i] != answer[search][i])
		{
			num++;
		}
	}
	return num;
}
//------------------------------------------------------------------------------------------------------------------

//----------------------------------- Display Incorrect Answer -----------------------------------------------------
void printMissQuestion(char skema[][MAX_QUESTION], char ans[][MAX_QUESTION], int search)
{
	cout << "List of the questions missed:" << endl;
	cout << setw(10) << left << "Question"
		 << setw(18) << left << "Correct Answer"
		 << setw(18) << left << "Student Answer" << endl;

	for (int i = 0; i < MAX_QUESTION; i++)
	{
		if (skema[0][i] != answer[search][i])
		{
			cout << i + 1 << "\t\t" << skema[0][i] << "\t\t" << answer[search][i] << endl;
		}
	}
}
//------------------------------------------------------------------------------------------------------------------

//----------------------------------- Display Percentage of Correct answer -----------------------------------------
double coutpercentage(int miss)
{
	double percent = (20.0 - miss) / 20.0 * 100;
	return percent;
}
//------------------------------------------------------------------------------------------------------------------

//------------------------------------ Display Grade obtained ------------------------------------------------------
char coutgrade(double percent)
{
	char grade;
	if (percent >= 80 && percent <= 100)
		grade = 'A';
	else if (percent >= 70 && percent < 80)
		grade = 'B';
	else if (percent >= 60 && percent < 70)
		grade = 'C';
	else
		grade = 'F';
	return grade;
}
//------------------------------------------------------------------------------------------------------------------