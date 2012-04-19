//Dean's WordNum Converter.
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string wordNum(int num);

main()
{
      cout << "Welcome to dean's Number - Word Conversion app.\n\nPlease enter a number:";
      int number;
      cin >> number;
      cout << "\n\n" << number << " is:\n";
      string wordNumber = wordNum(number);
      cout << wordNumber << ".\n\nHave a nice day.\n\n";
      
      //Create file
      ofstream TextFile;
      TextFile.open("Output.txt");
    
      for (int i = 0; i < wordNumber.length(); i++)
          TextFile.put(wordNumber[i]);
    
      //Close File
      TextFile.close();
      
      system("pause");      
      return 0;
}


string wordNum(int num)
{
//converts the passed integer into a string.

//just in case we need it later, back up num
const int origNum = num;

//Create strings that will represent the number
string sSign = "";
string sNumber = "";
string sHundred = "";
string sThousand = "";
string sMillion = "";
string sBillion = "";
//create an array w/ base numbers
string saNums[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
string saTens[8] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};


//if it's a neg, set a value for later use
if(num<0)
{
 num = 0-num; //  make absolute value
 sSign = "Negative ";
}
//num is hereby a positive

//if it's a basic number, return that
if(num==1000)
 return sSign + "One Thousand";

if(num==10000)
 return sSign + "Ten Thousand";

if(num==100000)
 return sSign + "One Hundred Thousand";

if(num==1000000)
 return sSign + "One Million";
 
if(num==10000000)
 return sSign + "Ten Million";
 
if(num==100000000)
 return sSign + "One Hundred Million";

if(num==1000000000)
 return sSign + "One Billion";

/*
//if it's out of range return that (impliment basic conversion here)
if (origNum>1000000000)
 return "More than One Billion!";

if (origNum<-1000000000)
 return "Less than Negative One Billion!";
*/

if (num > 1000000000)
{
    if (num < 1000000100)
       sBillion = "One Billion and ";
    else
       sBillion = "One Billion, ";
    num -= 1000000000;
}

//If it's between one and nine (inclusive), set it.
if(num>=0 && num<10)
 sNumber = saNums[num];

//if it's exactly one, two, or ninety nine million, return that.
for (int i = 1; i < 1001; i++)
{
    if (num == 1000000 * i)
    return sSign + wordNum(num/1000000) + " Million";
}

//if it's between one million and one hundred million (non inclusive),
//then set sThousand to be wordNum of the thousands, + " Thousand ". 
if (num > 1000000 && num < 1000000000)
 sMillion = wordNum(num/1000000) + " Million, ";

for (int i = 1; i < 1000001; i++)
{
    if (num >= 1000000 * i && num < (1000000 * i) + 100)
    sMillion = wordNum(num/1000000) + " Million and ";
}

//chop millions
if(num>=1000000)//if it's one million or more, 
   for(int i = 1; i<1000; i++) // for i = 1 thru 99
      if (num>=1000000*i && num < (1000000*i) + 1000000) //if it's between eg, 200000 & 300000
         num -= 1000000*i;//chop off the millions

//if it's between one thousand and one million (non inclusive),
//then set sThousand to be wordNum of the thousands, + " Thousand ". 
if (num > 1000 && num < 1000000)
 sThousand = wordNum(num/1000) + " Thousand, ";

//BUT if it's between one thousand, and one thousand, one hundred
//for example: one thousand and one, or one thousand and ninety nine
//then make it say " thousand and " instead of the old " Thousand, ".
//"One Thousand, One" sounds silly.
for (int i = 1; i < 1001; i++)
{
    if (num >= 1000 * i && num < (1000 * i) + 100)
    sThousand = wordNum(num/1000) + " Thousand and ";
}

//if it's exactly one, two, or ninety nine thousand, return that.
for (int i = 1; i < 1001; i++)
{
    if (num == 1000 * i)
    return sSign + wordNum(num/1000) + " Thousand";
}

//chop thoudsands
if(num>=100000)//if it's one hundred thousand or more, 
   for(int i = 1; i<10; i++) // for i = 1 thru 9
      if (num>=100000*i && num < (100000*i) + 100000) //if it's between eg, 200000 & 300000
         num -= 100000*i;//chop off the hundreds of thousands


if(num>=10000)//if it's ten thousand or more, 
  for(int i = 1; i<10; i++) // for i = 1 thru 9
    if (num>=10000*i && num < (10000*i) + 10000) //if it's between eg, 20000 & 30000
      num -= 10000*i;//chop off the tens of thousands

if(num>=1000)//if it's one thousand or more
  for(int i = 1; i<10; i++) // for i = 1 thru 9
    if (num>=1000*i && num < (1000*i) + 1000) //if it's between for eg, 2000 & 3000
      num -= 1000*i;//chop off the thousands.
//we have hereby finished with tesn of thousands, and thousadsn operations. 

//now work with the between one hundred and one thousand.
if(num>=100)
{
 for(int i=1; i<10; i++)
 {
  if(num>=(100*i) && num < ((100*i)+100))
  {
   if(num==(100*i))
   { 
    sHundred = saNums[i] + " Hundred";
    break;
   }//End if perfect equal
   else
   {
    num -= 100*i;
    sHundred = saNums[i] + " Hundred and ";
    break;
   }
  }//end if  exact hundred
 }//end loop

}

//fix if it's not a base number


if(num>=10)
{
 //if adding 'teen' to the end fixes it...
 if(num==16 || num==17 || num==19)
 {
  num-=10;
  sNumber = saNums[num] + "teen";
 }
 //Otherwise, things are a little more complex
 else
 {
  switch(num)
  {
   case 10:
    sNumber = "Ten";
    break;

   case 11:
    sNumber = "Eleven";
   break;

   case 12:
    sNumber = "Twelve";
    break;

   case 13:
    sNumber = "Thirteen";
    break;

   case 14:
    sNumber = "Fourteen";
    break;

   case 15:
    sNumber = "Fifteen";
    break;

   case 18:
    sNumber = "Eighteen";
    break;

   default:
    for(int i=2; i<10; i++)
    {
     if(num>=(10*i) && num < ((10*i)+10))
     {
      if(num==(10*i))
      { 
       i-=2;
       sNumber = saTens[i];
       break;
      }//End if perfect equal
      else
      {
       num -= 10*i;
       sNumber =  saTens[i-2] + " " + saNums[num];
       break;
      }
     }//end if between 20 and 100
    }//end loop
   break;
  }//end switch
 }//end ifelse
}//end if more than 10
else
{
 sNumber = saNums[num];
}

string sResult = sSign + sBillion + sMillion + sThousand + sHundred + sNumber;
if (sResult == "")
   return "ERROR";
else
   return sResult;
}//end wordNum fn
