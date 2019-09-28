#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int>& nums, int k) {
    for (int i = 0; i < k; i++) {
        int n = nums.back();
        nums.pop_back();
        nums.insert(nums.begin(), n);
    }
}

bool testCaseOne() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);

    rotate(nums, 3);

    vector<int> ans;
    ans.push_back(5);
    ans.push_back(6);
    ans.push_back(7);
    ans.push_back(1);
    ans.push_back(2);
    ans.push_back(3);
    ans.push_back(4);
    

    if (nums == ans) {
        return true;
    } else {
        return false;
    }
}


int main() {

    cout << "Result of test #1 is " << testCaseOne() << endl;
    return 0;
}