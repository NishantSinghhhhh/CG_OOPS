#include<iostream>
#include<cmath>

using namespace std;

class Complex{
    private:
        double real;
        double imaginary;
    public:
        Complex(): real(0.0), imaginary(0.0){}
        Complex(double r, double i): real(r),imaginary(i){}
        double getReal() const{return real;}
        double getImag()const{return imaginary;}
        Complex operator + (const Complex& other) const{
            return Complex(real+other.real,imaginary+other.imaginary);
        }
        Complex operator - (const Complex& other)const{
            return Complex(real-other.real,imaginary-other.imaginary);
        }
        Complex operator *(const Complex& other){
            //(a+bi)*(c-di)=(ac-bd)+(ad+bc)i
            double r = real*other.real-imaginary*other.imaginary;
            double i = real*other.imaginary+imaginary*other.real;
            return Complex(r,i);
        }
        Complex operator / (const Complex& other)const{
            //[(a+bi)/(c+di)]=((a+bi)*(c-di))/(c^2+d^2)
            //(ac+bd)+(bc-ad)i
            double denominator=other.real*other.real+other.imaginary*other.imaginary;
            double real_part= (real*other.real+imaginary*other.imaginary)/denominator;
            double imag_part= (imaginary*other.real-real*other.imaginary)/denominator;
            return Complex(real_part,imag_part);
        }
        double argument() const{
            return atan2(imaginary,real);
        }
        friend ostream& operator << (ostream& out, Complex& c){
            out<< c.real <<"+"<<c.imaginary<<"i";
            return out;
        }
        friend istream& operator >>(istream& in, Complex& c){
            cout<<"Enter the real part of the complex number: ";
            in>>c.real;
            cout<<"Enter the imaginary part of the complex number: ";
            in>>c.imaginary;
            return in;
        }
};
int main(){
    Complex c1(2.0,5.1);
    Complex c2(5.0,6.0);
    //addition
    Complex sum = c1+c2;
    cout<<"sum: "<<sum<<endl;
    //Subtaction
    Complex sub = c1-c2;
    cout<<"Subtraction: "<<sub<<endl;
    //Multiplication
    Complex mul = c1*c2;
    cout<<"Multiplication: "<<mul<<endl;
    //Division
    Complex div = c1/c2;
    cout<<"Division: "<<div<<endl;
    //Argument
    cout<<"Argument of c1: "<<c1.argument()<<"radians"<<endl;
    Complex c3;
    cout<<"Enter a complex number: "<<endl;
    cin>>c3;
    cout<<"You entered: "<<c3<<endl;
    return 0;


}