#include <iostream>
#include "calc.h"
using namespace std;
int main()
{
    BigDecimal num1("009");
    BigDecimal num7("-0010");

    BigDecimal num2("-24573");
    BigDecimal num3("-254");
    BigDecimal num4 = num1 + num7;
    BigDecimal num5 = num3 - num2;//    cout << "num1 = " << num1 << endl;
//    cout << "num2 = " << num2 << endl;
    // Next statement will print 236913578023691357802369135780
    cout << "num2 + num1 = " << num4 << endl;
    // Next statement will print -313456789011345678901134567890
    cout << "num2 - num3 = " << num5 << endl;
    if (num7>num1)
    {
        cout << "true"<<endl;
    } else
    {
        cout << false;
    }
    return 0;
}
