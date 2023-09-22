#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits> // header file
#include <conio.h>

using namespace std; //C++ directive that tells the compiler to make all the symbols (functions, classes, and objects)

int main() {
	srand(time(0)); //C++ statement that seeds the random number generator
    int guess, Number; //Declaring variables
    Number = rand()%100 + 1; // Generating a random number
    cout << "Welcome to the Number Guessing Game!" << endl; // Heading to tell user it's guessing game

    do //A loop asking user guess until the guess is true
	 {
        cout << "Enter your guess: "; // Asking user's guess
        if (cin >> guess) // check if the user's guess is equal to the random number
		{
            if (guess > Number) // Check if the guess is higher than the number
			 {
                cout << "Too high! Try again." << endl; // it will tell the user your guess is high
            } 
			else if (guess < Number) // Check if the guess is lower than the number
			 {
                cout << "Too low! Try again." << endl; // it will tell the user your guess is low
            }
			 else {
                cout << "Congratulations! You guessed the number " << Number << endl; // If the guess is correct the game will end
                getch();
            }
        } 
		else {
            cout << "Invalid input. Please enter a valid number." << endl; // if the input is invalid for example: alphabet, etc
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // it will clear the screen
        }
    } 
	while (guess != Number); // The loop will not end until the guess is correct

    return 0;
}
