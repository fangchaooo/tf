#include <iostream>
#include "algorithm"
#include "fstream"
#include "stdio.h"
#include "stdlib.h"
using  namespace std;

int offset(string int_s, string dec_s);
string get_floating_s(string int_s, string dec_s);
int get_number_sign(float num);
string get_fraction(string int_s, string dec_s, int index);
string get_index(int offset);
int offset(string int_s, string dec_s);
string int_cover_to_binary(int n, bool change = false);
string dec_cover_to_binary(float n, bool change = false);
int int_bit(float num);

union bits {
        float f;
        unsigned int bits;
};

void print_hex( float f) {
    union  bits t;
    t.f = f;
    printf( "The float looks like Ox%x in hex.\n", t.bits );
}

void float_trans_to_bit(float num)
{
    union bits b;
    b.f = num;

}

int get_number_sign(float num)
{
    int number_sign
    ;
    if(num >= 0)
        number_sign
        = 1;
    else
        number_sign
        = 0;
    return number_sign;
}

string get_index(int offset)
{
    int index = 127 + offset;
    string s = int_cover_to_binary(index);
    if(s.length() < 8)
        s = "0" + s;
    return s;
}

string get_floating_s(string int_s, string dec_s, int index)
{
    string s="" ;
    if(index > 0)
    {
        s = int_s[0] + "." + int_s.substr(1) + dec_s;
    }
    else if( index < 0)
    {
        string ss = ".";
        s = dec_s[-index+1] + ss + dec_s.substr(-index);
    }
    else
    {
        s = int_s + "." + dec_s;
    }
    return s;
}

int offset(string int_s, string dec_s)
{
    if (atol(int_s.c_str())>=1)
        return int_s.length() - 1;
    else
    {
        int index = 0;
        for(auto i : dec_s)
        {
            if(i == '1')
                break;
            else
                index -= 1;
        }
        return index-1;
    }
}
float dec_num(string s)
{
    int index = s.find(".");
    s = s.substr(index);
    return stod(s.c_str());
}



string init_bit(float num)
{
    int i_n = num > 0? (int)num : -(int)num;
    float d_n = num - (int)num;
    cout<<d_n<<endl;
    string int_s = int_cover_to_binary(i_n);
    string dec_s = dec_cover_to_binary(d_n);
    int index = offset(int_s, dec_s);
    string s = get_floating_s(int_s, dec_s, index);
    s += "00000000000000000000000000000000";
    s = s.substr(0,25);
    s = s + " * 2^" + to_string(index);
    if(num>=0)
        return s;
    else
        return "-"+s;
    return s;
}

string int_cover_to_binary(int n, bool change)
{
    static string i_s = "";
    if(change) i_s = "";
    if(n/2 != 0)
    {
        int_cover_to_binary(n / 2);
    }
    i_s += ::to_string(n%2);
    return i_s;
}

string dec_cover_to_binary(float n, bool change)
{
    static string d_s = "";
    if(change) d_s ="";
    while(n != 1)
    {
        n *= 2;
        if(n > 1)
        {
            d_s += "1";
            n  -= 1;
        }
        else if(n<1)
            d_s += "0";
        if(d_s.length() > 32)
            break;
    }
    return d_s + "1";
}

int main2() {
    fstream file;
    file.open("/home/fc/Downloads/floating.data/floating.1.in", ios::in);
    string s;
    if(file.is_open())
    {
        getline(file, s);
        int num = ::atoi(s.c_str());
        while(num--)
        {
            getline(file,s);
            float n = ::atof(s.c_str());
            cout<<n<<endl;
        }
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int main()
{

//    string s = "0.001101010101";
//    long int a = atol(s.c_str());
//    int l  = ::to_string(a).length() - s.length();
    float s = dec_num("0.8000000119209");

    cout<<s<<endl;
//string s = "1";
//string b = s.substr(1);
//cout<<b.length();


}
