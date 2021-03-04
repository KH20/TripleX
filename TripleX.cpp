#include <iostream>
#include <ctime>

void PrintIntroduction(int LevelDifficulty){

//     std::string inspector_gadget = R""""(
//              .'|
//              |  |  _ _
//              |  | (_X_)
//              |  |   |
//               `.|_.-"-._
//                 |.-"""-.|
//                _;.-"""-.;_
//            _.-' _..-.-.._ '-._
//           ';--.-(_o_I_o_)-.--;'
//            `. | |  | |  | | .`
//              `-\|  | |  |/-'
//                 |  | |  |
//                 |  \_/  |
//              _.'; ._._. ;'._
//         _.-'`; | \  -  / | ;'-.
//       .' :  /  |  |   |  |  \  '.
//      /   : /__ \  \___/  / __\ : `.
//     /    |   /  '._/_\_.'  \   :   `\
//    /     .  `---;"""""'-----`  .     \
//   /      |      |()    ()      |      \
//  /      /|      |              |\      \
// /      / |      |()    ()      | \      \
// |         |
// \     \  | ][     |   |    ][  |  /     /
//  \     \ ;=""====='"""'====""==; /     /
//   |/`\  \/      |()    ()      \/  /`\|
//    |_/.-';      |              |`-.\_|
//      /   |      ;              :   \
//      |__.|      |              |.__|
//          ;      |              |
//          |      :              ;
//          |      :              |
//          ;      |              |
//          ;      |              ;
//          |      :              |
//          |      |              ;
//          |      |              ;
//          '-._   ;           _.-'
//              `;"--.....--";`
//               |    | |    |
//               |    | |    |
//               |    | |    |
//               T----T T----T
//          _..._L____J L____J _..._
//        .` "-. `%   | |    %` .-" `.
//       /      \    .: :.     /      \
//       '-..___|_..=:` `-:=.._|___..-'
// )"""";

    // std::cout << inspector_gadget << "\n\n";
    std::cout << "You are a secret agent breaking into a level " << LevelDifficulty << " secure server room\n";
    std::cout << "You need to enter the correct codes to continue...\n\n";
};


bool PlayGame(int LevelDifficulty){

    srand(time(NULL));

    //Briefing to the user on the terminal
    PrintIntroduction(LevelDifficulty);

    //Declare 3 number code
    const int CodeA = (rand() % LevelDifficulty) + LevelDifficulty;
    const int CodeB = (rand() % LevelDifficulty) + LevelDifficulty;
    const int CodeC = (rand() % LevelDifficulty) + LevelDifficulty;

    //Mathematical sum and product of the 3 number code for clues
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //Print the clues to terminal
    std::cout << "+ There are 3 numbers in the code\n";
    std::cout << "+ The codes add up to: " << CodeSum << "\n";
    std::cout << "+ The codes multiply to make: " <<  CodeProduct << "\n";

    //Take in the users input
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    //Sum and product of user submitted input
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Check if the player has guessed correctly
    if(GuessSum == CodeSum && GuessProduct == CodeProduct){
        std::cout << "\nSuccess! On to level " << ++LevelDifficulty << "!\n\n";
        return true;
    }
    else{
        std::cout << "\nOh no! You failed!\nTry again at level " << LevelDifficulty << "\n";
        return false;
    }
}

int main ()
{
    int LevelDifficulty = 1;
    const int MaxLevel = 10;

    while(LevelDifficulty <= MaxLevel){
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete){
            //Increase the level difficulty.
            LevelDifficulty++;
        }
        
    }

    std::cout << "\n\nYou have managed to hack the server! Congratulations!\n\n";

    return 0;
}