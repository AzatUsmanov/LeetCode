class NestedIterator {
public:
    void push(vector<int>& a, vector<NestedInteger> &nestedList){
        for(int i = 0; i < nestedList.size(); i++){
            if (nestedList[i].isInteger()){
                a.push_back(nestedList[i].getInteger());
            } else {
                push(a, nestedList[i].getList());
            }
        }
    }
    vector<int> a;
    int i;
    NestedIterator(vector<NestedInteger> &nestedList) {
        push(a, nestedList);
        i = 0;
    }
    int next() {
        return a[i++];
    }
    
    bool hasNext() {
        return (i < a.size());
    }
};