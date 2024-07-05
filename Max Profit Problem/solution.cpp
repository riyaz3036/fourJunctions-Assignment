#include <bits/stdc++.h>
using namespace std;

// Structure to represent a building type
struct Building {
    int time;       
    int earning;    
    char type;      
};


void findOptimalMix(int n) {
    //three types of buildings
    vector<Building> buildings = {
        {5, 1500, 'T'},
        {4, 1000, 'P'},
        {10, 3000, 'C'}
    };

    // dp array to store the maximum earnings for each time unit
    vector<int> dp(n + 1, 0);
    // dp array to store the number of each type of building
    vector<vector<int>> count(n + 1, vector<int>(3, 0));

    // Iterate over each time unit
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < buildings.size(); ++j) {
            if (i >= buildings[j].time) {
                int newEarning = dp[i - buildings[j].time] + buildings[j].earning;
                if (newEarning > dp[i]) {
                    dp[i] = newEarning;
                    count[i] = count[i - buildings[j].time];
                    ++count[i][j];
                }
            }
        }
    }

    // Print the result
    cout << "Time Unit: " << n << endl;
    cout << "Earnings: $" << dp[n] << endl;
    cout << "Solutions:" << endl;
    cout << "T: " << count[n][0] << " P: " << count[n][1] << " C: " << count[n][2] << endl;
}

int main() {
    int timeUnits;
    cout << "Enter the number of time units: ";
    cin >> timeUnits;

    findOptimalMix(timeUnits);

    return 0;
}
