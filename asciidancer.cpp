#include<iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

void mirrorImage(string & current){
    if(current[0]=='(' && current[2]==' '){
        current[0]=' ';
        current[2]=')';
    }
    else if(current[0]==' ' && current[2]==')'){
        current[0]='(';
        current[2]=' ';
    }
    else if(current[4]=='/' && current[6]==' '){
        current[4]=' ';
        current[6]='\\';
    }
    else if(current[4]==' ' && current[6]=='\\'){
        current[6]=' ';
        current[4]='/';
    }
    else if(current[4]=='/' && current[6]=='>'){
        current[4]='<';
        current[6]='\\';
    }
    else if(current[4]=='<' && current[6]=='\\'){
        current[4]='/';
        current[6]='>';
    }
    if(current[4]==' ' && current[6]=='>'){
        current[4]='<';
        current[6]=' ';
    }
    else if(current[4]=='<' && current[6]==' '){
        current[4]=' ';
        current[6]='>';
    }
    if(current[8]=='/' && current[10]=='>'){
        current[8]='<';
        current[10]='\\';
    }
    else if(current[8]=='<' && current[10]=='\\'){
        current[8]='/';
        current[10]='>';
    }
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string current=" o \n/|\\\n/ \\";
        int face=0;
        int d;
        cin>>d;
        fflush(stdin);
        for(int i=0;i<d;i++){
            string command;
            int size=command.size();
            getline(cin,command);
            string opcode=command.substr(0,3);
            if(opcode=="say"){
                string msg=command.substr(4,size-1);
                cout<<msg;
                cout<<"\n";
            }
            else{
                if(command=="left hand to hip" && face==0){
                    current[2]=' ';
                    current[6]='>';
                    cout<<current<<endl;
                }
                else if(command=="left hand to head" && face==0){
                    current[6]=' ';
                    current[2]=')';
                    cout<<current<<endl;
                }
                else if(command=="left hand to start" && face==0){
                    current[2]=' ';
                    current[6]='\\';
                    cout<<current<<endl;
                }
                else if(command=="left leg in" && face==0){
                    current[10]='>';
                    cout<<current<<endl;
                }
                else if(command=="left leg out" && face==0){
                    current[10]='\\';
                    cout<<current<<endl;
                }
                else if(command=="right hand to hip" && face==0){
                    current[0]=' ';
                    current[4]='<';
                    cout<<current<<endl;
                }
                else if(command=="right hand to head" && face==0){
                    current[4]=' ';
                    current[0]='(';
                    cout<<current<<endl;
                }
                else if(command=="right hand to start" && face==0){
                    current[0]=' ';
                    current[4]='/';
                    cout<<current<<endl;
                }
                else if(command=="right leg in" && face==0){
                    current[8]='<';
                    cout<<current<<endl;
                }
                else if(command=="right leg out" && face==0){
                    current[8]='/';
                    cout<<current<<endl;
                }
                else if(command=="turn" && face==0){
                    mirrorImage(current);
                    face=1;
                    cout<<current<<endl;
                }
                else if(command=="right hand to hip" && face==1){
                    current[2]=' ';
                    current[6]='>';
                    cout<<current<<endl;
                }
                else if(command=="right hand to head" && face==1){
                    current[6]=' ';
                    current[2]=')';
                    cout<<current<<endl;
                }
                else if(command=="right hand to start" && face==1){
                    current[2]=' ';
                    current[6]='\\';
                    cout<<current<<endl;
                }
                else if(command=="right leg in" && face==1){
                    current[10]='>';
                    cout<<current<<endl;
                }
                else if(command=="right leg out" && face==1){
                    current[10]='\\';
                    cout<<current<<endl;
                }
                else if(command=="left hand to hip" && face==1){
                    current[0]=' ';
                    current[4]='<';
                    cout<<current<<endl;
                }
                else if(command=="left hand to head" && face==1){
                    current[4]=' ';
                    current[0]='(';
                    cout<<current<<endl;
                }
                else if(command=="left hand to start" && face==1){
                    current[0]=' ';
                    current[4]='/';
                    cout<<current<<endl;
                }
                else if(command=="left leg in" && face==1){
                    current[8]='<';
                    cout<<current<<endl;
                }
                else if(command=="left leg out" && face==1){
                    current[8]='/';
                    cout<<current<<endl;
                }
                else if(command=="turn" && face==1){
                    mirrorImage(current);
                    face=0;
                    cout<<current<<endl;
                }
            }
        }
    }
    return 0;
}