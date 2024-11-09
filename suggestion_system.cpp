#include<bits/stdc++.h>
using namespace std;
int k;
class Node{
public:
    Node* child[26];
    bool end;
    int count;
    Node(){
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
        end=false;
        //count=0;
    }
    void insert(Node* root,string str){
        Node* temp=root;
        for(int i=0;i<str.size();i++){
            int ind=str[i]-'a';
            if(temp->child[ind]==NULL){
                temp->child[ind]=new Node();
            }
            temp=temp->child[ind];
        }
        temp->end=true;
    }
    vector<string> find(Node* root,string &prefix){
        vector<string>ans;
        Node* temp=root;
        for(char c:prefix){
            int ind=c-'a';
            if(!temp->child[ind]){
                return ans;
            }
            temp=temp->child[ind];
        }
        dfs(temp,prefix,ans);
        return ans;
    }
    void dfs(Node* node,string prefix,vector<string>&ans){
        if(ans.size()>=k){
            return;
        }
        if(node->end){
            ans.push_back(prefix);
        }
        for(int i=0;i<26;i++){
            if(node->child[i]){
                dfs(node->child[i],prefix+char(i+'a'),ans);
            }
        }
    }
};
int main() {
        Node t;
        Node* root=new Node();
        int n;
        cout<<"How many words you will enter:"<<endl;
        cin>>n;
        cout<<"Enter those words:"<<endl;
        for(int i=0;i<n;i++){
            string e;
            cin>>e;
            t.insert(root,e);
        }
        string prefix,searchWord;
        cout<<"Enter the search Word:"<<endl;
        cin>>searchWord;
        cout<<"How many No.of suggestion words you want:";
        cin>>k;
        for(char c:searchWord){
            prefix+=c;
            cout<<"when entered:"<<" "<<prefix<<endl;
            vector<string>temp=(t.find(root,prefix));
            for(int i=0;i<temp.size();i++){
                cout<<temp[i]<<endl;
            }
            cout<<endl;
        }
}

