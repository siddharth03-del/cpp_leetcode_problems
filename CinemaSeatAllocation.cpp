#include <unordered_map>
#include <vector>
using namespace std;
#include <iostream>
#include <vector>
#include <bitset>
#include <unordered_map>

class Solution {
public:
    int maxNumberOfFamilies(int n, std::vector<std::vector<int>>& reservedSeats) {
        std::unordered_map<int, std::bitset<10>> seats;
        for (const auto& seat : reservedSeats) {
            seats[seat[0]][seat[1] - 1] = 1; // Subtract 1 to make it 0-indexed
        }

        int count = 2 * (n - seats.size()); // Each empty row can have 2 families

        for (const auto& [row, seatRow] : seats) {
            bool canPlaceFamily1 = !seatRow[1] && !seatRow[2] && !seatRow[3] && !seatRow[4];
            bool canPlaceFamily2 = !seatRow[5] && !seatRow[6] && !seatRow[7] && !seatRow[8];
            bool canPlaceFamily3 = !seatRow[3] && !seatRow[4] && !seatRow[5] && !seatRow[6];

            if (canPlaceFamily1) ++count;
            if (canPlaceFamily2) ++count;
            else if (!canPlaceFamily1 && canPlaceFamily3) ++count;
        }

        return count;
    }
};
