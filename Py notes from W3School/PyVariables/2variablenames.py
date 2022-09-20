# Variable Names

from xml.dom.minidom import CharacterData


Variable Names 

A variable can have a short name (like x and y) or a more descriptive name(age, carname, total_volume).callable

    A variable name mmust start with a letter or underscore Character. 
    A variable name cannot start with a number. 
    A variable name can only contain alpha-numeric characters and underscores (A-z. 0-9, _)
    Variable names are case-sensitive (age, Age and ANGE are three different variables)

# Legal variable names

myvar = "John"
my_var = "John"
_my_var = "John"
myVar = "John"
MYVAR = "John"
myvar2 = "John"

# Illegal variable names:

2myvar = "John"
my-var = "John"
my var = "John"

__________________________________________________________________________________________________________________________________________________

#Multi Words Variable Names

Variable names with more than one word can be difficult to read. 

There are several techniques you can use to make them more readable:

#Camel Case

Each word, except the first, starts with a capital letter:

myVariableName = "John"

# Pascal Case

Each word starts with a capital letter:

MyVariableName = "John"

# Snake Case

Each word is separated by an underscore character:

my_variable_name = "John"