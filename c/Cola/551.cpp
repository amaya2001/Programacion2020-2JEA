#include<bits/stdc++.h>

using namespace std;

int main(void){

	#ifdef DBG
	freopen("551.in", "r", stdin);
	freopen("551.out", "w", stdout);
	#endif

	string str;

	while(getline(cin, str)){

		stack<char> st;
		int count = 0;
		int numOfstar = 0;

		for(int i = 0 ; i < str.size() ; i++){

			count++;
			if(str[i] == '(' || str[i] == '[' || str[i] == '{' || str[i] == '<'){

				if(str[i] == '(' && str[i+1] == '*'){

					st.push('*');
					i++;
					numOfstar++;
				}
				else
					st.push(str[i]);
			}
			else if(str[i] == ')' || str[i] == ']' || str[i] == '}' || str[i] == '>' || (str[i] == '*' && str[i+1] == ')')){

				if(st.empty())
					break;
				if(str[i] == '*'){

					if(st.top() != '*')
						break;
					st.pop();
					i++;
					numOfstar++;
				}
				else if(str[i] == ')'){

					if(st.top() != '(')
						break;
					st.pop();
				}
				else if(str[i] == ']'){

					if(st.top() != '[')
						break;
					st.pop();
				}
				else if(str[i] == '}'){

					if(st.top() != '{')
						break;
					st.pop();
				}
				else if(str[i] == '>'){

					if(st.top() != '<')
						break;
					st.pop();
				}
			}
		}
		if(!st.empty() || count < str.size()){

			printf("NO %d\n", count);
		}
		else
			printf("YES\n");
	}
	return 0;
}