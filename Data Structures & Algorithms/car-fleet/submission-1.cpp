// A four-beat recall chain

// Chain these so each beat cues the next:

// Position is a red herring — time is the real quantity. Cars merge, positions collide, but arrival times are stable. (target − p) / s.
// Only cars ahead matter. Nobody behind can affect you. → sort descending by position, process nearest-target first.
// A blocked car inherits the time of the car ahead. So a car is only a new fleet if its time already exceeds everything ahead.
// Count the strict increases. That's the answer.
class Solution 
{
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
         int n = position.size();
        if(n == 0)
        {
            return 0;
        }
        vector<pair<int,int>>cars(n);

        for(int i = 0; i < n; i++)
        {
            cars[i].first = position[i];
            cars[i].second = speed[i];
        }
        stack<double>fleet;
        sort(cars.rbegin(),cars.rend());
        double time_target;
        for(int i = 0; i < n; i++)
        {
            time_target = static_cast<double>(target -            cars[i].first)/cars[i].second;
            
            if((fleet.empty()) || (time_target > fleet.top()))
            {
                
                fleet.push(time_target);
                
            }

        }
        
        return fleet.size();

    }
};
