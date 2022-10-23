#include<iostream>
#include<vector>
#include<string.h>
#include<stdlib.h>
using namespace std;

int main(){
    int p;
    cin>>p;
    fflush(stdin);
    int n;
    cin>>n;
    fflush(stdin);
    char ch;
    int r,c;
    cin>>r>>ch>>c;
    char position;
    cin>>position;
    fflush(stdin);
    vector<string> phrases(p);
    for(int i=0;i<p;i++){
        cin>>phrases[i];
    }
    vector<char> row(c,'\0');
    vector<vector<char>> matrix(r,row);
    for(int i=0;i<n;i++){
        int j=0;
        label:
        int msgindex=3;
        string xmlline;
        getline(cin,xmlline);
        string tag=xmlline.substr(0,3);
        if(tag=="<p>"){    
            while(j<r){
                int k=0;
                while(k<c){
                    if(xmlline[msgindex]=='<'){
                        i++;
                        k++;
                        msgindex=3;
                        continue;
                    }
                    cout<<i<<j<<k<<endl;
                    matrix[j][k]=xmlline[msgindex];
                    msgindex++;
                    k++;
                }
                j++;
            }
        }
    }
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}