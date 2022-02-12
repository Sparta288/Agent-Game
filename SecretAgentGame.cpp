
# include <iostream>
# include <string>
# include <fstream>
# include <ctime>
using namespace std;

void PrintIntroduction(int Difficulty)
    {
    // Print welcome messages to the terminal
    std:: cout << "\nWelcome to the Secret Agent Game!";
    std:: cout << std::endl;
    std:: cout << "\nYou are a secret agent breaking into a level " << Difficulty;
    std:: cout << " secure server room...\nEnter the correct code to continue: \n";
    }

void printASCII(string fileName)
{
    string line = " ";
    ifstream inFile;
    inFile.open("image.txt");
    if (inFile.is_open())
    {
        while (getline(inFile,line))
        {
            cout << line << endl;
        }
    }
    else
    {
        cout << "File failed to load. " << endl;
        cout << "No image displayed. " << endl;
    }
    inFile.close();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
}


bool PlayGame(int Difficulty)
{

    PrintIntroduction(Difficulty);

    // Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //Print sum and product of the numbers
    std:: cout << "There are 3 numbers in the code" << std::endl; 
    std:: cout << "The codes add-up to: " << CodeSum << std::endl;
    std:: cout << "The codes multiply to give: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;
    
    std::cout << "Guess 3 numbers: ";

    // Player Guesses input stored
    std:: cin >> GuessA >> GuessB >> GuessC;


    // Players Guesses Sum and Product 
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    
    // Check if player guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** Well done Agent! You extracted a file! Keep going! ***\n" << std::endl;
        return true;
    }
    else
    {
        std::cout << "\n*** You entered the wrong code. Careful Agent! Try again! ***\n" << std::endl;
        return false;
    }
}



int main()

{
    srand(time(NULL)); // create new random sequence based on time of day
    int LevelDifficulty = 1;
    const int MaxLevel = 5;
    
    string fileName = "image.txt"; //ASCII image 'Agent Code'
    printASCII(fileName);
    
    while (LevelDifficulty <= MaxLevel) // Loop the game until all levels are completed
    {
        
       
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //Clears any errors
        std::cin.ignore(); //Discards the buffer

        if (bLevelComplete) 
        {
            ++LevelDifficulty; 
        }
        
        
    }
    
    std::cout << "\n*** Great work agent! You hacked all the files! Now exfil the area! ***\n";
    return 0;
}





