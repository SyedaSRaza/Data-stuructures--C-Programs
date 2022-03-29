#include<iostream>
#include<conio.h>
#include<dos.h>  //handling, intercepts, producing, sound, date and time functions
#include <windows.h> // Contains declarations for all functions in windows API and all common programmers.Defines a large number of Windows specific functions
#include <time.h> // Gets and manipulates time and date information

//DEFINE CONSTANTS
#define SCREEN_WIDTH 90 //screen width
#define SCREEN_HEIGHT 26 //screen height
#define WIN_WIDTH 70  //windows width

using namespace std; 
 
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // Retrieves a handle to the specified standard device (standard input, standard output, or standard error).(HANDLES OBJECT)

//GETStdHandle() retrieves a handle to the specified standard device here: STD_OUTPUT_HANDLE The standard output device. Initially, this is the active console screen buffer

COORD CursorPosition; //Set the cursor position. 

// Global variables

int enemyY[3];
int enemyX[3];
int enemyFlag[3];
char car[4][4] = { ' ','±','±',' ',    //car 
					'±','±','±','±', 
					' ','±','±',' ',
					'±','±','±','±' }; 
					
int carPos = WIN_WIDTH/2;    //The position of car = windows width/2
int score = 0; 

//GotoXY is used to move the cursor on the console screen. It positions the cursor at (X,Y), X in horizontal, Y in vertical direction relative to the origin of your console window.
//So, if you put 'gotoXY(5,7);' before the statement 'Cout<<'Hello world';' , it will display "Hello World" 5 digits to the right and 7 digits to the bottom of your console origion/corner.

void gotoxy(int x, int y){
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition); //Sets the cursor position in the specified console screen buffer
}

void setcursor(bool visible, DWORD size) { //t's defined in <windows.h>.Is a 32-bit unsigned integer
	if(size == 0)
		size = 20;	
	
	CONSOLE_CURSOR_INFO lpCursor;	//Contains information about the console cursor.
	lpCursor.bVisible = visible; //The visibility of the cursor.
	lpCursor.dwSize = size; //The percentage of the character cell that is filled by the cursor.
	SetConsoleCursorInfo(console,&lpCursor);  //Sets the size and visibility of the cursor for the specified console screen buffer.	
}

//Draw the race track for game
void drawBorder(){  
	for(int i=0; i<SCREEN_HEIGHT; i++){
		for(int j=0; j<17; j++){
			gotoxy(0+j,i); cout<<"±";
			gotoxy(WIN_WIDTH-j,i); cout<<"±";
		}
	} 
	for(int i=0; i<SCREEN_HEIGHT; i++){
		gotoxy(SCREEN_WIDTH,i); cout<<"±";
	} 
}

//Generating enemy function
void genEnemy(int ind){
	//to generate a random number between 0 and 33 and add 17 to it: = 50
	enemyX[ind] = 17 + rand()%(33);  //the rand() function is used in C/C++ to generate random numbers in the range [0, RAND_MAX). 
	
}

//Draw enemy function 
void drawEnemy(int ind){
	if( enemyFlag[ind] == true ){
		gotoxy(enemyX[ind], enemyY[ind]);   cout<<"****";  
		gotoxy(enemyX[ind], enemyY[ind]+1); cout<<" ** "; 
		gotoxy(enemyX[ind], enemyY[ind]+2); cout<<"****"; 
		gotoxy(enemyX[ind], enemyY[ind]+3); cout<<" ** ";  
	} 
}

//erase enemy as soon as the enemy reaches end of track
void eraseEnemy(int ind){
	if( enemyFlag[ind] == true ){
		gotoxy(enemyX[ind], enemyY[ind]); cout<<"    ";  
		gotoxy(enemyX[ind], enemyY[ind]+1); cout<<"    "; 
		gotoxy(enemyX[ind], enemyY[ind]+2); cout<<"    "; 
		gotoxy(enemyX[ind], enemyY[ind]+3); cout<<"    "; 
	} 
}

//enemy should continue at the end of the track but it should come from above in different direction

void resetEnemy(int ind){
	eraseEnemy(ind);
	enemyY[ind] = 1;
	genEnemy(ind);
}
//Drawing car
void drawCar(){
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			gotoxy(j+carPos, i+22); cout<<car[i][j];
		}
	}
}

//Only one car should be shown as increments are made by moving cursor
void eraseCar(){
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			gotoxy(j+carPos, i+22); cout<<" ";
		}
	}
}
// Collision occurs: when car and enemy collide
int collision(){
	if( enemyY[0]+4 >= 23 ){
		if( enemyX[0] + 4 - carPos >= 0 && enemyX[0] + 4 - carPos < 9  ){
			return 1;
		}
	}
	return 0;
} 

//At the end of the game:
//Game over function
void gameover(){
	system("cls");
	cout<<endl;
	cout<<"\t\t--------------------------"<<endl;
	cout<<"\t\t-------- Game Over -------"<<endl;
	cout<<"\t\t--------------------------"<<endl<<endl;
	cout<<"\t\tPress any key to go back to menu.";
	getch();
}

//Update score
void updateScore(){
	gotoxy(WIN_WIDTH + 7, 5);cout<<"Score: "<<score<<endl;  
}

//Instructions:
void instructions(){
	
	system("cls");
	cout<<"Instructions";
	cout<<"\n----------------";
	cout<<"\n Avoid Cars by moving left or right. "; // A and D are mapped in a game to move left and right
	cout<<"\n\n Press 'a' to move left";
	cout<<"\n Press 'd' to move right";
	cout<<"\n Press 'escape' to exit";
	cout<<"\n\nPress any key to go back to menu";
	getch();
}

//start game function

void play(){
	carPos = -1 + WIN_WIDTH/2;  //-1 + 70/2
	score = 0;
	enemyFlag[0] = 1;
	enemyFlag[1] = 0;
	enemyY[0] = enemyY[1] = 1;
	  
	system("cls"); //To clear the screen in C++
	drawBorder(); 
	updateScore();
	genEnemy(0);
	genEnemy(1);
	
	gotoxy(WIN_WIDTH + 7, 2);cout<<"Car Game";
	gotoxy(WIN_WIDTH + 6, 4);cout<<"----------";
	gotoxy(WIN_WIDTH + 6, 6);cout<<"----------";
	gotoxy(WIN_WIDTH + 7, 12);cout<<"Control ";
	gotoxy(WIN_WIDTH + 7, 13);cout<<"-------- ";
	gotoxy(WIN_WIDTH + 2, 14);cout<<" A Key - Left";
	gotoxy(WIN_WIDTH + 2, 15);cout<<" D Key - Right"; 
	
	gotoxy(18, 5);cout<<"Press any key to start";
	getch();
	gotoxy(18, 5);cout<<"                      ";
	
	while(1){
		if(kbhit()){
			char ch = getch();
			if( ch=='a' || ch=='A' ){
				if( carPos > 18 )
					carPos -= 4;
			}
			if( ch=='d' || ch=='D' ){
				if( carPos < 50 )
					carPos += 4;
			} 
			if(ch==27){
				break;
			}
		} 
		
		drawCar(); 
		drawEnemy(0); 
		drawEnemy(1); 
		if( collision() == 1  ){
			gameover();
			return;
		} 
		Sleep(50);
		eraseCar();
		eraseEnemy(0);
		eraseEnemy(1);   
		
		if( enemyY[0] == 10 )
			if( enemyFlag[1] == 0 )
				enemyFlag[1] = 1;
		
		if( enemyFlag[0] == 1 )
			enemyY[0] += 1;
		
		if( enemyFlag[1] == 1 )
			enemyY[1] += 1;
		 
		if( enemyY[0] > SCREEN_HEIGHT-4 ){
			resetEnemy(0);
			score++;
			updateScore();
		}
		if( enemyY[1] > SCREEN_HEIGHT-4 ){
			resetEnemy(1);
			score++;
			updateScore();
		}
	}
}

int main()
{
	setcursor(0,0); 
	srand( (unsigned)time(NULL)); //makes use of the computer's internal clock to control the choice of the seed.  Since time is continually changing, the seed is forever changing
	 
	do{
		system("cls");
		gotoxy(10,5); cout<<" -------------------------- "; 
		gotoxy(10,6); cout<<" |        Car Game        | "; 
		gotoxy(10,7); cout<<" --------------------------";
		gotoxy(10,9); cout<<"1. Start Game";
		gotoxy(10,10); cout<<"2. Instructions";	 
		gotoxy(10,11); cout<<"3. Quit";
		gotoxy(10,13); cout<<"Select option: ";
		char op = getche();
		
		if( op=='1') play();
		else if( op=='2') instructions();
		else if( op=='3') exit(0);
		
	}while(1);
	
	return 0;
}
