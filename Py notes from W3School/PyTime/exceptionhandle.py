try:
    numerator = float(input("Enter a numebr to divide: "))
    denominator = float(input("Enter a number to divide by: "))
    result = numerator/denominator
except ZeroDivisionError as e:
    print(e)
    print("You can't divide by zero! idiot!")
except NameError as e:
    print(e)
    print("Please enter a number.")
except Exception as e:
    print(e)
    print("something went wrong")
else:
    print(result)
finally:
    print("This will always execute")