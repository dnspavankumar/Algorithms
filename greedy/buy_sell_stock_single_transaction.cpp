 int maximumProfit(vector<int> &prices) {
   /*buy on the minimum price ans sell on the highest price present after the minimum price*/
   //let minimum price be the price on the 0th day
        int minimum_price=prices[0];
   //initially maximum profit is 0
        int maximum_profit=0;
   
        for(int i=1;i<prices.size();i++){
          //if u find a price on ith day which is greater than the minimum price and the profit earned by selling is greater than current max profit
            maximum_profit=max(maximum_profit,prices[i]-minimum_price);
          // if u find a price lesser than the current minimum price update
            minimum_price=min(minimum_price,prices[i]);
        }
        return maximum_profit;
    }
