#include <iostream>

std::string convert(std::string s, int numRows) {
        if (numRows == 1){
            return s;
        }
        std::string res = "";
        bool goingDown = false;
    
        for (int j = 0; j < numRows; ++j){
            int depth = 0;
                for (int i = 0; i < s.length(); ++i){
                    if (depth == j)
                        res += s.at(i);
                    if (depth == numRows - 1)
                        goingDown = false;
                    if (depth == 0)
                        goingDown = true;
                    if (goingDown == true)
                        depth++;
                    if (goingDown == false)
                        depth--;
                }
            }
        return res;
}

int main()
{
    std::string res = "PAYPALISHIRING";
    int rows = 4;

    std::cout << convert(res, rows) << std::endl;
}