class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> answer;
        bool stop = false;
        for (int i = 0; i < nums.size(); i++)
        {
            if (stop)
                break;
            for (int j = 0; j < nums.size(); j++)
            {
                if (i == j)
                {
                    continue;
                }
                if (nums[i] + nums[j] == target)
                {
                    answer.push_back(i);
                    answer.push_back(j);
                    stop = true;
                    break;
                }
            }
        }
        return answer;
    }
};
