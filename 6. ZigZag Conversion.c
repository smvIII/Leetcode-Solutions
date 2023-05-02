// solution for zigzag conversion from leetcode.com
// performs poorly in runtime, but in 70th percentile of memory usage

class Solution {
public:
    string convert(string s, int numRows) {
        
        char arr[numRows][s.size()];
        //char answer[s.size()];
        string answer;
        bool falling = true;
        int currentRow = 0;
        int currentCol = 0;

        if (numRows == 1)
        {
                answer = s;
                return answer;
        }

        for (int r = 0; r < numRows; r++)
        {
                for( int c = 0; c < s.size(); c++)
                {
                        arr[r][c] = '0';
                }
        }
        for (int i = 0; i < s.size(); i++)
        {
                if (falling)
                {
                        arr[currentRow][currentCol] = s[i];
                        currentRow++;
                }
                else
                {
                        arr[currentRow][currentCol] = s[i];
                        if (currentRow != 0)
                        {
                                currentRow--;
                                currentCol++;
                        }
                }

                if (falling && currentRow % numRows == 0)
                {
                        if (falling)
                                currentRow--;
                        falling = false;
                        currentRow--;
                        currentCol++;
                }
                if (!falling && currentRow == 0)
                {
                        falling = true;
                }
        }

        for (int r = 0; r < numRows; r++)
        {
                for (int c = 0; c < s.size(); c++)
                {
                        if ( arr[r][c] != '0')
                        {
                             answer.push_back(arr[r][c]);
                        }
                }
        }
        return string(answer);
    }
};
