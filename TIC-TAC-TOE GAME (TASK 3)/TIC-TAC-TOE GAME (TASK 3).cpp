#include <iostream>
#include <cctype>
#include <cstdlib>
#include <limits>
// Header file
using namespace std;  
//C++ directive that tells the compiler to make all the symbols (functions, classes, and objects)
char square[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
 // Array for the Game Board
int checkwin() 
/*This function checks the current state of the game and returns:
1 if a player has won.
0 if the game is a draw (no empty positions left).
-1 if the game is still ongoing.*/
 {
//It also checks all possible win conditions for both players and handles the case where the board is full with no winner.
    if (square[1] == square[2] && square[2] == square[3]) return 1;
    else if (square[4] == square[5] && square[5] == square[6]) return 1;
    else if (square[7] == square[8] && square[8] == square[9]) return 1;
    else if (square[1] == square[4] && square[4] == square[7]) return 1;
    else if (square[2] == square[5] && square[5] == square[8]) return 1;
    else if (square[3] == square[6] && square[6] == square[9]) return 1;
    else if (square[1] == square[5] && square[5] == square[9]) return 1;
    else if (square[3] == square[5] && square[5] == square[7]) return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' &&
             square[7] != '7' && square[8] != '8' && square[9] != '9') return 0;
    else return -1;
}
void board() 
//This function clears the console screen and displays the current state of the game board with player marks ('X' and 'O').
 {
    system("cls"); 
	//Clear the screen
    cout << "\n\n\tTic Tac Toe\n\n";
    cout << "Player 1 (X)  -  Player 2 (O)\n\n\n";

    cout << "     |     |     \n";
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << " \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << " \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << " \n";
    cout << "     |     |     \n\n";
}

int main() 
//This is the main part of the program where the game logic resides.
 {
    int player = 1, i, choice; 
    char mark, end; 
	// Variable declaration
    do  
	//loop to keep the game running until there's a winner or a draw.
	{
        board(); 
		//displays the current board using the board() function.
        player = (player % 2) ? 1 : 2; 
		//Alternates between Player 1 ('X') and Player 2 ('O').
        cout << "Player " << player << ", enter a number:  "; 
		// ask  player to input their move as a number (1-9) on the board.
        while (1) 
		/*This loop is responsible for getting valid input from the current player for their move. 
		It runs until the player enters a valid input*/
		{
            char input[3];
            cin >> input; 
			// reads the user's input.
            if (isdigit(input[0]) && input[1] == '\0') 
            /*checks if the first character of the input is a digit (0-9) and the second character 
			is the null terminator ('\0'), which indicates the end of the string. This validates that
			 the input is a single digit.*/
			{
                choice = atoi(input);
                break;
            } else {
                cout << "Invalid input. Enter a number (1-9): "; // If the input is not valid
            }
        }
        mark = (player == 1) ? 'X' : 'O'; 
		/*This line determines the current player's mark ('X' for Player 1 and 'O' for Player 2) 
		based on the value of the player variable.*/

        if (choice >= 1 && choice <= 9 && square[choice] == '0' + choice) 
		//This block checks whether the player's move is valid.
            square[choice] = mark;
		/*It verifies that choice is within the range of 1 to 9 and that the 
		corresponding square on the game board is still unoccupied*/
        else {
            cout << "Invalid move "; 
			//If the move is invalid, it displays "Invalid move,"
            player--;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
			//clears any remaining input from the input buffer
        }
        i = checkwin(); 
		//After each valid move, the code checks if there is a winner or if the game is a draw by calling the checkwin() function.
        player++; 
		//It then increments the player variable to switch to the next player's turn.
    } while (i == -1); 
	//The loop continues until there is a winner (i == 1) or the game is a draw (i == 0).
    board(); 
	//After the game ends, it displays the final state of the game board using the board() function.
    if (i == 1) cout << "==>Player " << ((player == 1) ? 2 : 1) << " wins!" << endl;
    //It then checks the value of i to determine the outcome (win or draw) and prints an appropriate message.
    else cout << "==>Game draw" << endl;
    cout << "Do you want to play again? (1 for yes, 0 for no): "; // ask player if they want to play again and handles their input.
     while (true)
	 //This loop handles the user's choice to play again or exit the program.
	  {
        cin >> end; 
        //It reads the user's input into the end variable.
        if (end == '1') 
		//If the user enters '1', it resets the game board by setting all squares to their initial values and then calls main() to start a new game.
		{
            for (int j = 1; j <= 9; j++)
                square[j] = '0' + j;
            main();
        } else if (end == '0') {
            cout << "Goodbye!" << endl; //If the user enters '0', it prints "Goodbye!" and returns 1, which exits the program.
            return 1; // Exit the program
        } else {
            cout << "Invalid input. \nEnter '1' to play again or '0' to exit: "; //If the user enters an invalid input, it displays an error message
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            //clears the input buffer, and prompts the user again.


        }
    }
}
