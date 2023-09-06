/* ENGGEN131 C Project 2022 - Boulder Break */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define CAVE_SIZE 10

// Task One: InitialiseStory
void InitialiseStory(char* paragraph)
{
	// Writing a summery of the story with a total of 193 characters + a few unprintable characters
	// And assigning it to the pointer input, paragraph. Output = none (void)
	// Author: Tamara Land
	
	// Assinging the paragraph
	paragraph = ("An explorer entered a maze cave. To escape he/she must:\n" // 55 Printable characters
		" - not fall into any holes because then she/he dies.\n" // 52 Printable characters
		" - collect as many treasures to get rewarded.\n" // 45 Printable characters
		" - Move boulders while escaping if necessary.\n"); // 45 Printable characters
}

// Task Two: PrintCave
void PrintCave(int cave[CAVE_SIZE][CAVE_SIZE])
{
	// Prints the cave out with the operate characters. 
	// input: a single 2D array containing the cave layout - output: none(void
	// Author: Tamara Land
	
	// For every row
	for (int i = 0; i < CAVE_SIZE; i++) {
		// For every column
		for (int j = 0; j < CAVE_SIZE; j++) {
			
			// If it's E or 0 than print an empty space
			if (cave[i][j] == 0 || cave[i][j] == 'E') {
				printf(" ");
			}
			// If it's 1 print the border
			else if (cave[i][j] == 1) {
				printf("#");
			}
			// Otherwise print the character that's currently being stored.
			else { // Printing the character 's currently stored
				printf("%c", cave[i][j]);
			}
		}
		
		// Go to the next line for a new row.
		printf("\n");
	}
}

// Task Three: InitialiseCave
void InitialiseCave(int cave[CAVE_SIZE][CAVE_SIZE], char* layout)
{
	// Changes a 1D array of string to a 2D array of strings with appropiate characters.
	// Input: layout - 1D string to be converted into a X*X size where X is the cave size.
	//         cave -  the 2D array that needs to be updated with the given layout.
	// Output: none (void). Just updates the cave array as it is a pointer.
	// Author: Tamara Land
	
	// For every row
	for (int i = 0; i < CAVE_SIZE; i++) {
		// For every column
		for (int j = 0; j < CAVE_SIZE; j++) {
			
			// Assigning a space (0) to the current position
			cave[i][j] = 0;
			
			// Overwriting if the current value indicated is a border/obstacle and if it's an E
			if (layout[i*CAVE_SIZE + j] == '1') { // If it's a border
				cave[i][j] = 1;
			}
			
			else if (layout[CAVE_SIZE*i + j] == 'E'){ // If it's an exit
				cave[i][j] = 'E';
			}
		}
	}
}

// As you work on the other tasks, remove the comments below
int IsBorderComplete(int cave[CAVE_SIZE][CAVE_SIZE])
{
	// Checks if the border doesn't contain any spaces.
	// input: the cave that needs to be checked
	// output: returns 0 if the border is not complete and 1 if it is complete
	// Author: Tamara Land
	
	// Checking the first and last row
	for (int i = 0; i < CAVE_SIZE; i++) {
		if (cave[0][i] == 0 || cave[CAVE_SIZE - 1][i] == 0) {
			return 0;
		}
	}
	// Checking the first and last column
	for (int i = 0; i < CAVE_SIZE; i++) {
		if (cave[i][0] == 0 || cave[i][CAVE_SIZE - 1] == 0) {
			return 0;
		}
	}
	// If no spaces found in the border return 1.
	return 1;
}

int IsExitUnique(int cave[CAVE_SIZE][CAVE_SIZE])
{
	// Checks if there's only 1 exit present in the cave
	// Input: the cave that needs to be checked
	// Output: returns 0 if there's 0 or more than 1 exit. Returns 1 if there's only 1 exit present
	// Author: Tamara Land

	// Variable to keep track of the number of exits found
	int numExits = 0;

	// For every row
	for (int i = 0; i < CAVE_SIZE; i++) {
		// For every column
		for (int j = 0; j < CAVE_SIZE; j++) {
			
			// Check if it it an exit and if so add 1 to numExits.
			if (cave[i][j] == 'E')
				numExits++;
		}
	}
	
	// If the number of exits isn't exactly 1 return 0
	if (numExits != 1) {
		return 0;
	}
	// Otherwise return 1.
	return 1;
}

int IsExitAccessible(int cave[CAVE_SIZE][CAVE_SIZE])
{
	// Checks if the exit is on the border but not in the corner
	// Input: the cave that needs to be checked if the exit is reachable
	// Output: returns 0 if the cave is not on the border or in the corner. Otherwise returns 1.
	// Authour: Tamara Land
	
	// For every row to find exit
	for (int i = 0; i < CAVE_SIZE; i++) {
		// For every column to find exit
		for (int j = 0; j < CAVE_SIZE; j++) {
			
			// Finds the exit and checks if it's on the border and not in the top left corner or bottom right corner
			if (cave[i][j] == 'E') {
				// Checking if it's on the border
				if (i == 0 || j == 0 || i == CAVE_SIZE - 1 || j == CAVE_SIZE) {
					
					// Checking if it's in the corner and if so return 0.
					if ((i == CAVE_SIZE - 1 && j == 0) || (i == 0 && j == CAVE_SIZE - 1)
						|| i + j == 0 || i + j == 2 * (CAVE_SIZE - 1)) {
						return 0;
					}
					
					// Otherwise return 1
					return 1;
				}
			}
		}
	}
	// If it isn't on the border at all than return 0.
	return 0;
}

void AddItem(int cave[CAVE_SIZE][CAVE_SIZE], int row, int col, char *element)
{
	// Adds the required element to the cave array
	// Input: cave - an 2D array containing the layout of the cave
	//        row, col - the position that needs to be updated if possible
	//        element - the object that needs to be added if it's possible
	// Output: none (void). Just add the element to the cave if all required conditions are met.
	// Author: Tamara Land
	
	// To check if a players is present
	int player = 0;

	// Checks if the row number and column number are valid
	if (0 <= row && row < CAVE_SIZE && 0 <= row && row < CAVE_SIZE){
		// Checks if the space is empty
		if (cave[row][col] == 0) {
			
			// Adding player
			if (element == "player") {
				// For every row
				for (int i = 0; i < CAVE_SIZE; i++) {
					// For every column to see if there's already a player in the cave.
					for (int j = 0; j < CAVE_SIZE; j++) {
						if (cave[i][j] == 'X') {
							player++;
						}
					}
				}
				// If no players are found add the player to the wanted position.
				if (!player) {
					cave[row][col] = 'X';
				}
			}
			// Adding in the hole
			else if (element == "hole") {
				cave[row][col] = '*';
			}
			// Adding in the treasure
			else if (element == "treasure") {
				cave[row][col] = '+';
			}
			// Adding in the boulder
			else if (element == "boulder") {
				cave[row][col] = 'O';
			}
		}
	}
}

void RotateCave(int cave[CAVE_SIZE][CAVE_SIZE])
{
	// This rotates the cave by 90 degrees clockwise using an algorithm
	// Input: Cave that needs to be rotated
	// Output: none (void). But cave is updated and rotated by 90 degrees clockwise.
	// Author: Tamara Land

	// To store the rotated values so that while rotating, original values don't get overwritten
	int tempCave[CAVE_SIZE][CAVE_SIZE];
	
	// For every row
	for (int i = 0; i < CAVE_SIZE; i++) {
		// For every columns to rotate all the values in the cave
		for (int j = 0; j < CAVE_SIZE; j++) {
			
			// Rotating the cave using: new i = cave_size - 1 - old j, new j = old i
			tempCave[i][j] = cave[CAVE_SIZE - 1 - j][i];
		}
	}
	// Assigning the temporary cave to the actual cave by chaning each position individually
	for (int i = 0; i < CAVE_SIZE; i++) {
		for (int j = 0; j < CAVE_SIZE; j++) {
			cave[i][j] = tempCave[i][j];
		}
	}
}

int MakeMove(int cave[CAVE_SIZE][CAVE_SIZE], char move)
{
	// Moves the player or boulder if there's space in the indicated direction. If the exit is found
	// move the player to the exit, print the cave and return 2. Or if the player fell into a hole 
	// return 1 and print the board with the player removed.
	// Input: cave - 2D array containg the layout of the current cave the player is in.
	//        move - a = left, w = up, s = down, d = right, indicating which direction the player moves
	// Output: none (void). But changes the cave if required.
	// Author: Tamara Land

	// Setting up variables
	// Knowing the return value should be
	int returnVal = 0;
	// For keep track of the number of rotatinon of the cave
	int rotations = 0;
	// For knowing the coordinates of the player
	int x;
	int y;

	// Rotating the cave so that the entered move is always moving up.
	if (move != 'w') {
		RotateCave(cave);
		rotations++;
	}
	if (move == 's' || move == 'd') {
		RotateCave(cave);
		rotations++;
	}
	if (move == 'd') {
		RotateCave(cave);
		rotations++;
	}

	// Locating the player - Checking every row than every column
	for (int i = 0; i < CAVE_SIZE; i++) {
		for (int j = 0; j < CAVE_SIZE; j++) {

			// check if the player is in the current positon
			if (cave[i][j] == 'X') {
				// If so remember the location
				x = i;
				y = j;
			}
		}
	}

	// If it's an empty space or there's a treasure above the player, move the player up
	if (cave[x - 1][y] == 0 || cave[x - 1][y] == '+') {
		cave[x][y] = 0;
		cave[x - 1][y] = 'X';
	}

	// If the player encounters a boulder that can move in that direction
	else if (cave[x - 1][y] == 'O' && (cave[x - 2][y] == 0 || cave[x - 2][y] == '*')) {
		// While there's an empty space above the bolder keep moving it up
		while (cave[x - 2][y] == 0) {
			cave[x - 1][y] = 0;
			cave[x - 2][y] = 'O';
			x--;
		}
		// If there is a hole above the bolder remove both the bolder and the hole
		if (cave[x - 2][y] == '*') {
			cave[x - 1][y] = 0;
			cave[x - 2][y] = 0;
		}
	}
	// If the player reaches a hole
	else if (cave[x - 1][y] == '*') {
		// Remove the player from the current position
		cave[x][y] = 0;
		// Set return value to 1
		returnVal = 1;
	}
	else if (cave[x - 1][y] == 'E') {
		cave[x][y] = 0;
		cave[x - 1][y] = 'X';
		returnVal = 2;

	}

	// Rotating the cave back to its orignal position
	while (rotations % 4 != 0) {
		RotateCave(cave);
		rotations++;
	}

	// Printing the cave if the player lost (fell into hole) or won (found exit)
	if (returnVal != 0) {
		PrintCave(cave);
	}

	// Return the appropiate value
	return returnVal;
}


/***********************************************************/
/***********************************************************/
/******* A SIMPLE MAIN FUNCTION TO TEST YOUR PROGRESS ******/
/***********************************************************/
/***********************************************************/

/* You should add your own tests in here */
int main(void)
{
	int caveA[CAVE_SIZE][CAVE_SIZE] = {
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};
	PrintCave(caveA);
	printf("Complete? %d\n", IsBorderComplete(caveA));
}