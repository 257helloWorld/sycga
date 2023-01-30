#include<obs.h>
void start_game() {
	d_time(h,m,s,getmaxx()/2-25,25);
	int a = 0;
	int jump = 0;
	int line_v = 1;
	int x = 132, y = 261;
	int line_x = 132+60, line_y = 261;
	int dino_x = x+50;
	int dino_y = y+3;
	int obs_x = 480;
	int obs_y = 258;
	while(dino_y > 185) {
		clr_dino(dino_x,dino_y);
		dino_y--;
		dino(dino_x,dino_y);
		line(x+20,y,x+60,y);
		delay(2);
	}
	while(dino_y < 264) {
		clr_dino(dino_x,dino_y);
		dino_y++;
		dino(dino_x,dino_y);
		line(x+20,y,x+60,y);
		delay(2);
	}
	int d_a = 0;
	int d_b = 0;
	int d_c = 0;
	obs_g1(obs_x, obs_y);
	while(1) {
		// Time
		h = c_hours();
		m = c_mins();
		s = c_secs();
		if(s != t_s) {
			clr_d_time(t_h,t_m,t_s,getmaxx()/2-25,25);
			d_time(h,m,s,getmaxx()/2-25,25);
			t_s = s;
			t_m = m;
			t_h = h;
		}
		// End
		int t_x = dino_x;
		int t_y = dino_y;
		if(kbhit()) { a = getch(); }
		if(a == 8) {
			closegraph();
			break;
		}
		
		
		// Move dino first time
		if(dino_x < x+50+15 && d_c == 5) {
			clr_dino(dino_x,dino_y);
			dino_x += 1;
			dino(dino_x,dino_y);
		}
		
		if(d_b == 2 && d_b == 2) {
			clr_obs_g1(obs_x,obs_y);
			obs_x -= 2;
			obs_g1(obs_x,obs_y);
		}
		
		if(obs_x == 100) {
			clr_obs_g1(obs_x,obs_y);
			obs_x = 480;
		}
		
		if(a == 32) {
			if(dino_y == line_y + 3 && dino_x == x+50+15) {
				jump = 1;
				a = 0;
			}
		}
		
		if(jump == 1 && d_a == 2) {
			if(dino_y > 185) {
				dino_y -= 2;
			} else {
				jump = 2;
			}
		}
		if(jump == 2 && d_a == 2) {
			if(dino_y < 264) {
				dino_y += 2;
			} else {
				jump = 0;
			}
		}
		if(t_x != dino_x || t_y != dino_y) {
			clr_dino(t_x,t_y);
			dino(dino_x,dino_y);
		}
		
		// Redraw erased line
		if(line_v == 1) {
			line(x+20,y,x+60,y);
		}
		if(line_v == 0) {
			line(x+20,y,480,y);
		}
		
		if(line_x <= 480) {
			putpixel(line_x,line_y,WHITE);
			line_x++;
			if(line_x == 480) { line_v = 0; }
		}
		d_a++;
		d_b++;
		d_c++;
		if(d_a == 3) { d_a = 0; }
		if(d_b == 3) { d_b = 0; }
		if(d_c == 10) { d_c = 0; }
		
		delay(1);
	}
}
