#include<iostream>
#include<set>
#include<fstream>
#include<map>
#include<string>
using namespace std;

set<string>Set;
map<string,int> m;
char arr[1024];
int num = 0;
int Count(const char *str)
{
	const char *p = str;
	while(*p != '\0')
	{
		if((*p&0x80) && (*(p+1)&0x80))
		{	
			char china[3] = {'\0'};
			china[0] = *p;
			china[1] = *(p+1);
			string S = china;
			//cout << S << endl;
			Set.insert(S);
			//cout << china << endl;
			num++;
			p = p + 2;
		}
		else
		{
			p++;
		}
	}
	return num;
}

void TraverseSet(set<string> s)
{
	for(set<string>::iterator iter = s.begin();iter !=s.end();iter++)
	{
		cout << *iter;
	}
	cout << endl;
}
int main(int argc, char *argv[])
{
	ifstream world(argv[1]);
	if(!world)
	{
		cout <<"can't get file common world\n";
		return 0;
	}
	else
	{
		string str;
		while(getline(world,str))
		{
			const char* ch = str.c_str();
			Count(ch);
		}
	}
	TraverseSet(Set);

	cout <<"Total num: "<< num << endl;
	cout <<"Different num: " <<Set.size()<< endl;
	return 0;
}
