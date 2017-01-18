//tutorial.cpp

//First things first: this is a comment. Anything following '//' is commented in C++ - meaning it's ignored.
/* 
For multi line commenting, you can use these two combinations of symbols.
*/

//these are commands to reference and copy other pieces of code in the world directly into this program,
//allowing pieces of that code to be referenced for our use. Very handy, as many, many other programmers 
//have already put a lot of work into making very simple functions that we'll use all the dang time.

#include <stdlib.h> //standard library header, for things like math related functions, random numbers, and dates.
#include <stdio.h>  //standard input/output header, for printing to and reading from the command line. 

/* Standard command line program - 'main' is the 'entry point function', or the code that runs first when 
** the program starts.
** It's also the first instance of a function definition you'll see in code.
** The format is like this: 
**                            int                           main              (                     )
** [variable return type - what the function gives back] [function name] ([variables the function takes in])
         {printf("Hello, world!");}
** {function body, which may include variable declarations, variable assignments, switching mechanisms, loops, and other function calls}
*/
int main()
{
  //first function call: notice, it's the name of the function and then parenthesis afterward to have a place to put some information.
  //The information, separated by commas, are referred to as 'arguments'; in this case, there's only one argument, and it's a 'string literal'
  // i.e., it's literally just text. This text is passed to the 'printf' function - which comes from stdio - which takes the string literal and
  // prints it to the command line where the program is running. 
  //Also, every line in code ends with a ';' in C++.
    printf("Hello, world!");
  
  //let's do something not boring, though:
  
  int x = 10; //declare a variable called 'x' that is of type 'int' (integer) and set that variable equal to 10;
  int y = 11; //declare a variable called 'y' ... do the same thing, except 11 instead of 10.
  
  if(x > y) //tell the program that 'if x is greater than y'... 
    //run whatever is in this block of code.  (between the {}, which always defines enclosed pieces of code)
    //To be clear: the above test is never true, because 10 will never be bigger than 11, so the first block of code never runs.
  {
    
    for(int i = 0; i < x; i++)
    {
      x = x * y;
    }
  }
  //however, we have an 'else' here - which runs if the first 'if' part is false. So, "if this, then this, or else do this"
  else
  {
    //since the above code doesn't get called, ever, I'll explain this portion here. 
    //this is a 'for loop' - it's a way of setting the program up to run the same commands many, many times until certain conditions are met.
    for(int j = 0;  //In this case, we create a variable called 'j' and set it to zero. 
        j < y;      //this is the conditional portion of the statement. here, we say 'run the loop while j is less than y'
        j++)        //and this portion tells the loop how to change the variable each time the loop is run. in this case, 
                    //'j++' is a shortcut way of saying 'j = j + 1;' - meaning that each time the loop runs the code below, 
                    //j gets incremented by one and we get closer to j being equal to y, the statement above becoming false,
                    //and the loop ending.
    {
      y = y * x;
    }
    //so, we can predict how many times this loop will run as we know all the variables involved. 'j' is 0, it adds one each time the loop 
    //runs, so the loop will only run until j = 11. And that means that it should run 11 times. (0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
    //so y should end up equalling "y * x * y", or 11 * 10 * 11, or 1210. x should stay the same, meaning it should be 10. 
  }
  //this function call will print out the two values (the %d tells the function in a special way that the variables we're giving it are integers)
  printf("x: %d, y: %d", x, y);
  
}