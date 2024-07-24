# list iterations

l1 = [58, 69, 45, 47, 22, 69, 41, 69, 2, 10, 4, 3]
l2 = ["Max", "Charles", "Lando", "Fernando", "Kimi", "Sebastian", "Sergio", "Kush"]

l1.append(52)
print("appending 52")
print(l1)
l2.append("Daniel")
print("appending Daniel to l2")
print(l2)

li = [101, 520, 420, 782, 110, 324, 96]
print("\nAdding/Extending list l1")
l1.extend(li)
print(l1)
print("Adding/Extending list l2")
le = ["Niki", "Michael", "Yuki", "Nico"]
l2.extend(le)
print(l2)

l1.insert(4, 128)
print("\nInserting 128 at index 4")
print(l1)
print("Inserting Lewis at index 3")
l2.insert(3, "Lewis")
print(l2)

d = l1.pop()
print("\nRemoved last element ", d, " from l1")
print(l1)
j = l2.pop()
print("Removing last element ", j, " from l2")
print(l2)

l1.remove(420)
print("\nRemoving Element 420 from list l1")
print(l1)
print("Removing ",l2[8]," from l2")
l2.remove("Kush")
print(l2)

p = l1.index(520)
print("\n520 in list l1 at index ", p)
p2 = l2.index("Sebastian")
print(l2[p2], "is at index", p2)

l1.sort()
print("\nSorted l1: ")
print(l1)
l2.sort()
print("Sorted l2")
print(l2)

l1.reverse()
print("\nReversed l1: ")
print(l1)
l2.reverse()
print("Reverses s2: ")
print(l2)

lenl1 = len(l1)
print("\nLength of l1 is", lenl1)

lenl2 = len(l2)
print("Length of l2 is", lenl2)
