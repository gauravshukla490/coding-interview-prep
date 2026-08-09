class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
     unordered_set<string>st;
     st.insert(wordList.begin() , wordList.end());

     if(!st.count(endWord)) return 0;

     queue<string>q;
     q.push(beginWord);
     int level = 1;

     while(!q.empty()){
        int size = q.size();

        while(size--){
            string word = q.front();
            q.pop();

            if(word==endWord) return level;

            for(int i=0 ; i<word.size() ; i++){
                  char curr = word[i];

                  for(char ch='a' ; ch <= 'z' ; ch++){
                     word[i]=ch;

                     if(st.count(word)){
                        q.push(word);
                        st.erase(word);
                     }
                  }
                word[i]=curr;
            }
        }
        level++;
     }
     return 0;
    }
};