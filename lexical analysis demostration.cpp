//Lexical analysis demonstration
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm>


int numberofdight = 0;
int keywords = 0;
int specials = 0;
int characters = 0;
int operater = 0;

std::vector<std::string> integer = {"1","2","3","4","5","6","7","8","9","0"};
std::vector<std::string> keyword = {"if","then","else","begin","end"};
std::vector<std::string> special = {"(",")","[","]",","};
std::vector<std::string> character = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u",
                            "v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V"
                            ,"W","X","Y","Z"};
std::vector<std::string> operators = {"+","-","*","/","="};
std::vector<std::string> allNumbers;
std::vector<std::string> allkeywords;
std::vector<std::string> allspecials;
std::vector<std::string> allcharas;
std::vector<std::string> alloperaters;

std::vector<std::string>::iterator it;


int main(int argc, char* argv[])
{
    std::ifstream ifs;

    if(argc!=2)
    {
        std::cout << "Please type main.exe and file name to run the program! Please Try Again" << std::endl;
    }

    ifs.open(argv[1], std::ifstream::in);  // open file
    if(!ifs.is_open())  // check file is open or not.
    {
        std::cout << "wrong file name! please open again!" << std::endl;
    }

    char line[80];
    char *point;
    while(ifs.getline(line,80))
    {
        point = strtok(line, "  ~`!@#$%^&*_{}:<>|?;");
        while(point!=NULL)
        {
            if(std::find(integer.begin(),integer.end(), point) != integer.end())
            {
                numberofdight++;
                allNumbers.push_back(point);
            }
            else if(std::find(keyword.begin(),keyword.end(),point) != keyword.end())
            {
                keywords++;
                allkeywords.push_back(point);
            }
            else if(std::find(special.begin(),special.end(),point) != special.end())
            {
                specials++;
                allspecials.push_back(point);
            }
            else if(std::find(character.begin(),character.end(),point) != character.end())
            {
                characters++;
                allcharas.push_back(point);
            }
            else if(std::find(operators.begin(),operators.end(),point) != operators.end())
            {
                operater++;
                alloperaters.push_back(point);
            }
            else
            {
                ;
            }
            point = strtok(NULL, "  ~`!@#$%^&*_{}:<>|?;");
        }
    }
    std::cout << "Class: " << "Digit" << ": " << numberofdight << std::endl;
        std::cout << "The Digit that are found in the file: ";
    for(int x = 0; x!= allNumbers.size(); x++)
    {
        std::cout << allNumbers[x] << " | ";
    }
    std::cout << std::endl << "Class: " << "Keyword" << ": " << keywords << std::endl;
    std::cout << "Keywords that are found in the file: ";
    for(int x = 0; x!= allkeywords.size(); x++)
    {
        std::cout << allkeywords[x] << " | ";
    }
    std::cout << std::endl << "Class: " << "Special" << ": " << specials << std::endl;
        std::cout << "Specials that are found in the file: ";
    for(int x = 0; x!= allspecials.size(); x++)
    {
        std::cout << allspecials[x] << " | ";
    }
    std::cout << std::endl << "Class: " << "Character" << ": " << characters << std::endl;
        std::cout << "Characters that are found in the file: ";
    for(int x = 0; x!= allcharas.size(); x++)
    {
        std::cout << allcharas[x] << " | ";
    }
    std::cout << std::endl << "Class: " << "Operator" << ": " << operater << std::endl;
        std::cout << "Operators that are found in the file: ";
    for(int x = 0; x!= alloperaters.size(); x++)
    {
        std::cout << alloperaters[x] << " | ";
    }
    ifs.close();
}
