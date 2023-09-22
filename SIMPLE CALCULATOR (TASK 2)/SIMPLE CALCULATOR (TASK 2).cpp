#include <iostream>
#include <conio.h>
#include <limits>
// header file
using namespace std; //C++ directive that tells the compiler to make all the symbols (functions, classes, and objects)

int main() {
    char opt;
    int n1, n2;
    float result;
    bool validOperator = false;
	 // Variable declaration
    cout<<"Welcome to C++ Calculator"; // Heading telling user it is a calculator
	cout <<"\nEnter the first number(operand): "; // Asking user to enter first number
    cin >> n1;
    cout << "Enter the second number(operand): "; // Asking user to enter second number
    cin >> n2;
    while (!validOperator) //This loop will start if the operator is valid
	 {
        cout << "Enter an operator (+, -, *, /) : "; // Asking user to choose the operator
        cin >> opt;
        switch (opt)
		 { 
            case '+': // If the operator is + the below code will run
                result = n1 + n2; //Addition 
                cout << "You have selected: Addition" << endl;
                cout << "The result of "<<n1<<" "<<opt<<" "<<n2<<" "<<"= "<< result << endl; // The result
                validOperator = true;
                break;

            case '-': // If the operator is - the below code will run
                result = n1 - n2; // Subtraction
                cout << "You have selected: Subtraction" << endl;
                cout << "The result of "<<n1<<" "<<opt<<" "<<n2<<" "<<"= "<< result << endl; // The result
                validOperator = true;
                break;

            case '*': // If the operator is * the below code will run
                result = n1 * n2; // Multiplication
                cout << "You have selected: Multiplication" << endl;
                cout << "The result of "<<n1<<" "<<opt<<" "<<n2<<" "<<"= "<< result << endl; // The result
                validOperator = true;
                break;

            case '/': // If the operator is / the below code will run
                if (n2 != 0) // The code will run if the second number is not 0
				{
                    result = static_cast<float>(n1) / n2; //division
                    cout << "You have selected: Division" << endl;
                	cout << "The result of "<<n1<<" "<<opt<<" "<<n2<<" "<<"= "<< result << endl; // The result
                    validOperator = true;
                } else {
                    cout << "Division by zero is not allowed!" << endl; // If the second is 0
                }
                break;

            default: // If the operrator is not valid 
                cout << "Invalid operator entered! Please try again." << endl;	
                cin.clear();
            	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // this will clear the screen
                break;
        }
        getch();
    }

    return 0;
}

