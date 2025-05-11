class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //let numRows = 1
        //create the final answer matrix
       vector<vector<int>>ans;
       //ans=[[1]] do this
       ans.push_back({1});
       //ans=[[1]]
       for(int i=0;i<numRows-1;i++){
        //i==0
        //i==1
        vector<int>dummyRow={0};
        //dummyrow = [0]
        //dummyrow=[0]
        dummyRow.insert(dummyRow.end(),ans.back().begin(),ans.back().end());
        //dummyRow=[0,1]
        //dummyRow=[0,1,1]
        dummyRow.push_back(0);//add an extra zero at the end
        //dummyRow=[0 1 0]
        //dummyrow=[0,1,1,0]
        vector<int>row;//initialize an empty vector row
        for(int j =0;j<dummyRow.size()-1;j++){
            //pascal triangle logic
            row.push_back(dummyRow[j]+dummyRow[j+1]);
            //row=[1]
            //row=[1,1]
            //row=[1,2,2,1]
        }
        ans.push_back(row);
        //ans=[[1],[1,1],[1,2,2,1]]
       } 
       return ans;
    }
};
