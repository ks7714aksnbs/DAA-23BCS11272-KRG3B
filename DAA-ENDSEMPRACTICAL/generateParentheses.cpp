class Solution {
public:
void    tryCombinations(int open, int close, vector<string>& res, string str)
{
        if (open == 0 && close == 0)
        {
            res.push_back(str);
            return ;
        }
        if (open > 0)
            tryCombinations(open - 1, close, res, str + "(");
        if (close > 0 && close > open)
            tryCombinations(open, close - 1, res, str + ")");
}

vector<string> generateParenthesis(int n)
{
        vector<string>  res;

        tryCombinations(n, n, res, "");
        return res;
}
};