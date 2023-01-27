#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<scene1.h>

void window() {
	rectangle(27,80,616,461);
	line(27,110,616,110);
}

void url_google() {
	settextstyle(2,0,5);
	outtextxy(250,87,"https://google.co.in");
}

void google() {
	settextstyle(3,0,7);
	outtextxy(233,190,"Google");
	setcolor(WHITE);
}

void search_bar() {
	for(int x = 160; x < 480; x++) {
		circle(x,320,14);
	}
	setcolor(BLACK);
	for(int y = 160; y < 480; y++) {
		circle(y,320,13);
	}
	setcolor(WHITE);
	circle(480-10,318,5);
	line(475,323,478,326);
}
void search_button() {
	setcolor(WHITE);
	int x = 190;
	int y = 360;
	settextstyle(2,0,4);
	rectangle(x,y,x+100,y+20);
	outtextxy(x+13,y+4,"Google Search");
}
void lucky_button() {
	setcolor(WHITE);
	int x = 320;
	int y = 360;
	settextstyle(2,0,4);
	rectangle(x,y,x+120,y+20);
	outtextxy(x+13,y+4,"I'm Feeling Lucky");
}

void wifi_off() {
	clr_wifi_icon();
	wifi_off_icon();
}

void open_chrome() {
	taskbar();
	int a = 0;
	int cur_x = 84;
	int cur_y = 128;
	window();
	google();
	search_bar();
	url_google();
	search_button();
	lucky_button();
	while(1) {
		if(kbhit()) {
			a = getch();
			if(a == 8) {
				closegraph();
				break;
			}
			if(a == 59) {
				wifi_off();
			}
		}
	}
}

void main() {
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
//	click_chrome();
//	delay(300);
//	cleardevice();
	open_chrome();
}
