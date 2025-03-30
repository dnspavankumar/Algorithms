/*There are some gas stations along a circular route. You are given
two integer arrays gas[] denoted as the amount of gas present at 
each station and cost[] denoted as the cost of travelling to the 
next station. You have a car with an unlimited gas tank. You 
begin the journey with an empty tank from one of the gas stations.
Return the index of the starting gas station if it's possible to
travel around the circuit without running out of gas at any 
station in a clockwise direction. If there is no such starting 
station exists, return -1.
Note: If a solution exists, it is guaranteed to be unique.*/
int startStation(vector<int> &gas, vector<int> &cost) {
    int totalGas = 0, totalCost = 0;
    int tank = 0, startIndex = 0;
    
    for (int i = 0; i < gas.size(); i++) {
        totalGas += gas[i];
        totalCost += cost[i];
        tank += gas[i] - cost[i];
        
        // If tank is empty, reset the start index
        if (tank < 0) {
            startIndex = i + 1;
            tank = 0;
        }
    }

    return (totalGas >= totalCost) ? startIndex : -1;
    }
