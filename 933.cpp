#include <vector>
class RecentCounter {
public:
vector<int> vec;
    RecentCounter() {
    }
    
    int binSearch(int t, int l, int r){
        while (l < r){
            int m = (l+r)/2;
            if (vec[m] >= t){
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }

    int ping(int t) {
        vec.push_back(t);
        int l = binSearch(t-3000, 0, vec.size());
        return vec.size() - l;
    }
};
