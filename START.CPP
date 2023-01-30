#include<graphics.h>
#include<conio.h>
#include<iostream.h>
#include<scene2.h>
#include<dos.h>
void main(){
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TC\\BGI");

	click_chrome();
//	delay(1000);
	cleardevice();
	open_chrome();


	getch();
	closegraph();
}