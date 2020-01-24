class Solution {
private:
    int t;
    unordered_map<int, vector<pair<int,int>> events;
private:
    void processInputs() {
        int n = 0;
        cin >> n;
        char op = ' ', lastOp = ' ';
        int to = 0;

        for (int i = 0; i < n; ++i) {
            cin >> op >> to;
            if (op == 'W') {
                t += to;
                lastOp = 'W';
            }
            else if (op == 'R') {
                t += (lastOp == 'W') ? 0 : 1;
                events[to].push_back(make_pair(t, -1));
                lastOp = 'R';
            } else {
                t += (lastOp == 'W') ? 0 : 1;
                events[to][events[to].size() - 1].second = t;
                lastOp = 'S';
            }
        }
    }
public:
    Solution() { t = 0; }
    vector<pair<int,int>> getWaitTimes() {
        vector<pair<int,int>> totalWaitTimes;
        for (auto it = events.begin(); it != events.end(); ++it) {
            int to = it->first;
            vector<pair<int,int>> sendReceiveVector = it->second;

            int totalWaitTime = 0;
            for(pair<int,int> event : sendReceiveVector) {
                if (event.second == -1) {
                    totalWaitTime = -1;
                    break;
                }
                totalWaitTime += (event.second - event.first);
            }
            totalWaitTimes.push_back(make_pair(to, totalWaitTime));
        }

        std::sort(totalWaitTimes.begin(), totalWaitTimes.end(), [](const std::pair<int,int> &left, const std::pair<int,int> &right) {
            return left.first < right.first;
        });

    }
};

