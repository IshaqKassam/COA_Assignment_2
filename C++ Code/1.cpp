//https://www.tutorialspoint.com/cplusplus-program-to-convert-decimal-number-to-binary
//https://googler700.blogspot.com/2015/07/cprogramtoconvertdecimaltobinaryoctalandhexadecimal.html
#include <iostream>
using namespace std;
// The hex, and dec identifiers are stream manipulators

void DecimalToBinary(int n) {
   int binaryNumber[100], num=n;
   int i = 0;
   if(n==0){
    cout<<0;
   }
   while (n > 0) {
      binaryNumber[i] = n % 2;
      n = n / 2;
      i++;
   }

   for (int j = i - 1; j >= 0; j--)
   cout << binaryNumber[j];
   cout<<"\t";
}

int main()
{
cout << "Decimal\t\tBinary\t\tHexadecimal\n(base 10)\t(base 2)\t(base 16)\n";
for ( int i = 0; i <= 256; ++i )
{
cout << dec << i << "\t\t";
// Output binary number
DecimalToBinary(i);
// Output hexadecimal numbers
cout << '\t'  << hex << i << endl;
}
return 0;
}
