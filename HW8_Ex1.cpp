// Author:        Bishesh Manandhar
// Course:        CS 1336.003
// Date:          11/11/2017
// Assignment:    Lecture Homework 8, Exercise 1
// Compiler:      Visual Studio C++ 2017

// Description:   This program will output a set of prime numbers, given some input from the user.

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Function prototype for function bool isPrime (int number)
bool isPrime(int number);

// Main function, in which we call bool isPrime (int number)
int main()
{
   int num,       // Used to hold user input for number between 1 - 100
      count,      // Used to count the number of number
      currNum;    // Used to see what the current num is

   // Opening the outfile Prime.txt
   ofstream outfile;
   outfile.open("Prime.txt");

   // Checking to see if the file opened correctly
   if (!outfile)
   {
      cout << "File open failure!" << endl;
   }

   // Getting input for num from user
   cout << "Enter a number between 1 and 100:   ";
   cin >> num;

   // Input validation loop for num
   while (num < 1 || num > 100)
   {
      cout << "Invalid number. Please enter a number between 1 and 100:   ";
      cin >> num;
   }

   // Printing out starting text
   outfile << "The first " << num << " primes:" << endl << endl;

   // Initializing count and currNum
   count = 0;
   currNum = 2;

   // Loop to print out the prime numbers
   while (count < num)
   {
      // Function call to see whether the number is prime or not
      if (isPrime(currNum))
      {
         outfile << setw(5) << currNum;
         count++;

         // Making sure that there are 10 numbers per line of output in the file
         if (count % 10 == 0)
         {
            outfile << endl;
         }
      }

      // Incrementing currNum
      currNum++;
   }

   // Closing the output file
   outfile.close();

   cout << endl;
   system("pause");
   return 0;
}     // End of function main()



/**************************************************************************
Function:   bool isPrime (int number)                                     *
Descr:      This function will be used to check whether a number is prime *
            or not. If the number is prime, then it will return true, but *
            if the number is not prime, it will return false. A loop will *
            be used to check whether the number is prime or not.          *
Input:      number - int data type                                        *  
Return:     True or false depending on whether the number is prime or not *
**************************************************************************/
bool isPrime (int number)
{
   int n = 2;
   
   // Checking to see if number is prime
   while (!(number % n == 0) && n <= number)
   {
      n = n + 1;
   }

   // If it is prime, return true. If not prime, return false.
   if (n != number)
   {
      return false;
   }
   else
   {
      return true;
   }
}       // End of function bool isPrime(int number)