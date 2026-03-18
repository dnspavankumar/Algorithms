/*
https://atcoder.jp/contests/abc221/tasks/abc221_d
*/

/*
Problem Explaination:
We have the log in time A of a player 
We have the log out time B of a player
Hence these are the two events taking place
Event 1 : Log in denoted by state 1 is taking place at time A => Event (A,1);
Event 2 : Log in denoted by state -1 is taking place at time B => Event (B,-1);

To mark a point of time in the interval is log in or log out time the state is being used


*/

#include<bits/stdc++.h>
using namespace std;

#define int long long

// make the structure of event
struct Event {
  int time;
  int state;
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  // store all the events here
  vector<Event> events;

  for(int i = 0; i < N; i++){
    int A, B;
    cin >> A >> B;
    //Login 
    events.push_back({A, 1});
    //Log out
    events.push_back({A + B, -1}); 
  }
  //The events must be arranged in chronological order so that they construct intervals for the line to sweep over them
  sort(events.begin(), events.end(), [](Event a, Event b){
    return a.time < b.time;
  });
  //We need to find the number of days k players logged in k := 1 to n
  vector<int> ans(N+1, 0);
  //Let us set a count for number of players
  int cnt = 0;

  for(int i = 0; i < events.size() - 1; i++){
    cnt += events[i].state; // if a player is active i.e logged in and not logged out the count will increase otherwise decrease by 1

    int duration = events[i+1].time - events[i].time;

    if(cnt > 0){
      ans[cnt] += duration;
    }
  }

  for(int k = 1; k <= N; k++){
    cout << ans[k] << " ";
  }
}


/*
When to apply sweep line algorithm on segments

This algorithm is usually applied during the interval problems

Here since the constraints tend to 10^9 any other solution would give a TLE so this is a perfect scenario to apply sweep line



*/