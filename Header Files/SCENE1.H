#include<layout.h>

void desktop() {
	taskbar();
	wifi_icon();
	battery_icon();
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
	setcolor(WHITE);
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
	chrome_icon(84,128);
	cursor_movement();
	delay(300);
	click_animation();

}
