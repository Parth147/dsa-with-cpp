//largest common prefix->approach 1;
#include<iostream>
using namespace std;
#include<vector>
string longest(vector<string>v){
    string ans="";
    for(int i=0;i<v[0].length();i++){
        for(int j=1;j<v.size();j++){
            if(v[0][i]!=v[j][i]){
                return ans;
            }
        }
        ans.push_back(v[0][i]);
    }
    return ans;
}
//2nd approach using trie
class node{
    public:
    char data;
    int childcount;
    node *children[26];
    bool isterminal;
    node(char data){
        this->data=data;
        isterminal=0;
        childcount=0;
        for(int i=0;i<26;i++){
            children[i]=0;
        }
    }
};
class trie{
    public:
    node *root=new node('\0');                     
    void insertword(node *root,string s){
        if(s.length()==0){
            root->isterminal=1;
            return;
        }
        int index=s[0]-'a';
        node *child;
        if(root->children[index]!=0){
            child=root->children[index];
        }
        else{
            child= new node(s[0]);
            root->children[index]=child;
            root->childcount++;
        }
        insertword(child,s.substr(1));
    }
    void insert(string s){
        insertword(root,s);
    }
    string lcp(string str){
        string ans="";
        node *temp=root;
        for(int i=0;i<str.length();i++){
            if(temp->childcount==1){
                ans.push_back(str[i]);
                temp=temp->children[str[i]-'a'];
            }
            else{
                break;
            }
        }
        return ans;
    }
};
int main(){
    vector<string>s={"pinja","night","nil","nikal"};
    trie t;
    for(int i=0;i<s.size();i++){
        t.insert(s[i]);
    }
    cout<<t.lcp(s[0]);
    //string ans=longest(s);
    //cout<<ans;
}
