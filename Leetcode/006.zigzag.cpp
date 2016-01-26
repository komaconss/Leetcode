#include <iostream>
#include <vector>

using namespace std;

string convert(string text, int nRows)
{
	if (text.size() <= nRows)
	{
		return text;
	}	
	vector<vector<char>> vec;
	int add = nRows / 2;
	int j = 0;
	int len = text.size();
	for (; j < nRows; ++j) //第一列的处理 
	{
		vector<char> subVec;
		subVec.push_back(text[j]);
		vec.push_back(subVec);
	}
	int i = nRows;
	while (i < len)
	{
		for (j = nRows - 2; j > 0 && i < len; ++i, --j)
		{
			//cout << "j = " << j << "text[i] = " << text[i] << endl;
			vec[j].push_back(text[i]);
		}
		for (j = 0; j < nRows && i < len; ++i, ++j)
		{
			//cout << "j = " << j << "text[i] = " << text[i] << endl;
			vec[j].push_back(text[i]);
		}
	}
	string res;
	i = 0;
	while (i < vec.size())
	{
		string tmp(vec[i].cbegin(), vec[i].cend());
		res += tmp;
		++i;
	}
	return res;
}

int main()
{
	string s = "ABCD";
	int nRows = 2;
	string res = convert(s, nRows);
	cout << res << endl;
}




