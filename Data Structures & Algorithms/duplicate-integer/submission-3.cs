public class Solution {
    public bool hasDuplicate(int[] nums) {
        HashSet<int> set = new HashSet<int>();

        foreach(int number in nums)
        {
            if(set.Contains(number)) return true;
            set.Add(number);
        }

        return false;
    }
}