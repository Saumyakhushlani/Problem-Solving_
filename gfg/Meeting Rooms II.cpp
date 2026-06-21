class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        int n = start.size();

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int rooms = 0, maxRooms = 0;
        int i = 0, j = 0;

        while (i < n) {
            if (start[i] < end[j]) {
                rooms++;
                maxRooms = max(maxRooms, rooms);
                i++;
            } else {
                rooms--;
                j++;
            }
        }

        return maxRooms;
    }
};
