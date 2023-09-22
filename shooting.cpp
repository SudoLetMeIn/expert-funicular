#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
int board[11][11];
int enemyX[4][8],enemyY[4][8];
int headX[4],headY[4];
int total=4;
int attempts=0;bool won=false;
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
		}printf("|");
		if(i==0)printf("\t\ttotal planes left : %d",total);
		if(i==1)printf("\t\ttotal attempts : %d",attempts);
		printf("\n");
	}
	printf("Press 'p' to shoot\nPress \"ASWD\" to move around!!\n!!!'X' = hit, 'O' = miss!!!\n");
	printf("\n\nx : %d\ny : %d\n",x,y);
}
int isithead(int x,int y){
	for(int i=0;i<4;i++){
		if(x==headX[i]&&y==headY[i]){
			return i;
		}
	}
	return 5;
}
bool checkfor(int x,int y){
	for(int i=0;i<4;i++){
		for(int e=0;e<7;e++){
			if(x==enemyX[i][e] && y==enemyY[i][e]){
				return true;
			}
		}
	} return false;
}
bool unidentified(int x,int y){
	if(board[x][y]!=' '){
		return false;
	}return true;
}
void shoot(int x,int y){
	bool painting=true;
	if(unidentified(y,x)){
	attempts++;
	int a=isithead(x,y);
	if(a!=5){
	int f,s;
		for(int i=0;i<8;i++){
			f=enemyX[a][i];s=enemyY[a][i];
			board[s][f]='X';
		}
		total--;
	}else if (checkfor(x,y)){
			board[y][x]='X';
	}else {
		board[y][x]='O';
	}
	}
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
		case 'p':shoot(x,y);break;
		}
	}
void scan(){
	std::ifstream in("myPlane.txt");
	char ch;
	bool turnX=true;
	int e=0,k=0;
	while(in){
		in>>ch;
		if(turnX && enemyX[e][k]==0){
			enemyX[e][k]=ch-48;
			turnX=false;
		}else if((!turnX) &&enemyY[e][k]==0){
			enemyY[e][k]=ch-48;
			k++;
			turnX=true;
		}
		if(k>=8){
			if(e!=3){
			e++;
			}
			k=0;
		}	
		}
	for(int i=0;i<4;i++){
		headX[i]=enemyX[i][7];
		headY[i]=enemyY[i][7];
	}
}
main(){
	system("color 0a");
	scan();
	char me=254;
	int x=1,y=1;
	char movement;
	
	for(int i=1;i<11;i++){
	for(int j=0;j<11;j++){
		board[i][j]=' ';
	}
	}
	for(int i=0;i<10;i++){
	board[i][0]=i+48;
	board[0][i]=i+48;
	}
while(!won){
	system("cls");
	printBoard(me,x,y);
	movement=getch();
	move(me,x,y,movement);
	if(total==0){
		system("cls");
	printBoard(me,x,y);	
		won=true;
	}
}
}