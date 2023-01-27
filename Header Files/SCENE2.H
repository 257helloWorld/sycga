#include<scene1.h>
#include<dino.h>
#include<game.h>

int wifi = 0;

void wifi_off_layout() {
	window();
	window_title();
	taskbar();
	battery_icon();
	wifi_off_icon();
	setcolor(LIGHTGRAY);
	int x = 132, y = 261;
//	line(x+20,y,x+400,y);
	line(x+20,y,x+60,y);
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

void wifi_on_layout() {
	taskbar();
	battery_icon();
	wifi_icon();
	window();
	window_title();
	google();
	search_bar();
	search_button();
	lucky_button();
}

void toggle_wifi() {
	if(wifi == 1) {
		clr_wifi_icon();
		wifi_off_icon();
		cleardevice();
		wifi_off_layout();
		wifi = 0;
	} else  {
		clr_wifi_off_icon();
		wifi_icon();
		cleardevice();
		wifi_on_layout();
		wifi = 1;
	}
}

void scene2() {
	int a = 0;
	if(wifi == 1) {	wifi_on_layout(); }
	if(wifi == 0) { wifi_off_layout(); }
	while(1) {
		a = 0;
		if(kbhit()) {
			a = getch();
			if(a == 8 || a == 7) {
				closegraph();
				break;
			}
			if(a == 59) {
				toggle_wifi();
			}
			if(wifi != 1 && a == 32) {
				start_game();
				break;
			}
		}

	}
}

void open_chrome() {
	scene2();
}
