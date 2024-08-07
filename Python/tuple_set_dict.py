#tuple
t = (1,456,76,123,1,1,54,784,34,1)

print("tuple t = ", t)
print("Number of times 1 is repeated in t", t.count(1))
print("Index of 54 is", t.index(54))
print("Minimum value in t",min(t))
print("Maximum value in t",max(t))
sort_t = sorted(t)
print("sorted t: ", sort_t)


print("\n")
#set

s = {45,54,8,69,23,1,14,6,2,31,420,1000,7}
s1 = {24,458,128,147,689,327,178}
s2 = {147,6,945,45,54,8,698,327,178}

print("set s: ",s, "\nset s1: ", s1,"\nset s2: ")

print("Popping an element in set s: ", s.pop(), "\nset :", s)
s.remove(8)
print("removing 8 from s, set :", s)
s.discard(45)
print("Discarded 45 from sert :", s)
s.update(s1)
print("Updated set with set s1: ",s)
print("Intersection set: ", s.intersection(s2))
print("Difference in set s and s2: ", s.difference(s2))
s_copy = s1.copy() 
print("Copied set from set s i.e s_copy: ",s_copy)

print("\n")

#dictionary

dict = {99:"Jethalal", 
        98:"Champaklal", 
        97:"Gada",
        96:"Electronics"}

dict1 = {10:"G",
         11:"H",
         12:"Raisoni",
         13:"college",
         14:"of",
         15:"Engineering"}

d_k = [4,8,9,6,7,2]
d_v = ["sfd","sdf","dsfsf","sdfsf","asd","qwe"]

print("Ductionary: ", dict)
print("value at key 99: ", dict.get(99))
print("Popitem from dict1: ", dict1.popitem(), " Dict1: ", dict1)
print("popped key 15 with value: ",dict1.pop(11))
print("all items in dict: ", dict.items())