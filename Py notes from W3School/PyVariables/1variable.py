# Variables

Variable are containers for storing data values. 

#Creating Variables

Python has no command for declaring a variable.

A variable is created the moment you first assign a value to it.

x = 5
y = "John"
print(x)
print(y)

Variables do not need to be declared with any paricular type, and can even change type after they have been set. 

x = 4       # x is of type int
x = "Sally" # x is now to type str
print(x)

__________________________________________________________________________________________________________________________________________________

# Type Casting

If you want to specift the data type of a variable, this can be done with casting.

x = str(3)      # x will be '3'
y = int(3)      # y will be 3
z = float(3)    # z will be 3.0

__________________________________________________________________________________________________________________________________________________

# Get the Type 

You can get the data type of a variable with the type() function. 

x = 5
y = "John"
print(type(x))
print(type(y))

__________________________________________________________________________________________________________________________________________________

# Single or Double Quotes?

String variables can be declared either by using single or double quotes:

x = "John"
# is the same as
x = 'John'

__________________________________________________________________________________________________________________________________________________

# Case-Sensitive

Variable names are case-sensitive

This will create two variable:

a = 4
A = "Sally"
#A will not overwrite a