#pragma once

#include <vector>
#include <string>
#include <exception>
using namespace std;

typedef char* charArrayPtr;


class JumblePuzzle {
	private:

		int puzzleSize;
        string difficulty;
        string hiddenWord;
        char directionArr[4] = {'n', 's', 'e', 'w'};
        char direction; 
        int rowPos; 
        int colPos;
        charArrayPtr* myPuzzle = nullptr;

        /**
		The keyword nullptr denotes the pointer literal. 
		It is a prvalue of type std::nullptr_t. 
		There exist implicit conversions from nullptr to null pointer value of any pointer type and any pointer to member type. Similar conversions exist for any null pointer constant, which includes values of type std::nullptr_t as well as the macro NULL. 
        */
        charArrayPtr* puzzle = nullptr; 
        charArrayPtr* initializeRandomPuzzle(const int& size);
        charArrayPtr* initializePuzzle();



    public:
    	JumblePuzzle(const string& toHide, const string& difficulty);
    	//charArrayPtr* getJumble() const
         int getSize() const;
        int getRowPos() const;
        int getColPos() const;
        char getDirection() const;
        charArrayPtr* getJumble() const; 




};


class BadJumbleException {
	public:
		BadJumbleException(const string& message);
		string& what();
	private:
		string message;
};
