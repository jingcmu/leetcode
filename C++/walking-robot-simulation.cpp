class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dir[4][2] = {{0,1}, {1,0},{0,-1},{-1,0}};
        int dir_index = 0;
        int max_dis = 0;
        vector<int> pos = {0, 0};
        map<vector<int>, int> obs;
        for (int i = 0; i < obstacles.size(); i++) {
            obs[obstacles[i]] = 1;
        }
        for (int i = 0; i < commands.size(); i++) {
            if (commands[i] == -1) {
                dir_index = (dir_index + 1) % 4;
            } else if (commands[i] == -2) {
                dir_index = (dir_index -1 + 4) % 4;
            } else {
                for (int j = 0; j < commands[i]; j++) {                    
                    pos[0] += dir[dir_index][0];
                    pos[1] += dir[dir_index][1];
                    if (obs[{pos[0], pos[1]}] == 1) {
                        pos[0] -= dir[dir_index][0];
                        pos[1] -= dir[dir_index][1];
                        break;
                    }
                }
            }
            max_dis = max(max_dis, pos[0]*pos[0] + pos[1]*pos[1]);
        }
        return max_dis;
    }
};