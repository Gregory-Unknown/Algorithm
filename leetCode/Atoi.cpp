#include <iostream>
#include <climits>

int myAtoi(std::string &s) {
    int sign = 1;
	long long res = 0;
    int i;
    if (!s.size()) return (0);
	for (i = 0; i < s.size() && (s.at(i) == '\t' || s.at(i) == '\n' || s.at(i) == '\v' || s.at(i) == '\f' || s.at(i) == '\r' || s.at(i) == 32); ++i)
        ;
    if (i >= s.size())
        return (0);
	if (s.at(i) == '-')
	{
		sign = -sign;
		++i;
	}
	else if (s.at(i) == '+')
		++i;
	while ( i < s.size() && s.at(i) > 47 && s.at(i) < 58)
	{
		res = 10 * res + (s.at(i) - 48);
        if (res * sign > INT_MAX)
			return (INT_MAX);
		if (res * sign < INT_MIN)
			return (INT_MIN);
		++i;
	}
	return (res * sign);
}

int main()
{
    std::string s = " ";
    std::cout << myAtoi(s) << std::endl;
}