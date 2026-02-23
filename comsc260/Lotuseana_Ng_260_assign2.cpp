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

int bin_to_dec(string);
string dec_to_bin(int);
int hex_to_dec(string);  
string dec_to_hex(int);  


int main() 
{
	
	cout<<"10000011 binary = "<<bin_to_dec("10000011")<<" decimal\n"; // you should get 131
	cout<<"01010101 binary = "<<bin_to_dec("01010101")<<" decimal\n"; // you should get 85
	cout<<"1111111111111111 binary = "<<bin_to_dec("1111111111111111")<<" decimal\n"; // you should get 65,535
	cout<<"0111111111111111 binary = "<<bin_to_dec("0111111111111111")<<" decimal\n\n"; // you should get 32,767
	
	cout<<"255 decimal = "<<dec_to_bin(255)<<" binary\n"; //you should get 11111111
	cout<<"65532 decimal = "<<dec_to_bin(65532)<<" binary\n"; //you should get 1111111111111100
	cout<<"12 decimal = "<<dec_to_bin(12)<<" binary\n"; //you should get 1100
	cout<<"1000000 decimal = "<<dec_to_bin(1000000)<<" binary\n\n"; //you should get 11110100001001000000
	
	cout<<"ABC hexadecimal = "<<hex_to_dec("ABC")<<" decimal\n"; //you should get 2,748
	cout<<"F5 hexadecimal = "<<hex_to_dec("F5")<<" decimal\n"; //you should get 245
	cout<<"1234 hexadecimal = "<<hex_to_dec("1234")<<" decimal\n"; //you should get 4,660
	cout<<"FDECB hexadecimal = "<<hex_to_dec("FDECB")<<" decimal\n\n"; //you should get 1,040,075
	
	cout<<"512 decimal = "<<dec_to_hex(512)<<" hexadecimal\n"; //you should get 200
	cout<<"5000 decimal = "<<dec_to_hex(5000)<<" hexadecimal\n"; //you should get 1388
	cout<<"900000 decimal = "<<dec_to_hex(900000)<<" hexadecimal\n"; //you should get DBBA0
	cout<<"65525 decimal = "<<dec_to_hex(65525)<<" hexadecimal\n\n"; //you should get FFF5
	
	
	system("PAUSE");
	return 0;

}

// Converts any UNsigned binary number to decimal

int bin_to_dec(string s) 
{
    //1. keeping a running sum of converted bits
    int sum = 0;
    //2. iterating through the bits from left to right (starting with the MSB)
    for (int i = 0; i < s.length(); i++)
    {
        //3. if the current bit is a 1, add the bit's corresponding power of 2
        if (s[i] == '1')
        {
            sum += pow(2, s.length()-1-i);
        }
    }
    return sum;
}	

//Converts any non-negative decimal number to binary

string dec_to_bin(int n)  
{
    //4. keeping a running string of converted numbers
	string s = "";
    bool done = false;
    //5. while algorithm not done and quotient is not 0, loop
    while (!done)
    {
        //6. add the remainder to the beginning of the string
        s = to_string(n % 2) + s ;
        //7. divide the current number by 2
        n = n / 2;
        if (n==0)
        {
            done = true;
        }
    }
    return s;
}


//Converts any UNsigned hexadecimal number to decimal

int hex_to_dec(string s) 
{
    int sum = 0;
    //8. loop through the hexadecimal characters
    for (int i = 0; i < s.length(); i++)
    {
        //9. if the character is a letter, shift ASCII accordinginly
        if (s[i] >= 65)
        {
            sum += (s[i] - 55) * pow (16, s.length()-1-i);
        }
        //10. if the character is a nunber, shift ASCII accordingly
        else
        {
            sum += (s[i] - 48) * pow (16, s.length()-1-i);
        }
    }
    return sum;
}	


//Converts any non-negative decimal number to hexadecimalConverts any non-negative decimal number to hexadecimal

string dec_to_hex(int n)  
{
	string s = "";
    bool done = false;
    while (!done)
    {
        //11. same process as decimal to binary, but divisions by 2 replaced with divisions by 16
        int t = n % 16;
        string temp = "";
        //12. conversions to turn numbers over 9 to their corresponding hexadecimal character
        if (t > 9)
        {
            temp = char(t + 55);
        }
        else
        {
            temp = to_string(t);
        }
        s = temp + s ;
        n = n / 16;
        if (n == 0)
        {
            done = true;
        }
    }
    return s;
}



