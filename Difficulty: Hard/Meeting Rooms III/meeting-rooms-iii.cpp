//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
    sort(meetings.begin(), meetings.end());  

    vector<int> meetingCount(n, 0);
    priority_queue<int, vector<int>, greater<int>> availableRooms; 
    for (int i = 0; i < n; ++i) availableRooms.push(i);

    using PII = pair<long long, int>; 
    priority_queue<PII, vector<PII>, greater<>> busyRooms; 

    for (const auto& meeting : meetings) {
        long long start = meeting[0], end = meeting[1];

        while (!busyRooms.empty() && busyRooms.top().first <= start) {
            availableRooms.push(busyRooms.top().second);
            busyRooms.pop();
        }

        if (!availableRooms.empty()) {
            int room = availableRooms.top(); availableRooms.pop();
            busyRooms.emplace(end, room);
            meetingCount[room]++;
        } else {
            auto top = busyRooms.top(); busyRooms.pop();
            long long freeTime = top.first;
            int room = top.second;
            long long duration = end - start;
            busyRooms.emplace(freeTime + duration, room);
            meetingCount[room]++;
        }

    }

    int maxMeetings = 0, answerRoom = 0;
    for (int i = 0; i < n; ++i) {
        if (meetingCount[i] > maxMeetings) {
            maxMeetings = meetingCount[i];
            answerRoom = i;
        }
    }
    return answerRoom;
}
};


//{ Driver Code Starts.

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> m;
        vector<vector<int>> meetings(m, vector<int>(2));
        for (int i = 0; i < m; i++) {
            cin >> meetings[i][0] >> meetings[i][1];
        }
        Solution ob;
        cout << ob.mostBooked(n, meetings) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends