/*
* find all accending sub-sequence in the vector and get all the profit in each sub-sequence
* sum them up
*/
class Solution {
public :
   int maxProfit( vector< int> & prices) {
       // Note: The Solution object is instantiated only once and is reused by each test case.
       vector< int> accending;
       int profit = 0;
       if( prices.size()){    
           accending.push_back( prices[0]);  // if prices not null, push first price to vector
       }
       for( int i=0; i<( int) prices.size()-1; i++){
           if( prices[i] > prices[i+1]){  // if the price descend
                profit += accending.back()-accending.front();
                accending.clear();       // clear the vector to save next accending vector
                accending.push_back( prices[i+1]); // push the first price in next sequence
           }
           else {                                  // if the price accend
               accending.push_back( prices[i+1]); // continue to push into vector
           }
       }
       if(accending.size()){
           profit += accending.back()-accending.front(); // for the last accending vector
       }
       return profit;
   }
};
