# CS 124 Project 2
Create a Queue class and explore big-Oh complexities!

For this project, you will write a C++ program that uses Stack and Queue data structures to store objects of varying data types.

## Requirements
It is recommended that you use the data and program from Project 1 as a starting point.

### Stack Class
The Stack class from lecture is included in the starter code for this project.

### Queue Class
Create a Queue class that uses the Node class (also included in the starter code) to create a functioning queue data structure.
* Your Queue should keep track of where the front and back Nodes are.
* Your Queue should be able to:
  * `enqueue` (push Objects onto its back),
  * `dequeue` (pop and return Objects off its front),
  * `search` (determine if an Object is in the Queue or not), and
  * `print` (list all of the items in the Queue object, ordered from front to back).
* Your Queue must be able to be used with any data type.
* Your Nodes must be stored in heap memory.
* Your program must not have any memory leaks.

### Main function
Create two Queue objects: one of integers and one of strings. Demonstrate that the Queue methods work correctly by calling methods on the integer and string Queues and printing out to the console when appropriate.

Perform the following operations:
* Create a third Queue object and a Stack object, both of the type you created in Project 1.
* Use a loop to print and enqueue the first 10 objects from your vector (from Project 1) onto the Queue.
* Use a second loop to dequeue the 10 objects off the Queue and push them onto the Stack.
* Use a third loop to pop the 10 objects off the Stack and print them.

What is the order of the objects before and after adding them to the Queue and Stack?When and why did it change?

### Design
Consider the following questions:
* Using the Node class, will the links point from the front to the back of the Queue or from the back to the front? Which way will make the push and pop methods more efficient?
* How will you make sure there are no memory leaks?
* How will you print the objects in the main function? Should you overload an operator?

### Test
How can you demonstrate in your code that your Queue class works correctly? How can you use the integer and string Queue objects to show this?

## Report
You must write a report about your project. Answer the following questions directly in this section of the README file:
* Information about your data set (you will be assigned a different grader for this project)
  * My dataset is made up of individual ATP tennis matches from 2022, up to the US open in September.  Each object contains fields for: 
    * a unique rowID
    * the tourney date
    * the tourney name
    * the number of minutes played in the match
    * the winner's: name, number of aces, number of 1st serves that were made in, the number of 1st serve points won, the number of break points saved, the number of break points faced.
    * the loser's: name, number of aces, number of 1st serves that were made in, the number of 1st serve points won, the number of break points saved, the number of break points faced
* The time complexities of each method in the Stack and Queue classes
  * Destructor: O(N).  In the worst case, the user didn't pop any of the objects from the stack, so the destructor has to go through the entire stack and pop off every one so there are no memory leaks.
  * push: O(1). No matter the size of the stack, to push an object to the top of the stack, you only have to reassign to top pointer to the new top item and link the new top to the previous top item. Increasing input size has no effect on this method. 
  * pop: O(1).  Similar to above, popping only consists of reassigning the top pointer to the next item in the stack and removing the previous top item from heap memory.  Doubling the size of the stack has no impact on this method because you can always access the top item through the top pointer. 
  * search: O(N).  In the worst case, the object being searched is not in the stack and the loop has to iterate through the entire stack.  Therefore, increasing the size of the stack will increase the amount of time needed to search the entire stack in the worst case.
  * print: O(N).  Print will always have to iterate through the entire stack in order to print every element, so as input size increases, so will the time needed to traverse the entire stack.
* Justify your use of pointers in the Queue (i.e. the direction of the arrows between the Nodes) as it relates to the complexity of the enqueue and dequeue methods
  * For my queue class I had the nodes being linked from the front-->rear direction.  Similar to the Stack class, I felt that since we are enqueuing items to the back of the queue and dequeuing items from the front of the queue, if we had the nodes going from the rear-->front, when we dequeue an object, the object that was next in the queue would be the front item, but it would be pointing to nothing.  In the direction that I chose, every time you dequeue an object, all you have to do is reassign the object to which the front object is pointing to be the new front object and deallocate the dequeued item.  Similarly, with enqueue, you are adding a new object by linking the previous rear item to the new item and then setting the new item to the rear pointer.  This way, you don't have any objects that are pointing to nothing.         
* An explanation of when and why the 10 objects in the main function changed their order
  * In the main function, I first created a queue of ATP Matches containing the first 10 objects of a vector of ATP Matches by enqueuing each object by index (rowIDs from 0-9).  Next, I created a stack of ATP Matches by dequeuing each item from the queue and pushing them to the stack.  Because dequeue removes items from the front, the order of pushing to the stack should be the same as enqueuing (0-9).  Next, I looped through the stack and popped each item.  Because stacks use LIFO (last in, first out), the first items to be removed from the stack are the last to be added.  Therefore, the order of the removing the objects from the stack should be (9-->0).  

**Note: Any code that was not authored by yourself or the instructor must be cited in your report. This includes the use of concepts not taught in lecture.**

## Submit

You must include your source files, your data file(s), CMakeLists.txt, and your updated README.md file that contains your report to your repository. Submit to Gradescope using the GitHub repository link, double-check that all the correct files are there, and wait for the autograder to provide feedback.

## Grading
The project is out of 60 points.

| Points Possible | Description of requirement |
|------------------- | ----------------------------- |
| 5 pts | Program compiles and runs. |
| 5 pts | Code style. Readable, naming style is consistent, comments where appropriate. |
| 20 pts | Queue class satisfies requirements. |
| 5 pts | You create at least two Queue objects of different types, as described above. |
| 5 pts | You test your code to demonstrate that everything works correctly. |
| 10 pts | You perform the operations with the Stack and the Queue as described above. |
| 10 pts | Report satisfies requirements, is easily readable, and is professional. |