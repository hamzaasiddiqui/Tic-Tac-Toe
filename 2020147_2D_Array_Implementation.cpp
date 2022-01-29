#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <iomanip>

using namespace std;

void display_array(char grid[3][3]);
char get_user_input(char available[3][3]);
void display_countdown();
char get_comp_input(char available[3][3]);
void update_array(char pos, char grid[3][3], bool user_turn);
int is_there_a_winner (char grid[3][3]);
void announce_outcome (int winner);


int main () {
    cout << "--Welcome to Tic Tac Toe (2D Implementation) by 2020147-Hamza Akhtar Siddiqui--" << endl << "Please maximize window for best experience" << endl;
    start: cout << "\nYou (X) will play against the computer (O)!\nPlace input by entering number according to the grid!\nYour turn is first!" << endl;

    char grid[3][3] = {{'0', '1', '2'}, {'3', '4', '5'}, {'6', '7', '8'}};

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
        if (winner > 0) {
            break;
        }

        if (moves == 9) {
            game_finished = true;
        }

    } while (game_finished == false);
    
    announce_outcome(winner);

    cout << "Do you want to play again? (press y for yes or n for no): ";
    
    cin >> play_again;
    
    if (play_again == 'y') {
        goto start;
    }
    else {
    	cout << "Thanks for playing!" << endl;
	}

    return 0;
}

void display_array (char grid[3][3]) {
	cout << endl;
	
	//control loop for rows
    for (int r = 0; r < 3; r++) {
        cout << setw(85) << "-------------" << endl << setw(74) << "| ";
		
		//control loop for columns
        for (int c = 0; c < 3; c++) {
            cout << grid[r][c] << " | ";
        }

        cout << endl << setw(74);
    }

    cout << setw(85) << "-------------" << endl << endl << setw(0);
}

char get_user_input(char available[3][3]) {
    char pos{'0'};
    bool valid_pos{false};

    cout << "Enter position to pace your mark(X): ";
	
	//loop to ensure correct and available place
    do {
        cin >> pos;
	
		//loops to check if place not used already
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                if (pos == available[r][c]) {
                    valid_pos = true;
                }
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
	
	/*loop iterates 5 times (for 5 seconds)
	1 second divided into 4 parts for aesthetics*/
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

char get_comp_input(char available[3][3]) {
	//seeding random
    srand(time(0));

    char pos{'0'};
    bool valid_pos{false};
	
	//loop to ensure randome number is available
    do {
        pos = '0' + (rand() % 9);

        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                if (pos == available[r][c]) {
                    valid_pos = true;
                }
            }
        }
    } while (valid_pos == false);

    return pos;
}

void update_array(char pos, char grid[3][3], bool user_turn) {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
        	//if position in grid assign corresponding mark
            if (pos == grid [r][c] && user_turn == false) {
                grid[r][c] ='X';
            }
            else if (pos == grid[r][c] && user_turn == true) {
                grid[r][c] = 'O';
            }
        }
    }
}

int is_there_a_winner (char grid[3][3]) {
	//to check winner in columns
    for (int c = 0; c < 3; c++) {
        if (grid[0][c] == grid[1][c] && grid[0][c] == grid[2][c]) {
            if (grid[0][c] == 'X') {
                return 1;
            }
            else {
                return 2;
            }
        }
    }
	
	//to check winner in rows
    for (int r = 0; r < 3; r++) {
        if (grid[r][0] == grid[r][1] && grid[r][0] == grid[r][2]) {
            if (grid[r][0] == 'X') {
                return 1;
            }
            else {
                return 2;
            }
        }
    }
	
	//to check winner in diagonals
    if (grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2]) {
        if (grid[0][0] == 'X') {
            return 1;
        }
        else {
            return 2;
        }
    }

    if (grid[2][0] == grid[1][1] && grid[2][0] == grid[0][2]) {
        if (grid[0][0] == 'X') {
            return 1;
        }
        else {
            return 2;
        }
    }

	//if no winner return 0 (false)
    return 0;
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
