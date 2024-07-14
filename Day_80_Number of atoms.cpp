#include <string>
#include <deque>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    string countOfAtoms(string &formula) {
        deque<pair<string, int>> elementsDeque;
        string_view formulaView = formula;
        int length = formulaView.length();
        
        for (int i = 0; i < length; i++) {
            if (isUpperCase(formulaView[i])) {
                processElement(formulaView, i, elementsDeque);
            } else if (formulaView[i] == '(') {
                elementsDeque.push_back({ "(", -1 });
            } else {
                processClosingBracket(formulaView, i, elementsDeque);
            }
        }
        
        return generateResult(elementsDeque, formula.length());
    }

private:
    bool isUpperCase(char ch) {
        return ch >= 'A' && ch <= 'Z';
    }

    bool isLowerCase(char ch) {
        return ch >= 'a' && ch <= 'z';
    }

    bool isDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }

    void processElement(const string_view &formulaView, int &i, deque<pair<string, int>> &elementsDeque) {
        string elementName;
        string elementCount;
        
        elementName.push_back(formulaView[i]);
        i++;
        
        while (i < formulaView.length() && isLowerCase(formulaView[i])) {
            elementName.push_back(formulaView[i]);
            i++;
        }
        
        while (i < formulaView.length() && isDigit(formulaView[i])) {
            elementCount.push_back(formulaView[i]);
            i++;
        }
        
        elementCount = (elementCount.empty()) ? "1" : elementCount;
        elementsDeque.push_back({ elementName, stoi(elementCount) });
        i--;
    }

    void processClosingBracket(const string_view &formulaView, int &i, deque<pair<string, int>> &elementsDeque) {
        i++;
        string multiplierStr;
        
        while (i < formulaView.length() && isDigit(formulaView[i])) {
            multiplierStr.push_back(formulaView[i]);
            i++;
        }
        
        if (multiplierStr.empty()) {
            multiplierStr = "1";
        }
        
        int multiplier = stoi(multiplierStr);
        stack<pair<string, int>> bufferStack;
        
        while (elementsDeque.back().first != "(") {
            elementsDeque.back().second *= multiplier;
            bufferStack.push(elementsDeque.back());
            elementsDeque.pop_back();
        }
        
        elementsDeque.pop_back();  // Remove the '('
        
        while (!bufferStack.empty()) {
            elementsDeque.push_back(bufferStack.top());
            bufferStack.pop();
        }
        
        i--;
    }

    string generateResult(deque<pair<string, int>> &elementsDeque, int formulaLength) {
        string result;
        map<string, int> elementCountMap;
        result.reserve(formulaLength * 2);
        
        while (!elementsDeque.empty()) {
            elementCountMap[elementsDeque.back().first] += elementsDeque.back().second;
            elementsDeque.pop_back();
        }
        
        for (const auto &pair : elementCountMap) {
            result += pair.first;
            if (pair.second != 1) {
                result += to_string(pair.second);
            }
        }
        
        return result;
    }
};
