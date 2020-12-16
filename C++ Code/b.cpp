
//https://www.youtube.com/watch?v=OF8hCaX24Vs
//(2020). Retrieved 16 December 2020, from https://www.youtube.com/watch?v=OF8hCaX24Vs


//https://www.cplusplus.com/forum/beginner/57858/
//keeping zero after floating point - C++ Forum. (2020). Retrieved 16 December 2020, from https://www.cplusplus.com/forum/beginner/57858/

//https://www.geeksforgeeks.org/convert-decimal-fraction-binary-number/
//Convert decimal fraction to binary number - GeeksforGeeks. (2017). Retrieved 16 December 2020, from https://www.geeksforgeeks.org/convert-decimal-fraction-binary-number/
#include<iostream>
#include<random>
#include <iomanip>
#include<ctime>
#include<bits/stdc++.h>

using namespace std;


string decimalToBinary(double num, int k_prec)
{
    string binary = "";

    // Fetch the integral part of decimal number
    int Integral = num;

    // Fetch the fractional part decimal number
    double fractional = num - Integral;

    // Conversion of integral part to
    // binary equivalent
    while (Integral)
    {
        int rem = Integral % 2;

        // Append 0 in binary
        binary.push_back(rem +'0');

        Integral /= 2;
    }

    // Reverse string to get original binary
    // equivalent
    reverse(binary.begin(),binary.end());

    // Append point before conversion of
    // fractional part
    binary.push_back('.');

    // Conversion of fractional part to
    // binary equivalent
    while (k_prec--)
    {
        // Find next bit in fraction
        fractional *= 2;
        int fract_bit = fractional;


        if (fract_bit == 1)
        {
            fractional -= fract_bit;
            binary.push_back(1 + '0');
           // cout<<"Exact";
        }
        else{
            binary.push_back(0 + '0');
           // cout<<"Approximate";
        }
           if(fractional == 0){
            cout<<"Exact";
           }
    }

    return binary;

}


string remarks(double num, int k_prec)
{
    string remarkss = "";
    string binary = "";
int Integral = num;
    double fractional = num - Integral;

     while (Integral)
    {
        int rem = Integral % 2;

        // Append 0 in binary
        binary.push_back(rem +'0');

        Integral /= 2;
    }

    // Reverse string to get original binary
    // equivalent
    reverse(binary.begin(),binary.end());

    // Append point before conversion of
    // fractional part
    binary.push_back('.');


    while (k_prec--)
    {
        // Find next bit in fraction
        fractional *= 2;
        int fract_bit = fractional;

        if (fract_bit == 1)
        {
            fractional -= fract_bit;
            binary.push_back(1 + '0');
           // cout<<"Exact";
        }
        else{
            binary.push_back(0 + '0');
           // cout<<"Approximate";
        }

    }
        if(fractional == 0){
            remarkss = "exact";
           }
           else{
            remarkss = "Approximate";
           }
    return remarkss;

}

int main(){
    mt19937 generator;
    generator.seed(std::time(0));

    uniform_int_distribution<uint32_t>random_number(1001,99999);

    int random;
    int decimal_places = 1000;

    cout<<"S/No.\t\tDecimal Number\t\tBinary Number\t\t\tRemarks\t\t\n";
    for(int i = 1; i < 31; ++i){
        random = random_number(generator);
        cout<<i;

        double floating = (double)random/decimal_places;
        cout<<"\t\t"<<floating<<fixed<<setprecision(2)<<"\t\t\t"<<decimalToBinary(floating, 5)<<"\t\t\t"<<remarks(floating, 5)<<endl;
    }
    return 0;
}
