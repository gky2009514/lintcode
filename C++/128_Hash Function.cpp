class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key, int HASH_SIZE) {
        int n = static_cast<int>(key.length());
        long long res = 0;
        for (int i = 0; i < n; i++)
            res = (res * 33 + key[i]) % HASH_SIZE;
        return static_cast<int>(res);
    }
};