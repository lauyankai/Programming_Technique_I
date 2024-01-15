#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

const int SIZE = 100;
string type[SIZE];
double C[SIZE], P[SIZE], F[SIZE];
double nC[SIZE], nP[SIZE], nF[SIZE];
double Cdv[SIZE], Pdv[SIZE], Fdv[SIZE];
string gradeC[SIZE], gradeP[SIZE], gradeF[SIZE];

//----------------------------------- Function prototypes ----------------------------------------------------------
void readData(int &, string &, string[], double[], double[], double[]);
void calConvert(double[], double[], double[], double[], double[], double[], int &);
void calDV(double[], double[], double[], double[], double[], double[], int &);
void determineCategory(string[], string[], string[], double[], double[], double[], int &);
void Carbohydrate(int, int, string, string[]);
void Protein(int, int, string, string[]);
void Fat(int, int, string, string[]);
void aveDV(int, double &, double &, double &, string &, string &, string &);
void Export(int, string, double, double, double, string, string, string);
//------------------------------------------------------------------------------------------------------------------


int main()
{
	int count = 0, choice, ct;
	string name, gradeatC, gradeatF, gradeatP;
	int a = 1, b = 1, c = 1;
	char again;

	readData(count, name, type, C, P, F);

	// Declare function
	calConvert(C, P, F, nC, nP, nF, count);
	calDV(nC, nP, nF, Cdv, Pdv, Fdv, count);
	determineCategory(gradeC, gradeP, gradeF, Cdv, Pdv, Fdv, count);

	cout << "\n1. Carbohydrate" << endl;
	cout << "2. Protein" << endl;
	cout << "3. Fat" << endl;

	cout << "\nPlease enter your choice >> ";
	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		cout << "\n\n1. Low" << endl;
		cout << "2. Moderate" << endl;
		cout << "3. High" << endl;
		Carbohydrate(count, a, name, gradeC);
		break;
	}
	case 2:
	{
		cout << "\n\n1. Low" << endl;
		cout << "2. Moderate" << endl;
		cout << "3. High" << endl;
		Protein(count, b, name, gradeP);
		break;
	}
	case 3:
	{
		cout << "\n\n1. Low" << endl;
		cout << "2. Moderate" << endl;
		cout << "3. High" << endl;
		Fat(count, c, name, gradeF);
		break;
	}
	default:
	{
		cout << "\nSorry. Invalid choice. Please choose again. \n"
			 << endl;
		break;
	}
	}

	double atC = 0, atP = 0, atF = 0;
	aveDV(count, atC, atP, atF, gradeatC, gradeatP, gradeatF);
	Export(count, name, atC, atP, atF, gradeatC, gradeatP, gradeatF);
}


//--------------------------------- Reading data from input file ---------------------------------------------------
void readData(int &count, string &name, string type[], double C[], double P[], double F[])
{
	ifstream inp("Case1_Data.txt");

	if (!inp.is_open())
	{
		cout << "ERROR: Input file not exists!\n";
		exit(1);
	}

	while (!inp.eof())
	{
		inp >> name >> type[count] >> C[count] >> P[count] >> F[count];
		count++;
	}

	// Close input file
	inp.close();
}

//--------------------------------- Convert Ounce to Gram and round off ---------------------------------------------
void calConvert(double C[], double P[], double F[], double nC[], double nP[], double nF[], int &count)
{
	const double Ounce_to_Gram = 28.35;

	for (int i = 0; i < count; i++)
	{
		nC[i] = C[i] * Ounce_to_Gram;
		nP[i] = P[i] * Ounce_to_Gram;
		nF[i] = F[i] * Ounce_to_Gram;

		// Round the values to two decimal places
		nC[i] = round(nC[i] * 100) / 100.0;
		nP[i] = round(nP[i] * 100) / 100.0;
		nF[i] = round(nF[i] * 100) / 100.0;
	}
}

//----------------------------------------- Calculation for DV ------------------------------------------------------
void calDV(double nC[], double nP[], double nF[], double Cdv[], double Pdv[], double Fdv[], int &count)
{
	for (int i = 0; i < count; i++)
	{
		Cdv[i] = nC[i] / 300.0 * 100;
		Pdv[i] = nP[i] * 2;
		Fdv[i] = nF[i] / 65.0 * 100;
	}
}

//------------------------------------ Determining the level of nutrints --------------------------------------------
void determineCategory(string gradeC[], string gradeP[], string gradeF[], double Cdv[], double Pdv[], double Fdv[], int &count)
{
	for (int i = 0; i < count; i++)
	{
		if (Cdv[i] <= 5)
			gradeC[i] = "low";
		else if (Cdv[i] > 5 && Cdv[i] < 20)
			gradeC[i] = "moderate";
		else if (Cdv[i] >= 2)
			gradeC[i] = "high";

		if (Pdv[i] <= 5)
			gradeP[i] = "low";
		else if (Pdv[i] > 5 && Pdv[i] < 20)
			gradeP[i] = "moderate";
		else if (Pdv[i] >= 2)
			gradeP[i] = "high";

		if (Fdv[i] <= 5)
			gradeF[i] = "low";
		else if (Fdv[i] > 5 && Fdv[i] < 20)
			gradeF[i] = "moderate";
		else if (Fdv[i] >= 2)
			gradeF[i] = "high";
	}
}

//----------------------------------------- Choice of Carbohydrate ------------------------------------------------------
void Carbohydrate(int count, int a, string name, string gradeC[])
{
	int ct;
	cout << "\nPlease enter your choice >> ";
	cin >> ct;

	switch (ct)
	{

	case 1:
		cout << "\n\nList of cereal(s) with low amount of carbohydrate:" << endl;
		for (int i = 0; i < count; i++)
		{
			if (gradeC[i] == "low")
			{
				cout << a << ". " << name << " " << type[i] << endl;
				a++;
			}
		}
		break;

	case 2:
		cout << "\n\nList of cereal(s) with moderate amount of carbohydrate:" << endl;
		for (int i = 0; i < count; i++)
		{
			if (gradeC[i] == "moderate")
			{
				cout << a << ". " << name << " " << type[i] << endl;
				a++;
			}
		}
		break;

	case 3:
		cout << "\n\nList of cereal(s) with high amount of carbohydrate:" << endl;
		for (int i = 0; i < count; i++)
		{
			if (gradeC[i] == "high")
			{
				cout << a << ". " << name << " " << type[i] << endl;
				a++;
			}
		}
		break;

	default:
		cout << "\nSorry. Invalid choice. Please choose again. " << endl;
		break;
	}
}

//---------------------------------------------- Choice of Protein ------------------------------------------------------
void Protein(int count, int b, string name, string gradeP[])
{
	int ct;
	cout << "\nPlease enter your choice>> ";
	cin >> ct;

	switch (ct)
	{

	case 1:
		cout << "\n\nList of cereal(s) with low amount of protein:" << endl;
		for (int i = 0; i < count; i++)
		{
			if (gradeP[i] == "low")
			{
				cout << b << ". " << name << " " << type[i] << endl;
				b++;
			}
		}
		break;

	case 2:
		cout << "\n\nList of cereal(s) with moderate amount of protein:" << endl;
		for (int i = 0; i < count; i++)
		{
			if (gradeP[i] == "moderate")
			{
				cout << b << ". " << name << " " << type[i] << endl;
				b++;
			}
		}
		break;

	case 3:
		cout << "\n\nList of cereal(s) with high amount of protein:" << endl;
		for (int i = 0; i < count; i++)
		{
			if (gradeP[i] == "high")
			{
				cout << b << ". " << name << " " << type[i] << endl;
				b++;
			}
		}
		break;

	default:
		cout << "\nSorry. Invalid choice. Please choose again. " << endl;
		break;
	}
}

//------------------------------------------------ Choice of Fat --------------------------------------------------------
void Fat(int count, int c, string name, string gradeF[])
{
	int ct;
	cout << "\nPlease enter your choice>> ";
	cin >> ct;

	switch (ct)
	{
	case 1:
		cout << "\n\nList of cereal(s) with low amount of fat:" << endl;
		for (int i = 0; i < count; i++)
		{
			if (gradeF[i] == "low")
			{
				cout << c << ". " << name << " " << type[i] << endl;
				c++;
			}
		}
		break;

	case 2:
		cout << "\n\nList of cereal(s) with moderate amount of fat:" << endl;
		for (int i = 0; i < count; i++)
		{
			if (gradeF[i] == "moderate")
			{
				cout << c << ". " << name << " " << type[i] << endl;
				c++;
			}
		}
		break;

	case 3:
		cout << "\n\nList of cereal(s) with high amount of fat:" << endl;
		for (int i = 0; i < count; i++)
		{
			if (gradeF[i] == "high")
			{
				cout << c << ". " << name << " " << type[i] << endl;
				c++;
			}
		}
		break;

	default:
		cout << "\nSorry. Invalid choice. Please choose again. " << endl;
		break;
	}
}

//-------------------------------- Determining the average DV  ------------------------------------------------------
void aveDV(int count, double &atC, double &atP, double &atF, string &gradeatC, string &gradeatP, string &gradeatF)
{
	double tC = 0, tP = 0, tF = 0;
	for (int i = 0; i < count; i++)
	{
		tC += Cdv[i];
		tP += Pdv[i];
		tF += Fdv[i];
	}

	atC = tC / count;
	atP = tP / count;
	atF = tF / count;

	if (atC <= 5)
		gradeatC = "low";
	else if (atC > 5 && atC < 20)
		gradeatC = "moderate";
	else if (atC >= 20)
		gradeatC = "high";

	if (atP <= 5)
		gradeatP = "low";
	else if (atP > 5 && atP < 20)
		gradeatP = "moderate";
	else if (atP >= 20)
		gradeatP = "high";

	if (atF <= 5)
		gradeatF = "low";
	else if (atF > 5 && atF < 20)
		gradeatF = "moderate";
	else if (atF >= 20)
		gradeatF = "high";
}

//---------------------------------------- Export the summary  ------------------------------------------------------
void Export(int count, string name, double atC, double atP, double atF, string gradeatC, string gradeatP, string gradeatF)
{
	ofstream out("result.txt");

	out << left << setw(15) << "Type" << left << setw(25) << "Carbohydrate" << left << setw(25) << "Protein"
		<< "Fat" << endl;
	out << left << setw(15) << "=====" << left << setw(25) << "============" << left << setw(25) << "======="
		<< "===" << endl;

	for (int i = 0; i < count; i++)
	{
		out << name << " " << type[i];
		if (gradeC[i] == "high")
			out << right << setw(14) << " " << fixed << setprecision(1) << Cdv[i] << "%(" << gradeC[i] << left << setw(5) << ")";
		else if (gradeC[i] == "moderate")
			out << right << setw(15) << " " << fixed << setprecision(1) << Cdv[i] << "%(" << gradeC[i] << left << setw(1) << ")";
		else if (gradeC[i] == "low")
			out << right << setw(15) << " " << fixed << setprecision(1) << Cdv[i] << "%(" << gradeC[i] << left << setw(6) << ")";

		if (gradeP[i] == "high")
			out << setw(7) << " " << setw(4) << fixed << setprecision(1) << Pdv[i] << "%(" << gradeP[i] << left << setw(5) << ")";
		else if (gradeP[i] == "moderate")
			out << setw(7) << " " << setw(4) << fixed << setprecision(1) << Pdv[i] << "%(" << gradeP[i] << left << setw(1) << ")";
		else
			out << setw(7) << " " << setw(4) << fixed << setprecision(1) << Pdv[i] << "%(" << gradeP[i] << left << setw(6) << ")";

		out << right << setw(10) << " " << fixed << setprecision(1) << Fdv[i] << "%(" << gradeF[i] << ")" << endl;
	}

	out << "\n\nThe 10 cereal types produce an average %DV of: " << endl;
	out << "Carbohydrate : " << static_cast<int>(atC) << "%(" << gradeatC << ")\n";
	out << "Protein      : " << static_cast<int>(atP) << "%(" << gradeatP << ")\n";
	out << "Fat          : " << static_cast<int>(atF) << "%(" << gradeatF << ")\n";

	// Close output file
	out.close();
}