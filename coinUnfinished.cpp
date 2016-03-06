class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        sort(coins.begin(), coins.end());
        return coinFind(coins, amount);
    }
    
    int coinFind(vector<int>& coins, int amount){
        int coinSize = coins.size();
        int number = 0;
        if(amount == 0)
            return 0;
        else if(amount < 0)
            return -1;
        
        for(int i = 0; i < coinSize; i++){
            number = coinFind(coins, amount - coins[coinSize - 1 - i]);
            if(number >= 0)
                return number+1;
        }
        
        return -1;
    }
};