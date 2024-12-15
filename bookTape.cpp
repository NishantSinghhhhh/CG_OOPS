#include<iostream>
#include<string>

using namespace std;

class Publication{
    string title;
    float price;
    public:
        void getData(){
            cout<<"Enter the title: ";
            cin.ignore();
            getline(cin,title);
            cout<<"Enter the price: ";
            cin>>price;
            if(price<=0)throw invalid_argument("Invalid Price");
        }
        void displayData()const{
            cout<<"Title: "<<title<<"\nPrice: "<<price<<endl;
        }
};
class Book:public Publication{
    int pages;
    public:
        void getData(){
            Publication::getData();
            cout<<"Enter the number of pages of the book: ";
            cin>>pages;
            if(pages<=0)throw invalid_argument("Invalid page count");
        }
        void displayData(){
            Publication::displayData();
            cout<<"Page count: "<<pages<<endl;
        }
};
class Tape:public Publication{
    float playtime;
    public:
        void getData(){
            Publication::getData();
            cout<<"Enter the play time of the tape: ";
            cin>>playtime;
            if(playtime<=0)throw invalid_argument("Invalid playtime!");

        }
        void displayData(){
            Publication::displayData();
            cout<<"Play time: "<<playtime<<"minutes"<<endl;
        }
};
int main(){
    Book book;
    Tape tape;
    try{
        cout<<"Enter data for the book:\n";
        book.getData();
    }catch(...){
        book=Book();
        cout<<"Invalid Input.Resetting book data.\n";
    }
    try{
        cout<<"Enter the data for tape:\n";
        tape.getData();
    }
    catch(...){
        tape=Tape();
        cout<<"Invalid input.Resetting tape data.\n";
    }
    cout<<"\nBook Details:\n";
    book.displayData();
    cout<<"\nTape Details:\n";
    tape.displayData();
    return 0;
}
