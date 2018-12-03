#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

char word[1001];
int L,best,found[1000];
vector<int> poss;


class node{
private:
    int count;
    node *child[4];
public:
    node(){
        count = 0;
        for(int i =0;i<4;i++){
          child[i]=NULL;
        }
    }

friend class Trie;
};

class Trie{
    node *root;
    public:
    Trie(){
        root = new node();  
    }
    
    void insert(int pos){
        node *tmp = root;
        string str;
        int nxt;
        for(int i = pos;i < L;++i){
            str += word[i];
            switch(word[i]){
              case 'A':
                nxt=0;
                break;
              case 'C':
                nxt=1;
                break;
              case 'G':
                nxt=2;
                break;
              case 'T':
                nxt=3;
                break;
            }      
            if(tmp->child[nxt] == NULL)
                tmp->child[nxt] = new node();
            tmp = tmp->child[nxt];
            ++tmp->count;
            
            if(tmp->count > 1){
                if(i-pos+1 > best){
                    poss.clear();
                    best = i-pos+1;
                }
                
                if(i-pos+1 == best){
                    poss.push_back(pos);
                    found[pos] = tmp->count;
                }
            }
        }
    }
};

int main(){
    int t;
    cin>>t;
    Trie *adn;
    adn = new Trie();
    while(t--){
        cin>>word;
        L = strlen(word);
        best = -1;        
        poss.clear();
        for(int i = 0;i < L;++i){
            adn->insert(i);
        }
        delete(adn);
        if(best == -1){
            cout<<"No repetitions found!"<<endl;
        }else{
            string ans = "Z";
            int ind,sz = poss.size();
            for(int i = 0;i < sz;++i){
                int x = poss[i];
                string str = string(word + x,word + (x+best));
                
                if(str <= ans){
                    ans = str;
                    ind = x;
                }
            }       
            printf("%s %d\n",ans.c_str(),found[ind]);
        }
    }
    return 0;
}
