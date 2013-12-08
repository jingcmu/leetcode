class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        if(matrix.empty()) {
            return res;
        }
        int beginY = 0, endY = matrix.size()-1;
        int beginX = 0, endX = matrix[0].size()-1;
        while(true){
            //from left to right
            for(int i=beginX; i<=endX; ++i) res.push_back(matrix[beginY][i]);
            if(++beginY > endY) break;
            //from up to down
            for(int i=beginY; i<=endY; ++i) res.push_back(matrix[i][endX]);
            if(--endX < beginX) break;
            //from right to left
            for(int i=endX; i>=beginX; --i) res.push_back(matrix[endY][i]);
            if(--endY < beginY) break;
            //from down to up
            for(int i=endY; i>=beginY; --i) res.push_back(matrix[i][beginX]);
            if(++beginX > endX) break;
        }
        return res;
    }
};