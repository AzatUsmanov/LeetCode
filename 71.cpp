#include <list>
class Solution {
public:
    string simplifyPath(string path) {
    list<string> list;
    string s;
    path += '/';
    for (int i = 0, j = 0; i < path.size(); j++) {
        while (j < path.size() && path[j] != '/') {
            j++;
        }
        if (j - i > 1) {
            string a = string(path.begin() + i + 1, path.begin() + j);
            if (a == "."){
            } else if (a == ".." && list.size()){
                list.pop_back();
            }  else if(a == ".."){
            } else {
                list.push_back(a);
            }
        }
        i = j;
    }
    while (list.size() && list.back() == "."){
        list.pop_back();
    }
    while (list.size()) {
        s = s + "/";
        s = s + list.front();
        list.pop_front();
    }
    if (!s.size()){
        s = "/";
    }
    return s;
}
};