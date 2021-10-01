class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        unordered_map<string, int> map_type;
        unordered_map<string, int> map_color;
        unordered_map<string, int> map_name;
        int cap = items.size();
        
        for (int i = 0; i < cap; i++) {
            if (map_type.find(items[i][0]) == map_type.end()) {
                map_type[items[i][0]] = 1;
            } else {
                map_type[items[i][0]] ++;
            }
            
            if (map_color.find(items[i][1]) == map_color.end()) {
                map_color[items[i][1]] = 1;
            } else {
                map_color[items[i][1]] ++;
            }
            
            if (map_name.find(items[i][2]) == map_name.end()) {
                map_name[items[i][2]] = 1;
            } else {
                map_name[items[i][2]] ++;
            }
        }
        
        if (ruleKey == "type") {
            if (map_type.find(ruleValue) != map_type.end()) {
                return map_type[ruleValue];
            }
        }
        if (ruleKey == "color") {
            if (map_color.find(ruleValue) != map_color.end()) {
                return map_color[ruleValue];
            }
        }
                
        if (ruleKey == "name") {
            if (map_name.find(ruleValue) != map_name.end()) {
                return map_name[ruleValue];
            }
        }
        
        return 0;
    }
};