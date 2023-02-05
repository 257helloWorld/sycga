#include<graphics.h>
#include<dino.h>
#include<conio.h>
#include<iostream.h>

void main() {
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	int x = getmaxx()/2;
	int y = getmaxy()/2;
	l_dino(x,y);
	getch();
	closegraph();
}
