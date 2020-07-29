#include <iostream>
#include <vector>
#include <string>

bool overTwentyOne(std::vector<std::string> cardArray) {
    int countValue = 0;
    std::string key = "A";
   
    for (int i = 0; i < cardArray.size(); i++)
    {
        if (cardArray[i] == "A") //Ace check
        {
            countValue += 11;
        }
        else if (cardArray[i] != "K" &&
            cardArray[i] != "Q" &&
            cardArray[i] != "J")
        {
            int number = stoi(cardArray[i]);
            if (number <= 10 && number >= 1)
            {
                countValue += number;
            }
        }
        else
            countValue += 10;// if face value, add to it
    }
    if (std::find(cardArray.begin(), cardArray.end(), key) != cardArray.end())
    {
        if (countValue > 21)// if value is beyond 21, convert ace to 1
            countValue -= 10;
    }
    if (countValue > 21)
    {
        std::cout << "False! Value was: " << countValue << " Bad Game!" << std::endl;
        return false;
    }
    else if (countValue <= 21)
    {
        std::cout << "True! Value was: " << countValue << " Good Game!" << std::endl;
        return true;
    }
}

int main()
{
    overTwentyOne({ "2", "8", "J" });
    overTwentyOne({ "A", "J", "K" });
    overTwentyOne({ "5", "5", "3", "9" });
    overTwentyOne({ "2", "6", "4", "4", "5" });
    overTwentyOne({ "J", "Q", "K" });

    return 0;
}