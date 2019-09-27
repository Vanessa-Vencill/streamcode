#include <iostream>
#include <vector>

using namespace std;


/**
 * Aproach:
 * 0. Check that vector length >= 2
 * 1. For each element in vector
 * 2. If we hit consecutive values
 * 3. Remove the value
 * 4. Return the vector.size()
 *
 * **/

int removeDuplicatesSlow(vector<int>& nums) {
    if (nums.size() < 2) {
        return nums.size();
    }

    for (int idx = 0; idx < nums.size() - 1; idx++) {
        if (nums.at(idx) == nums.at(idx+1)) {
            nums.erase(nums.begin() + idx);
            idx --;
        }
    }
    return nums.size();
}

int removeDuplicates(vector<int>& nums) {
    if (nums.size() < 2) {
        return nums.size();
    }

    int idx = 0;
    int jdx = 0;

    while (jdx < nums.size()) {
        if (nums.at(idx) == nums.at(jdx)) {
            jdx++;
        } else {
            idx++;
            nums.at(idx) = nums.at(jdx);
        }
    }
    return idx+1;
}


bool simpleGivenCase() {
    /**
     * Test the given example #1
     * */
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);

    int result = removeDuplicates(nums);
    
    if (result == 2) {
        return true;
    } else {
        return false;
    }
}

bool testEmptyVector() {
    /**
     * Test case for empty array
    **/
    vector<int> nums;

    int result = removeDuplicates(nums);
    cout << "result is: " << result;
    if (result == 0) {
        return true;
    } else {
        return false;
    }
}

bool exampleTwoGivenCase() {
    /**
     * Test the given example #2
     * */
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);

    int result = removeDuplicates(nums);
    cout << "result is: " << result;
    if (result == 5) {
        return true;
    } else {
        return false;
    }
}

bool allOnesCase() {
    /**
     * Test the situation where the input array is all a singluar value
     * */
    vector<int> nums;
    bool correct = true;

    for (int i = 5; i > 0; i--) {
        for (int j = i; j > 0; j--) {
            nums.push_back(1);
        }

        int result = removeDuplicates(nums);
        cout << "allOnes() with " << i << " , result is: " << result << endl;
        if (result != 1) {
            correct = false;
        }
    }

    return correct;

}

int main() {
    bool simpleGivenCaseResult = simpleGivenCase();
    cout << endl << "simpleGivenCase() yeilds:" << simpleGivenCaseResult << endl;

    bool exampleTwoGivenCaseResult = exampleTwoGivenCase();
    cout << endl << "exampleTwoGivenCase() yeilds:" << exampleTwoGivenCaseResult << endl;

    bool emptyTestCaseResult = testEmptyVector();
    cout << endl << "emptyTestCase() yeilds:" << emptyTestCaseResult << endl;

    bool allOnesCaseResult = allOnesCase();
    cout << endl << "allOnesCase() yeilds:" << allOnesCaseResult << endl;

    return 0;
} 