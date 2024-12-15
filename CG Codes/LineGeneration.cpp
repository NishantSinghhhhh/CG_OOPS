#include <iostream>
#include <GL/glut.h>
#include <math.h>

using namespace std;

class Line{
	public:
		void make(double x, double y){
		    glBegin(GL_POINTS);
		    glVertex2i(x, y);
		    glEnd();
		}
		
	    void line_bresenhem(double ax1, double ay1, double ax2, double ay2){
	        if (ax2 < ax1){
	            swap(ax2, ax1);
	            swap(ay1, ay2);
	        }
	
	        int dx = ax2 - ax1, dy = ay2 - ay1;
			int x = ax1, y = ay1;
	        
			glPointSize(2.0);
	        glColor3f(0.5, 0.5, 0.5);
	        
			make(x, y);	
	        
			int dp = 2 * dy - dx;
	        
			if (abs(dx) >= abs(dy)){
	
				if (dy >= 0)
	                for (int i = 0; i < dx; i++){
	                    x++;
	                    
						if (dp >= 0){
	                        y++;
	                        dp += (2 * dy - 2 * dx);
	                    }
	                    
						else
	                        dp += (2 * dy);

	                    glColor3f(0.5, 0.5, 0.5);
	                    make(x, y);
	                }
	            
				else{
	                dy = abs(dy);
	                
					for (int i = 0; i < dx; i++){
	                    x++;
	                    
						if (dp >= 0){
	                        y--;
	                        dp += (2 * dy - 2 * dx);
	                    }
	                    
						else
	                        dp += (2 * dy);
	
	                    glColor3f(0.5, 0.5, 0.5);
	                    make(x, y);
	                }
	            }
	        }
	        
			else{
				dp = 2 * dx - dy;
	            
				if (dy >= 0)
					for (int i = 0; i < dy; i++){
	                    y++;
	                    
						if (dp >= 0){
	                        x++;
	                        dp += (2 * dx - 2 * dy);
	                    }
	                    
	                    else
	                        dp += (2 * dx);
	                    
	                    glColor3f(0.5, 0.5, 0.5);
	                    make(x, y);
	                }
	                
	            else{
	                dy = abs(dy);
	                
					for (int i = 0; i < dy; i++){
	                    y--;
	                    
						if (dp >= 0){
	                        x++;
	                        dp += (2 * dx - 2 * dy);
	                    }
	                    
	                    else
	                        dp += (2 * dx);
	                
	                    glColor3f(0.5, 0.5, 0.5);
	                    make(x, y);
	                }
	            }
	        }
	        
	        glFlush();
	    }
};

