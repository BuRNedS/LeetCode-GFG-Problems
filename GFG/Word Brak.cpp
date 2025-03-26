bool wordBreak(string &s, vector<string> &dictionary) {

        // code here

        int n=s.size();

        vector<bool>dp(n+1,false);

        dp[0]=true;

        int maxl=0;

        for(const string &word:dictionary){

            maxl=max(maxl,(int)word.size());

        }

        unordered_set<string>dict(dictionary.begin(),dictionary.end());

        for(int i=1;i<=n;i++){

            for(int j=max(0,i-maxl);j<i;j++){

                if(dp[j]&&dict.find(s.substr(j,i-j))!=dict.end()){

                    dp[i]=true;

                    break;

                }

            }

        }

        return dp[n];

    }
