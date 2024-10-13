// https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/description/?envType=problem-list-v2&envId=an1phfb2

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) 
    {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int moves=0;
        int n=seats.size();

        for(int i=0; i<n; i++)
        {
            moves+=abs(seats[i]-students[i]);
        }

        return moves;
    }
};
