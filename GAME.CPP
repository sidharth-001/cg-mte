#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <process.h>
#include <stdio.h>

void main_menu(){
	cleardevice();
	setbkcolor(BLUE);
	setcolor(WHITE);
	rectangle(0,0,getmaxx(),getmaxy());
	settextstyle(0,0,4); // font, horiz or verti, size
	outtextxy(140,37,"21 MATCHSTICKS");
	bar3d(100,50, 560,100,35,125);
	setcolor(5);
	settextstyle(0,0,4);
	outtextxy(110,60,"21 MATCHSTICKS");
	setcolor(WHITE);
	settextstyle(0,0,2);
	outtextxy(50,200,"1. Start Game");
	outtextxy(50,230,"2. Instructions");
	outtextxy(50,260,"3. Exit");
	outtextxy(50,300,"Select any one from choice 1 to 3");
}

void instructions(){
	cleardevice();
	setbkcolor(GREEN);
	setcolor(WHITE);
	settextstyle(0,0,4);
	outtextxy(140,40,"INSTRUCTIONS");
	bar3d(100,50, 500,100, 25,100);
	setcolor(5);
	settextstyle(0,0,4);
	outtextxy(110,60,"INSTRUCTIONS");
	settextstyle(0,0,2);

	outtextxy(20,135,"This is a simple game, the game play");
	outtextxy(20,160,"and rules are pretty straight forward.");
	outtextxy(20,185,"Here you have to pick a stick in any");
	outtextxy(20,210,"number from 1 to 4, then there will be");
	outtextxy(20,235,"the computers turn picking up the");
	outtextxy(20,260,"stick. The same cotinues till all the");
	outtextxy(20,285,"sticks are picked. Whoever picks the");
	outtextxy(20,310,"last stick, LOOSES. Thats it.");

	settextstyle(0,0,3);
	setcolor(BLUE);
	outtextxy(135,420,"Enjoy Playing...");
	getch();
}

void matches(int no){
	cleardevice();
	char str[10];
	setbkcolor(RED);
	setcolor(WHITE);
	for(int i=0; i<no; i++){
		circle(55+(i*25),95,6);
	}
	for(i=0; i<no; i++){
		bar(50+(i*25),100,60+(i*25),200);
	}
	for(i=0; i<no; i++){
		settextstyle(0,0,2);
		sprintf(str,"%d",i+1);
		outtextxy(50+(i*25),210,str);
    }
}

void game_play(){
	cleardevice();
	int m =21, P ,C;  //m = matches-left, P = player's choice, C = computer's choice
	char comp[100],msg[100];
	while(1){
		matches(m);
		settextstyle(0,0,2);
		outtextxy(50,250,"Pick 1,2,3 or 4 match sticks.");
		cin>>P;
		sprintf(msg," %d",P);
		outtextxy(50,270,msg);
		if(P<1||P>4){
			outtextxy(50,270,"WRONG CHOICE !  Choose again.");
			getch();
			continue ;
		}
		m=m-P;
		matches(m);
		C=5-P;
		sprintf(comp,"Computer Pick's  %d",C);
		outtextxy(50,270,comp);
		m=m-C;
		getch();
		if(m==1){
			matches(m);
			outtextxy(50,270,"You Loose");
			break;
		}
	}
}

int main(){

    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    int choice;
    char ch;

    settextstyle(0,0,2);
    setcolor(14);
    outtextxy(260,150,"Hello !!");
    getch();
    cleardevice();
    instructions();
    getch();

    do{
        cleardevice();
        main_menu();
        cin>>choice;
        switch(choice){
            case 1:
                cleardevice();
                game_play();
            break;
            case 2:
                instructions();
            break;
            case 3:
                exit(0);
            break;
            default:
                outtextxy(100,350,"WRONG CHOICE! EXITING");
                getch();
            exit(0);
        }
        settextstyle(0,0,2);
        setcolor(14);
        outtextxy(40,400,"DO YOU WANT TO CONTINUE?(Y or N)");
        cin>>ch;
        if(ch=='N'||ch=='n')
        exit(0);
    }while(ch=='Y'||ch=='y');
    getch();

    closegraph();
    return 0;
}
