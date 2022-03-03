#include "raylib.h"
#include <iostream>
#include <vector>
#include <string>


const float SCREEN_W = 600;
const float SCREEN_H = 600;

class Word{
public:
   std::string wordChars; //the literal word in class "Word"

   char iterateString(Word iteratedWord, int currentIndex){ //return the char at the next index- needed for text output
      currentIndex ++;
      return(iteratedWord.wordChars[currentIndex]);
   }
   bool typedChar(Word iterateWord, int &currentIndex)//checks if current index char was typed
   {
      if(GetKeyPressed() == iterateWord.wordChars[currentIndex])
      {
         return true;
         //iterateString(iterateWord, currentIndex)
         currentIndex ++;
      }
      return false;
   }

   void typeWord(Word iterateWord) //this is messy lol - Check to see if you type the whole word
   {
      int index = 0;
      int currentWordLength;
      currentWordLength = iterateWord.wordChars.length();
      iterateWord.wordChars[index];
      while(index < currentWordLength-1)
      {
         if(typedChar(iterateWord,index) == true)
         {
            index ++;
         }
         std::cout << "there was a miss input" << std::endl;
      }
   }
   void iterateParagraph(std::vector<Word> paragraph)
   {
      for(const auto& p : paragraph)
      {
         typeWord(p.wordChars);
      }
   }
};
