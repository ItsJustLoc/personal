# Python Comments

Comments can be used to explain Python code.
Comments can be used to make the code more readable. 
Comments can be used to prevent execution when testing code.

# Creating a Comment
Comment stats with a #, and Python will ignore them: 

#This is a comment
print("Hello, World!")

Comments can be placed at the end of a line, and Python will ignore the rest of the line:

print("Hello, World!") #This is a Comment

A comment does not have to be text that explains the code, it can alos be used to prevent Python from executing code:

#print("Hello, World!")
print("Cheers, Mate!")

__________________________________________________________________________________________________________________________________________________

# Multi Line Comments

Python does not really have a syntax for multi line comments.

To add a multiline comment you could insera # for each line:

#This is a comment
#written in
#more than just one line
print("Hello, World!")

Or, not quite as intended, you can use a multiline string. 

Since Python will ignore string iterals that are not assigned to a variable, you can add a multiline string (triple quotes) in your code, and place your comment inside it:

"""

This is a comment
written in
more than just one line
"""

print("Hello, World!")

As long as the string is not assigned to a variable, Python will read the code, but then ignore it, and you have made a multiline comment.