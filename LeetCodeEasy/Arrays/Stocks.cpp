#include <iostream>
#include <vector>

using namespace std;


int maxProfit(vector<int>& prices) {

    if (prices.size() <= 0) {
        return 0;
    }

    int profit = 0;
    int buyPoint = 0;
    bool holding = false;
    cout << endl;
    for (int i = 0; i < prices.size()-1; i++) {
        if (not holding) {
            if (prices.at(i) < prices.at(i+1)) {
                holding = true;
                buyPoint = prices.at(i);
            }
        } else {
            if (prices.at(i) > prices.at(i+1)) {
                holding = false;
                profit += (prices.at(i) - buyPoint);
            }
        }
    }

    if (holding) {
        holding = false;
        profit += (prices.at(prices.size() - 1) - buyPoint);
    }

    return profit;
}

bool exampleOneTest() {
    vector<int> prices;
    prices.push_back(7);
    prices.push_back(1);
    prices.push_back(5);
    prices.push_back(3);
    prices.push_back(6);
    prices.push_back(4);

    int result = maxProfit(prices);

    if (result == 7) {
        return true;
    } else {
        return false;
    }
}

bool exampleTwoTest() {
    vector<int> prices;
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(3);
    prices.push_back(4);
    prices.push_back(5);

    int result = maxProfit(prices);

    if (result == 4) {
        return true;
    } else {
        return false;
    }
}

bool exampleThreeTest() {
    vector<int> prices;
    prices.push_back(7);
    prices.push_back(6);
    prices.push_back(4);
    prices.push_back(3);
    prices.push_back(1);

    int result = maxProfit(prices);

    if (result == 0) {
        return true;
    } else {
        return false;
    }
}

bool exampleCrazyMarket() {
    vector<int> prices;
    prices.push_back(7);
    prices.push_back(7);
    prices.push_back(1);
    prices.push_back(1);
    prices.push_back(1);
    prices.push_back(5);
    prices.push_back(6);
    prices.push_back(7);
    prices.push_back(7);
    prices.push_back(8);
    prices.push_back(8);
    prices.push_back(9);
    prices.push_back(10);
    prices.push_back(9);
    prices.push_back(10);
    prices.push_back(9);
    prices.push_back(10);
    prices.push_back(1);
    prices.push_back(1);
    prices.push_back(1);

    int result = maxProfit(prices);

    if (result == 11) {
        return true;
    } else {
        return false;
    }
}

bool exampleFiveTest() {
    vector<int> prices;
    prices.push_back(1);
    prices.push_back(2);

    int result = maxProfit(prices);

    if (result == 1) {
        return true;
    } else {
        return false;
    }
}

int main() {

    cout << endl << "Result of test #1 is " << exampleOneTest() << endl;
    cout << endl << "Result of test #2 is " << exampleTwoTest() << endl;
    cout << endl << "Result of test #3 is " << exampleThreeTest() << endl;
    cout << endl << "Result of test #4 is " << exampleCrazyMarket() << endl;
    cout << endl << "Result of test #5 is " << exampleFiveTest() << endl;

    return 0;
}