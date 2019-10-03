//To Do - crashes on second iteration. Figure out why

//Thomas's Code ###
#include <iostream>
#include <string>
#include <cctype>


using namespace std;

string englishtoMorse(string, string[]);
string morsetoEnglish(string);

char alphabet[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' , 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U','V', 'W', 'X', 'Y', 'Z' };
string morse[26] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };

int main()
{
	string text, morsecode;
	char choice;
	char repeat = 'y';

	while (repeat == 'y')
	{
		cout << "Please Select 1 for encoding the message into Morse.\nOr Select 2 to have a message decoded into English: " << endl;
		cin >> choice;

		if (choice == '1')
		{
			cout << "Please only use English Characters as special characters will not be translated.\n";
			cout << "Enter text and seperated words by using space / space\n";
			cin.ignore();
			getline(cin, text);
			cout << "Text entered: " << text << endl;
			cout << "Morse Code: " << englishtoMorse(text, morse) << endl;
		}
		else if (choice == '2')
		{
			cout << "Please enter a Morse code message. Leave one (1) space between letters and sperate words by using space / space i.e (...---... / ...---...)" << endl;
			cin.ignore();
			getline(cin, morsecode);
			cout << "Morse Code Message: " << morsecode << endl;
			cout << "English Message: " << morsetoEnglish(morsecode) << endl;
		}
		cout << "Do you wish to repeat the process?\n Enter y to repeat. Any other key will exit the program.\n" << endl;
		cin >> repeat;
		cout << " " << endl;
	}
	return 0;
}

string englishtoMorse(string text, string morse[])
{
	string morsevalue;
	string spaceBetweenletters = " ";
	string spaceBetweenWords = "/ "; //Space between letters will add the space before words sticks the slash in.

	for (int counter = 0; text[counter]; counter++)
	{
		if (text[counter] != ' ') // if words to not encounter a space.
		{
			text[counter] = toupper(text[counter]); // will make letters upper case. No special code for lower or upper
			morsevalue = spaceBetweenletters += morse[text[counter] - 'A'] + " ";
		}
		else
		{
			spaceBetweenletters += spaceBetweenWords;
		}
	}
	return morsevalue;
}
//Amp's Code ###

string morsetoEnglish(string morsecode) {

	//mid value, used to hold "letters" during translation
	string outputletter = "";
	//Final string that gets printed
	string resultletter = "";


	//length of input value
	int morseLength = morsecode.length();
	//array of char values, what the input value is broken into
	char inputMorseArray[2048];
	//Copy input value into array
	strcpy_s(inputMorseArray, morsecode.c_str());

	//Big Papa loop, runs until end of input value string
		for (int x = 0; x <= morseLength; x++) {
			//Is a character?
			if (inputMorseArray[x] != 0 && inputMorseArray[x] != ' ' && inputMorseArray[x] != '/') {
				outputletter += inputMorseArray[x];
			}
			//End?
			if (inputMorseArray[x] == ' ' || inputMorseArray[x] == 0) {

					//Little baby loop, runs the checks to see what the letters match up with
					for (int k = 0; k < 26; k++) {
						if (outputletter == morse[k]) {
							resultletter += alphabet[k];
						}
					}	
					outputletter = "";
			}
			if (inputMorseArray[x] == '/') {
				resultletter += " ";
			}
		}
	return resultletter;

}

