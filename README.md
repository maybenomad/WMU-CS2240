# CS2240 - Western Michigan University

Here, you may find the following:

* Assignment specifications
* Assignment test drivers
* Example code

And much, much more. You may also come across any wisdom that Dr. Trenary has chosen to impart digitally.


# CS 2240 Coding Standards

Every language you will ever use has an idiomatic coding style. Although there are sometimes disagreements on what this should be, in any given project a certain coding standard must be enforced in an attempt to unify the codebase. These coding standards are a subset of Google's C++ coding standards for open source projects and are very consistent with most modern C projects that you will find on the internet. I ask that you use them, as they will help you to develop nice, readable code in an otherwise nasty, unreadable language. 

## Header Files 
**#define Guard**
Each header file should have a proper #define guard. The format should be as follows: `__<PROJECT>_<FILE>_H__`

## Naming
**Type Names**
All user-defined types should start with a capital letter and have a capital letter for each new word, with no underscores: `SomeCoolStruct`, `SomeCoolerStructAndStuff`. 

**Variable Names**
Variables should be all lower-case with underscores separating words. `dumb_variable`, `other_dumb_variable`. 

**Function Names**
Function names should start with a capital letter and have a capital letter for each new word - no underscores. `HerpDerp()`, `DerpityHerpity()`. 

**Globals / Constants**
Globals should rarely be used - and if they are, they should represent some time of compile-time constant (such as the width and height of a window, etc). They should be named using all capitals, with underscores. `CAPS_ARE_COOL`, `NO_UR_MOM_IS_COOL`. 

## Comments
**Comment Style**
Choose either // or /* */ and stick with it. Do not use a mix of both. Most people use the // style, as this allows their block comments to be consistent with their inline ones. 

**File Comments**
Each file should start with a description of it's content as well as any licensing information you may wish to include (since this is a class, this generally will just include your name/class/hour boilerplate). 

**Struct Comments**
Every struct should have an accompanying comment describing what it is and how it should be used. 

**Function Comments**
Comments at the declaration of a function (usually in a header file) should describe the use of the function. Comments at the implementation should describe the function's operation. Do NOT just copy/paste the header comment into the implementation file or vice-versa. If a function is simplistic

**Variable Comments**
In general, the names of your variables should be descriptive enough that you do not need comments. But please note, this does NOT mean be ridiculously verbose. Almost any variable's usage should be able to be captured in two or three words. 

**Redundancy**
Most of all, DO NOT WRITE REDUNDANT COMMENTS. Code is meant for humans to read and to this end should be self-documenting. Comments are only meant for visual separation and for documenting dirty implementation details. Don't comment the closing bracket of your `for` loops, this is what indentation is for. Don't do:
`int x = 5; // Assigns 5 to x`.
Nice formatting and spacing goes a long way in making your code readable without comments. Strive for this. 

##Formatting
**Line Length**
Each line of text in your code should be at most 80 characters long. 

**Spaces vs. Tabs**
Use only spaces and indent 2 spaces at a time.
```c
//
// This function does absolutely nothing. 
//
int DumbFunc() 
{
  int foo = Bar();
  if (foo == 0) 
  {
    puts("Weeeeeeeee");
  }
  else 
  {
    puts("alaksdflkajsl");
  }
  return 1;
}
```

## Assignment Turn-in 
- You must include your code (derp)
- You must include a Makefile compatible with the GNU Make tool
- You must include a PDF file containing all of your code, preferably syntax highlighted
- The project you turn in should NOT have a pre-compiled executable
- You must zip/tar up your working project and send it to **trenarycs224@gmail.com**  

When I grade your projects, I will unzip/untar the folder you sent me, `cd` into it, and type `make`. If nothing happens
or if there is a program error that is clearly not my fault (segfault, bus error, etc), YOU WILL LOSE POINTS. This means
that you will be working on the command line with `gcc` and `make` even if you are used to working in an IDE. 

If I try to build your project and there are errors unrelated to your code, you will not lose points.  

Your assignment will be graded both on your coding style and the functionality of the program. After it is graded, you 
will recieve a marked up version of your PDF back via e-mail along with your score. 

##Final Words
Most of all - BE CONSISTENT. If you strongly disagree with some of the coding standards here, just choose your own and stick with it. The actual standards that you adhere to are not important, so long as you are consistent. You will not be marked down for not conforming to this document, but you WILL be marked down if I have to spend time reformatting your code just so I can read it. 
