             
             //**********************
             //   	Lau Yan Kai     *
             //      A23CS0098      *           
             //**********************

#include <iostream>
#include <cmath>
#include <iomanip> 
using namespace std; 

string Model (int carmodel);
string VariantsX50 (int variants);
string VariantsExora (int variants);
string VariantsPersona (int variants);
string Region (int carregion);
string Painttype (int carpainttype);

int main() {   
a: 
    cout << "\n\nProton Car Loan Calculator \n\n";
    int carmodel, variants, carregion, carpainttype;
	
    do                          // Input Model 
    {
        cout << "Model [1-X50, 2-Exora, 3-Persona]: ";
        cin >> carmodel;
    } while (carmodel <0 || carmodel >4);
    string CarModel = Model(carmodel);
    string Variants;
    
    if (carmodel == 1)          // Input Variant for X50
    {
        do {
            cout << "Variants [1-1.5T Standard, 2-1.5T Executive, 3-1.5T Premium, 4-1.5TGDi Flagship]: ";
            cin >> variants;   
            Variants = VariantsX50(variants);
        } while (variants <0 || variants >=4);
    }

    else if (carmodel == 2)     // Input Variant for Exora
    {
        do {
        cout << "1-1.3L Standard CVT, 2-1.6L Executive CVT, 3-1.6L Active CVT: ]";
        cin >> variants;
        Variants = VariantsExora(variants);
        } while (variants <0 || variants >=3);
    }
    
    else if (carmodel == 3)     // Input Variant for Persona
    {
        do {
        cout << "1-1.6L Standard CVT, 2-1.6L Executive CVT, 3-1.6L Premium CVT: ]";
        cin >> variants;
        Variants = VariantsPersona(variants);
        } while (variants <0 || variants >=3);
    }

    do {                        // Input Region
        cout << "Region [1-Peninsular Malaysia, 2-East Malaysia]: ";
        cin >> carregion; 
    } while(carregion <0 || carregion >3);
    string region = Region(carregion);

    do {                        // Input Paint Type
        cout << "Paint Type [1-Solid, 2-Metallic]: ";
        cin >> carpainttype; 
    } while(carpainttype <0 || carpainttype >3);
    string CarPaintType = Painttype(carpainttype);
    
             //***************************
             //    Display Car Info      *
             //***************************

    cout << "\nCar Info" << endl; 
    cout << "Model: " << CarModel << endl; 
    cout << "Variant: " << Variants << endl; 
    cout << "Region: " << region << endl; 
    cout << "Paint Type: " << CarPaintType << endl; 
    
    double price;                   // Loan price for the car
    cout << "Price (MYR): "; 
    cin >> price; 

    double DownPayment;             // Deposit paid for the loan
    cout << "\n Down payment / Deposit (MYR): ";
    cin >> DownPayment; 

    double InterestRate;            // Interest rate for the loan
    cout << " Interest Rate (%): ";
    cin >> InterestRate;

    double RepaymentPeriod;         // Repayment period for the loan
    do {
        cout << " Repayment Period (in years): ";
        cin >> RepaymentPeriod; 
    } while (RepaymentPeriod <0 || RepaymentPeriod >10);

    double month = (RepaymentPeriod * 12);      // Convert period in years to months
    double Loan = (price - DownPayment);        // Deduct deposit from the car loan
    double TotalInterest = (((InterestRate/100)*Loan)*RepaymentPeriod); // Calculate total interest
    double TotalLoan = (Loan + TotalInterest);      // Calculate total loan
    double MonthlyInstallment = (TotalLoan)/(month);        // Calculate monthly installment

    cout << "\nMONTHLY INSTALLMENT: RM " << fixed << setprecision(2) << MonthlyInstallment << endl; 

    string ANS; 
    do {                  // Whether restart the programme or end

        cout << "\nDo you want to enter other data? [Y @ N]: ";
        cin >> ANS;

        if (ANS == "y" || ANS == "Y")
            goto a; 
        else if (ANS == "n" || ANS == "N")
            cout << "\nThank you :)\n\n";
    } while (ANS != "y" && ANS != "Y" && ANS != "n" && ANS != "N");

    return 0; 
}

string Model (int carmodel) 
{
    if (carmodel == 1)
        return "Proton X50";
    else if (carmodel == 2)
        return "Proton Exora";
    else if (carmodel == 3)
        return "Proton Persona";
}

string VariantsX50 (int variants) 
{
    if (variants == 1)
        return "1.5T Standard";
    else if (variants == 2)
        return "1.5T Executive";
    else if (variants == 3)
        return "1.5T Premium";  
    else if (variants == 4)
        return "1.5TGDi Flagship";  
}

string VariantsExora (int variants)
{
 if (variants == 1)
        return "1.3L Standard CVT";
    else if (variants == 2)
        return "1.6L Executive CVT";
    else if (variants == 3)
        return "1.6L Active CVT";  
}   

string VariantsPersona (int variants)
{
    if (variants == 1)
        return "1.6L Standard CVT";
    else if (variants == 2)
        return "1.6L Executive CVT";
    else if (variants == 3)
        return "1.6L Premium CVT";        
}

string Region (int carregion)
{
    if (carregion == 1)
        return "Peninsular Malaysia";
    else if (carregion == 2)
        return "East Malaysia";
}

string Painttype (int carpainttype)
{
    if (carpainttype == 1)
        return "Solid";
    else if (carpainttype == 2)
        return "Metallic";
}
