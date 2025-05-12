class Solution {
private:
    vector<int> meetCnt;
    priority_queue<int, vector<int>, greater<int>> availableRooms;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busyRooms;

    void initializeRooms(int n) 
    {
        meetCnt.resize(n, 0);
        while (!availableRooms.empty()) availableRooms.pop();
        while (!busyRooms.empty()) busyRooms.pop();
        for (int i = 0; i < n; ++i) 
        {
            availableRooms.push(i);
        }
    }

    void freeUpRooms(int currentTime) 
    {
        while (!busyRooms.empty() && busyRooms.top().first <= currentTime) 
        {
            availableRooms.push(busyRooms.top().second);
            busyRooms.pop();
        }
    }

    void allocateRoom(int startTime, int endTime) 
    {
        if (!availableRooms.empty()) 
        {
            int roomInd = availableRooms.top();
            availableRooms.pop();
            meetCnt[roomInd]++;
            busyRooms.push({endTime, roomInd});
        } 
        else 
        {
            pair<int, int> topRoom = busyRooms.top(); // structured binding replaced
            busyRooms.pop();
            int roomEndTime = topRoom.first;
            int roomInd = topRoom.second;
            int duration = endTime - startTime;
            meetCnt[roomInd]++;
            busyRooms.push({roomEndTime + duration, roomInd});
        }
    }

    int getMostBookedRoom() 
    {
        int maxMeetings = 0, roomIndex = 0;
        for (int i = 0; i < meetCnt.size(); ++i) 
        {
            if (meetCnt[i] > maxMeetings) 
            {
                maxMeetings = meetCnt[i];
                roomIndex = i;
            }
        }
        return roomIndex;
    }

public:
    int mostBooked(int n, vector<vector<int>> &meetings) 
    {
        sort(meetings.begin(), meetings.end());
        initializeRooms(n);
        for (const auto& meeting : meetings) 
        {
            int start = meeting[0], end = meeting[1];
            freeUpRooms(start);
            allocateRoom(start, end);
        }
        return getMostBookedRoom();
    }
};
