// KMP Algorithm

#include<bits/stdc++.h>
using namespace std;

int i,j,n;

int  main(){
    string text,pattern; cin >> text >> pattern;
    n = pattern.size();

    // lps calculation
    vector<int>lps(n);
    int len = 0;
    lps[len] = len;
    for(i=1;i<n;){
        if(pattern[i]==pattern[len]){
            lps[i] = len+1;
            len++,i++;
        }
        else{
            if(len) len = lps[len-1];
            else lps[i] = len , i++;
        }
    }

    //pattern finding
    j = 0;
    for(i=0;i<text.size();){
        if(text[i]==pattern[j]) i++ , j++;
        else{
            if(j) j = lps[j-1];
            else i++;
        }

        if(j==n){
            // found the pattern
            cout << i-n << " ";
            j = lps[j-1];
        }
    }
    
    return 0;
}