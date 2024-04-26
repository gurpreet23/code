 #include <iostream>
 #include <map>
 using namespace std;

 int main(){
    std::string s = "tmmzuxt";
    int left = 0, max_len = 0;
    unordered_map<char, int> mp;
    for(int right = 0; right < s.length(); right++) {
        if(mp.find(s[right]) == mp.end()) {
            mp[s[right]] = right;
            max_len = max(max_len, right-left+1);
        }
        else {
            left = mp[s[right]] + 1;
            mp[s[right]] = right;
        }
    }
    cout<<max_len<<endl;
    return 0;
 }    
