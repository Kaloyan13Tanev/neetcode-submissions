class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {
            char curr = s[i];
            if (curr == '(' || curr == '[' || curr == '{')
            {
                st.push(curr);
            }
            else 
            {
                bool isValid = false;
                if (!st.empty())
                {
                    char top = st.top();
                    switch (curr)
                    {
                        case ')': isValid = (top == '(');
                        break;
                        case ']': isValid = (top == '[');
                        break;
                        case '}': isValid = (top == '{');
                        break;
                    }
                }

                if (isValid) st.pop();
                else return false;
            }
        }

        return st.empty();
    }
};