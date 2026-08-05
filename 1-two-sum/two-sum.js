/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
    // Brute Force
    let Sec = 0;
    for (let i = 0; i < nums.length - 1; i++) {
        Sec = target - nums[i]
        for (let j = i + 1; j < nums.length; j++) {
            if (nums[j] == Sec) {
                return [i, j]
            }
        }
    }
};