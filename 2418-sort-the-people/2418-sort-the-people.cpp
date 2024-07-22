class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<int> indices(names.size());
        for (int i = 0; i < names.size(); ++i) {
            indices[i] = i;
        }
        
        sort(indices.begin(), indices.end(), [&](int i, int j) {
            return heights[i] > heights[j];
        });
        
        vector<string> sortedNames(names.size());
        for (int i = 0; i < indices.size(); ++i) {
            sortedNames[i] = names[indices[i]];
        }
        
        return sortedNames;
    }
};