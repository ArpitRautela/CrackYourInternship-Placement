class Solution
{
public:
  int calculate(string s)
  {
    stack<int> st;
    char ch = '+';
    for (int i = 0; i < s.size(); i++)
    {
      int num = 0;
      // store the number
      while (i < s.size() && !(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'))
      {
        if (s[i] == ' ')
        {
          i++;
          continue;
        }
        num = num * 10 + (s[i] - '0'), i++;
      }
      if (i <= s.size() && ch == '*')
      {
        int a = st.top();
        st.pop();
        st.push(a * num);
      }
      else if (i <= s.size() && ch == '/')
      {
        int a = st.top();
        st.pop();
        a = a / num;
        st.push(a);
      }
      else if (i < s.size() && ch == '-')
      {
        st.push(-num);
      }
      else if (i < s.size() && ch == '+')
      {
        st.push(num);
      }

      if (i >= s.size() && !(ch == '/' || ch == '*'))
      {
        if (ch == '+')
          st.push(num);
        else
          st.push(-num);
      }
      else
        ch = s[i];
    }
    while (st.size() != 1)
    {
      int a = st.top();
      st.pop();
      int b = st.top();
      st.pop();
      st.push(a + b);
    }
    return st.top();
    return 8;
  }
};
