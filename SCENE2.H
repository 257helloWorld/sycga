void open_chrome() {
	taskbar();
	
	// Window
	rectangle(27,80,616,461);
	line(27,110,616,110);
	
	// Google
	settextstyle(6,0,7);
	outtextxy(233,200,"Google");
	setcolor(WHITE);
	settextstyle(2,0,5);
	outtextxy(250,87,"https://google.co.in");
	
	// Search Bar
	for(int x = 160; x < 480; x++) {
		circle(x,330,14);
	}
	setcolor(BLACK);
	for(int y = 160; y < 480; y++) {
		circle(y,330,13);
	}
}
