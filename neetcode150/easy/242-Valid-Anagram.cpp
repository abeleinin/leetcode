#include <map>
#include <string>
using namespace std;

class Solution {
public:
    // Two map solution:
    // Store the frequency of each letter in a map and
    // compare the frequencies of the two strings.
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        map<char, int> freq_s;    
        map<char, int> freq_t;    
        // Add frequencies of string s
        for(int i = 0; i < s.size(); i++){
            if(freq_s.find(s[i]) == freq_s.end()) {
                freq_s.insert(make_pair(s[i], 1));
            } else{
                freq_s[s[i]]++;
            }
        }
        // Add frequencies of string t
        for(int j = 0; j < t.size(); j++){
            if(freq_t.find(t[j]) == freq_t.end()) {
                freq_t.insert(make_pair(t[j], 1));
            } else{
                freq_t[t[j]]++;
            }
        }
        // Compare frequencies of the two strings
        for(int k = 0; k < s.size(); k++){
            if(freq_s[s[k]] != freq_t[s[k]]){
                return false;
            }
        } 
        return true;
    }
};

class Solution {
public:
    // Single array solution:
    // Create an array of all 26 letters and increment when 
    // a character is found in string s and decrement when 
    // a character is found in string t.
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        int count[26] = {};
        for(int i = 0; i < s.size(); i++){
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        
        for(int i : count){
            if(i != 0){
                return false;
            }
        }
        return true;
    }
};