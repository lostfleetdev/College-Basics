# Arithmatic Operators
'''
print("Arithmetic Operations on Two Integers: ")
a = int(input("Enter a Number: "))
b = int(input("Enter another Number: "))
print("{a} + {b} = ", a+b) #Addithon
print("{a} - {b} = ", a-b) #Subtraction
print("{a} * {b} = ", a*b) #multiplication
print("{a} / {b} = ", a/b) #divison
print("{a} % {b} = ", a%b) #modulus

print("=====================================================================\n")

print("Arithmetic Operations on Two Floating point numbers: ")
x = float(input("Enter a Number: "))
y = float(input("Enter another Number: "))
print("{x} + {y} = ", x+y) #Addithon
print("{x} - {y} = ", x-y) #Subtraction
print("{x} * {y} = ", x*y) #multiplication
print("{x} / {y} = ", x/y) #divison
print("{x} % {y} = ", x%y) #modulus

print("=====================================================================\n")

# Comparison Operators
print("Comparing Two Integers:")
p = int(input("Enter an Integer: "))
q = int(input("Enter another Integer: "))

if(p == q):
    print(p," is equal to ",q)
else:
    if(p>q):
        print(p," is not equal to ",q," but\n",p," > ",q)
    else:
        print(p," is not equal to ",q," but\n",p," < ",q)

print("=====================================================================\n")

#boolean comparison
print("Boolean Comparison using 3 boolean variables: (Enter Only True OR False) ")
f = bool(input("Variable F: "))
g = bool(input("Variable g: "))
h = bool(input("Variable h: "))

print("f:",f ," AND g:",g," is ",f and g)
print("g:",g," OR h:",h," is ",g or h)
print("NOT h:",h," is ", not h)

print("=====================================================================\n")

'''
lst = []
 
# number of elements as input
n = int(input("Enter number of elements : "))

for i in range(0, n):
    ele = input()
    lst.append(ele)  
 
print("List = ",lst)

find = input("What Element would you like to find? : ")

