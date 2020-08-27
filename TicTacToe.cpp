#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include<iomanip>
#include <string>
#include<fstream>
using namespace std;

class TicTacToe
{
private:
	int **board;		//2D array to make board
	int size;			//size of the grids
public:
	
	
	TicTacToe(int size)		//parameterized constructor
	{
		set_size(size);
		ClearBoard();
	}

	TicTacToe()				//Default constructor
	{
		set_size(3);
		ClearBoard();
	}
	void ClearBoard()		//initializes the board with empty spaces
	{
		int count=1;
		board=new int*[size];
     	    for(int i=0; i<size; i++){
      	        board[i]=new int[size];
      	        for(int j=0; j<size; j++){
      	        	board[i][j]=count++;
       	        }
      	    }
	}

	void set_size(int Size)		//setter to set size
	{
		if(Size>=3 && Size<=5)	//Assigns the value on if it lies between 3 and 5(both inclusive) otherwise it assigns the default value
		{
			size=Size;
		}
		else
		{
			size=3;
		}
	}
	void PrintBoard()		//prints the board
	{
		cout<<"\n\n\n\n    ";
	
		cout<<endl;
		for(int i=0; i<size; i++){
			
			for(int j=0; j<size; j++)	//for vertical lines of the board
			{
				if(board[i][j]==-1)
				{
					cout<<" | "<<setw(3)<<'X';
				}else if(board[i][j]==-2){
					cout<<" | "<<setw(3)<<'0';
				}else{
					cout<<" | "<<setw(3)<<board[i][j];
				}
			}
			cout<<" |"<<endl;
			for(int k=0; k<(size*7)-1; k++)		//for horizontal lines
			{
				cout<<'_';
			}
			cout<<endl;
		}
	
	}


	void save(int turn){
			
            ofstream out("data.txt", ios::app);                                     // if everything clears open a file and write the data 
            SYSTEMTIME login_time;
			GetLocalTime(&login_time);
			out << "\ndate:" << login_time.wDay << "/"<< login_time.wMonth << "/"<< login_time.wYear;
			out<< " Time:" << login_time.wHour << ":"<< login_time.wMinute << ":"<< login_time.wSecond <<endl;
           
            out<<size<<endl;
            for(int i=0; i<size; i++){
                for(int j=0; j<size; j++){
                    
                        out<<board[i][j]<<' ';
                    
                }
            }
            out<<'\n'<<turn;                                 // just to make sure when the game is played again the right person's turns first
            out.close();
               showmenu();     
            }
            
            
		void play_save_game(int game_number){
				ifstream in("data.txt"); 
          		if(!in){                          // if file does not open
               		cout<<"\nNo Saved game exist!"<<endl;
					system("pause");
					showmenu();
				
         	   }
         	   string input,date,names;
         	   int game=1, sizee, count=0;
         	   int ch;
         	   
         	   while(1){
         	   		
                    
                    if(game==game_number){
                   	count=0;
         	   		getline(in,date);
                
               	
                	in>>size;
               		ClearBoard();
                	for(int i=0; i<size; i++){
                  	  for(int j=0; j<size; j++){
                        in>>ch;
                        if(ch==-1 || ch==-2){
                        	count++;
						}
                        board[i][j]=ch;
                   	  }
               		}
               		bool turn;
               		in>>turn;
               		
                    	in.close();
                    if(turn)	
                    	PlayGame('0',count);
                    else{
                    	PlayGame('X',count);
					}	
					}else{
						getline(in,names);
						getline(in,names);
						getline(in,names);
						getline(in,names);
						game++;
					}
				}
			}
	void saved_games(){
			system("cls");
			char ch;
			cout<<"1.Play previous games"<<endl;
			cout<<"\n2.Delete Previous Games"<<endl;
			cout<<"\n\nTo save Game press 0."<<endl;
			cout<<"\n\nEnter your choice: ";
			ch=_getche();
			if(ch=='1'){
				play_save_game(show_previous_games());
			}else if(ch=='2'){
				delete_game(show_previous_games());
			}
		}
		void delete_game(int game){
				ifstream in("data.txt");	//opening source file
				ofstream in2("temp.txt");	//creating temporary file
				int gamech=1, count=0;
				string names;
				while(!in.eof())	//checking end of file occurance
				{
					if(gamech==game){
					
						getline(in,names);
						getline(in,names);
						getline(in,names);
						getline(in,names);
						gamech++;
					}else{
						getline(in,names);
						if(count==0){
							in2<<names<<endl;
							count++;
						}else{
							in2<<'\n'<<names<<endl;
						}
						
						getline(in,names);
						in2<<names<<endl;
						getline(in,names);
						in2<<names<<endl;
						getline(in,names);
						in2<<names;
						gamech++;
					}	
				}

	in.close();	//closing std file
	in2.close();	//closing temp file
	
	remove("data.txt");	//deleting the std file
	rename("temp.txt", "data.txt");	//renaming t
	
			}
			
			
	int show_previous_games(){
		ifstream in("data.txt");
		if(!in ){
			cout<<"\nNo Saved game"<<endl;
			system("pause");
			showmenu();
		}
		string str;
		int i=0;
		system("cls");
            while(  !in.eof()){
            	i++;
            	getline(in,str);
            	cout<<i<<". "<<str<<endl;
            	getline(in,str);
            	getline(in,str);
            	getline(in,str);
            	
			}
			int input;
			while(1){
				cout<<"\nEnter Game number: ";
				cin>>input;
				if(input>=1 && input<=i){
					return input;
				}
			}
	}

	bool placeMarker(int x, int currentplayer)
	{
		int count = 1;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (count==x && board[i][j]!=-2 && board[i][j]!=-1){
					board[i][j]=currentplayer;
					return true;
				}else{
					count++;
				}
					
			}
		
		}
		return false;
	}

	bool checkWin(int currentplayer)		//function to check the winning status
	{
		int count;
		//for rows
		for (int i = 0; i < size; i++)
		{
			count = 0;
			for (int j = 0; j < size; j++)
			{
				if (board[i][j] == currentplayer)
					count++;
			}
			if (count == size)
				return true;
		}
		//for columns
		for (int i = 0; i < size; i++)
		{
			count = 0;
			for (int j = 0; j < size; j++)
			{
				if (board[j][i] == currentplayer)
					count++;
			}
			if (count == size)
				return true;
		}
		//for right diagonal check
		count = 0;
		for (int i = 0; i < size; i++)
		{
			if (board[i][i] == currentplayer)
				count++;
		}

		if (count == size)
			return true;
		//for left diagonal check
		count = 0;
		for (int i = 0, j = size - 1; i < size; i++, j--)
		{
			if (board[i][j] == currentplayer)
				count++;
		}
		if (count == size)
			return true;
		return false;
}

	int box(int x, int y){
		int count = 1;
		for (int i = 0; i < size; i++)
		{	
			for (int j = 0; j < size; j++)
			{
				if (i==x && y==j)
					return count;
					else{
				count++;
				}
			}
			
		}
	}
	bool vs(){
		int count;
		int k,l;
		for (int i = 0; i < size; i++)
		{
			count = 0;
			for (int j = 0; j < size; j++)
			{
				if (board[i][j] ==-2)
					count++;
				else{
					k=i,l=j;
				}	
			}
		}
		if (count == size-1)
		{
			if(placeMarker(box(k,l), -2)){
				return true;
			}
		}
		//for columns
		for (int i = 0; i < size; i++)
		{
			count = 0;
			for (int j = 0; j < size; j++)
			{
				if (board[j][i] ==-2)
					count++;
				else{
					k=j,l=i;
				}	
			}
		}
		if (count == size-1)
		{
			if(placeMarker(box(k,l), -2)){
				return true;
			}
		}
		//for right diagonal check
		count = 0;
		for (int i = 0; i < size; i++)
		{
			if (board[i][i] ==-2)
				count++;
			else{
				k=i,l=i;
			}
		}
		if (count == size-1)
		{
			if(placeMarker(box(k,l), -2)){
				return true;
			}
		}
		//for left diagonal check
		count = 0;
		for (int i = 0, j = size - 1; i < size; i++, j--)
		{
			if (board[i][i] ==-2)
				count++;
			else{
				k=i,l=i;
			}
		}
		if (count == size-1)
		{
			if(placeMarker(box(k,l), -2)){
				return true;
			}
		}
		while(1){
			int xyz=rand()%(size*size)+1;
			if(placeMarker(xyz, -2)){
				return true;
			}
		}
}
	void PlayGame(char currentplayer='X',int turn = 0)				
	{
	//	ClearBoard();
		system("cls");
		char player1='X';		//symbol of first player is X
		char player2 ='0';		//symbol of second player is 0
				//player who is playing now
		int input;
		int mark;
					//integer to store number of turns
		
		while (1)				//while loop to tell whether game continues or not
		{
			takeagain:			//goto statement
				system("cls");
				PrintBoard();
				if(currentplayer=='X'){
					cout << endl << player1<<"'s turn: "<<endl;
				}else{
					cout << endl << player2<<"'s turn: "<<endl;
				}
			
			if(currentplayer=='X'){
				mark=-1;
			}else{
				mark=-2;
			}
			cin>>input;
			if(input==0 ){
				if(currentplayer=='X'){
					save(0);
				}else{
					save(1);
				}
				
			}
			if(!(input>=1 && input<=size*size)){
				goto takeagain;
			}
			if (!placeMarker(input,mark) ) // check for the marker whether it is at the right place or not
			{
				cout << "The space is already occupied!\n";
				system("pause");
				goto takeagain;						//if there is invalid input from one player then there's chanvce to input again for the same player
			}
			else		
			{
				system("cls");
				PrintBoard();
				turn++;		//increment the turns
				if(checkWin(mark) )
				{
					if(currentplayer=='X')		//check for player who won
					{
						cout << "\nThe Game is Over!  " << player1 << " has won!\n\n";
					}
					else
					{
						cout << "\nThe Game is Over!  " << player2 << " has won!\n\n";
					}
					system("pause");
					showmenu();
					//break;
				}
				else if(turn == size*size)		//if turns are equal to the total number of grids then its a tie game
				{
					cout << "It's a tie game!\n";
					showmenu();

					//break;
				}

			}

				//switch players
				if(currentplayer==player1)		//if player1 played this time then its the turn for player 2
				{
					currentplayer=player2;
				}
				else
					currentplayer=player1;
		}
	}
	void vsComp()				
	{
		ClearBoard();
		system("cls");
		char player1='X';		//symbol of first player is X
		char player2 ='0';		//symbol of second player is 0
		char currentplayer=player1;		//player who is playing now
		int input;
		int mark;
		int turn = 0;			//integer to store number of turns
		
		while (1)				//while loop to tell whether game continues or not
		{
			takeagain:			//goto statement
				system("cls");
				PrintBoard();
				cout << endl << player1<<"'s turn: "<<endl;
			if(currentplayer=='X')
			{
				cin>>input;
				if(!(input>=1 && input<=size*size)){
					goto takeagain;
			}
			}else{
				vs();
			}
			if(currentplayer=='X'){
				mark=-1;
			}else{
				mark=-2;
			}
			if (!placeMarker(input,-1) && currentplayer=='X') // check for the marker whether it is at the right place or not
			{
				cout << "The space is already occupied!\n";
				system("pause");
				goto takeagain;						//if there is invalid input from one player then there's chanvce to input again for the same player
			}
			system("cls");
			PrintBoard();
			turn++;		//increment the turns
			if(checkWin(-1) || checkWin(-2) )
			{
				if(currentplayer=='X')		//check for player who won
				{
					cout << "\nThe Game is Over!  " << player1 << " has won!\n\n";
				}
				else
				{
					cout << "\nThe Game is Over! computer has won!\n\n";
				}
				system("pause");
					break;
			}
			else if(turn == size*size)		//if turns are equal to the total number of grids then its a tie game
			{
				cout << "It's a tie game!\n";
				break;
			}
			if(currentplayer==player1)		//if player1 played this time then its the turn for player 2
			{
				currentplayer=player2;
			}
			else{
				currentplayer=player1;
			}
				
			}

				//switch players
			
		}
	
	
	
void instructions()		//function for telling instructions to the player
{
	cout << "Here's how to play the game *TicTacToe*:\n";
	cout << "1.There are two players in this game X and O.\n";
	cout << "2.If X is on the current turn then on the next turn should be 0 and vice versa.\n";
	cout << "3.when any complete row, complete column, right diagonal or left diagonal is filled with the same symbol then the player with that symbol will win the game.\n";
	cout << "4.And when all the boxes are filled and no row,column or diagonal is filled with the same symbol then it will be a tie game.\n";
	
	cout << "Thank you!\n";
}
void showmenu()		//function that shows the main menu
{
	char choice = ' ';
	while (true)
	{
		system("cls");
		system("Color 3F");
		cout << "\n\n\n\n\n\n\t\t\t\tMAIN MENU\n\n";
		cout << "\t\t\tSelect an option\n";
		cout << "\n\t\t\t1.Start Game\n";
		cout << "\t\t\t2.Read Instructions\n";
		cout<<"\t\t\t3.Play vs Computer\n";
		cout << "\t\t\t4.Exit\n";
		cout<<"\t\t\t5.Play or Delete A saved Game\n";
		cout << "\n\t\t\tEnter your choice here:";
		cin >> choice;
		cin.ignore();
		if (choice == '1')	//when user inputs 1 the game will start
		{
			system("cls");
			system("Color 3F");
			SizeAgain:
			system("cls");
			cout << "Enter the size of the grid you want to play!\n\n";
			cout << "3 , 4 or 5\n\n";
			cout << "To Save a Game Enter 0!";
			cout << "\nEnter size : ";
			int Size;
			cin>>Size;
			if(!(Size>=3 && Size<=5))
			{
				goto SizeAgain;
			}
		
		set_size(Size);
		ClearBoard();
			PlayGame();
		

		}else if(choice=='5'){
			saved_games();
		}
		else if (choice == '2') //at input 2 player will go to the instructions
		{
			system("cls");
			system("Color 3F");
			instructions();
			Sleep(1000);
		}else if (choice == '4'){
			break;
		}else if(choice=='3'){
			system("cls");
			system("Color 3F");
			SizeAgain2:
			system("cls");
			cout << "Enter the size of the grid you want to play!\n\n";
			cout << "3 , 4 or 5\n\n";
			cout << "Enter size : ";
			int Size;
			cin>>Size;
			if(!(Size>=3 && Size<=5))
			{
				goto SizeAgain2;
			}
		
		set_size(Size);
		ClearBoard();
		vsComp(); 
		}
		else{
			cout << "\n\t\t\tInvalid input!try again\n";
			system("pause");
		}
		
	}
}

		
};


int main()
{
	srand(time(0));   //83 115
	cout << "\n\n\n\n\n\n\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	cout << "\t\t$$\t\t\t\t\t$$\n";
	cout << "\t\t$$\tWelcome to my Second Game!!!\t$$\n";
	cout << "\t\t$$\t\tTicTacToe\t\t$$\n";
	cout << "\t\t$$\t  Name:Rimsha Ashraf\t\t$$\n";
	cout << "\t\t$$\t  Roll no.BCSF16A539\t\t$$\n";
	cout << "\t\t$$\t\t\t\t\t$$\n";
	cout << "\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n";
	cout << "\n\n\t\t\t***Let's Start The Game***\n\n\n";
	system("Color 3F");
	system("pause");
	system("cls");
	

	char input;	
	TicTacToe game;
	game.showmenu(); 
	
	
	
}
