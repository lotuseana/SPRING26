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
	cout<<"Run 1:"<<endl;
	cout<<"binary 1101 + 1000 = "<<addbin("1101", "1000")<<endl;   //you should get 10101
	cout<<"binary 11000 + 1011 = "<<addbin("11000", "1011")<<endl; //you should get 100011
	cout<<"binary 11111111 + 1 = "<<addbin("11111111", "1")<<endl; //you should get 100000000
	cout<<"binary 101010 + 10 = "<<addbin("101010", "10")<<endl<<endl; //you should get 101100

	cout<<"Run 2:"<<endl;
	cout<<"hexadecimal A4 + A5 = "<<addhex("A4", "A5")<<endl;  //you should get 149
	cout<<"hexadecimal 2B + C = "<<addhex("2B",  "C")<<endl;    //you should get 37
	cout<<"hexadecimal FABC + 789 = "<<addhex("FABC", "789")<<endl;  //you should get 10245
	cout<<"hexadecimal FFFFFF + FF = "<<addhex("FFFFFF", "FF")<<endl<<endl; //you should get 10000FE 

	cout<<"Run 3:"<<endl;
	cout<<"binary 1 + 1 = "<<addbin("1", "1")<<endl;
	cout<<"hexadecimal 1A + 2B = "<<addhex("1A", "2B")<<endl<<endl;

	cout<<"Run 4:"<<endl;
	cout<<"binary 101 + 11 = "<<addbin("101", "11")<<endl;
	cout<<"hexadecimal 10 + F = "<<addhex("10", "F")<<endl<<endl;

	cout<<"Run 5:"<<endl;
	cout<<"binary 1000 + 1000 = "<<addbin("1000", "1000")<<endl;
	cout<<"hexadecimal ABC + 123 = "<<addhex("ABC", "123")<<endl<<endl;

	cout<<"Run 6:"<<endl;
	cout<<"binary 0 + 0 = "<<addbin("0", "0")<<endl;
	cout<<"hexadecimal 0 + 0 = "<<addhex("0", "0")<<endl<<endl;

	cout<<"Run 7:"<<endl;
	cout<<"binary 111111 + 1 = "<<addbin("111111", "1")<<endl;
	cout<<"hexadecimal 7FFF + 1 = "<<addhex("7FFF", "1")<<endl<<endl;
	
	system("PAUSE");
	return 0;
	
}

string sign_extend(string s, int digits)
{
	// comment 1: sign_extend adds leading zeros to s so that shorter strings can be padded before addition.  
	string new_s = s;
	for (int i = 0; i<digits; i++)
	{
		new_s = "0" + new_s;
	}
	return new_s;
}

string addbin(string bin1, string bin2)
{
	// comment 2: Compute the lengths of the two binary strings and set up variables for the loop and carry.  
	int bin1_length = bin1.length();
	int bin2_length = bin2.length();
	int length = 0;
	int carry = 0;

	string new_string = "";

	// comment 3: If one binary string is shorter, pad it with leading zeros so both have equal length.  
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

	// comment 4: Loop from the rightmost bit to the left, adding bits and any existing carry at each position.  
	for (int i = length-1; i >= 0; i--)
	{
		// comment 5: cur_sum holds the numeric sum of the two bits at position i plus the current carry.  
		int cur_sum = int(bin1[i]-'0') + int(bin2[i]-'0') + carry;
		if (cur_sum %2 == 0)
		{
			new_string = "0" + new_string;
		}
		else
		{
			new_string = "1" + new_string;
		}

		// comment 6: If the sum at this position is 2 or 3, we set carry to 1 for the next higher bit.  
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
		// comment 7: If there is a leftover carry after the loop, prepend '1' to the front of the binary result.  
		new_string = "1" + new_string;
	}
	
	return new_string;
}

string addhex(string hex1, string hex2)
{
	// comment 8: Start by finding the lengths of the hex strings and preparing variables for the sum and carry.  
	int len1 = hex1.length();
	int len2 = hex2.length();
	int length = 0;
	int carry = 0;

	string result = "";

	// comment 9: Pad the shorter hexadecimal string with leading zeros so both strings are the same length.  
	if (len1 < len2)
	{
		hex1 = sign_extend(hex1, len2 - len1);
		length = len2;
	}
	else if (len2 < len1)
	{
		hex2 = sign_extend(hex2, len1 - len2);
		length = len1;
	}
	else
	{
		length = len1;
	}

	// comment 10: Add the hex digits from right to left, treating each character as a base-16 digit with carry.  
	for (int i = length - 1; i >= 0; i--)
	{
		int val1;
		int val2;

		// comment 11: Convert the current hex digit from hex1 into its integer value between 0 and 15.  
		if (hex1[i] >= '0' && hex1[i] <= '9')
		{
			val1 = hex1[i] - '0';
		}
		else if (hex1[i] >= 'A' && hex1[i] <= 'F')
		{
			val1 = hex1[i] - 'A' + 10;
		}
		else
		{
			val1 = hex1[i] - 'a' + 10;
		}

		// comment 12: Convert the current hex digit from hex2 into its integer value between 0 and 15.  
		if (hex2[i] >= '0' && hex2[i] <= '9')
		{
			val2 = hex2[i] - '0';
		}
		else if (hex2[i] >= 'A' && hex2[i] <= 'F')
		{
			val2 = hex2[i] - 'A' + 10;
		}
		else
		{
			val2 = hex2[i] - 'a' + 10;
		}

		// comment 13: cur_sum stores the total of both digits and the carry, then we split it into a new digit and updated carry.  
		int cur_sum = val1 + val2 + carry;
		int digit = cur_sum % 16;
		carry = cur_sum / 16;

		// comment 14: Convert the numeric digit (0 to 15) back into the corresponding hexadecimal character.  
		char digit_char;
		if (digit < 10)
		{
			digit_char = char('0' + digit);
		}
		else
		{
			digit_char = char('A' + (digit - 10));
		}

		result = digit_char + result;
	}

	// comment 15: If there is a remaining carry after the loop, convert it to hex and put it in front of the result.  
	if (carry > 0)
	{
		char carry_char;
		if (carry < 10)
		{
			carry_char = char('0' + carry);
		}
		else
		{
			carry_char = char('A' + (carry - 10));
		}
		result = carry_char + result;
	}

	return result;
	
}
