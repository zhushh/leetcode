// https://leetcode.com/problems/flatten-nested-list-iterator/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) 
            : current(0) {
        for (int i = 0; i < nestedList.size(); i++) {
            putNestedListIntoVector(nestedList[i]);
        }
    }

    int next() {
        return integerList[current++];
    }

    bool hasNext() {
        return (current < integerList.size());
    }

private:
    // vector<NestedInteger> _nestedList;
    vector<int> integerList;
    int current;
    // int curInNestedList;

    void putNestedListIntoVector(const NestedInteger &nested) {
        if (nested.isInteger()) {
            integerList.push_back(nested.getInteger());
        } else {
            const vector<NestedInteger> &v = nested.getList();
            for (int i = 0; i < v.size(); i++) {
                putNestedListIntoVector(v[i]);
            }
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
