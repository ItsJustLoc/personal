utensils = {"fork","spoon","knife", "knife", "knife", "spoon"}
dishes = {"bowl","plate","cup","knife"}

"""utensils.add("napkin")
utensils.remove("fork")
utensils.clear()"""

#utensils.update(dishes)
#dishes.update(utensils)
#dinner_table = utensils.union(dishes)


#for x in dishes:
    #print(x)

print(utensils.difference(dishes))
print(dishes.difference(utensils))
print(utensils.intersection(dishes))