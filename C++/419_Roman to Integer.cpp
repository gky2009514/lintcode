class Solution {
public:
    /**
     * @param s Roman representation
     * @return an integer
     */
    int romanToInt(string& s) {
        if (s.length() <= 0)
            return 0;
        int num = 0;
        for (int i = 0; i < s.length(); i++)
            num += getNum(s[i]);
        int pre = 0, cur = getNum(s[0]);
        for (int i = 1; i < s.length(); i++) {
            pre = cur;
            cur = getNum(s[i]);
            if (pre * 5 == cur || pre * 10 == cur)
                num -= pre << 1;
        }
        return num;
    }

private:
    int getNum(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
};