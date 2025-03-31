int maximumProfit(vector<int> &prices) {
        long long profit=0;
        for(long long day=1;day<prices.size();day++){
            //if todays price is greater than tomorrows sell to get profit 
            if(prices[day]>prices[day-1]){
                profit+=prices[day]-prices[day-1];
            }
        }
        return profit;
    }
