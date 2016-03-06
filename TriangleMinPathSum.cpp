class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int tHeight = triangle.size();
        
        if(tHeight == 0)
            return 0;
        else if(tHeight == 1)
            return triangle[0][0];
        
        int current = 2;
        
        vector<vector<int>> minPath;
        
        minPath = triangle;
        minPath[0][0] = triangle[0][0];
        
        for(int i = 1; i < tHeight; i++){
            for(int j = 0; j < current; j++){
                if(j == 0)
                    minPath[i][j] = minPath[i-1][j] + triangle[i][j];
                else if(j == current-1)
                    minPath[i][j] = minPath[i-1][j-1] + triangle[i][j];
                else{
                    //cout << "Comparing:" << minPath[i-1][j] << " with " << minPath[i-1][j-1] << endl;
                    if(minPath[i-1][j] > minPath[i-1][j-1]){
                        minPath[i][j] = minPath[i-1][j-1] + triangle[i][j];
                        //cout << minPath[i][j] << endl;
                    }
                    else
                        minPath[i][j] = minPath[i-1][j] + triangle[i][j];
                }
            }
            current++;
        }
        
        int smallest = minPath[tHeight-1][0];
        
        for(int j = 0; j < tHeight; j++){
            //cout << "Comparing:" << minPath[tHeight-1][j] << " with " << smallest << endl;
            if(minPath[tHeight-1][j] < smallest)
                smallest = minPath[tHeight-1][j];
        }
        
        return smallest;
    }
};