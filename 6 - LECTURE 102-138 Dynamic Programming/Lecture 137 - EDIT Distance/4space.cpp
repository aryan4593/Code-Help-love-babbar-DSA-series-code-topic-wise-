#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {

    int space(string &word1, string &word2){
        int l1 = word1.size() ,l2 = word2.size();
        vector<vector<int>> dp(l1+1 , vector<int>(l2+1 ,0));
        vector<int> next (l2+1, 0);
        vector<int> curr (l2+1, 0);
        
        for(int i=0;i<l2; i++) next[i] = l2 - i;

        // next[l2] = curr[l2] 

        for(int i=l1-1; i>=0; i--){
                for(int j = l2-1; j>=0; j--){

                // main part, 
                curr[l2]=l1 - i;
                // case1 charecter matched
                if(word1[i] == word2[j]){
                    curr[j] = next[j+1];
                }
                else{
                    // case 2 insert
                    int case2 = 1 + curr[j+1];

                    // case 3 delete
                    int case3 = 1 + next[j];

                    // case 3 replace
                    int case4 = 1 + next[j+1];

                    curr[j] = min(case2 , min(case3 ,case4));
                }
            }
            next = curr;
        }

        return curr[0];
    }
public:
    int minDistance(string &word1, string &word2) {
        // base case
        if(word1 == "") return word2.length();
        if(word2 == "") return word1.length();
        return space(word1 ,word2);
    }
};

int main() {
    Solution solution;
    string word1 = "intention";
    string word2 = "execution";
    int result = solution.minDistance(word1, word2);
    cout << "The minimum edit distance between \"" << word1 << "\" and \"" << word2 << "\" is: " << result << endl;
    return 0;
}