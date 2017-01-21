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
  printf("x: %d, y: %d\n", x, y);
  
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
  
  Some other variable types and their max/min values: 
  
  signed char, char:  -128 - 128 - chars are read as letters according to their integer code/ASCII assocation
  unsigned char:      0 - 255 - 'unsigned' means that it's only ever positive or 0
  short:              -32,768 - 32,767
  unsigned short:     0 - 65,535
  int:                –2,147,483,647 - 2,147,483,647
  unsigned int:       0 - 4,294,967,295
  long:               –2,147,483,647 - 2147483647
  unsigned long:      0 - 4,294,967,295
  
  Other variable types include:
  - float (for numbers with decimals)
  - double (for numbers with a very large amount of decimal places)
  - bool (short for 'boolean' - meaning a value that is either true (1) or false (0))
  
  Programmers super concerned with efficiency will always give a variable a very targeted type based on the requirements for its value. 
  This allows the programmer to optimize for extremely tight memory management (say, if he or she were to create very, very large numbers of similar variables
  and package them together, there are ways of making the CPU very, very fast at accessing that information by controlling size). 
  */
  
  
  //OK - that covers: functions, basic variables and types, and for loops. Time for more concepts.
  
  //Here's a while loop. Rather than having a bunch of conditions and ways those conditions are modified, it relies on a single statement. 
  //As long as that statement is true, it will run the commands in the brackets for forever, You have to be careful with these, because they're conducive 
  //to creating infinite loops. Fun!
  while(x > 0)
  {
    x--;
    printf("x: %d\n", x);
  }
  /*
    There are a few variable types not mentioned above because they're a bit more complex than a simple single value. An enum is one such example.
    Enums are collections of names that C++ will turn into straight up integers. This allows us to use them and pass them around in a format that we
    can read and is meaningful to us, but, when it comes to the actual value, is very simple.
  */
  enum NUMBERS
  {
    ONE, TWO, THREE, FOUR, FIVE
  };
  enum NUMBERS number = ONE;
  
  /*
    Enums are most often used as a control value for another flow control mechanism: switches. 
    
    A switch will take a variable, and, based on its integer value, switch into the appropriate case and run the code block for that case, skipping 
    all the rest. If the value isn't found, it runs the default.
    
    In this case, since 'number' will always equal 'ONE', whatever 'ONE's underlying value is will be called according to the appropriate case.In
    (The below is a bit deceptive; I could just as easily have written "case(ONE)... case(TWO)... etc., but this is more interesting and demonstrative).
  */
  switch(number)
  {
      case(0):
      {
        printf("switch 0\n");
      } break;
      case(1):
      {
        printf("switch 1\n");
      } break;
      default:
      {
        printf("switch default\n");
      }
  }
  
  /*
   And now, time for one of the most important of C++ object types: the struct!
   Many people obsessed with 'Object Oriented Programming' will probably disagree with this, but I subscribe to the 'procedural programming' camp, so... whatevs.
   Anyway: a struct is very simple. It is a way for you to create a new variable type that packs together several basic variable types into a single variable.Anyway
   For example:
  */
  
  //declaring a struct and what this kind of struct should be able to hold inside it.
  struct CharacterProperties 
  {
    int AGE;
    int SPEED; 
    float X_POSITION;
    float Y_POSITION;
    char *NAME;
  };
  
  //declaring a new variable of our struct type that will hold its own values according to the struct definition above.
  struct CharacterProperties PlayerOne;
  
  //assigning values to the parts of the struct using '.'to access the internal variables.
  PlayerOne.AGE         = 32;
  PlayerOne.SPEED       = 2;
  PlayerOne.X_POSITION  = 0.0f; //this is float notation, by the way; you just have to put an 'f' at the end of the decimal.
  PlayerOne.Y_POSITION  = 0.0f;
  char *playerName = "PlayerNameTest";
  
  PlayerOne.NAME = playerName;
  
  printf("Player One's Name is %s.\n", PlayerOne.NAME);
  
  /*    
    Most unfortunately, the above is going to force me to start addressing another topic, and probably the hardest topic in C/C++ programming (and the reason why
    C/C++ programming is simply better than programming in any other language just about). That topic is...C
    
    POINTERS *dun dun dun* The bane of many a learning programmer. 
    
    See that little asterisk next to the 'char' variable above? That's a special character that changes the type of the variable from a simple char to a 
    reference to a char in memory. As you may not have any idea what that means, let me break it down in pictures.reference
    
    char x = 12; -> this is pretty easy. we're creating a variable, and then assigning it to a value of 12. We saw this work above. But what the computer does
    with this is a bit different than you might imagine. When the computer sees 'char x', it will assign a portion of memory according to the exact maximum of 
    that variable type's size, so that it never has to change the size of the memory apportioned for that variable (it just needs to change the value of the 
    memory). A lot of times, this means that a variable representing the address of a specific variable in memory - that is, an address that represents its 
    location - is smaller than the size of the variable itself in memory. 
    
    So, we declare a 'char *' to store the reference to or address of a char rather than the value of the char itself. This is a lot more efficient, because 
    the address is usually smaller.
    
    There's an underlying process going on here. You might be wondering why the char (or char *) is singular if it references a longer string of characters.
    Well... that brings up another variable type: the array!
    
    An array looks like this:
    */
    int integers[16]; 
  /*
    This does the same thing as 'int integer;' but it creates them all in a row in memory and gives them to a single variable for access. Each 'element' in 
    the array can be accessed individually like this:
    */
    integers[0] = 22;
  /*
    The number in brackets represents the numeric designation for the element you want, and the first element always starts with 0. So, the above element
    will always be addressed 0-15.
    
    In C/C++ though, pointers to arrays and pointers to individual variables within arrays aren't really any different - they both refer to a chunk of 
    memory, so you can use pointers to move through arrays and manipulate their contents using 'pointer math'. Since an array of 'ints' is just several
    ints stacked on each other in memory, you can use the pointer - which refers to the beginning of the array - and add by the width of one 'int' to go 
    through and read the memory at addresses within the scope of the array in memory. 
  */
  int * p_ints = &integers[0];
  p_ints++;
  *p_ints = 21;
  
  printf("element 0: %d, element 1: %d\n", integers[0], integers[1]);
  
  /*
  
  
  */
  }