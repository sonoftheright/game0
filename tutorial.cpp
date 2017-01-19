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

/* Standard command line program - 'main' is the 'entry point function', or the code that runs first when the program starts.
** It's also the first instance of a function definition you'll see in code. The format is like this: 
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
    printf("Hello, world!\n");
  //that '\n' is a special character: '\' is the 'escape character' telling the printf it's special, and the 'n' just inserts a carriage return
  
  //let's do something not boring, though:
  
  int x = 10; //declare a variable called 'x' that is of type 'int' (integer) and set that variable equal to 10;
  int y = 11; //declare a variable called 'y' ... do the same thing, except 11 instead of 10.
  
  if(x > y) //tell the program that 'if x is greater than y'... 
    //run whatever is in this block of code.  (between the {}, which always defines enclosed pieces of code)
    //To be clear: the above test is never true, because 10 will never be bigger than 11, so the first block of code never runs.
  {
    for(int i = 0; i < y; i++)
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
        j < x;      //this is the conditional portion of the statement. here, we say 'run the loop while j is less than x'
        j++)        //and this portion tells the loop how to change the variable each time the loop is run. in this case, 
                    //'j++' is a shortcut way of saying 'j = j + 1;' - meaning that each time the loop runs the code below, 
                    //j gets incremented by one and we get closer to j being equal to y, the statement above becoming false,
                    //and the loop ending.
    {
      //the equals symbol is interesting in C++ - you'll see here that we're actually using the variable we want to change in order to change
      //the variable - so the program will read the original value of the variable, and then use it to calculate what the new value should be.
      //Technically, in the underlying assembly, something different is happening - probably storing the value elsewhere in memory, and then 
      //using that to assign from after changing it... but Adam would know more about that than I would, I still need to learn assembly.
      y = y * x;
      printf("j: %d, y: %d\n", j, y);
    }
    //so, we can predict how many times this loop will run as we know all the variables involved. 'j' is 0, it adds one each time the loop 
    //runs, so the loop will only run until j = 9 and then stop. That means that it should run 10 times. (0, 1, 2, 3, 4, 5, 6, 7, 8, 9)
    //so y should end up equalling "y * x^x", or 11 * 10 ^ 10, or 11,000,000,000. x should stay the same, meaning it should be 10. 
  }
  //this function call will print out the two values (the %d tells the function in a special way that the variables we're giving it are integers)
  //so first we pass the text with the symbols to denote where the numbers go, then we pass the two variables we want to print in those places.
  //all separated by commas.
  printf("x: %d, y: %d", x, y);
  
  /*
  if we run this though, something really weird happens:
  j: 0, y: 110
  j: 1, y: 1100
  j: 2, y: 11000
  j: 3, y: 110000
  j: 4, y: 1100000
  j: 5, y: 11000000
  j: 6, y: 110000000
  j: 7, y: 1100000000
  j: 8, y: -1884901888
  j: 9, y: -1669149696
  x: 10, y: -1669149696
  
  The 'y' variable seems to be going a bit nuts towards the end of the loop...
  While the expected value was being reached for, y never really made it there. This is because of a little issue with how variables work:
  
  the declaration for the type of the variable - in this case, 'int', or integer - is a way of telling the program that you will need a certain amount of 
  memory temporarily in order to store a limited amount of information. In this case, the 'int' variable type is only allowed to store a value of 
  a certain size, of which there is a maximum. In this case, the max size is 2 ^ 32 bits wide, or 4,294,967,296 possible values split in two to allow for 
  negative values. So our variables in this case, because we've declared them as 'int's can only hold values between –2,147,483,647 and 2,147,483,647. When
  the value of the variable gets too big, it simply wraps around until it's in the acceptable range (as you can see above).
  */
}