class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operations;
        int result;
        int left;
        int right;
        string operation;
        for (int i = 0 ; i < tokens.size(); i++) {
            if (tokens[i].size() > 1 || isalnum(tokens[i][0])) {
                operations.push(stoi(tokens[i]));
            } else {
                right = operations.top();
                operations.pop();
                left = operations.top();
                operations.pop();
                result = performOperation(left,right, tokens[i]);
                std::cout << result << "\n";
                operations.push(result);
            }
        }
        return (int)operations.top();
    }

    int performOperation(double left, double right, string operation) {
        if (operation == "+") {
            return left + right;
        } else if (operation == "-") {
            return left - right;
        } else if (operation == "*") {
            return left * right;
        } else if (operation == "/") {
            return left / right;
        } return 0.0;
    }
};
