// Assignment #11: 3D Tic Tac Toe w/ Partner
// Author: Austin Hendrix and Andrew Harmon
// Date: 4/15/2016
// Section 2

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std; 

class Space{
	public: 
	string value;
};

class Board{	
	public: 
	Space spaces[9];
	
	
	void fillSpace(Space* move, int player){
		string character;
		if(player == 1){
			character = "X";
		}else{
			character = "O";
		}	
	
		move->value = character;
	}
	
	bool avaliable(Space space){
		
		if((space.value)!="X"&&(space.value)!="O"){
			return true;
		}
		
		return false; 
	}
	
	
	
	~Board(){}
	
};	

class ThreeDBoard: public Board{
	public: 
	Space spaces[27];
	int playerWins, computerWins;
	//initializes the board
	ThreeDBoard(){
		this->spaces[0].value = "1";
		this->spaces[1].value = "2";
		this->spaces[2].value = "3";
		this->spaces[3].value = "4";
		this->spaces[4].value = "5";
		this->spaces[5].value = "6";
		this->spaces[6].value = "7";
		this->spaces[7].value = "8";
		this->spaces[8].value = "9";
		this->spaces[9].value = "10";
		this->spaces[10].value = "11";
		this->spaces[11].value = "12";
		this->spaces[12].value = "13";
		this->spaces[13].value = "14";
		this->spaces[14].value = "15";
		this->spaces[15].value = "16";
		this->spaces[16].value = "17";
		this->spaces[17].value = "18";
		this->spaces[18].value = "19";
		this->spaces[19].value = "20";
		this->spaces[20].value = "21";
		this->spaces[21].value = "22";
		this->spaces[22].value = "23";
		this->spaces[23].value = "24";
		this->spaces[24].value = "25";
		this->spaces[25].value = "26";
		this->spaces[26].value = "27";
	}
	
	//clears board 
	void clearBoard(){
		this->spaces[0].value = "1";
		this->spaces[1].value = "2";
		this->spaces[2].value = "3";
		this->spaces[3].value = "4";
		this->spaces[4].value = "5";
		this->spaces[5].value = "6";
		this->spaces[6].value = "7";
		this->spaces[7].value = "8";
		this->spaces[8].value = "9";
		this->spaces[9].value = "10";
		this->spaces[10].value = "11";
		this->spaces[11].value = "12";
		this->spaces[12].value = "13";
		this->spaces[13].value = "14";
		this->spaces[14].value = "15";
		this->spaces[15].value = "16";
		this->spaces[16].value = "17";
		this->spaces[17].value = "18";
		this->spaces[18].value = "19";
		this->spaces[19].value = "20";
		this->spaces[20].value = "21";
		this->spaces[21].value = "22";
		this->spaces[22].value = "23";
		this->spaces[23].value = "24";
		this->spaces[24].value = "25";
		this->spaces[25].value = "26";
		this->spaces[26].value = "27";
		this->playerWins = 0;
		this->computerWins = 0; 
	}
	
	//Checks to see if the game is over
	bool checkEnd(){
		
	if(this->spaces[0].value!="1" && this->spaces[1].value!=("2") && this->spaces[2].value!=("3") 
			&& this->spaces[3].value!=("4") && this->spaces[4].value!=("5") 
			&& this->spaces[5].value!=("6") && this->spaces[7].value!=("8") 
			&& this->spaces[8].value!=("9") && this->spaces[9].value!="10" && this->spaces[10].value!=("11") && this->spaces[11].value!=("12") 
			&& this->spaces[12].value!=("13") && this->spaces[13].value!=("14") 
			&& this->spaces[14].value!=("15") && this->spaces[15].value!=("16") 
			&& this->spaces[16].value!=("17") && this->spaces[17].value!="18" && this->spaces[18].value!=("19") && this->spaces[19].value!=("20") 
			&& this->spaces[20].value!=("21") && this->spaces[21].value!=("22") 
			&& this->spaces[22].value!=("23") && this->spaces[23].value!=("24") && this->spaces[24].value!=("25")&&this->spaces[6].value!="7"&&this->spaces[25].value!="26"&&this->spaces[26].value!="27") {
			return true;
		}
		return false; 
	}
	
	
	//function to print out the board
	void printBoard(){
		//first pane
		cout <<"\n " << this->spaces[0].value << " | " << this->spaces[1].value << " | " << this->spaces[2].value;
		cout << "\n-----------";
		cout << "\n " << this->spaces[3].value << " | " << this->spaces[4].value << " | " << this->spaces[5].value;
		cout << "\n-----------";
		cout << "\n " << this->spaces[6].value << " | " << this->spaces[7].value << " | " << this->spaces[8].value << "\n";
		
		//second pane
		cout <<"\n           " << this->spaces[9].value << " | " << this->spaces[10].value << " | " << this->spaces[11].value;
		cout << "\n           ------------";
		cout << "\n           " << this->spaces[12].value << " | " << this->spaces[13].value << " | " << this->spaces[14].value;
		cout << "\n           ------------";
		cout << "\n           " << this->spaces[15].value << " | " << this->spaces[16].value << " | " << this->spaces[17].value << "\n";
		
		//third pane
		cout <<"\n                        " << this->spaces[18].value << " | " << this->spaces[19].value << " | " << this->spaces[20].value;
		cout << "\n                        ------------";
		cout << "\n                        " << this->spaces[21].value << " | " << this->spaces[22].value << " | " << this->spaces[23].value;
		cout << "\n                        ------------";
		cout << "\n                        " << this->spaces[24].value << " | " << this->spaces[25].value << " | " << this->spaces[26].value << "\n";
		
	}
	
		//algorithms to check for winner
		//Every time one player gets three in a row, adds one to their score
	void checkWinner(){
			
			//Checks horizontal for each vertical panes
		for(int j = 0; j<19; j+=9){
			for(int i = 0; i < 7; i+=3){ 
				if(this->spaces[i+j].value==(this->spaces[i+1+j].value) && this->spaces[i+j].value==(this->spaces[i+2+j].value)){
					if(this->spaces[i+j].value==("X")){
						playerWins++;
					}else{
						computerWins++;
					}
				}
			}
		}	
			//Checks right diagonal for each vertical pane
		for(int i=0;i<19;i+=9){
			if(this->spaces[i].value==(this->spaces[i+4].value) && this->spaces[i].value==(this->spaces[i+8].value)){
				if(this->spaces[i].value==("X")){
					playerWins++;
				}else{
					computerWins++;
				}
			}
		}
		
		//checks right diagonal for each horizontal pane
		for(int i=0;i<7;i+=3){
			if(this->spaces[i].value==(this->spaces[i+10].value) && this->spaces[i].value==(this->spaces[i+20].value)){
				if(this->spaces[i].value==("X")){
					playerWins++;
				}else{
					computerWins++;
				}
			}
		}
		
		//checks left diagonal for each horizontal pane
		for(int i=2;i<9;i+=3){
			if(this->spaces[i].value==(this->spaces[i+8].value) && this->spaces[i].value==(this->spaces[i+16].value)){
				if(this->spaces[i].value==("X")){
					playerWins++;
				}else{
					computerWins++;
					
				}
			}
		}
		
		
			//Checks left diagonal for each vertical pane
		for(int i=2;i<21;i+=9){
			if(this->spaces[i].value==(this->spaces[i+2].value) && this->spaces[i].value==(this->spaces[i+4].value)){
				if(this->spaces[i].value==("X")){
					playerWins++;
				}else{
					computerWins++;
				}
			}
		}
			//Checks vertical for each vertical pane
		for(int j = 0; j <19; j+=9){	
			for(int i = 0; i < 3; i++){
				if(this->spaces[i+j].value==(this->spaces[i+3+j].value) && this->spaces[i+j].value==(this->spaces[i+6+j].value)){
					if(this->spaces[i+j].value==("X")){
						playerWins++;
					}else{
						computerWins++;
					}
				}
			}
		}
			//checks vertical for each horizontal pane 
		for(int j = 0; j <7; j+=3){	
			for(int i = 0; i < 3; i++){
				if(this->spaces[i+j].value==(this->spaces[i+9+j].value) && this->spaces[i+j].value==(this->spaces[i+18+j].value)){
					if(this->spaces[i+j].value==("X")){
						playerWins++;
					}else{
						computerWins++;					
					}
				}
			}
		}	
	
		//check four diagonals that go through the center
		if(this->spaces[0].value==(this->spaces[13].value) && this->spaces[0].value==(this->spaces[26].value)){
				if(this->spaces[0].value==("X")){
					playerWins++;
				}else{
					computerWins++;
				}
			}
		
		if(this->spaces[3].value==(this->spaces[13].value) && this->spaces[3].value==(this->spaces[24].value)){
				if(this->spaces[3].value==("X")){
					playerWins++;
				}else{
					computerWins++;				
				}
			}
			
		if(this->spaces[20].value==(this->spaces[13].value) && this->spaces[20].value==(this->spaces[6].value)){
				if(this->spaces[20].value==("X")){
					playerWins++;				
				}else{
					computerWins++;				
				}
			}
		
		if(this->spaces[18].value==(this->spaces[13].value) && this->spaces[18].value==(this->spaces[8].value)){
				if(this->spaces[18].value==("X")){
					playerWins++;		
				}else{
					computerWins++;
				}
			}
		
		
	}
	//Algorithm for deciding computer move
	int pickComputerSpace(ThreeDBoard *board){
		int nextMove;
		int *pNextMove = &nextMove;
		
			
			if(board->avaliable(board->spaces[13])){
				return 14;
				
			}
			
			for(int i = 1; i < 28; i++){
				nextMove = i;
				if(board->avaliable(board->spaces[nextMove-1])){
					if(checkForFullRow(pNextMove,*board)){
						return nextMove;
					}
				}
			}			

		do{	
		
			nextMove = (rand()%27) + 1;			
		}while(!board->avaliable(board->spaces[nextMove-1]));
		
		return nextMove;
		
			
	}
	//Algorithm that checks if any moves for the computer create a new three in a row
	bool checkForFullRow(int* pNextMove, ThreeDBoard  tempBoard){
		
				tempBoard.spaces[*pNextMove-1].value = "O";
				//Checks horizontal for each vertical panes
				for(int j = 0; j<19; j+=9){
					for(int i = 0; i < 7; i+=3){ 
						if(tempBoard.spaces[i+j].value==(tempBoard.spaces[i+1+j].value) && tempBoard.spaces[i+j].value==(tempBoard.spaces[i+2+j].value)){

							if((tempBoard.spaces[i+j].value==("O"))&&(i+j == *pNextMove -1 || i+j+1 == *pNextMove -1)|| i+j+2 == *pNextMove -1){

								return true;
							}
						}
					}
				}	
					//Checks right diagonal for each vertical pane
				for(int i=0;i<19;i+=9){
					if(tempBoard.spaces[i].value==(tempBoard.spaces[i+4].value) && tempBoard.spaces[i].value==(tempBoard.spaces[i+8].value)){
						if((tempBoard.spaces[i].value==("O"))&&(i == *pNextMove -1 || i+4 == *pNextMove -1)|| i+8 == *pNextMove -1){
							return true;
						}
					}
				}
				
				//checks right diagonal for each horizontal pane
				for(int i=0;i<7;i+=3){
					if(tempBoard.spaces[i].value==(tempBoard.spaces[i+10].value) && tempBoard.spaces[i].value==(tempBoard.spaces[i+20].value)){

						if((tempBoard.spaces[i].value==("O"))&&(i == *pNextMove -1 || i+10 == *pNextMove -1)|| i+20 == *pNextMove -1){
							
							return true;
						}
					}
				}
				
				//checks left diagonal for each horizontal pane
				for(int i=2;i<9;i+=3){
					if(tempBoard.spaces[i].value==(tempBoard.spaces[i+8].value) && tempBoard.spaces[i].value==(tempBoard.spaces[i+16].value)){

						if((tempBoard.spaces[i].value==("O"))&&(i == *pNextMove -1 || i+8 == *pNextMove -1)|| i+16 == *pNextMove -1){
						
							return true;
						}
					}
				}
				
				
					//Checks left diagonal for each vertical pane
				for(int i=2;i<21;i+=9){
					if(tempBoard.spaces[i].value==(tempBoard.spaces[i+2].value) && tempBoard.spaces[i].value==(tempBoard.spaces[i+4].value)){
						if((tempBoard.spaces[i].value==("O"))&&(i == *pNextMove -1 || i+2 == *pNextMove -1)|| i+4 == *pNextMove -1){
							
							return true;
						}
					}
				}
					//Checks vertical for each vertical pane
				for(int j = 0; j <19; j+=9){	
					for(int i = 0; i < 3; i++){
						if(tempBoard.spaces[i+j].value==(tempBoard.spaces[i+3+j].value) && tempBoard.spaces[i+j].value==(tempBoard.spaces[i+6+j].value)){
							if((tempBoard.spaces[i+j].value==("O"))&&(i+j == *pNextMove -1 || i+j+3 == *pNextMove -1)|| i+j+6 == *pNextMove -1){
								
								return true;
							}
						}
					}
				}
					//checks vertical for each horizontal pane 
				for(int j = 0; j <7; j+=3){	
					for(int i = 0; i < 3; i++){
						if(tempBoard.spaces[i+j].value==(tempBoard.spaces[i+9+j].value) && tempBoard.spaces[i+j].value==(tempBoard.spaces[i+18+j].value)){
							if((tempBoard.spaces[i+j].value==("O"))&&(i+j == *pNextMove -1 || i+j+9 == *pNextMove -1)|| i+j+18 == *pNextMove -1){
								
								return true;
							}
						}
					}
				}	
			
				//check four diagonals that go through the center
				if(tempBoard.spaces[0].value==(tempBoard.spaces[13].value) && tempBoard.spaces[0].value==(tempBoard.spaces[26].value)){
						if((tempBoard.spaces[0].value==("O"))&&(0 == *pNextMove -1 || 13 == *pNextMove -1)|| 26 == *pNextMove -1){
							
							return true;
						}
					}
				
				if(tempBoard.spaces[3].value==(tempBoard.spaces[13].value) && tempBoard.spaces[3].value==(tempBoard.spaces[24].value)){
						if((tempBoard.spaces[3].value==("O"))&&(3 == *pNextMove -1 || 13 == *pNextMove -1)|| 24 == *pNextMove -1){
							
							return true;
						}
					}
					
				if(tempBoard.spaces[20].value==(tempBoard.spaces[13].value) && tempBoard.spaces[20].value==(tempBoard.spaces[6].value)){
						if((tempBoard.spaces[20].value==("O"))&&(20 == *pNextMove -1 || 13 == *pNextMove -1)|| 6== *pNextMove -1){
							
							return true;			
						}
					}
				
				if(tempBoard.spaces[18].value==(tempBoard.spaces[13].value) && tempBoard.spaces[18].value==(tempBoard.spaces[8].value)){
						if((tempBoard.spaces[18].value==("O"))&&(18 == *pNextMove -1 || 13 == *pNextMove -1)|| 8 == *pNextMove -1){
							
							return true;		
						}
					}
				return false;
	}
		
	~ThreeDBoard(){}
	
};


class AndrewThreeDBoard : public Board{
		int coordConv(int z, int y, int x){//convert from 3d to 1d coordinates
		int num = z*9;
		num = num + y * 3;
		num = num + x +1;
		return num;
	}
	
	string toString(int num){
		stringstream s;
		s << num;
		return s.str();
	}
	
	int stoi(char snum){
		return snum - '0';
	}
	
	public :int pickComputerSpace2(ThreeDBoard &board){
		static string seedSpace;
		string convBoard[3][3][3];
		int i,j,k;
		int counter = 0;
		for(int i = 0; i<3;i++){//converts array board to a 3d array
			for(int j = 0; j<3;j++){
				for(int k = 0; k<3;k++){
					convBoard[i][j][k] = board.spaces[counter].value;
					counter++;
				}
			}
		}
		//grab center space if open
		if(convBoard[1][1][1] != "O" && convBoard[1][1][1] != "X"){
			seedSpace = "111";
			return 14;
		}
		while(true){
			while(seedSpace == ""){
				int num = (rand()%27);
				int tempNum = num;
				int z = num/9;
				num = num%9;
				int y = num/3;
				int x = num%3;
			
				if(convBoard[z][y][x] != "O" && convBoard[z][y][x] != "X"){
					seedSpace = toString(z) + toString(y) + toString(x);
					return tempNum +1;
				}
			}
			
			//these lines apply to all points
			//z-axis
			bool usableRow = true;
			
			for(i=0;i<3;i++){
				if(convBoard[i][stoi(seedSpace[1])][stoi(seedSpace[2])] == "O"){
					usableRow = false;
					break;
				}
			}
			if(usableRow){
				for(i=0;i<3;i++){
					if(convBoard[i][stoi(seedSpace[1])][stoi(seedSpace[2])] != "X"){
						return coordConv(i,stoi(seedSpace[1]),stoi(seedSpace[2]));
					}
				}
			}
			//y-axis
			usableRow = true;
			for(i=0;i<3;i++){
				if(convBoard[stoi(seedSpace[0])][i][stoi(seedSpace[2])] == "O"){
					usableRow = false;
					break;
				}
			}
			if(usableRow){
				for(i=0;i<3;i++){
					if(convBoard[stoi(seedSpace[0])][i][stoi(seedSpace[2])] != "X"){
						return coordConv(stoi(seedSpace[0]),i,stoi(seedSpace[2]));
					}
				}
			}
			//x-axis
			usableRow = true;
			for(i=0;i<3;i++){
				if(convBoard[stoi(seedSpace[0])][stoi(seedSpace[1])][i] == "O"){
					usableRow = false;
					break;
				}
			}
			if(usableRow){
				for(i=0;i<3;i++){
					if(convBoard[stoi(seedSpace[0])][stoi(seedSpace[1])][i] != "X"){
						return coordConv(stoi(seedSpace[0]),stoi(seedSpace[1]),i);
					}
				}
			}
			//xy plane diagonal
				if((seedSpace[1]==2 && seedSpace[2]==0)||(seedSpace[1]==0 && seedSpace[2]==2)||(seedSpace[1]==1 && seedSpace[2]==1)){
					usableRow = true;
					for(i=0;i<3;i++){
						if(convBoard[stoi(seedSpace[0])][2-i][i] == "O"){
							usableRow = false;
							break;
						}
					}
					if(usableRow){
						for(i=0;i<3;i++){
							if(convBoard[stoi(seedSpace[0])][2-i][i] != "X"){
								return coordConv(stoi(seedSpace[0]),2-i,i);
							}
						}
					}
				}
				if((seedSpace[1]==2 && seedSpace[2]==2)||(seedSpace[1]==1 && seedSpace[2]==1)||(seedSpace[1]==0 && seedSpace[2]==0)){
					usableRow = true;
					for(i=0;i<3;i++){
						if(convBoard[stoi(seedSpace[0])][i][i] == "O"){
							usableRow = false;
							break;
						}
					}
					if(usableRow){
						for(i=0;i<3;i++){
							if(convBoard[stoi(seedSpace[0])][i][i] != "X"){
								return coordConv(stoi(seedSpace[0]),i,i);
							}
						}
					}
				}
			//xz plane diagonal
				if((seedSpace[0]==0 && seedSpace[2]==0)||(seedSpace[0]==1 && seedSpace[2]==1)||(seedSpace[0]==2 && seedSpace[2]==2)){
					usableRow = true;
					for(i=0;i<3;i++){
						if(convBoard[i][stoi(seedSpace[1])][i] == "O"){
							usableRow = false;
							break;
						}
					}
					if(usableRow){
						for(i=0;i<3;i++){
							if(convBoard[i][stoi(seedSpace[1])][i] != "X"){
								return coordConv(i,stoi(seedSpace[0]),i);
							}
						}
					}
				}
				if((seedSpace[0]==0 && seedSpace[2]==2)||(seedSpace[0]==1 && seedSpace[2]==1)||(seedSpace[0]==2 && seedSpace[2]==0)){
					usableRow = true;
					for(i=0;i<3;i++){
						if(convBoard[i][stoi(seedSpace[1])][2-i] == "O"){
							usableRow = false;
							break;
						}
					}
					if(usableRow){
						for(i=0;i<3;i++){
							if(convBoard[i][stoi(seedSpace[1])][2-i] != "X"){
								return coordConv(i,stoi(seedSpace[0]),2-i);
							}
						}
					}
				}
			//yz plane diagonal
				if((seedSpace[0]==0 && seedSpace[1]==0)||(seedSpace[0]==1 && seedSpace[1]==1)||(seedSpace[0]==2 && seedSpace[1]==2)){
					usableRow = true;
					for(i=0;i<3;i++){
						if(convBoard[i][i][stoi(seedSpace[2])] == "O"){
							usableRow = false;
							break;
						}
					}
					if(usableRow){
						for(i=0;i<3;i++){
							if(convBoard[i][i][stoi(seedSpace[2])] != "X"){
								return coordConv(i,i,stoi(seedSpace[0]));
							}
						}
					}
				}
				if((seedSpace[0]==0 && seedSpace[1]==2)||(seedSpace[0]==1 && seedSpace[1]==1)||(seedSpace[0]==2 && seedSpace[1]==0)){
					usableRow = true;
					for(i=0;i<3;i++){
						if(convBoard[i][2-i][stoi(seedSpace[2])] == "O"){
							usableRow = false;
							break;
						}
					}
					if(usableRow){
						for(i=0;i<3;i++){
							if(convBoard[i][2-i][stoi(seedSpace[2])] != "X"){
								return coordConv(i,2-i,stoi(seedSpace[0]));
							}
						}
					}
				}
			//cross diagonal right down
			if((seedSpace[0] == 0 && seedSpace[1]==0 && seedSpace[2] == 0)||(seedSpace[0] == 1 && seedSpace[1]==1 && seedSpace[2] == 1)||(seedSpace[0] == 2 && seedSpace[1]==2 && seedSpace[2] == 2)){                      
				usableRow = true;
					for(i=0;i<3;i++){
						if(convBoard[i][i][i] == "O"){
							usableRow = false;
							break;
						}
					}
					if(usableRow){
						for(i=0;i<3;i++){
							if(convBoard[i][i][i] != "X"){
								return coordConv(i,i,i);
							}
						}
					}
			}
			//cross diagonal right up
			if((seedSpace[0] == 0 && seedSpace[1]==2 && seedSpace[2] == 0)||(seedSpace[0] == 1 && seedSpace[1]==1 && seedSpace[2] == 1)||(seedSpace[0] == 2 && seedSpace[1]==0 && seedSpace[2] == 2)){                      
				usableRow = true;
					for(i=0;i<3;i++){
						if(convBoard[i][2-i][i] == "O"){
							usableRow = false;
							break;
						}
					}
					if(usableRow){
						for(i=0;i<3;i++){
							if(convBoard[i][2-i][i] != "X"){
								return coordConv(i,2-i,i);
							}
						}
					}
			}
			//cross diagonal left down
			if((seedSpace[0] == 0 && seedSpace[1]==0 && seedSpace[2] == 2)||(seedSpace[0] == 1 && seedSpace[1]==1 && seedSpace[2] == 1)||(seedSpace[0] == 2 && seedSpace[1]==2 && seedSpace[2] == 0)){                      
				usableRow = true;
					for(i=0;i<3;i++){
						if(convBoard[i][i][2-i] == "O"){
							usableRow = false;
							break;
						}
					}
					if(usableRow){
						for(i=0;i<3;i++){
							if(convBoard[i][i][2-i] != "X"){
								return coordConv(i,i,2-i);
							}
						}
					}
			}
			//cross diagonal left up
			if((seedSpace[0] == 0 && seedSpace[1]==2 && seedSpace[2] == 2)||(seedSpace[0] == 1 && seedSpace[1]==1 && seedSpace[2] == 1)||(seedSpace[0] == 2 && seedSpace[1]==0 && seedSpace[2] == 0)){                      
				usableRow = true;
					for(i=0;i<3;i++){
						if(convBoard[i][2-i][2-i] == "O"){
							usableRow = false;
							break;
						}
					}
					if(usableRow){
						for(i=0;i<3;i++){
							if(convBoard[i][2-i][2-i] != "X"){
								return coordConv(i,2-i,2-i);
							}
						}
					}
			}
			seedSpace = "";//base case if all spots around seed are filled.
		}
		
	}
};

class Competition : public ThreeDBoard, AndrewThreeDBoard{
	

	int gamesToPlay, austinGameWins , andrewGameWins , tieGames ;
	//default game of one
	Competition(){
		this->gamesToPlay = 1;
	}
	//allows main to decide how many games are played
	public : Competition(int gamesToPlay){
		this->gamesToPlay = gamesToPlay;
	}
	
	void playGame(){
		
		ThreeDBoard board;
		austinGameWins = 0;
		andrewGameWins = 0;
		tieGames = 0;
		srand(time(NULL));
		while(gamesToPlay > 0){
			
			board.clearBoard();
			int andrewMove, austinMove;
			//creating all of the space objects and assigning their character value
			
			
			bool goesFirst = rand()%2; 
			
			cout << "Let's play 3D Tic Taco Toe!";
				board.printBoard();
				
				if(goesFirst == 0){
					cout << "Austin goes first!" << endl;
					
					austinMove = board.pickComputerSpace(&board);				
					cout << "\nAustin chose space " << austinMove << "\n";
					board.fillSpace(&board.spaces[austinMove-1],2);
	
					board.printBoard();
					
				}else{
					cout << "Andrew goes first!";
				}
				//loop to continue playing the game
				while(!board.checkEnd()){
					
					
					do{
						
						andrewMove = pickComputerSpace2(board);	
						
						
					}while(andrewMove > 27 || (!board.avaliable(board.spaces[andrewMove-1])));	
					//fill in the players move, reprint the board, and check for a winner
					cout << "\nAndrew chose space " << andrewMove << "\n";;
					board.fillSpace(&board.spaces[andrewMove-1], 1);
				
					board.printBoard();
				
					if(board.checkEnd() == true){
						break;
					}
					//Loop to have the computer pick a random space until choosing one that is available
					do{
						austinMove = board.pickComputerSpace(&board);
					}while(!board.avaliable(board.spaces[austinMove-1]));
					
					cout << "\nAustin chose space " << austinMove << "\n";;
					board.fillSpace(&board.spaces[austinMove-1],2);
					
					
					board.printBoard();
				
				}
				
				board.checkWinner();
				
				cout << "Austin filled this many rows: " << board.computerWins << endl; 
				cout << "Andrew filled this many rows: " << board.playerWins << endl;
				
				if(board.computerWins > board.playerWins){
					cout << "Overall, Austin won." << endl << endl;
					austinGameWins++;
					
				
				}else if(board.playerWins == board.computerWins){
					cout << "It's a tie!" << endl << endl;
					tieGames++;
				}
				else{
					cout << "Overall, Andrew won." << endl << endl;
					andrewGameWins++;
				}
				
				gamesToPlay--;
		}
		
	}
	
	//print out the score from the competition
	void printScore(){
		
		cout << "COMPETITION RESULTS" << endl << endl;
		
		cout << "Andrew won this many games: " << andrewGameWins << endl;
		cout << "Austin won this many games: " << austinGameWins << endl;
		cout << "This many games were a tie: " << tieGames;
	}
	
	
};

	
int main(){
	Competition game(1000);
	
	game.playGame();
	game.printScore();
			
}
	
