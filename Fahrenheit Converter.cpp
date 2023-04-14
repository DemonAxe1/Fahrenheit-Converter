/*
Name: Tarek Hisham Ahmed Fouad
In this program we prompt the user with 4 selections. They picks 1 or 2 we ask him to put the Fahrenheit temp to calc. If he picks 3 we show him a table.
If he picks 4 we say bye and close the program.
*/


//Setting up libraries.
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// Setting up some vars.
string userInp;
int i, j; 
double c, k, f, x, y; // c is Celsius, k is kelvin, f is Fahrenheit, x and y are used as filler vars latter.

// Getting the 
void showMenu();
void showKelvin(double f);
void showCelsius(double f);



int main()
{
	
	double list[3][10]; //creating a 2d array that can carry all the temps.
	
	// This for loop is to set all the spots in the array to be 0.0 
	//(when I was coding I had problems checking if the spot in the array was empty, This was the best way I can think of.)
	for(int a = 0; a < 3; a++) 
	{
	    for(int b = 0; b < 10; b++)
	    {
	        list[a][b] = 0.0;
	    }
	}
	// Program welcome.
	cout << "This program converts a temperature in Fahrenheit to Celsius or Kelvin.\nNOTE: A Maximum of 10 temperatures can be entered.\n" << endl;
	
	// Start of the loop (main part of the program)
	for(i=0;i<=10;)
	{
	c=0;
	f=0;
	k=0;
	
	// If the user put 10 temps, then send this error message. 
	if (i>=10)
	{
		cout << "****10 Temperatures have been added, no more Temperatures can be inputted!****" << endl << "****You may check your Temperatures you have entered or end the program****" << endl;
	}
	
	//Prompts menu. 
	showMenu();
	
	// Celsius calculation.
	if (userInp == "1" && i!=10) // i checks if the user has entered 10 temps
	{
		cout << "Enter the Fahrenheit  temperature: ";
		cin >> f;
		if (f < -459.67) // Temps can not get to -459.67. If user enters lower than that he gets an error msg and try again.
		cout << "That temperature does not exist, try again!\n" << endl;
		else 
		{
		showCelsius(f); // Calcs both Celsius and Kelvin but only outputs Celsius.
		showKelvin(f);
		cout << setprecision(1) << fixed << f << " Fahrenheite = "    << c << " Celsius" << endl;
		// Adds the calcs to the 2d array
		list[0][i] = f;
		list[1][i] = c;
		list[2][i] = k;
		i++;
		cout << "\nThe number of temperatures  you entered is: " << i << endl << endl; // Tells the user how many temps they have entered.
		}
	}
	// Calcs Kelvin
	else if (userInp == "2" && i!=10) // i checks if the user has entered 10 temps
	{
		cout << "Enter the Fahrenheit temperature: ";
		cin >> f;
				if (f < -459.67) // Temps can not get to -459.67. If user enters lower than that he gets an error msg and trys again.
		cout << "That temperature does not exist, try again!\n" << endl;
		else
		{
		showKelvin(f); //Calcs both Celsius and Kelvin but only outputs kelvin.
		showCelsius(f);
		cout << setprecision(1) << fixed << f << " Fahrenheite = "  << k << " Kelvin" << endl;
		// Adds the calcs to the 2d array
		list[0][i] = f;
		list[1][i] = c;
		list[2][i] = k;
		i++;
		cout << "\nThe number of temperatures  you entered is: " << i << endl << endl;
	}
		
		
		
	}
	else if (userInp == "3") // If the user inputs 3 the program displays the array outputs.
	{
		cout << "Data Entered" << endl;
		for(j=0;j<3;j++) //Changes the colloms 
		{
			// This prints the 3 temp titles before the array is printed
			cout << right << setw(12) << fixed;
			if (j == 0)
				cout << "Fahrenheit: ";
			else if (j == 1)
				cout << "Celsius: ";
			else
				cout << "Kelvin: ";
				
			for(int a=0;a<10;a++) //Changes the Row.
			{
				cout << right << setprecision(1) << setw(12) << fixed;
				
				
				x=list[2][a];
				y=list[0][a];
				
				if (x != 0 && y != 0){ // If it does not = 0 then it prints the output.
					
					cout << list[j][a] << " "; // prints the Row
				}
			
			
			}	
			cout << endl << endl << endl; // Just creats space between the output
			
			
		}
	}
	else if (userInp == "4")
	{
		cout << "Thank you for using the Temperature Conversion Program - Good-bye!" << endl; // Ends the program.
		break;
	}
	else
	{
	   
	        cout << "You entered \"" << userInp << "\". That is not a valid option try again!\n" << endl; // gives an error msg and asks to try again
	       
	}
	cout << "---------------------------------------------------" << endl;
	
}
return 0;
}


void showMenu(){ // Prompts the selection options
	cout << "Select one of the following menu options:" << endl;
	cout << "\t1. Convert Fahrenheit to Celsius (Centigrade)" << endl << "\t2. Convert Fahrenheit to Kelvin" << endl << "\t3. Display Data" << endl << "\t4. Quit" << endl << "Enter your choice:" << endl;
	cin >> userInp;
	
}

void showKelvin(double f){ // Does the calc for Kelvin

	k = 5*(f-32)/9+(273.15);
	
	
}

void showCelsius(double f){ //Does the calc for Celsius

	c = 5*(f-32)/9;
		
	
}

