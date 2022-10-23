#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int main() {
    string input;
    getline(cin,input);
    int size=input.size();
    for(int i=0;i<size;i++){
        char letter=input[i];
        if((letter<=90 && letter>=65)||(letter<=122 && letter>=97)){
        int offset = 'a'-'m';
        if(('a'<=letter && letter<'m') || ('A'<=letter && letter<'M')){
            letter+=26;
        }
        cout<<(char)(letter+offset);
        }
        else{
            cout<<letter;
        }
    }
    return 0;
}