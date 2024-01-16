             
             //****************************
             //   Brendan Chia Yan Fei    *
             //         A23CS0211         *           
             //****************************

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    a:
    int age, height , weight;
    char gender;

    cout << "\n\nBasal Metabolic Rate (BMR) Calculator \n" << endl;
    do{ cout << "Age [15-80]: " ;
    cin >> age;
    }
    while (age < 15 || age > 80);

    do {cout<< "Gender (M/F): ";
    cin  >> gender;}
    while(gender != 'M' && gender!= 'm' && gender!='F'&& gender!='f');

    cout << "Height (cm) : " ;
    cin >> height;
    cout << "Weight (kg) : ";
    cin >> weight;
    if (gender == 'M'|| gender=='m')
    cout << "\nBMR = " << ((10 * weight ) + (6.25 * height) - (5 * age) + 5) << " calories/day \n" << endl;
    if (gender == 'F'|| gender=='f')
    cout << "\nBMR = " << ((10 * weight ) + (6.25 * height) - (5 * age) - 161) << " calories/day \n" << endl;

    cout << setw(45) << "Daily calorie needs based on activity level" << setw(10) << "Calorie" << endl;
    cout << setw(45) << "Activity Level" << setw(10) << "1,727" << endl;
    cout << setw(45) << "Sedentary: little or no exercise" << setw(10) << "1,979" << endl;
    cout << setw(45) << "Exercise 1-3 times/week" << setw(10) << "2,108" << endl;
    cout << setw(45) << "Exercise 4-5 times/week" << setw(10) << "2,230" << endl;

    cout << "Exercise: 15-30 minutes of elevated heart rate activity." << endl;
    cout << "Intense exercise: 45-120 minutes of elevated heart rate activity." << endl;
    cout << "Very intense exercise: 2+ hours of elevated heart rate activity. \n" << endl;
    
    string choice;
    do {
        cout << "Do you want to enter other data? [Y @ N]:"; 
        cin >> choice; 
        if (choice == "y" || choice == "Y")
            goto a; 
        else if (choice == "n" || choice == "N")
            cout << "\nThank you :)\n\n";
    } while (choice != "y" && choice != "Y" && choice != "n" && choice != "N");
    
    return 0;
}
