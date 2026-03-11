// NOTE: The ONLY files that should be #included for this assignment are iostream,  
// cmath (for the pow function), 
// and string
// No other files should be #included

#include <iostream>
#include <cmath>
#include <string>


// NOTE: The ONLY files that should be #included for this assignment are iostream,  
// cmath (for the pow function), 
// and string
// No other files should be #included

using namespace std;

string addbin(string, string);  
string addhex(string, string); 


int main()
{
	
	cout<<"binary 1101 + 1000 = "<<addbin("1101", "1000")<<endl;   //you should get 10101
	cout<<"binary 11000 + 1011 = "<<addbin("11000", "1011")<<endl; //you should get 100011
	cout<<"binary 11111111 + 1 = "<<addbin("11111111", "1")<<endl; //you should get 100000000
	cout<<"binary 101010 + 10 = "<<addbin("101010", "10")<<endl<<endl; //you should get 101100
	
	// cout<<"hexadecimal A4 + A5 = "<<addhex("A4", "A5")<<endl;  //you should get 149
	// cout<<"hexadecimal 2B + C = "<<addhex("2B",  "C")<<endl;    //you should get 37
	// cout<<"hexadecimal FABC + 789 = "<<addhex("FABC", "789")<<endl;  //you should get 10245
	// cout<<"hexadecimal FFFFFF + FF = "<<addhex("FFFFFF", "FF")<<endl<<endl; //you should get 10000FE 
	

	system("PAUSE");
	return 0;
	
}

string sign_extend(string s, int digits)
{
	string new_s = s;
	for (int i = 0; i<digits; i++)
	{
		new_s = "0" + new_s;
	}
	return new_s;
}

string addbin(string bin1, string bin2)
{
	int bin1_length = bin1.length();
	int bin2_length = bin2.length();
	int length = 0;
	int carry = 0;

	string new_string = "";

	if (bin1_length < bin2_length)
	{
		bin1 = sign_extend(bin1, bin2_length-bin1_length);
		length = bin2_length;
	}
	else if (bin2_length < bin1_length)
	{
		bin2 = sign_extend(bin2, bin1_length-bin2_length);
		length = bin1_length;
	}
	else
	{
		length = bin1_length;
	}

	for (int i = length-1; i >= 0; i--)
	{
		int cur_sum = int(bin1[i]-'0') + int(bin2[i]-'0') + carry;
		if (cur_sum %2 == 0)
		{
			new_string = "0" + new_string;
		}
		else
		{
			new_string = "1" + new_string;
		}

		if (cur_sum >= 2)
		{
			carry = 1;
		}
		else
		{
			carry = 0;
		}

	}
	if (carry == 1)
	{
		new_string = "1" + new_string;
	}
	
	return new_string;
}

string addhex(string hex1, string hex2)
{
	//IMPLEMENT THIS FUNCTION
	//IMPLEMENT THIS FUNCTION
	//IMPLEMENT THIS FUNCTION

	return " ";
	
}
