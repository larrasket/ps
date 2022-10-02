#include <iostream>
#include "ArgumentManager.h"
#include <fstream>
#include <stack>
#include <queue>
#include <iterator>
#include <algorithm>
#include<cassert>
#include <map>
#include<cmath>
using namespace std;
struct node
{
    int *key;
    node **child;
    bool leaf;
    int n;
    node(int deg)
    {
        key = new int[deg];
        leaf = true;
        child=new node*[deg+1];
        n = 0;
        for(int i=0;i<deg;i++){
            child[i]=NULL;
        }
    }
    node* findNode(int data, node*temp,int t,node* root);
    void splitChild(node*temp,int t);
    void fullCheck(node*temp,int t);
    void printLevel(node*temp,int level,ofstream& fout);
    void height(node*temp,int height,int& result);
};

class btree{
    private:
    node* root;
    int t;
    public:
    btree(int val){
    root=NULL;
    t=val;
    }

    node* getRoot(){
        return root;
    }

    void insert(int data){


        if(root==NULL){
            root=new node(t);
            root->leaf=true;
            root->key[0]=data;
            root->n=1;
        }
        else{
           root= root->findNode(data, root,t,root);
           // root->fullCheck(root,t);
            }
    }

    void printLevel(int level,ofstream &fout){
        root->printLevel(root,level,fout);
    }

    int height(){
        int result;
        root->height(root,1,result);
        return result;
    }

};

node* node::findNode(int data, node* node_active,int t,node*temp){

        if(leaf){
            int i=t;
            /// go through keys until the value before it isnt null///
            while(!key[i-1]){
                i--;
            }
            //// if value before key is greater than the data push it to the right///
            while(key[i-1]>data && i!=0){
                key[i]=key[i-1];
                i--;
            }
            //// insert the value in the respective place in the node////
            key[i]=data;
            n=n+1;
              }
        else{
            ///// If the node is not leaf go to its appropriate child ////
             int i=0;
            while(i<n && data>key[i] ){
                i++;
            }
            child[i]->findNode(data,this,t,temp);
            //node_active->child[i]->findNode(data,node_active,t,temp);
        }
        ////// After insertion if the node is full then split it/////
        if(n==t){
///// If it is a root make the root the child of a new node then split the new node child///
            if(this==temp){
                node*s=new node(t);
                s->leaf=false;
                s->child[0]=this;
                s->splitChild(this,t);
                return s;

            }
            else{
                ///// split the child of this parent /////.
               node_active->splitChild(this,t);
            }


        }
        return temp;
    }


    void node::splitChild(node*fullNode, int t){
        node*rightNode=new node(t);
        int i_right=0,move_up=(t-1)/2;
        //// The nunmber of keys in th4e node at first entry//
        int n_fullNode=fullNode->n;
        int carry=fullNode->key[move_up],i_child=0;
        float val1=ceil(float(t)/2);
         int walk_child=val1;
        for(int i= move_up+1; i<n_fullNode; i++){
            rightNode->key[i_right]=fullNode->key[i];
            i_right++;
            //fullNode->key[i]=NULL;
            fullNode->n=(fullNode->n)-1;
            rightNode->n=(rightNode->n)+1;
        }
        if(fullNode->leaf==false){
            for(int a=walk_child;a<=t;a++){
            rightNode->child[i_child]=fullNode->child[a];
            i_child++;
        }
        rightNode->leaf=fullNode->leaf;
        }
        int hold=t-1;
        while(child[hold]!=fullNode){
           child[hold+1]=child[hold];
            hold--;
        }
        child[hold+1]=rightNode;
        int j=t-1;
            while(!key[j-1] && j!=0){
                j--;
            }
            //// if value before key is greater than the data push it to the right///
            while(key[j-1]>carry && j!=0){
                key[j]=key[j-1];
                j--;
            }
            //// insert the value in the respective place in the node////
            key[j]=carry;
            n=n+1;
            fullNode->n=(fullNode->n)-1;
    }

     void node::printLevel(node*temp,int level,ofstream &fout){
         if(level>1 && leaf){
             return;
         }
         else if(level==1){
             for(int i=0;i<n;i++){
                 fout<<key[i]<<" ";
             }
         }
         else{
             for(int i=0;i<=n;i++){
                 child[i]->printLevel(temp,level-1,fout);
             }
         }

        }


        void node:: height(node*temp, int h,int& result){
             if(leaf){
                result=h;
                return;

            }
            child[0]->height(temp,h+1,result);
        }







int main(int argc, char * argv[]) {
ArgumentManager am(argc,argv);
const string input=am.get("input");
const string command=am.get("command");
const string output=am.get("output");
ifstream file_in("input531.txt");
ifstream file_com("command531.txt");
ofstream file_out("output531.txt");
if(!file_in.is_open()){
    cout<<"The file could not be opened for reading!"<<endl;
assert(false);
}
if(!file_com.is_open()){
    cout<<"The file could not be opened for reading!"<<endl;
assert(false);
}
if(!file_out.is_open()){
 cout<<"The file could not be opened for writing!"<<endl;
assert(false);
}

string s_com,s_level,s_degree;
int int_level, int_degree=0 ,temp;

 file_com>>s_com;
    size_t find_degree=s_com.find("Degree=");
    if(find_degree!=string::npos){
        s_degree=s_com.substr(7,s_com.length()-1);
        int_degree=stoi(s_degree);
    }
    //int div=int_degree/2;
    btree t1(int_degree);
    map<int,int>bucket;

    while(!file_in.eof()){
    file_in>>temp;
    if(!bucket.count(temp)){
    t1.insert(temp);
    bucket[temp]=1;
    }

}
int h_tree=t1.height();
file_out<<"Height="<<h_tree<<endl;
while(!file_com.eof()){
    file_com>>s_com;
     if(isdigit(s_com[0])){
        s_level=s_com;
        int_level=stoi(s_level);
        if(int_level>h_tree){
            file_out<<"Empty";
        }
        else{
        t1.printLevel(int_level,file_out);
        }
        file_out<<"\n";
    }


}

}
