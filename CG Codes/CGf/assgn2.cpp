/*
	Name: Ayush Kumar Ghosh
	Roll no: 7215
	Assignment 2
*/
#include <GL/glut.h>
#include <iostream>
#include <math.h>

using namespace std;
class circle {
	
	public :
		int X1, Y1, r;
		void getPoints();
        void plot(int x, int y);
};


class bresenhamCircle : public circle{
	public:
		void drawCircle();
};
class ddaCircle : public circle{
	public :
	void drawCircle();
};
class midPointCircle : public circle{
	public :
	void drawCircle();
};

void circle :: plot(int x, int y){
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
}
void circle :: getPoints(){
	cout << "Enter the coordinates of the center:\n";
	cout << "X-coordinate   : "; cin >> X1;
	cout << "Y-coordinate : "; cin >> Y1;
	cout << "Enter radius : "; cin >> r;
	cout << "-------------------------------\n";
}
void midPointCircle::drawCircle()
{
	int x = 0;
	int y = r;
	float decision = 5/4 - r;
	plot(x, y);

	while (y > x)
	{
		if (decision < 0)
		{
			x++; 
			decision += 2*x+1;
		}
		else
		{
			y--;
			x++;
			decision += 2*(x-y)+1;
		}
		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);
		plot(y, x);
		plot(-y, x);
		plot(y, -x);
		plot(-y, -x);
	}

}
void bresenhamCircle :: drawCircle(){
	int x = 0, y = r;
	float d = 1.5 - r;

	while (y >= x){
		plot(x+X1,y+Y1);
		plot(x+X1,-y+Y1);
		plot(-x+X1,y+Y1);
		plot(-x+X1,-y+Y1);
		plot(y+X1,x+Y1);
		plot(y+X1,-x+Y1);
		plot(-y+X1,x+Y1);
		plot(-y+X1,-x+Y1);
		if (d < 0)
			d += 2*x + 1;
		else {
			d += 2*(x-y) + 1;
			y--;
		}
		x++;
	}
}

void ddaCircle :: drawCircle(){
	float x1,x2,y1,y2,eps,sx,sy;
	int val,i;
	x1=r;
	y1=0;
	sx=x1;
	sy=y1;
	i=0;
	
	do {
		val = pow(2,i);
		i++;
	}while(val < r);
	eps = 1/pow(2,i-1);
	
	do {
		x2 = x1 + y1*eps;
		y2 = y1 - eps*x2;
		plot(X1+x2,Y1-y2);
		x1=x2;
		y1=y2;
	}while((y1-sy)<eps || (sx-x1)>eps);
}
void myInit(){
	glClearColor(0,0,0,0);
	glColor3f(1,1,1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500,500,-500,500);
}
void keyboard (unsigned char key, int x, int y) {
	if (key == 'd'||key=='D') {
        ddaCircle dda;
		dda.getPoints();
		dda.drawCircle();
    }
	if (key == 'b'||key=='B') {
        bresenhamCircle bc;
		bc.getPoints();
		bc.drawCircle();
    }
    if(key=='m'||key=='M'){
		midPointCircle mpc;
		mpc.getPoints();
		mpc.drawCircle();
	}
	if(key==27)  exit (0);
}

int main(int argc, char** argv){
	
	
	cout << "---MENU---\n";
	cout << "D or d - DDA Circle Drawing Algorithm\n";
	cout << "B or b-  BresenhamCircle Drawing Algorithm \n";
	cout << "M or m- Midpoint Circle Drawing Algorithm\n";
	cout << "ESC for exit\n";
	
		
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);
	glutInitWindowSize(400,400);
	glutInitWindowPosition(50,50);
    
	glutCreateWindow("Circle Drawing Algoritm");
    glutKeyboardFunc(keyboard);
	myInit();
	
	
	glutMainLoop();

	return 0;
}


