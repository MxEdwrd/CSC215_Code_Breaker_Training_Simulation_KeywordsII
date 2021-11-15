/*
Author: Max Edward
Email : maxedwar@uat.edu
Assignment Name : Code Breaker Training Simulation - Keywords II
*/

// Include libraries & header files
#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <cctype>

// Website for "CIA" Words: https://spyscape.com/article/spy-glossary

// Namespace Block
using namespace std;

// Variable Block

string agentName = "";
int simCount = 0;
int maxWrong = 10;
int currWrong = 0;
string assignAns = "";
int ending = 0;
string endingAns;

// Function Block

int runSim();

void opening() {
	cout << "\n------------------------------------\n\n";
	cout << "Welcome to Keywords II\n\n";
	cout << "This simulation will test your code breaking skills.\n";
	cout << "Your assignment, if you choose to accept, is to guess the randomly chosen word before you run out of guesses.\n";
	cout << "If you run out of guesses, the simulation will be terminated.\n";
	cout << "Get through three simulation levels and you will be granted further access to the CIA's database.\n\n";
	cout << "Accept the assignment by entering 'yes'. Deny the assignment by entering 'no'.\n\n";
	cout << "------------------------------------\n\n";
}

int main() {
	cout << "Please log in to verify credentials.\n";
	cout << "Enter Last Name: ";
	cin >> agentName;
	cout << "\nWelcome, Agent " << agentName << ".\n";
	Sleep(2000); // Delays output for two seconds. 
	cout << "\nStarting Simulation KeywordsII.exe...\n";
	Sleep(3000); // Delays output for three seconds.

	opening();
	cout << ": ";
	cin >> assignAns;
	// If assignment answer is yes, move to while statement. While the simulation count is less than three, run the simulation.
	if (assignAns == "yes" || assignAns == "Yes" || assignAns == "YES") {
		while (simCount < 3) {
			runSim();
			// If return ending is equal to one, end the simulation.
			if (ending == 1) {
				return 0;
			}
		}
		// After simulation count reaches three, signifying the end of the simulation.
		cout << "Congradulations Agent " << agentName << ", you have completed the Keywords II Simulation.\n";
		cout << "A new assigment will be given to you within the coming weeks. Until then, wait for further instruction.\n";
		cout << "\nConnection Terminated... Goodbye Agent " << agentName << ".\n";
	}
	// If the user types anything but yes after the introduction of the simulation, the simulation will end.
	else {
		cout << "\nConnection Terminated... Goodbye Agent " << agentName << ".\n";
		return 0;
	}
}

int runSim() {
	// Creates a string vector of words to guess.
	vector<string> words;
	words.push_back("AGENT");
	words.push_back("ASSET");
	words.push_back("BURNED");
	words.push_back("CLASSIFIED");
	words.push_back("CIPHER");
	words.push_back("DECRYPTION");
	words.push_back("INFILTRATE");
	words.push_back("INTELLIGENCE");
	words.push_back("OPERATION");
	words.push_back("PATTERN");

	// Randomizes the words using srand function.
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());

	// Sets the wordOne, word to be chosen for current simulation count, equal to the first randomly chosen word. 
	const string wordOne = words[0];
	// Puts the unguessed word as * to allow the user to see what letters are correct and the length of the chosen word.
	string current(wordOne.size(), '*');
	// Creates a string that outputs already used letters to user.
	string used = "";

	// Adds one to simulation count each time the simulation is run.
	simCount++;
	cout << "\n\nSimulation Level: " << simCount << endl;
	Sleep(2000); // Delays output for two seconds.
	if (simCount == 1) {
		cout << "\nWelcome, Agent " << agentName << ", to the Keywords II Code Breaker Simulation. Good Luck." << endl;
	}

	// While the current wrong guesses are less than the maximum allowed guesses and the current word is not equal to the chosen word...
	while ((currWrong < maxWrong) && (current != wordOne)) {
		// Output specific information for the user to view.
		cout << "\nYou have " << (maxWrong - currWrong) << " incorrect guesses left.\n";
		cout << "\nYou've used the following letters: " << used << endl;
		cout << "\nSo far, the word is:\n\n" << current << endl;

		// Define the guess as a character. 
		char guess;
		cout << "\n\nEnter your guess:";
		cin >> guess;
		// Puts character input to upper case as chosen word will be uppercase.
		guess = toupper(guess);
		// If input character has already been input, then ask for a different character.
		while (used.find(guess) != string::npos) {
			cout << "\nYou've already guessed " << guess << endl;
			cout << "Enter your guess:";
			cin >> guess;
			guess = toupper(guess);
		}

		used += guess;

		// If input character has not been input...
		if (wordOne.find(guess) != string::npos) {
			cout << guess << " is in the chosen word.\n";
			// Find the character input within the word and replace the * with the input character.
			for (int i = 0; i < wordOne.length(); ++i)
			{
				if (wordOne[i] == guess) {
					current[i] = guess;
				}
			}
		}
		// Otherwise output incorrect guess and add one to current wrong count.
		else {
			cout << guess << " is not in the chosen word.\n";
			++currWrong;
		}
	}

	// Losing ending - guesses ran out.
	if (currWrong == maxWrong) {
		cout << "\nYou failed to crack the chosen word.";
		cout << "\nThe word was " << wordOne << endl;
		cout << "\nConnection Terminated... Goodbye Agent " << agentName << ".\n";
		ending = 1;
		return ending;
	}
	// Wining ending - word has been correctly guessed.
	else {
		cout << "\nYou've correctly cracked the chosen word.";
		cout << "\nThe word was " << wordOne << ".\n\n";
		endingAns = "";
		// If the simulation count is less than three, ask the user to continue. If yes, then go to new simulation level. If no, then end simulation. If anything else restate question.
		while (endingAns == "" && simCount < 3) {
			cout << "Do you wish to continue, Agent " << agentName << "?\n\n";
			cout << ": ";
			cin >> endingAns;
			if (endingAns == "yes" || endingAns == "Yes" || endingAns == "YES") {
				ending = 0;
				return ending;
			}
			if (endingAns == "no" || endingAns == "No" || endingAns == "NO") {
				cout << "\nConnection Terminated... Goodbye Agent " << agentName << ".\n";
				ending = 1;
				return ending;
			}
			else {
				cout << "Please answer the question.\n";
			}
		}
		return 0;
	}
}