/*
Coding Ninjas has provided you a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. Now, you are also provided with a word list that needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.
For example, The following is an example for the input crossword grid and the word list.
*/

#include<bits/stdc++.h>
using namespace std;


bool isVertical(char** grid, string s, int row, int col)
{
	if (10-row<s.size())
	{
		return false;
	}
	for (int i = 0; i < s.length(); ++i)
	{
		if (grid[row+i][col]=='-' || grid[row+i][col]==s[i])
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}
void setVertical(char** grid, string s, bool* helper1, int row, int col)
{
	for (int i = 0; i < s.length(); ++i)
	{
		if (grid[row+i][col]==s[i])
		{
			helper1[i]=1;
			continue;
		}
		grid[row+i][col]=s[i];
	}
}
void resetVertical(char** grid, string s, bool* helper1, int row, int col)
{
	for (int i = 0; i < s.length(); ++i)
	{
		if (helper1[i]==0)
		{
			grid[row+i][col]='-';
		}
	}
}
bool isHorizontal(char** grid, string s, int row, int col)
{
	if (10-col<s.size())
	{
		return false;
	}
	for (int i = 0; i < s.length(); ++i)
	{
		if (grid[row][col+i]=='-' || grid[row][col+i]==s[i])
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}
void setHorizontal(char** grid, string s, bool* helper2, int row, int col)
{
	for (int i = 0; i < s.length(); ++i)
	{
		if (grid[row][col+i]==s[i])
		{
			helper2[i]=1;
			continue;
		}
		grid[row][col+i]=s[i];
	}
}
void resetHorizontal(char** grid, string s, bool* helper2, int row, int col)
{
	for (int i = 0; i < s.length(); ++i)
	{
		if (helper2[i]==0)
		{
			grid[row][col+i]='-';
		}
	}
}
bool crossword(char** grid, vector<string> &word, int index)
{
	if (index>=word.size())
	{
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				cout<<grid[i][j];
			}
			cout<<endl;
		}
		return true;
	}
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (grid[i][j]=='-' || grid[i][j]==word[index][0])
			{
				if(isVertical(grid, word[index], i, j))
				{
					bool* helper1=new bool[word[index].size()];
					for (int i = 0; i < word[index].size(); ++i)
					{
						helper1[i]=0;
					}
					setVertical(grid, word[index], helper1, i, j);
					if (crossword(grid, word, index+1))
					{
						return true;
					}
					resetVertical(grid, word[index], helper1, i, j);
				}
				if(isHorizontal(grid, word[index], i, j))
				{
					bool* helper2=new bool[word[index].size()];
					for (int i = 0; i < word[index].size(); ++i)
					{
						helper2[i]=0;
					}
					setHorizontal(grid, word[index], helper2, i, j);
					if (crossword(grid, word, index+1))
					{
						return true;
					}
					resetHorizontal(grid, word[index], helper2, i, j);
				}
			}
			
			
		}
	}
	return false;
}
int main()
{
	char** grid=new char*[10];
	for (int i = 0; i < 10; ++i)
	{
		grid[i]=new char[10];
		for (int j = 0; j < 10; ++j)
		{
			cin>>grid[i][j];		
		}
	}
	string s;
	cin>>s;
	s+=';';
	vector<string> word;
	int index=0;
	string eachword;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i]!=';')
		{
			eachword+=s[i];
		}
		else
		{
			word.push_back(eachword);
			eachword="";
		}
	}
	bool b=crossword(grid, word, 0);
	
	return 0;
}