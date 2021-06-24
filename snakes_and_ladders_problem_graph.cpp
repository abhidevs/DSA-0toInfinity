#include<bits/stdc++.h>
using namespace std;

int main() {

    int ladders, snakes;
    cin>>ladders;
    map<int, int> lads;

    for(int i=0; i<ladders; i++) {
        int u, v;
        cin>>u>>v;
        lads[u] = v;
    }

    cin>>snakes;
    map<int, int> snks;

    for(int i=0; i<snakes; i++) {
        int u, v;
        cin>>u>>v;
        snks[u] = v;
    }

    int moves = 0;
    queue<int> q;
    q.push(1);
    bool found = false;
    vector<int> visited(101, 0);
    visited[1] = true;

    while(!q.empty() and !found) {
        int sz = q.size();
        while(sz--) {
            int t = q.front();
            q.pop();
            for(int dice=1; dice<=6; dice++) {
                if(t + dice == 100)
                    found = true;
                if(t+dice <= 100 and lads[t+dice] and !visited[lads[t+dice]]) {
                    visited[lads[t+dice]] = true;
                    if(lads[t+dice] == 100)
                        found = true;
                    q.push(lads[t+dice]);
                }
                else if(t+dice <= 100 and snks[t+dice] and !visited[snks[t+dice]]) {
                    visited[snks[t+dice]] = true;
                    if(snks[t+dice] == 100)
                        found = true;
                    q.push(snks[t+dice]);
                }
                else if(t+dice <= 100 and !visited[t+dice] and !snks[t+dice] and !lads[t+dice]) {
                    visited[t+dice] = true;
                    q.push(t+dice);
                }
            }
        }
        moves++;
    }

    if(found)
        cout<<moves;
    else
        cout<<-1;

    return 0;
}