// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int i=0;
//         int j=0;
//         deque<int> d1;
//         deque<int> d2;
//         int start = 0;
//         int sizee = gas.size();
//         if(sizee>200){
//             return 0;
//         }
//         while(i<sizee){
//             d1.push_back(gas[i]);
//             d2.push_back(cost[i]);
//             i++;
//         }
//         int tank=0;
//         while(j<sizee){                 // <-- changed condition
//             if(d1.front() -d2.front()<0){
//                 d1.push_back(d1.front());
//                 d1.pop_front();
//                 d2.push_back(d2.front());
//                 d2.pop_front();
                
//             }
//             else if (d1.front() -d2.front()>=0){
//                 tank = 0;
//                 bool ok = true;
//                 for(int k=0; k<sizee; k++){
//                     tank += d1[k] - d2[k];
//                     if(tank < 0){ ok = false; break; }
//                 }
//                 if(ok) return start;
//                 d1.push_back(d1.front());
//                 d1.pop_front();
//                 d2.push_back(d2.front());
//                 d2.pop_front();

//             }
//             start = (start+1)%sizee;
//             j++;
//         } 
//         return -1;
//     }
// };


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, tank = 0, start = 0;
        for (int i = 0; i < gas.size(); i++) {
            int diff = gas[i] - cost[i];
            total += diff;
            tank += diff;
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }
        return total < 0 ? -1 : start;
    }
};
