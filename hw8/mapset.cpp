#include <iostream>
#include <fstream>
#include<iterator>
#include<set>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

void toLower(string& str)
{
	transform(str.begin(),str.end(),str.begin(),::tolower);
}
int main()
{
	ifstream doc("sample_doc.txt");
	ifstream stopwords("stopwords.txt");
	vector<string> allWords;
	set<string> exclude;
	
	copy(istream_iterator<string>(doc),istream_iterator<string>(),back_inserter(allWords));
	copy(istream_iterator<string>(stopwords),istream_iterator<string>(),inserter(exclude,exclude.begin()));
	map<string,int> M;
	for_each(allWords.begin(),allWords.end(),toLower);
	for_each(allWords.begin(),allWords.end(),[&](string& s){exclude.find(s) == exclude.end()?M[s]++:true;});
	ofstream freq("frequency.txt");
	for_each(M.begin(),M.end(),[&](pair<string,int> P){freq << P.first <<": " << P.second<<"\n";});
	cout << M.size() << endl;	
	return 0;
}
