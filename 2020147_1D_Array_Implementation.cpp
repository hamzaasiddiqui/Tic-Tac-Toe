#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <iomanip>

using namespace std;

void display_array(char* arr);
char get_user_input(char* available);
void display_countdown();
char get_comp_input(char* available);
void update_array(char pos, char* grid, bool user_turn);
int is_there_a_winner(char* grid); 
void announce_outcome (int winner);

int main() {
    cout << "--Welcome to TIC TAC TOE (1D Implementation) by 2020147-Hamza Akhtar Siddiqui--" << endl << "Please maximize window for best experience" << endl;
    start: cout << "\nYou(X) will play against the computer(O)\nPlace input by entering number according to the grid!\nYour turn is first!" << endl;

    char grid[9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};

    display_array(grid);

    bool user_turn{true}, game_finished{false};
    int current_pos{0}, moves{0}, winner{0};
    char play_again{'n'};

    do {
        if (user_turn == true) {
            current_pos = get_user_input(grid);

            user_turn = false;
        }
        else {
            display_countdown();

            current_pos = get_comp_input(grid);

            user_turn = true;
        }

        moves++;

        update_array(current_pos, grid, user_turn);

        display_array(grid);

        winner = is_there_a_winner(grid);
        if ( winner > 0) {
            break;
        }

        if (moves == 9) {
            game_finished = true;
        }

    } while (game_finished == false);

    announce_outcome(winner);

    cout << "\nDo you want to play again? (press 'y' for yes or 'n' for no): ";
    
    cin >> play_again;
    
    if (play_again == 'y') {
        goto start;
    }
    else {
    	cout << "Thanks for playing!" << endl;
	}


    return 0;
}

void display_array(char* arr) {
    int c{0};

    cout << endl << setw(85) << "-------------" << endl << setw(74) << "| ";
	
	//loop iterates over each index
    for (int i = 0; i < 9; i++) {
        cout << arr[i] << " | ";

        c++;
		
		//condition to seperate lines of grid
        if (c % 3 == 0) {
            cout << endl << setw(85) << "-------------" << setw(74 )<< endl;
			
			//condition to include '|' before line
            if (i < 8) {
                cout << "| ";
            }
        }
    }
    cout << endl << setw(0);
}

char get_user_input(char* available) {
    char pos{'0'};
    bool valid_pos{false};

    cout << "Enter position to place your mark(X): ";
	
	//loop to ensure correct and available input
    do {
        cin >> pos;
        
        //check to see if place not used before
        for (int i = 0; i < 9; i++) {
            if (pos == available[i]) {
                valid_pos = true;

                break;
            }
        }

        if (!valid_pos) {
            cout << "Invalid position! Please enter available position again: ";
        }
    } while (valid_pos == false);

    return pos;
}

void display_countdown(){
	cout << "Please wait for computer's turn..." << endl;
	
	/*loop iterates 5 times for (5 seconds)
	one second divided into four intervals for aesthetics*/
	for (int i = 5; i > 0; i--) {
		cout << i;
		Sleep(250);
		cout << ".";
		Sleep(250);
		cout << ".";
		Sleep(250);
		cout << ".";
		Sleep(250);
	}
	
	cout << endl;
	
	return;
}

char get_comp_input(char* available) {
	//seeding random
    srand(time(0));

    char pos{'0'};
    bool valid_pos{false};

	//loop to ensure random number is availabele
    do {
        pos = '0' + (rand() % 9);

        for (int i = 0; i < 9; i++) {
            if (pos == available[i]) {
                valid_pos = true;

                break;
            }
        }
    } while (valid_pos == false);

    return pos;
}

void update_array(char pos, char* grid, bool user_turn) {
    for (int i = 0; i < 9; i++) {
    	//if place found in array assign suitable character
        if (pos == grid[i] && user_turn == false) {
            grid[i] = 'X';
            
            return;
        }
        else if (pos == grid[i] && user_turn == true) {
            grid[i] = 'O';
            
            return;
        }
    }
}

int is_there_a_winner(char* grid) {
	//checks to check for 3 consecutive marks for winner
    if (grid[0] == grid[1] && grid[0] == grid[2]) {
        if (grid[0] == 'X') {
            return 1;
        }
        else {
            return 2;
        }
    }
    else if (grid[0] == grid[3] && grid[0] == grid[6]) {
        if (grid[0] == 'X') {
            return 1;
        }
        else {
            return 2;
        }
    }
    else if (grid[3] == grid[4] && grid[3] == grid[5]) {
        if (grid[3] == 'X') {
            return 1;
        }
        else {
            return 2;
        }
    }
    else if (grid[6] == grid[7] && grid[6] == grid[8]) {
        if (grid[6] == 'X') {
            return 1;
        }
        else {
            return 2;
        }
    }
    else if (grid[1] == grid[4] && grid[1] == grid[7]) {
        if (grid[1] == 'X') {
            return 1;
        }
        else {
            return 2;
        }
    }
    else if (grid[2] == grid[5] && grid[2] == grid[8]) {
        if (grid[2] == 'X') {
            return 1;
        }
        else {
            return 2;
        }
    }
    else if (grid[0] == grid[4] && grid[0] == grid[8]) {
        if (grid[0] == 'X') {
            return 1;
        }
        else {
            return 2;
        }
    }
    else if (grid[2] == grid[4] && grid[2] == grid[6]) {
        if (grid[2] == 'X') {
            return 1;
        }
        else {
            return 2;
        }
    }
    //if no winner return 0 (false)
    else {
        return 0;
    }
}

void announce_outcome (int winner) {
	if (winner == 1) {
        cout << "Congratulations! You Won!" << endl;
    }
    else if (winner == 2) {
        cout << "Game Over! You Lost! Computer won!"<< endl;
    }
    else {
        cout << "Game Over! Draw!" << endl;
    }
    
    return;
}
