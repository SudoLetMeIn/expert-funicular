#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <windows.h>
#include <iostream>
#define SIZE 11
char board[11][11];
int selX[4][8],selY[4][8];
int headX[4],headY[4];
bool max_num_reached=false;
int total=0;
void checker(){
	if(total>3)max_num_reached=true;
}
void check(){
	int a,b;
	for(int i=0;i<4;i++){
		for(int j=0;j<8;j++){
			a=selX[i][j];b=selY[i][j];
			if(a!=0 && b!=0)board[b][a]=254;
}}}
void printBoard(char me,int x,int y){
	system("color 0a");
	for(int i=0;i<11;i++){
		for(int j=0;j<11;j++){
			if(i==y && x==j){
				printf("%c ",me);
			}else{
					if(j==10 && i==0)printf("10");
					else if(j==0 && i==10)printf("10");
					else printf("%c ",board[i][j]);
			}
		}
		printf("|");
		if(i==0){
			printf("\ttotal : %d",total);
		}
		printf("\n");
	}
	printf("Press 'p' to place your plane\nPress \"ASWD\" to move around!!\n ");
	printf("\n\nx : %d\ny : %d\n",x,y);
	for(int j=0;j<4;j++){
		printf("x :");
	for(int i=0;i<8;i++){
		if(selX[j][i]>9)
		printf("%d|",selX[j][i]);
		else printf(" %d|",selX[j][i]);
	}
	printf("\ny :");
	for(int i=0;i<8;i++){
		if(selY[j][i]>9)
		printf("%d|",selY[j][i]);
		else printf(" %d|",selY[j][i]);;
	}printf("\n");
	}
	
}
void printBoard(char me,int x,int y,int tempY[7],int tempX[7]){
	for(int i=0;i<11;i++){
		for(int j=0;j<11;j++){
			if(i==y && x==j){
				printf("%c ",me);
			}else{
					if(j==10 && i==0)printf("10");
					else if(j==0 && i==10)printf("10");
					else printf("%c ",board[i][j]);
			}
		}
		if(i==0){
			printf("\ttotal : %d",total);
		}
		printf("\n");
	}
		printf("Press 'v' to save your plane's current position\nPress 'c' to clear previous draft\nPress 'z' to cancel\nPress \"ASWD\" to determine plane position!!");
	printf("\nx : %d\ny : %d\n",x,y);
	printf("x : ");
	for(int i=0;i<7;i++){
		printf(" %d|",tempX[i]);
	}
	printf("\ny : ");
	for(int i=0;i<7;i++){
		printf(" %d|",tempY[i]);
	}
}
struct Tank{
	char c;
	int tempX[7]={0,0,0,0,0,0,0}; int tempY[7]={0,0,0,0,0,0,0};
	bool done=false;bool cancel=false;
	int e=0;
	Tank(char me,int x,int y){
	total++;
	board[y][x]=me;
	while(!done){
		if(e%2==0){
			system("color 0a");
		}else{
			system("color 0c");
		}e++;
		c=getch();
		place(c,x,y,(char) 254);
		system("cls");
		if(cancel){
			board[y][x]=' ';
			total--;	
		}
		printBoard((char) 254 , x , y , tempX ,tempY );}
	if(!cancel){
	for(int i=0;i<7;i++){
		selX[total-1][i]=tempY[i];
		selY[total-1][i]=tempX[i];
	}
	headX[total-1]=x;
	headY[total-1]=y;
	selX[total-1][7]=x;
	selY[total-1][7]=y;
	system("color 0a");
	check();
	}
	}
	void erase(){
		for(int i=0;i<7;i++){
			board[tempX[i]][tempY[i]]=' ';
		}
		for(int i=0;i<7;i++){
			tempX[i]=0;tempY[i]=0;
		}
	}
	bool empty(){
		for(int i=0;i<7;i++){
			if(tempX[i]!=0 && tempY[i]!=0) return false;
		}
		return true;
	}
	bool checkif(){
		for(int i=0;i<4;i++){
			for(int j=0;j<8;j++){
				for(int h=0;h<7;h++){
					if(selX[i][j]==tempY[h]&&selY[i][j]==tempX[h]){
						printf("\a");
						return true;
					}
				}
			}
		}
		return false;
	}
	void place(char c,int x,int y,char me){
		switch(c){
			case 'a': if(x>3 && y>1 && y!=11){
				erase();
				tempX[0]=y-1;tempY[0]=x-3;
				tempX[1]=y;tempY[1]=x-1;
				tempX[2]=y;tempY[2]=x-2;
				tempX[3]=y;tempY[3]=x-3;
				tempX[4]=y-1;tempY[4]=x-1;
				tempX[5]=y+1;tempY[5]=x-1;
				tempX[6]=y+1;tempY[6]=x-3;
				if(!checkif()){					
				board[y][x-1]=me;
				board[y][x-2]=me;
				board[y][x-3]=me;
				board[y-1][x-1]=me;
				board[y+1][x-1]=me;
				board[y+1][x-3]=me;
				board[y-1][x-3]=me;
				}else{
					for(int i=0;i<7;i++){
				tempX[i]=0;tempY[i]=0;
			}
				}
			}break;
			case 'w':if(y>3 && x>1 && x!=11){
				erase();
				tempX[0]=y-1;tempY[0]=x;
				tempX[1]=y-2;tempY[1]=x;
				tempX[2]=y-3;tempY[2]=x;
				tempX[3]=y-1;tempY[3]=x+1;
				tempX[4]=y-1;tempY[4]=x-1;
				tempX[5]=y-3;tempY[5]=x+1;
				tempX[6]=y-3;tempY[6]=x-1;
				if(!checkif()){
					
				board[y-1][x]=me;
				board[y-2][x]=me;
				board[y-3][x]=me;
				board[y-1][x+1]=me;
				board[y-1][x-1]=me;
				board[y-3][x-1]=me;
				board[y-3][x+1]=me;
				}else{
					for(int i=0;i<7;i++){
				tempX[i]=0;tempY[i]=0;
			}
				}
			}break;
			case 'd':if(x<8 && y>1 && y!=11){
				erase();
				tempX[0]=y-1;tempY[0]=x+3;
				tempX[1]=y;tempY[1]=x+1;
				tempX[2]=y;tempY[2]=x+2;
				tempX[3]=y;tempY[3]=x+3;
				tempX[4]=y-1;tempY[4]=x+1;
				tempX[5]=y+1;tempY[5]=x+1;
				tempX[6]=y+1;tempY[6]=x+3;
				if(!checkif()){
					
				board[y][x+1]=me;board[y][x+2]=me;board[y][x+3]=me;board[y-1][x+1]=me;
				board[y+1][x+1]=me;board[y+1][x+3]=me;board[y-1][x+3]=me;
				}else{
					for(int i=0;i<7;i++){
				tempX[i]=0;tempY[i]=0;
			}
				}
			}break;
			case 's':if(y<8 && x>1 && x!=11){
				erase();
				tempX[0]=y+1;tempY[0]=x;
				tempX[1]=y+2;tempY[1]=x;
				tempX[2]=y+3;tempY[2]=x;
				tempX[3]=y+1;tempY[3]=x+1;
				tempX[4]=y+1;tempY[4]=x-1;
				tempX[5]=y+3;tempY[5]=x+1;
				tempX[6]=y+3;tempY[6]=x-1;
				if(!checkif()){
				board[y+1][x]=me;
				board[y+2][x]=me;
				board[y+3][x]=me;
				board[y+1][x+1]=me;
				board[y+1][x-1]=me;
				board[y+3][x-1]=me;
				board[y+3][x+1]=me;
				}else{
					for(int i=0;i<7;i++){
				tempX[i]=0;tempY[i]=0;
			}
				}
			}break;
			case 'c':erase();break;
			case 'v':if(!empty())
			{ done=true;
			}
			
			
			break;
			case 'z':erase();cancel=true;done=true;break;
		}
	}
};
bool check2(int x,int y,char me){
	if(board[y][x]==me)return false;
	return true;
}
void move(char me,int &x,int &y,char m){
	switch(m){
		case 'a':if(x>1){x--;}break;
		case 75:if(x>1){x--;}break;
		case 'w':if(y>1){y--;}break;
		case 72:if(y>1){y--;}break;
		case 'd':if(x<10){x++;}break;
		case 77:if(x<10){x++;}break;
		case 's':if(y<10){y++;}break;
		case 80:if(y<10){y++;}break;
		case 'p':checker();if(!max_num_reached){
			if(check2(x,y,me))
		Tank tank(me,x,y);
		}break;
	}
}
main(){
char me=254;
int x=1,y=1;
char movement;
system("color 0a");
for(int i=1;i<11;i++){
	for(int j=0;j<11;j++){
		board[i][j]=' ';
	}
}
for(int i=0;i<10;i++){
	board[i][0]=i+48;
	board[0][i]=i+48;
}
while(!max_num_reached){
	system("cls");
	printBoard(me,x,y);
	movement=getch();
	move(me,x,y,movement);
	checker();
	}
	std::ofstream yout;
	std::string line;
	yout.open("myPlane.txt");
	int e=0;
	while (yout && e<4) {
		line.clear();
		for(int i=0;i<8;i++){
			line+=selX[e][i]+48;
			line+=' ';
			line+=selY[e][i]+48;
			line+=' ';
		}
		e++;
		yout<<line<<std::endl;
	}
	system("cls");
	system("g++ shooting.cpp");
	system("shooting.exe");
}
