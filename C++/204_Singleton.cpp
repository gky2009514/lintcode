class Solution {
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* getInstance() {
        static Solution *s = new Solution();
        return s;
    }

private:
    Solution(){}
};