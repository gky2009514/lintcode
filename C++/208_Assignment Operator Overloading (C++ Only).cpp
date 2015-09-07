class Solution {
public:
    char *m_pData;

    Solution() {
        this->m_pData = NULL;
    }

    Solution(char *pData) {
        this->m_pData = pData;
    }

    // Implement an assignment operator
    Solution operator=(const Solution &object) {
        if (this == &object)
            return *this;
        char *pre = this->m_pData;
        if (object.m_pData == NULL) {
            this->m_pData = NULL;
        } else {
            int len = static_cast<int>(strlen(object.m_pData));
            this->m_pData = new char[len + 1];
            memcpy(this->m_pData, object.m_pData, len);
            this->m_pData[len] = '\0';
        }
        free(pre);
        return *this;
    }
};