#include <GL/glut.h>
#include <iostream>

using namespace std;

class Circle{
	public:
		void make(double x, double y){
    		glBegin(GL_POINTS);
    		glVertex2i(x, y);
    		glEnd();
		}
		
		void circle_bresenhem(double ar, double ax1, double ay1){
			int r = ar, xc = ax1, yc = ay1;
			int x = 0, y = r;
			int d = 3 - 2 * r;
			
				while(y >= x){
					x++;
						
						if(d > 0){
							y--;
							d += 4 * (x - y) + 10;
						}
						
						else
							d += 4 * x + 6;
							
					glPointSize(2.0);
					glColor3f(1, 1, 1);
					
					make(xc + x, yc + y);
		            make(xc + x, yc - y);
		            make(xc - x, yc + y);
		            make(xc - x, yc - y);
		            make(xc + y, yc + x);
		            make(xc + y, yc - x);
		            make(xc - y, yc + x);
		            make(xc - y, yc - x);
				}
			glFlush();
		}
};
