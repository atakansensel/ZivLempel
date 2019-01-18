#include <iostream>
#include <string>
#include <fstream>
#include <ostream>

using namespace std;

// DECOMPRESS

bool find(string arr[],int i)
{
	if(arr[i]=="")
	{
		 return false;
	}
	else
	{
		return true;
	}


}


int main()
{
	string arr[4096];
	for(int i = 0;i<256;i++) // assigning ascii codes to array 
	{
	  arr[i]=char(i);
	}



	
	
	ifstream file;
	file.open("compout.txt");
	ofstream output("decompout.txt");

	int num;
	int code = 256;

	string q;// current string
	string p;// previuos string

	

	while(file>>num)
	{

		if(find(arr,num))// if number in the dictionary 
		{
			 q = arr[num]; 

			 output<<arr[num];
			
			 if(p != "" && code < 4096 ) // since our dictionary has max 4096 elements so we dont need to add new strings 
			 {
				 arr[code] = p + q.at(0); // 
			    code++;
			}
	         p = arr[num];  
		}

		else
		{
		
			arr[code] = p+p.at(0);
			output << arr[code];
			p=arr[code];
			if(code < 4096){
			code++;
			}
			

         }


	}
// close the files 
	file.close();
	output.close();

return 0;
}