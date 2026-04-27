# CS210-Portfolio
C++ item frequency tracking program built for CS 210 at SNHU

# CS 210 - Corner Grocer Item Tracking Program

## Project Summary
This project is a C++ item tracking program built for the Corner Grocer. 
The store generates a text file throughout the day listing every item 
purchased in order. The program reads that file and tracks how many times 
each item was purchased. It gives the user a menu to search for a specific 
item's frequency, view a full list of all items and their counts, or view 
a text-based histogram. A backup data file is also created automatically 
when the program starts.

## What I Did Particularly Well
I think I organized the code well by separating the class logic from the 
main menu. The GroceryTracker class handles all the data and file work, 
while main.cpp only handles what the user sees. This made the code easier 
to read and debug. I also made sure every function had comments explaining 
what it does so someone reading the code for the first time could follow along.

## Where I Could Enhance the Code
A few improvements could make this program stronger. First, the item search 
is case-sensitive right now, so typing "potatoes" would not find "Potatoes." 
Adding case-insensitive search would make it more user-friendly. Second, 
the program currently uses a sample input file. In a real setting it could 
be improved to let the user specify which file to load. Third, adding more 
detailed error messages would help users understand what went wrong if 
something does not work.

## Most Challenging Part
The most challenging part was understanding how std::map works and how to 
loop through it using an iterator. The syntax for accessing i->first and 
i->second was unfamiliar at first. I worked through it by reading the course 
materials on maps in zyBooks and testing small pieces of code on their own 
before adding them to the full program. Breaking the problem into smaller 
pieces made it much more manageable.

## Transferable Skills
Working with file input and output, using classes with public and private 
sections, and handling user input validation are all skills I will use in 
future projects. Understanding how to use a data structure like a map to 
count and organize data is also something that applies to many different 
types of programs beyond this one.

## Maintainability, Readability, and Adaptability
I made the program maintainable by storing file names as named string 
variables so they are easy to update in one place. I made it readable by 
adding comments above every function and key line of code. I made it 
adaptable by keeping the class logic separate from the menu logic, so if 
the Corner Grocer wanted a new feature added it could be done by adding 
a new function to the class without changing the rest of the program.
