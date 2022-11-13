#include <iostream>
#include <string>
#include <regex>
#include "calc.h"
using namespace std;
BigDecimal::BigDecimal(int num_param)
{

    num = std::to_string(num_param);
    if (num[0] == '+' || num[0] == '-')
    {
        sign = num[0];
        num = num.substr(1);
        size = num.size();
    }
    else
    {
        sign = '+';
        size = num.size();
    }
}

BigDecimal::BigDecimal(std::string num_param)
{
    std::regex filter("(\\+|-)?[0-9]+");
    if (!std::regex_match(num_param, filter))
    {
        throw std::invalid_argument("number");
    }
    else
    {
        if (num_param[0] == '+' || num_param[0] == '-')
        {
            num = num_param.substr(1);
            sign = num_param[0];
            size = num.size();
        }
        else
        {
            num = num_param;
            sign = '+';
            size = num.size();
        }
    }
    while (num[0]=='0'){
        num = num.substr(1);
        size = num.size();


    }
}

void BigDecimal::sizeBalance(string &str1, string &str2)
{
    string zero{"0"};
    while (str1.size() < str2.size())
    {
        str1 = zero + str1;
    }
    while (str1.size() > str2.size())
    {
        str2 = zero + str2;
    }
}

string BigDecimal::adding_strNums(string &str1, string &str2)
{
    size_t sz{str1.size() - 1};
    string res;
    int carry{0};
    for (int i = 0; i <= sz; ++i)
    {

        if ((((int)str1[sz - i] - 48) + ((int)str2[sz - i] - 48) + carry) > 9)
        {
            res = to_string(carry + ((int)str1[sz - i] - 48) + ((int)str2[sz - i] - 48) - 10) + res;
            carry = 1;
        }
        else
        {
            res = to_string(carry + ((int)str1[sz - i] - 48) + ((int)str2[sz - i] - 48)) + res;
            carry = 0;
        }
    }
    if (carry == 1)
    {
        res = "1" + res;
    }
    return res;
}

string BigDecimal::subtract_strNums(string str1, string str2)
{
    int number1{}, number2{};
    string first_num, second_num, result = "";
    char s = '+';
    if (str1 == str2)
    {
        result = "+0";
        return result;
    }
    for (int i = 0; i < str1.size(); i++)
    {
        if ((str1[i] - '0') > (str2[i] - '0'))
        {
            first_num = str1;
            second_num = str2;
            break;
        }
        else if ((str1[i] - '0') < (str2[i] - '0'))
        {
            first_num = str2;
            second_num = str1;
            s = '-';
            break;
        }
    }

    for (int i = str1.size() - 1; i > -1; --i)
    {
        number1 = first_num[i] - '0';
        number2 = second_num[i] - '0';
        if (number1 < number2)
        {
            int j = i - 1;
            if (first_num[j] == '0')
            {
                while (first_num[j] == '0' && j != 0)
                {
                    --j;
                }
                for (int k = j + 1; k < i; ++k)
                {
                    first_num[k] = '9';
                }
            }
            first_num[j] = char(((first_num[j] - '0') - 1) + 48);
            number1 += 10;
        }
        result += to_string(number1 - number2);
    }
    if (s == '-')
    {

        result += "-";
        reverse(result.begin(), result.end());
    }
    else
    {
        result += "+";
        reverse(result.begin(), result.end());
    }

    return result;
}

bool BigDecimal::Is_1stNum_Greater(string str1, string str2)
{
    for (int i = 0; i < str1.length(); i++)
    {
        if ((str1[i] - '0') > (str2[i] - '0'))
        {
            return 1;
        }
        else if ((str1[i] - '0') < (str2[i] - '0'))
        {
            return 0;
        }
    }
}
char BigDecimal::sign_()
{
    return sign;
}

int BigDecimal::size_()
{
    return size;
}

//operator methods
BigDecimal BigDecimal::operator+(BigDecimal num2)
{
    BigDecimal res{"0"};
    sizeBalance(this->num, num2.num);

    if (this->sign == '+' && num2.sign == '+')
    {
        res.sign = '+';
        res.num = adding_strNums(this->num, num2.num);
        res.size = res.num.size();
    }
    else if (this->sign == '-' && num2.sign == '-')
    {
        res.sign = '-';
        res.num = adding_strNums(this->num, num2.num);
        res.size = res.num.size();
    }
    else
    {
        if (this->sign == '-')
        {
            res.num = subtract_strNums(num2.num, this->num);
            res.sign = res.num[0];
            res.num = res.num.substr(1);
            res.size = res.num.length();
        }
        else
        {
            res.num = subtract_strNums(this->num, num2.num);
            res.sign = res.num[0];
            res.num = res.num.substr(1);
            res.size = res.num.length();
        }
    }
    return res;
}

bool BigDecimal::operator==(BigDecimal a)
{
    for (int i = 0; i < num.length(); ++i)
    {
        if (num == a.num)
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool BigDecimal::operator>(BigDecimal &dec2)
{
    if (dec2.sign == '-' && sign == '+')
    {
        return true;
    }
    else if (sign == '-' && dec2.sign == '+')
    {
        return false;
    }
    else if (sign == '+' && dec2.sign == '+')
    {
        if (num.length() < dec2.num.length())
        {
            return false;
        }
        for (int i = 0; i < num.length(); i++)
        {
            if (num[i] > dec2.num[i])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    else if (sign == '-' && dec2.sign == '-')
    {
        if (num.length() < dec2.num.length())
        {
            return true;
        }

        for (int i = 0; i < num.length(); i++)
        {
            if (num[i] < dec2.num[i])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}


BigDecimal BigDecimal::operator-(BigDecimal &num2)
{
    BigDecimal res{"0"};
    sizeBalance(this->num, num2.num);

    if (sign == '+' && num2.sign == '+')
    {
        res.num = subtract_strNums(num, num2.num);
        res.sign = res.num[0];
        res.num = res.num.substr(1);
        res.size = res.num.length();
    }
    else if (sign == '+' && num2.sign == '-')
    {

        res.num = adding_strNums(this->num, num2.num);
        res.sign = '+';
        res.size = res.num.length();
    }
    else if (sign == '-' && num2.sign == '+')
    {
        res.num = adding_strNums(this->num, num2.num);
        res.sign = '-';
        res.size = res.num.length();
    }
    else if (sign == '-' && num2.sign == '-')
    {
        res.num = subtract_strNums(num, num2.num);
        if (res.num[0] == '+')
        {
            res.sign = '-';
        }
        else
        {
            res.sign = '+';
        }
        // res.sign = res.num[0];
        res.num = res.num.substr(1);
        res.size = res.num.length();
    }
    return res;
}

bool BigDecimal::operator<(const BigDecimal &dec2)
{
    if (sign == '-' && dec2.sign == '+')
    {
        return true;
    }
    else if (sign == '+' && dec2.sign == '-')
    {
        return false;
    }
    else if (dec2.sign == '+' && sign == '+')
    {
        if (Is_1stNum_Greater(num, dec2.num))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        if (Is_1stNum_Greater(num, dec2.num))
        {
            return true;
        }
        else
            return false;
    }
}

ostream& operator<<(std::ostream &output, BigDecimal &x)
{
    while (x.num[0] == '0' && x.num.length() > 1)
    {
        x.num = x.num.substr(1);
    }
    if (x.sign == '-')
    {
        output << "-";
    }
    output << x.num;
    return output;
}
