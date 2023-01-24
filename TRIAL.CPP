#include<graphics.h>
#include<conio.h>
#include<iostream.h>
#include<dos.h>
#include<dino.h>

void main() {
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TC\\BGI");

	int x = getmaxx()/2;
	int y = getmaxy()/2;
	line(50,y,590,y);
	int dino_x = 100;
	int dino_y = getmaxy()/2 + 4;
	dino(dino_x,dino_y);
	int obs_x = 640;
	int obs_y = getmaxy()/2;
	rectangle(obs_x, obs_y, obs_x+20, obs_y-20);

	int a = 0;
	int jump = 0;
	while(1) {
		cleardevice();
		line(50,y,590,y);
		obs_x--;
		rectangle(obs_x, obs_y, obs_x+20, obs_y-20);
		int temp_x = dino_x;
		int temp_y = dino_y;
		if(obs_x < 0) {
			obs_x = 640;
		}
		if(kbhit()) {
			a = getch();
		}
		if(a == 59) {
			closegraph();
			break;
		}
		if(a == 32) {
			jump = 1;
			a = 0;
		}
		if(jump == 1) {
			if(dino_y >= 160) {
				dino_y--;
			}
			if(dino_y == 160) {
				jump = 2;
			}
		}
		if(jump == 2) {
			if(dino_y < (getmaxy()/2+4)) {
				dino_y++;
			}
		}
		dino(dino_x,dino_y);
		delay(3);
	}

	getch();
	closegraph();
}