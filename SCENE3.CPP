#include<scene1.h>
#include<scene2.h>
#include<dino.h>

void startgame() {
	setcolor(LIGHTGRAY);
	int x = 112, y = 261;
	line(x,y,x+420,y);
	setcolor(WHITE);
	dino(x+50,y+3);
	setcolor(LIGHTGRAY);
	settextstyle(2,0,6);
	outtextxy(x+10,y+25,"No Internet");
	settextstyle(2,0,4);
	outtextxy(x+10,y+55,"Try;");
	outtextxy(x+50,y+68,"Checking the network cables, modem and router.");
	outtextxy(x+50,y+82,"Reconnecting to Wi-Fi");
	outtextxy(x+10,y+100,"ERROR_INTERNET_DICONNECTED");

}

void scene3() {
	taskbar();
	clr_wifi_icon();
	wifi_off_icon();
	window();
	startgame();
}

void main() {
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	scene3();
	getch();
	closegraph();
}
