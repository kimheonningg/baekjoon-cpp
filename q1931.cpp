#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N; // number of meetings
    cin >> N;
    vector<pair<int, int>> meeting_infos; // vector of pairs (start time, end time)

    // store meeting infos
    for (int i = 0; i < N; i++) {
        int temp_start_time, temp_end_time;
        cin >> temp_start_time >> temp_end_time;
        meeting_infos.push_back(make_pair(temp_end_time, temp_start_time)); 
        // insert in this order to sort by ending time
    }

    sort(meeting_infos.begin(), meeting_infos.end()); // sort by ending time
    
    int max_num = 1; // max number of meetings
    int current_time = meeting_infos[0].first; // meeting 1 has just finished

    for(int i = 1; i < N; i++) {
        if (current_time <= meeting_infos[i].second) { 
            // if some meeting starts after the previous meeting finishes
            // choose that meeting
            max_num ++;
            current_time = meeting_infos[i].first;
        }
    }

    cout << max_num ;

    return 0;
}