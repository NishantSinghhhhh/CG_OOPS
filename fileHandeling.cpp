#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main(){
    const string filename ="example.txt";
    {
        ofstream outFile(filename);
        if(!outFile){
            cerr<<"Error opening file to write"<<endl;
            return 1;
        }
        outFile<<"Hello,World"<<endl;
        outFile<<"This is a simple C++ program."<<endl;
        outfile<<"Goodbye!"<<endl;
        outFile.close();
    }
    {
        ifstream inFile(filename);
        if(!inFile){
            cerr<<"Error opening file for reading."<<endl;
            return 1;
        }
        string line;
        while(getline(infile,line)){
            cout<<line<<endl;
        }
        inFile.close();
    }
    return 0;
}