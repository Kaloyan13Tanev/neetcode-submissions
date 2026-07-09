class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars(n);
        for (int i = 0; i < n; i++)
            cars[i] = {position[i], speed[i]};

        sort(cars.begin(), cars.end(), greater<>());

        int fleets = 0;
        double lastTime = 0;
        for (auto& [pos, spd] : cars) {
            double t = (double)(target - pos) / spd;
            if (t > lastTime) 
            {
                fleets++;
                lastTime = t;
            }
        }
        return fleets;
    }
};