class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int start = -1, end = seats.size(), ans = 0;
        for(int i = 0; i < seats.size() && start < 0; i++){
            if (seats[i] == 1){
                start = i;
            }
        }
        for(int i = seats.size()-1; i >= 0 && end == seats.size(); i--){
            if (seats[i] == 1){
                end = i;
            }
        }
        ans = max(ans, start);
        ans = max(ans, int(seats.size() - end - 1));
        for(int i = start, j = start; i <= end; i++){
            if (seats[i] == 1){
                ans = max(ans, (i - j)/2);
                j = i;
            }
        }
        return ans;
    }
};