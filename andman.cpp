#include <iostream>
#include<vector>
#include<stack>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        data=d;
        next=NULL;
    }
};

void insertNode(int data,Node* & head){
    Node* temp=new Node(data);
    if(head==NULL){
        head=temp;
    }
    else{
        Node* temp2=head;
        while (temp2->next!=NULL)
        {
            temp2=temp2->next;
        }
        temp2->next=temp;
        
    }
}

void display(Node * head,vector<unsigned long long> array){
    while(head!=NULL){
        cout<<"->"<<head->data<<","<<array[head->data-1]<<" ";
        head=head->next;
    }
    cout<<endl;
}

void addEdge(int a,int b,vector<Node*> & g1){
    insertNode(b,g1[a-1]);
    insertNode(a,g1[b-1]);
}

void printGraph(vector<Node*> g1,int n,vector<unsigned long long> array){
    for(int i=0;i<n;i++){
        cout<<i+1<<endl;
        display(g1[i],array);
    }
}

void pathFinder(vector<Node*> graph,vector<int>& visited,vector<int>& path,int u,int v,bool & found){
    visited[u-1]=1;
    path.push_back(u);
    stack<int> s;
    s.push(u);
    int x=s.top();
    s.pop();
    int k=0;
    while(true){
        if(k!=0){
            x=s.top();
            path.push_back(x);
            s.pop();
        }
        Node* temp=graph[x-1];
        while(temp!=NULL){
            if(visited[temp->data-1]==1){
                temp=temp->next;
                continue;
            }
            s.push(temp->data);
            visited[temp->data-1]=1;
            temp=temp->next;
        }
        if(k!=0){
            path.pop_back();
        }
        k=1;
    }
}

int main() {
    int t;
    cin>>t;
    fflush(stdin);
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        fflush(stdin);
        vector<Node*> graph(n,NULL);
        vector<unsigned long long> array(n);
        for(int i=0;i<n;i++){
            cin>>array[i];
        }
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            addEdge(u,v,graph);
        }
        int q;
        cin>>q;
        fflush(stdin);
        for(int i=0;i<q;i++){
            int t,u,w;
            cin>>t>>u>>w;
            fflush(stdin);
            if(t==1){
                array[u-1]=w;
            }
            else if(t==2){
                vector<int> visited(n,0);
                vector<int> path;
                bool found=false;
                pathFinder(graph,visited,path,u,w,found);
                unsigned long long product=1;
                for(int i=0;i<(int)path.size();i++){
                    product=product*array[path[i]-1];
                }
                cout<<product%1000000007<<endl;
            }
        }
    }
    return 0;
}