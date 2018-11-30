#include <iostream>
//#include <string>
using namespace std;

class node{
  private:
    node * child[4];
    char data;
    int count;
  public:
    node(char dat,int _count =1){
      data=dat;
      count=_count;
      for (int i = 0; i < 4; ++i)
      {
      	child[i]=NULL;
      }
    }
  friend class sufftrie;
};

class sufftrie
{
  private:
	node *phead;
  public:
    sufftrie(){
      phead=new node('a',0);
    }
    void insert1(string word){
      insert(phead,word);
    }
    void insert(node* tmp,string word){
      if (word=="")
      {
      	return;
      }
      string str="";
      for(int i=0;i<4;i++){
        if(tmp->child[i]!=NULL){
          if(tmp->child[i]->data==word[0]){
            tmp->child[i]->count++;
            //str=word[i];
            for(int j=1;j<word.size();j++){
              str+=word[j];
            }
            insert(tmp->child[i],str);
            return;
          }
        }
        tmp->child[i]=new node(word[0]);
        cout<<word.size();
        for(int j=1;j<word.size();j++){
          str+=word[j];
        }
        insert(tmp->child[i],str);
        return;
      }
    }
    void longest(node *tmp=phead,string str = ""){
    	string str2="";
    	for(int i=0;i<4;i++){
    		if(tmp->child[i]!=NULL){
    			if(tmp->child[i]->count>1){
    				str2+=tmp->child[i]->data;
    				longest(tmp->child[i],)
    			}
    		}
    	}
    }
};

int main(int argc, char const *argv[])
{
  cout<<'a';
  sufftrie s;
  s.insert1("CGAT");
  s.insert1("GGAT");
  s.insert1("AGAT");
  s.insert1("TGAT");
  s.insert1("GATA");
  cout<<"walker";
	//cin>>T;

	return 0;
}