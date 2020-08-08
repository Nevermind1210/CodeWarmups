#include <iostream>
#include <vector>

typedef std::vector<std::vector<char>> OthelloBoardState;

bool CheckDirection(char player, int xdir, int ydir, int x, int y, const OthelloBoardState& grid)
{
    int xi = (x + xdir);
    int yi = (y + ydir);
    bool foundOtherPlayer = true;

    while (xi >= 0 && xi < 8 && yi < 8 && grid[yi][xi] != player && grid[yi][xi] != ' ')
    {
        xi += xdir;
        yi += ydir;
        foundOtherPlayer = false;
    }

    if (xi >= 0 && xi < 8 && yi >= 0 && yi < 8 && grid[yi][xi] == player && !foundOtherPlayer)
    {
        return true;
    }

    return false;
}


bool IsValidMove(char player, int x, int y, const OthelloBoardState& grid)
{
    // It is assumed that 'grid' will have exactily 8x8 rows/cols
    // TODO: calculate if a given coordinate is a valid move.
    //  the given coordinate must adhere to the rules of othello for 
    //  determining if the move is valid
   
      // Look left
    if (CheckDirection(player, -1, 0, x, y, grid))
    {
        return true;
    }
    // Look right
    if (CheckDirection(player, 1, 0, x, y, grid))
    {
        return true;
    }
    // Look up
    if (CheckDirection(player, 0, -1, x, y, grid))
    {
        return true;
    }
    // Look down
    if (CheckDirection(player, 0, 1, x, y, grid))
    {
        return true;
    }
    // Look top left
    if (CheckDirection(player, -1, -1, x, y, grid))
    {
        return true;
    }
    // Look top right
    if (CheckDirection(player, 1, -1, x, y, grid))
    {
        return true;
    }
    // Look bottom left
    if (CheckDirection(player, 1, 1, x, y, grid))
    {
        return true;
    }
    // Look bottom right
    if (CheckDirection(player, -1, 1, x, y, grid))
    {
        return true;
    }
    return false;
}
OthelloBoardState MakeMove(char player, int x, int y, OthelloBoardState grid)
{
    // if the move was not valid, just return the original...
    if (IsValidMove(player, x, y, grid) == false)
        return grid;
    // TODO: This is optional, but give it a go if you have time ;)
    // update 'grid' so that the approprate tiles have been flipped.
    return grid;
}

int main(int argc, char** argv)
{
    OthelloBoardState state1 =
    {//   0    1    2    3    4    5    6    7
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 0
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 1
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 2
        {' ', ' ', ' ', 'W', 'B', ' ', ' ', ' '}, // 3
        {' ', ' ', ' ', 'B', 'W', ' ', ' ', ' '}, // 4
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 5
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 6
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}  // 7
    };
    auto ShouldBe = [](auto result, auto expected) {
        std::cout << (result == expected ? "\033[32m [PASS]" : "\033[31m [FAIL]") << "\033[0m" << std::endl;
    };
    ShouldBe(IsValidMove('B', 5, 4, state1), true); // true
    ShouldBe(IsValidMove('B', 2, 4, state1), false); // false
    ShouldBe(IsValidMove('B', 3, 2, state1), true); // true
    ShouldBe(IsValidMove('B', 3, 5, state1), false); // false
    ShouldBe(IsValidMove('B', 5, 5, state1), false); // false
    ShouldBe(IsValidMove('W', 5, 4, state1), false); // false
    ShouldBe(IsValidMove('W', 2, 4, state1), true); // true
    ShouldBe(IsValidMove('W', 3, 2, state1), false); // false
    ShouldBe(IsValidMove('W', 3, 5, state1), true); // true
    ShouldBe(IsValidMove('W', 5, 5, state1), false); // false
    OthelloBoardState state2 =
    {//   0    1    2    3    4    5    6    7
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 0
        {' ', ' ', 'B', ' ', ' ', ' ', ' ', ' '}, // 1
        {' ', ' ', 'B', 'W', ' ', ' ', ' ', ' '}, // 2
        {' ', ' ', 'B', 'W', 'B', ' ', ' ', ' '}, // 3
        {' ', ' ', 'W', 'W', 'W', ' ', ' ', ' '}, // 4
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 5
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, // 6
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}  // 7
    };
    ShouldBe(IsValidMove('B', 2, 5, state2), true); // true
    ShouldBe(IsValidMove('B', 3, 5, state2), false); // false
    ShouldBe(IsValidMove('B', 4, 5, state2), true); // true
    ShouldBe(IsValidMove('B', 3, 1, state2), false); // false
    ShouldBe(IsValidMove('B', 4, 2, state2), true); // true
    ShouldBe(IsValidMove('B', 4, 1, state2), true); // true

    ShouldBe(IsValidMove('W', 2, 5, state2), false); // false
    ShouldBe(IsValidMove('W', 2, 0, state2), true); // true
    ShouldBe(IsValidMove('W', 3, 1, state2), false); // false
    return 0;
}