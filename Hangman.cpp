#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;

struct Game
{
	char word[20];
};

string randomword()
{
	string word;
	int x = rand() % 550;
	ifstream in("words.txt");
	for (int i = 0; i<x; i++)
	{
		in >> word;
	}

	return word;

}
void DisplayMan() {

	cout << "_______" << endl;
	cout << "|      " << endl;
	cout << "|      " << endl;
	cout << "|      " << endl;
	cout << "|      " << endl;
	cout << "|      " << endl;
	cout << "_______" << endl << endl;
}
void DisplayMan0() {

	cout << "_______" << endl;
	cout << "|     |" << endl;
	cout << "|   (- -) " << endl;
	cout << "|      " << endl;
	cout << "|      " << endl;
	cout << "|      " << endl;
	cout << "_______" << endl << endl;
}
void DisplayMan1() {

	cout << "_______   " << endl;
	cout << "|     |   " << endl;
	cout << "|   (-_-)" << endl;
	cout << "|         " << endl;
	cout << "|         " << endl;
	cout << "|         " << endl;
	cout << "_______" << endl << endl;
}
void DisplayMan2() {

	cout << "_______  " << endl;
	cout << "|     |  " << endl;
	cout << "|   (-_-)" << endl;
	cout << "|     |  " << endl;
	cout << "|        " << endl;
	cout << "|        " << endl;
	cout << "_______" << endl << endl;
}
void DisplayMan3() {

	cout << "_______  " << endl;
	cout << "|     |  " << endl;
	cout << "|   (-_-)" << endl;
	cout << "|    /|  " << endl;
	cout << "|        " << endl;
	cout << "|        " << endl;
	cout << "_______" << endl << endl;
}
void DisplayMan4() {
	cout << "_______  " << endl;
	cout << "|     |  " << endl;
	cout << "|   (-_-)" << endl;
	cout << "|    /|\\" << endl;
	cout << "|        " << endl;
	cout << "|        " << endl;
	cout << "_______" << endl << endl;
}
void DisplayMan5() {
	cout << "_______  " << endl;
	cout << "|     |  " << endl;
	cout << "|   (-_-)" << endl;
	cout << "|    /|\\" << endl;
	cout << "|     |  " << endl;
	cout << "|        " << endl;
	cout << "_______" << endl << endl;

}
void DisplayMan6() {
	cout << "_______" << endl;
	cout << "|     |  " << endl;
	cout << "|   (-_-)" << endl;
	cout << "|    /|\\" << endl;
	cout << "|     |  " << endl;
	cout << "|    / \\  " << endl;
	cout << "_______" << endl << endl;

}
void DisplayMan7() {
	cout << "_______  " << endl;
	cout << "|       " << endl;
	cout << "|   (-_-)" << endl;
	cout << "|    /|\\ " << endl;
	cout << "|     |  " << endl;
	cout << "|    / \\" << endl;
	cout << "_______" << endl << endl;
}
int playgame() {
	string word;
	word = randomword();
	string display = word;
	int wrong_guess = 0;
	int x = 0;
	cout << "Here's your word:" << endl;
	for (int i = 0; i<display.length(); i++)
		display[i] = '*';
	DisplayMan();
	Game WORD;
	string Originalword = word;
	string Userguess;
	string status;
	while (x<word.length())
	{
		cout << display << ":\n\n";
		cout << "Wrong guess=" << wrong_guess << "\n\n";
		cout << "Enter a letter in word:";
		char response = ' ';
		cin >> response;
		Userguess = Userguess + response;
		bool rightguess = false;
		bool sameguess = false;
		for (int i = 0; i<word.length(); i++)
			if (response == word[i])
			if (display[i] == word[i])
			{
				cout << response << " is already in the word.\n";
				Sleep(1000);
				sameguess = true;
				break;
			}
			else
			{
				display[i] = word[i];
				x++;
				rightguess = true;
			}
			if (sameguess)
			continue;
			if (rightguess) 
			{
				cout << "\nGood guess!\n\n";
				Sleep(1000);
			}
			if (!rightguess)
			{
				wrong_guess++;
				cout << "\nYou entered a wrong letter!\n\n";
				Sleep(1000);
			}
			if (wrong_guess == 0) 
			{
				system("cls");
				system("Color 2B");
				DisplayMan();
			}
			if (wrong_guess == 1) 
			{
				system("cls");
				system("Color 3C");
				DisplayMan0();
			}
			if (wrong_guess == 2) 
			{
				system("cls");
				system("Color 4D");
				DisplayMan1();
			}
			if (wrong_guess == 3) 
			{
				system("cls");
				system("Color 5E");
				DisplayMan2();
			}

			if (wrong_guess == 4) 
			{
				system("cls");
				system("Color 6F");
				DisplayMan3();
			}
			if (wrong_guess == 5) 
			{
				system("cls");
				DisplayMan4();
			}
			if (wrong_guess == 6) 
			{
				system("cls");
				system("Color A1");
				DisplayMan5();
			}
			if (wrong_guess == 7)
			{
				system("cls");
				system("Color B2");
				DisplayMan6();
				cout << "\n";
				cout << "\t\t\tYou lost!" << endl;
				cout << "\t\t\tGAME OVER" << endl;
				cout << "Word was:" << word << "." << endl;
				cout << "Your entered guess was : " << Userguess << endl;
				status = "lost";
				cout << endl;
				Sleep(1000);
			}

			else if (word == display)
			{
				system("cls");
				system("Color C3");
				DisplayMan7();
				cout << "\t\t\tYou won!" << endl;
				cout << "Word was:" << word << "." << endl;
				cout << "Your entered guess was : " << Userguess << endl;
				status = "Won";
				cout << endl;
				Sleep(1000);
			}
			if (status != "")
			{	
				ofstream out("record.bin", ios::binary | ios::app);
				int length = sizeof(char)*Originalword.length();
				out.write((char*)&length, sizeof(int));
				out.write(Originalword.c_str(), length);
				length = sizeof(char)*Userguess.length();
				out.write((char*)&length, sizeof(int));
				out.write(Userguess.c_str(), length);
				length = sizeof(char)*status.length();
				out.write((char*)&length, sizeof(int));
				out.write(status.c_str(), length);
				out.close();
				status = "";
				break;
			}
	}
	return wrong_guess;
}
void previous_record()
{
	ifstream in("record.bin", ios::binary);
	cout << "Previous Record\n";
	cout << "************************************************************************\n";
	if (in.is_open()){
		cout << "Word\t\tGuess\t\tStatus\t\t\n" << endl;
		in.seekg(0, ios::end);
		int sizeOfFile = in.tellg();
		in.seekg(0);
		int length;
		while (in.tellg() < sizeOfFile){
			for (int i = 0; i < 3; ++i){
				in.read((char*)&length, sizeof(int));
				char *WORD = new char[length + 1];//length+1 for the \0 character
				in.read((char*)WORD, length);
				WORD[length] = '\0';
				cout << WORD << '\t';
				delete[] WORD;
			}
			cout << endl;
		}
		in.close();
	}
	else{
		cout << "No games played yet" << endl;
	}
}
void game() {
	string name;
	cout << "\n\n\n\n\n\n\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	cout << "\t\t$$\t\t\t\t\t$$\n";
	cout << "\t\t$$\tWelcome to my first Game!!!\t$$\n";
	cout << "\t\t$$\t\tHANGMAN\t\t\t$$\n";
	cout << "\t\t$$\t  Name:Rimsha Ashraf\t\t$$\n";
	cout << "\t\t$$\t  Roll no.BCSF16A539\t\t$$\n";
	cout << "\t\t$$\t\t\t\t\t$$\n";
	cout << "\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n";
	cout << "\n\n\t\t\t***Let's Start The Game***\n";
	cout << "\t\t\t\t\tEnter Your Name Here:";
	cin >> name;
	system("cls");
	system("Color D4");
}
void instructions() {
	cout << "Here's how to play the game *HANGMAN*:\n";
	cout << "1.You've to guess a word hidden behind ******.\n";
	cout << "2.Type in the letters you wish to guess.Careful! Wrong letters will lose the chances.\n";
	cout << "3.If you guess the hidden word correctly you'll win the game!\n";
	cout << "4.With every wrong guess a part of hangman will be drawn.\n";
	cout << "5.And If You do seven wrong guesses hangman will be hung and you'll lose the game.\n";
}
void showmenu() {
	char choice = ' ';
	while (true)
	{
		system("cls");
		system("Color 1A");
		cout << "\n\n\n\n\n\n\t\t\t\tMAIN MENU\n\n";
		cout << "\t\t\tSelect an option\n";
		cout << "\t\t\t1.Start Game\n";
		cout << "\t\t\t2.Read Instructions\n";
		cout << "\t\t\t3.Previous record\n";
		cout << "\t\t\t4.Exit\n\n";
		cout << "\t\t\tEnter your choice here:";
		cin >> choice;
		cin.ignore();
		if (choice == '1') 
		{
			system("cls");
			system("Color E5");
			playgame();

		}
		else if (choice == '2') 
		{
			system("cls");
			system("Color F6");
			instructions();
			Sleep(1000);
		}

		else if (choice == '3')
		{
			system("cls");
			system("Color 4D");
			previous_record();
			Sleep(1000);
		}
		else if (choice == '4')
			break;
		else
			cout << "\n\t\t\tInvalid input!try again\n";
			system("pause");
	}
}
int main()
{
	system("Color 3C");
	srand(time(0));
	game();
	showmenu();
	return 0;
}


