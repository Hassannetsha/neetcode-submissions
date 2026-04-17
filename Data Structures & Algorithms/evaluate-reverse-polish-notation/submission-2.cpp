class Solution {
public:
int evalRPN(vector<string> &tokens)
{
  stack<pair<string, int>> op;
  stack<int> num;
  int ctn = 0, res = 0;
  bool first = true;
  for (int i = tokens.size() - 1; i >= 0; i--)
  {
    if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
    {
      op.emplace(tokens[i], i);
      ctn = 0;
    }
    else
    {
      num.push(stoi(tokens[i]));
      ctn++;
    }
    while (ctn == 2 && !op.empty())
    {
      int x, y;
      x = num.top();
      num.pop();
      y = num.top();
      num.pop();
      if (op.top().first == "+")
      {
        x += y;
      }
      else if (op.top().first == "-")
      {
        x -= y;
      }
      else if (op.top().first == "*")
      {
        x *= y;
      }
      else
      {
        x /= y;
      }
      num.push(x);
      if (op.top().second + 1 < tokens.size() && (tokens[op.top().second + 1] == "+" || tokens[op.top().second + 1] == "-" || tokens[op.top().second + 1] == "*" || tokens[op.top().second + 1] == "/"))
      {
        ctn = 1;
      }
      op.pop();
    }
  }
  while (!op.empty())
  {
    int x, y;
    // if (first)
    // {
    x = num.top();
    num.pop();
    // first = false;
    // }
    y = num.top();
    num.pop();
    if (op.top().first == "+")
    {
      x += y;
    }
    else if (op.top().first == "-")
    {
      x -= y;
    }
    else if (op.top().first == "*")
    {
      x *= y;
    }
    else
    {
      x /= y;
    }
    op.pop();
    num.push(x);
    // if (!num.empty() && !op.empty())
    // {
    //   y = num.top();
    //   num.pop();
    //   num.push(x);
    //   num.push(y);
    // }
  }
  return num.top();
}
};
