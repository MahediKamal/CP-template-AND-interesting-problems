# 11855 Buzzwords [***Problem Link***](https://onlinejudge.org/external/118/11855.pdf)

## observations
- We will iterate for all possible substring of all possible length.
- This iteration will cost `O(n^2)`
- For every substring we will calculate the hash value using `hash_val()` function in `O(1)` complexity.
- For finding the maximum generated hash value we will maintain a map; 


## **Solution Code(C++)**
```C++

#include <bits/stdc++.h>
using namespace std;
#define FastRead ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sz 20007  // maximum string size

struct hash_pair {
   size_t operator()(const pair<int,int>&x)const{
   return x.first * 23 + x.second;
 }
};
// we are doing double hash, so we are using two base and two mod
#define base1 3207
#define base2 3721
#define mod1 1000003999
#define mod2 1000000861
int pow1[sz+1];
int pow2[sz+1];

void calculate_pow(){
    pow1[0] = 1; pow2[0] = 1;
    for(int i=1; i<sz; i++){
        pow1[i] = (pow1[i-1] *1LL* base1) % mod1;
        pow2[i] = (pow2[i-1] *1LL* base2) % mod2;
    }
}

class HASH{
    int hashV1; int hashV2;
    int prefix_hash1[sz+1]; // size = len of string
    int prefix_hash2[sz+1];
    
    int calculate_hash(int h, int m, int b, char c){
        h = (h*1LL*b) % m;
        h = (h*1LL +(c + 1)) % m;// adding 1 so that 0 does not occur
        return h;
    }
public:
    HASH(){
        hashV1 = 0; hashV2 = 0;
    }
    
    // for a string we are generation two different(double hash) prefix hash array
    void create_prefix_hash_table(string s){ // hash table in 0 base index
        int ln = s.size();
        for(int i=0; i<ln; i++){
            hashV1 = calculate_hash(hashV1, mod1, base1, s[i]);
            hashV2 = calculate_hash(hashV2, mod2, base2, s[i]);
            prefix_hash1[i] = hashV1;
            prefix_hash2[i] = hashV2;
        }
    }
    
    // returning a double hash value for a whole string
    pair<int,int> hash_total_string(string s){
        hashV1 = 0; hashV2 = 0;
        for(int j=0;j<s.size();j++){
            hashV1 = calculate_hash(hashV1, mod1, base1, s[j]);
            hashV2 = calculate_hash(hashV2, mod2, base2, s[j]);
        }
        pair<int,int> pr = {hashV1,hashV2};
        return pr;
    }
    
    // returning double hash value of any substring using previously created prefix_hash_table
    pair<int,int> hash_val(int i,int j){// 0 index based query
        pair<int,int> pr = {prefix_hash1[j], prefix_hash2[j]};
        if(i != 0)
            pr = {(mod1*1LL + ((prefix_hash1[j] - prefix_hash1[i-1] *1LL* pow1[j-i+1]) % mod1)) % mod1,
                (mod2*1LL + ((prefix_hash2[j] - prefix_hash2[i-1] *1LL* pow2[j-i+1]) % mod2)) % mod2};
        return pr;
    }
};

int main() {
    calculate_pow();
    string s;
    while(true){
        getline(cin, s);
        if(s.size() == 0) break;
        int l = s.length();
        int c= count(s.begin(), s.end(),' '); 
        remove(s.begin(), s.end(),' ');
        s.resize(l - c);
        
        HASH hash;
        hash.create_prefix_hash_table(s);
        
        for(int i=0; i<s.size(); i++){
            map< pair<int,int>, int>mp;
            int res = 0;
            for(int j=0; j+i<s.size(); j++){
                pair<int,int> pr = hash.hash_val(j, j+i);
                mp[pr]++;
                res = max(res, mp[pr]);
            }
            if(res > 1) cout<<res<<endl;
            else break;
        }
        cout<<endl;
    }
    
}

```