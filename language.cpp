#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Node{
    public:
    int indegree=0;
    char type;
    int id;
    char character;
    string language;
    Node* YES=NULL;
    Node* NO=NULL;
};

void inorder(Node* root){
    Node* temp=root;
    if(temp==NULL){
        return;
    }
    inorder(temp->YES);
    if(temp->type=='I'){
        cout<<temp->character<<" ";
    }
    else{
        cout<<temp->language<<" ";
    }
    inorder(temp->NO);
}

void preorder(Node* root){
    Node* temp=root;
    if(temp==NULL){
        return;
    }
    if(temp->type=='I'){
        cout<<temp->character<<" ";
    }
    else{
        cout<<temp->language<<" ";
    }
    preorder(temp->YES);
    preorder(temp->NO);
}

int searchIndex(vector<int> array,int num){
    for(int i=0;i<array.size();i++){
        if(array[i]==num){
            return i;
        }
    }
    return -1;
}

bool searchChar(string phrase,char character){
    for(int i=0;i<phrase.size();i++){
        if(phrase[i]==character){
            return true;
        }
    }
    return false;
}

void languageArray(Node* root,string phrase,vector<string> & final){
    if(root->type=='L'){
        final.push_back(root->language);
        return;
    }
    else{
        if(searchChar(phrase,root->character)){
            languageArray(root->YES,phrase,final);
        }
        else{
            languageArray(root->YES,phrase,final);
            languageArray(root->NO,phrase,final);
        }
    }

}

void heapify(vector<string> *arr, int n, int m)
{
    int max=m;
    int l=2*m+1;
    int r=2*m+2;
    if (l < n && (*arr)[l] > (*arr)[max])
        max = l;
    if (r < n && (*arr)[r] > (*arr)[max])
        max = r;
    if (max != m)
    {
        (*arr)[m].swap((*arr)[max]);
        heapify(arr, n, max);
    }
}

void heapSort(vector<string> *arr, int n)
{
    for (int i=n/2 - 1;i>-1;i--)
        heapify(arr,n, i);
    for (int i=n-1;i>-1;i--)
    {
        (*arr)[0].swap((*arr)[i]);
        heapify(arr,i,0);
    }
}

int main(){
    int n,p;
    int j=0;
    cin>>n>>p;
    vector<Node*> tree(n,NULL);
    vector<int> mapping(n,-1);
    for(int i=0;i<n;i++){
        Node* temp=new Node();
        tree[i]=temp;
    }
    for(int i=0;i<n;i++){
        char t;
        cin>>t;
        if(t=='I'){
            int id;
            cin>>id;
            if(searchIndex(mapping,id)==-1){
                mapping[j]=id;
                j++;
            }
            tree[searchIndex(mapping,id)]->type='I';
            cin>>tree[searchIndex(mapping,id)]->character;
            int yesid;
            cin>>yesid;
            if(searchIndex(mapping,yesid)==-1){
                mapping[j]=yesid;
                j++;
            }
            tree[searchIndex(mapping,id)]->YES=tree[searchIndex(mapping,yesid)];
            tree[searchIndex(mapping,yesid)]->indegree+=1;
            int noid;
            cin>>noid;
            if(searchIndex(mapping,noid)==-1){
                mapping[j]=noid;
                j++;
            }
            tree[searchIndex(mapping,id)]->NO=tree[searchIndex(mapping,noid)];
            tree[searchIndex(mapping,noid)]->indegree+=1;
        }
        else if(t=='L'){
            int id;
            cin>>id;
            if(searchIndex(mapping,id)==-1){
                mapping[j]=id;
                j++;
            }
            tree[searchIndex(mapping,id)]->type='L';
            cin>>tree[searchIndex(mapping,id)]->language;
            tree[searchIndex(mapping,id)]->YES=NULL;
            tree[searchIndex(mapping,id)]->YES=NULL;
        }
    }
    Node* root=NULL;
    for(int i=0;i<n;i++){
        if(tree[i]->indegree==0){
            root=tree[i];
        }
    }
    // inorder(root);
    // cout<<endl;
    // preorder(root);
    fflush(stdin);
    for(int i=0;i<p;i++){
        string phrase;
        getline(cin,phrase);
        vector<string> final;
        languageArray(root,phrase,final);
        heapSort(&final,final.size());
        for(int i=0;i<final.size();i++){
            cout<<final[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}