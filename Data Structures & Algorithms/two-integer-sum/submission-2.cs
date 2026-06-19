public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int, int> map = new Dictionary<int, int>();

        for (int i = 0; i < nums.Count(); i++)
        {
            if (map.ContainsKey(target - nums[i]))
            {
                return [map[target - nums[i]], i];
            }

            map.Add(nums[i], i);
        }

        return [0, 0];
    }
}
