#include<iostream.h>
#include<time.h>
#include<dos.h>
#include<graphics.h>
#include<conio.h>
void main(){
	int gd = DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	time_t isTime;
	struct tm *currentTime;
	char ch[100];
	while(!kbhit()){
	cleardevice();
	isTime = time(NULL);
	currentTime = localtime(&isTime);
	strftime(ch,100, "%I : %M : %S", currentTime);
	setcolor(1);
	settextstyle(SANS_SERIF_FONT , HORIZ_DIR , 7);
	outtextxy(100,100,ch);
	//Am Pm
	strftime(ch,100, "%p", currentTime);
	settextstyle(SANS_SERIF_FONT , HORIZ_DIR , 3);
	outtextxy(530,138,ch);
	delay(1000);
	}
	getch();
	closegraph();
}
