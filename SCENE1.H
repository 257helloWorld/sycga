#include<graphics.h>
#include<conio.h>
#include<iostream.h>
#include<dos.h>

void cursor(int x, int y) {
	setcolor(WHITE);
	line(x,y,x+1,y+16);
	line(x+1,y+16,x+5,y+8);
	line(x,y,x+14,y+9);
	line(x+14,y+9,x+5,y+8);
	setfillstyle(SOLID_FILL,WHITE);
	floodfill(x+2,y+5,WHITE);
}

void clr_cursor(int x, int y) {
	setcolor(BLACK);
	line(x,y,x+1,y+16);
	line(x+1,y+16,x+5,y+8);
	line(x,y,x+14,y+9);
	line(x+14,y+9,x+5,y+8);
	setfillstyle(SOLID_FILL,BLACK);
	floodfill(x+2,y+5,BLACK);
}

void taskbar() {
	// Battery Icon
	rectangle(569,33,579,40);
	rectangle(579,40,569,25);

	setfillstyle(SOLID_FILL,WHITE);
	floodfill(573,36,WHITE);

	settextstyle(2,0,5);
	outtextxy(590,25,"78%");

	// Wi-Fi Icon
	sector(546,38,50,130,12,12);
}

void chrome_icon(int x, int y) {
	setcolor(WHITE);
	circle(x,y,25);
	circle(x,y,13);
	circle(x,y,8);

	line(x,y-13,x+20,y-13);
	line(x,y+25,x+13,y+4);
	line(x-12,y+5,x-20,y-13);

	settextstyle(2,0,5);
	outtextxy(x-22,y+35,"Chrome");
}

void clr_chrome_icon(int x, int y) {
	setcolor(BLACK);
	circle(x,y,25);
	circle(x,y,13);
	circle(x,y,8);

	line(x,y-13,x+20,y-13);
	line(x,y+25,x+13,y+4);
	line(x-12,y+5,x-20,y-13);

	settextstyle(2,0,5);
	outtextxy(x-22,y+35,"Chrome");
}

void desktop() {
	line(0,57,getmaxx(),57);
	chrome_icon(84,128);
	taskbar();
}

void click_animation() {
	int cur_x = 84;
	int cur_y = 128;
	clr_chrome_icon(84,128);
	clr_cursor(cur_x,cur_y);
	setcolor(LIGHTGRAY);
	rectangle(47,189,123,95);
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	floodfill(112,161,LIGHTGRAY);
	chrome_icon(84,128);
	cursor(cur_x,cur_y);
}

void cursor_movement() {
	int cur_x = 326;
	int cur_y = 248;
	int flag1 = 0;
	int cursor_move = 1;
	// Initial cursor
	cursor(cur_x,cur_y);
	// Movemet
	while(cursor_move == 1) {
		clr_cursor(cur_x,cur_y);
		cur_x = cur_x -1;
		cur_y = (flag1%2 == 0) ? cur_y-1 : cur_y;
		cursor(cur_x,cur_y);
		if(cur_x == 84) {
			cursor_move = 0;
		}
		chrome_icon(84,128);
		flag1++;
		delay(2);
	}

}

void click_chrome() {
	desktop();
	cursor_movement();
	delay(300);
	click_animation();

}
