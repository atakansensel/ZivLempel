#include <iostream>
#include <string>
#include <fstream>
#include"Tree.h"
#include <ostream>
#include "Binarynode.h"


//COMPRESSOR

using namespace std;


int main(){
	Tree<int,string> dict;
    int num = 256 ;// add num while adding elemnts on tree
	

	ifstream file;
	file.open("compin.txt");
	ofstream output("compout.txt");

	char ch;
	string str;
    file.get(ch);
	str = ch;
	while (!file.eof())
	{

		file.get(ch);
		
		
		if(dict.find(str+ch) == -1 )// if its not in the tree
		{  
			
			string str2 = str + ch;

			if(str.length()==1) 
			{
			   char c = str.at(0);
			   output << int(c) << " ";

            }
			else 
			{
				output <<dict.find(str)<<" ";
			}
			if(num<4096) 
			{
			dict.insert_public(num,str2);
			num++;}
			str = ch;
}
		else // if str in the tree  finds the next elemnt which is not tree
		{
			
			
		str = str +ch;
			}
}

	file.close();
	output.close();
	

	return 0;
}