#include "jumble.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std; 


BadJumbleException::BadJumbleException(const string& m) : message(m) {}
string& BadJumbleException::what() { return message; }

JumblePuzzle::JumblePuzzle(const string& toHide, const string& setDifficulty){

 	bool isValidDifficulty = setDifficulty == "easy" || setDifficulty == "medium" || setDifficulty == "hard";
	bool isValidHiddenWord = toHide.length() > 0; 

	if(isValidDifficulty && isValidHiddenWord){ 
		this->hiddenWord = toHide; 	
		//set our difficulty
		this->difficulty = setDifficulty;
		cout << this->hiddenWord << endl;  
		cout << this->difficulty << endl;

		//now set the hidden size
		if(this->difficulty == "easy"){
			this->puzzleSize = this->hiddenWord.length() * 2; 
			cout << "set puzzle size for easy difficulty: " << this->hiddenWord.length() * 2 << endl; 
			this->myPuzzle = initializePuzzle();
		}else if(this->difficulty == "medium"){
			this->puzzleSize = this->hiddenWord.length() * 3; 
			cout << "set puzzle size for medium difficulty: " << this->hiddenWord.length() * 3 << endl; 
			this->myPuzzle = initializePuzzle();
		}else if(this->difficulty == "hard"){
			this->puzzleSize = this->hiddenWord.length() * 4; 
			cout << "set puzzle size for hard difficulty: " << this->hiddenWord.length() * 4 << endl; 
			this->myPuzzle = initializePuzzle();
		}
 
	}else if(!isValidDifficulty){
		 throw BadJumbleException("\nInvalid difficulty - please enter 'easy', 'medium', 'hard' or extreme (case sensitive)\n");
	}else if(!isValidHiddenWord){
		 throw BadJumbleException("\nInvalid word to hide - please enter another word.\n");
	}

}


charArrayPtr* JumblePuzzle::initializeRandomPuzzle(const int& size) {
    charArrayPtr* randomPuzzle = new charArrayPtr[size];
    srand(time(NULL));
    /**
    cout << "================================" << endl; 
    cout << "Word puzzle" << endl; 
    cout << "================================" << endl;
    */
    for (int i = 0; i < size; i++) {
        randomPuzzle[i] = new char[size];
        for (int j = 0; j < size; j++) {
                randomPuzzle[i][j] = 'a' + rand() % 26; // Select random letter using ASCI
        }
        //cout << randomPuzzle[i] << endl; 
    }
    return randomPuzzle;
}



charArrayPtr* JumblePuzzle::initializePuzzle(){
	charArrayPtr* completePuzzle = initializeRandomPuzzle(this->puzzleSize);

	//this code is really bad but its the only way I could think of placing it on the right direction

	//generate row and col bigger then hidden word length	

	//if its south gen a row thats less then or equal to the puzzle size mimus the word length

	//if its east its has to be a col thats less then or equal to the puzzleSize - word length

	//if its west it has to be col thats geater then or equal to word length

	direction = directionArr[rand() % 4]; 

	this->rowPos = rand() % (puzzleSize);
	this->colPos = rand() % (puzzleSize); 

	int row, col, hiddenWordPlaceIndex; 

	//if its north gen a row that's bigger then the word
	if(direction == 'n'){
		while(this->rowPos < hiddenWord.length()){
			this->rowPos = rand() % (puzzleSize);
		}

		/**
		cout << "THIS is for north: " << endl;  
		cout << this->rowPos << endl; 
		cout << this->colPos << endl; 
		*/

		row = this->rowPos; 
		col = this->colPos; 

		hiddenWordPlaceIndex = 0; 

		while(row >= 0 && hiddenWordPlaceIndex < hiddenWord.length()){
		completePuzzle[row--][col] = hiddenWord[hiddenWordPlaceIndex++]; 
		//cout << "placed letter: " << completePuzzle[3][4]; 
			if(hiddenWordPlaceIndex == hiddenWord.length()){
				//placeWord = true; 
			}
		}

	}else if(direction == 's'){

		//if its south gen a row thats less then or equal to the puzzle size mimus the word length
		while(this->rowPos > hiddenWord.length()){
			this->rowPos = rand() % (puzzleSize);
		}

		cout << "THIS is for south: " << endl;  
		cout << this->rowPos << endl; 
		cout << this->colPos << endl; 

		row = this->rowPos; 
		col = this->colPos; 

		hiddenWordPlaceIndex = 0; 

		while(row >= 0 && hiddenWordPlaceIndex < hiddenWord.length()){
		completePuzzle[row++][col] = hiddenWord[hiddenWordPlaceIndex++]; 
		//cout << "placed letter: " << completePuzzle[3][4]; 
			if(hiddenWordPlaceIndex == hiddenWord.length()){
				//placeWord = true; 
			}
		}

	}else if(direction == 'e'){

		//if its east its has to be a col thats less then or equal to the puzzleSize - word length
		while(this->colPos > hiddenWord.length()){
			this->colPos = rand() % (puzzleSize);
		}
		/**
		cout << "THIS is for east: " << endl;  
		cout << this->rowPos << endl; 
		cout << this->colPos << endl; 
		*/

		row = this->rowPos; 
		col = this->colPos; 

		hiddenWordPlaceIndex = 0; 

		while(row >= 0 && hiddenWordPlaceIndex < hiddenWord.length()){
		completePuzzle[row][col++] = hiddenWord[hiddenWordPlaceIndex++]; 
		//cout << "placed letter: " << completePuzzle[3][4]; 
			if(hiddenWordPlaceIndex == hiddenWord.length()){
				//placeWord = true; 
			}
		}


	}else if(direction == 'w'){

		//if its east its has to be a col thats less then or equal to the puzzleSize - word length
		while(this->colPos < hiddenWord.length()){
			this->colPos = rand() % (puzzleSize);
		}

		/**
		cout << "THIS is for west: " << endl;  
		cout << this->rowPos << endl; 
		cout << this->colPos << endl; 
		*/
		row = this->rowPos; 
		col = this->colPos; 

		hiddenWordPlaceIndex = 0; 

		while(row >= 0 && hiddenWordPlaceIndex < hiddenWord.length()){
		completePuzzle[row][col--] = hiddenWord[hiddenWordPlaceIndex++]; 
		//cout << "placed letter: " << completePuzzle[3][4]; 
			if(hiddenWordPlaceIndex == hiddenWord.length()){
				//placeWord = true; 
			}
		}


	}


	/**

	for (int i = 0; i < this->puzzleSize; i++) {
        for (int j = 0; j < this->puzzleSize; j++) {
                //completePuzzle[i][j] = 'a' + rand() % 26; // Select random letter using ASCI
        }
        cout << completePuzzle[i] << endl; 
    }

    */

    return completePuzzle; 
}


charArrayPtr* JumblePuzzle::getJumble() const {
	charArrayPtr* tempPuzzle = new charArrayPtr[this->puzzleSize];
    for (int i = 0; i < this->puzzleSize; i++) {
        tempPuzzle[i] = new char[this->puzzleSize];
        for (int j = 0; j < this->puzzleSize; j++) {
            tempPuzzle[i][j] = this->myPuzzle[i][j];
        }
    }
    return tempPuzzle;

}

int JumblePuzzle::getSize() const {
    return this->puzzleSize;
}

int JumblePuzzle::getRowPos() const {
    return this->rowPos;
}

int JumblePuzzle::getColPos() const {
    return this->colPos;
}

char JumblePuzzle::getDirection() const {
    return this->direction;
}







	//check the difficulty

	//this is how we get the array 2D , 
	/**
	typedef char* charArrayPtr; 

	charArrayPtr* randomPuzzle = new charArrayPtr[10]; 

	for(int i = 0; i < 10; i++){
		randomPuzzle[i] = new char[30];
		 for (int j = 0; j < 10; j++) {
            randomPuzzle[i][j] = 'a' + rand() % 26; 
        }
        cout << randomPuzzle[i] << endl; 
	}

	*/