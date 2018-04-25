#include "MapArray.h"
#include "SetList.h"
#include <iostream>
#include <fstream>
#include<iterator>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

void toLower(string& str)
{
	transform(str.begin(),str.end(),str.begin(),::tolower);
}

/*
string toLower(string& str)
{
	string cpy = str;
	transform(cpy.begin(),cpy.end(),cpy.begin(),::toLower);
	return cpy;
}
*/
int main()
{
	ifstream doc("sample_doc.txt");
	ifstream stopwords("stopwords.txt");
	vector<string> allWords;
	SetList<string> exclude;
	
	copy(istream_iterator<string>(doc),istream_iterator<string>(),back_inserter(allWords));
	for_each(istream_iterator<string>(stopwords),istream_iterator<string>(),[&](string s){exclude.insert(s);});
	MapArray<string,int> M;
	for_each(allWords.begin(),allWords.end(),toLower);
	for_each(allWords.begin(),allWords.end(),[&](string& s){exclude.find(s) == exclude.end()?M[s]++:true;});
	ofstream freq("frequency.txt");
	for_each(M.begin(),M.end(),[&](pair<string,int> P){freq << P.first <<": " << P.second<<"\n";});
	return 0;
}
