//define M, K = alphabet size
int trie[M][K], word[M*K+3], cnt[M*K+3], sz; 

void Insert(string s){
int node = 0;
for(int i=0; i<s.size(); i++){ 
  int c = s[i]-'a'; 
  if(!trie[node][c]){ trie[node][c] = ++sz; }
        node = trie[node][c];
        cnt[node]++;
    }
    word[node]++;
}

bool Search(string s){
int node = 0, ret = 0;
for(int i=0; i<s.size(); i++){
int c = s[i]-'a'; if(!trie[node][c]) return false;
node = trie[node][c]; 
}
  return (word[node] > 0); 
}

void Delete(string s){ int node = 0;
vector<int>v(1, 0);
for(int i=0; i<s.size(); i++){ int c = s[i]-'a';
node = trie[node][c]; cnt[node]--; v.push_back(node);
}
    word[node]--;
for(int i=1; i<v.size(); i++){ int c = s[i-1]-'a'; if(!cnt[v[i]]){
  trie[v[i-1]][c] = 0;
}
}
}
