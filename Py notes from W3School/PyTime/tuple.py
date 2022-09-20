student = ("Loc",21,"Male")

print(student.count("Loc"))
print(student.index("Male"))

for x in student:
    print(x)

if "Loc" in student:
    print("Loc is here")