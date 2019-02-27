#pragma once
#include<string>
#include"arrayStack.h"
using namespace std;
class Solution {
public:
	bool isValid(string s) {
		for (int i = 0; i < size(s); i++) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
				st.push(s[i]);
			}
			else
			{
				if (st.empty())
					return false;

				char topchar = st.top();
				st.pop();
				if (s[i] == ')'&& topchar != '(')
					return false;
				if (s[i] == ']'&& topchar != '[')
					return false;
				if (s[i] == '}'&& topchar != '{')
					return false;
			}
		}
		return st.empty();
	}

private:
	arrayStack<char> st;
};
