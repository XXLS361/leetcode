/*
 * @lc app=leetcode.cn id=458 lang=cpp
 *
 * [458] 可怜的小猪
 */

// @lc code=start
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if (buckets==1) return 0;
        int step,num,max;
        step=minutesToTest/minutesToDie+1;
        for (num=1;num<buckets;num++){
            max=1;
            for(int i=num;i>=1;i--){
                max=max*step;
            }
            if (max>=buckets){
                return num;
            }
        }
        return num;
    }
};
// @lc code=end

