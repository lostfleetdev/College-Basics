"""
1. Write a Python program that takes two input numbers from the user and performs basic
arithmetic operations: addition, subtraction, multiplication, division, and modulus. Display
the results of each operation.
"""
# a common function for all
def operations(num1, num2):
    addition = num1 + num2
    subtraction = num1 - num2
    multiplication = num1 * num2
    division = num1 / num2
    modulus = num1 % num2

    print(f"Addition: {num1} + {num2} = {addition}")
    print(f"Subtraction: {num1} - {num2} = {subtraction}")
    print(f"Multiplication: {num1} * {num2} = {multiplication}")
    print(f"Division: {num1} / {num2} = {division}")
    print(f"Modulus: {num1} % {num2} = {modulus}")


num1 = int(input("Enter the first number: "))
num2 = int(input("Enter the second number: "))
operations(num1, num2)


"""
2. Write a Python program that accepts two floating-point numbers from the user and
performs the same set of arithmetic operations: addition, subtraction, multiplication, division,
and modulus. Display the results with appropriate formatting.
"""
# utlizing above function
num3 = float(input("Enter the first number: "))
num4 = float(input("Enter the second number: "))
operations(num3, num4)



"""
3. Write a Python program that takes two input numbers from the user and demonstrates the
use of comparison operators: equal to, not equal to, greater than, less than, greater than or
equal to, and less than or equal to. Display the results of each comparison.
"""
# creating a similar function as above
def comparisons(num1, num2):
    equal_to = num1 == num2
    not_equal_to = num1 != num2
    greater_than = num1 > num2
    less_than = num1 < num2
    greater_than_or_equal_to = num1 >= num2
    less_than_or_equal_to = num1 <= num2

    # Display the results
    print(f"{num1} == {num2} : {equal_to}")
    print(f"{num1} != {num2} : {not_equal_to}")
    print(f"{num1} > {num2}  : {greater_than}")
    print(f"{num1} < {num2}  : {less_than}")
    print(f"{num1} >= {num2} : {greater_than_or_equal_to}")
    print(f"{num1} <= {num2} : {less_than_or_equal_to}")

num1 = float(input("Enter the first number: "))
num2 = float(input("Enter the second number: "))

comparisons(num1, num2)


"""
4. Write a Python program that takes three Boolean inputs from the user and demonstrates the
use of logical operators: and, or, and not. Display the results of each logical operation.
"""
#similar as above functions
def logical_operations(bool1, bool2, bool3):
    and_result = bool1 and bool2 and bool3
    or_result = bool1 or bool2 or bool3
    not_result_bool1 = not bool1
    not_result_bool2 = not bool2
    not_result_bool3 = not bool3

    print(f"({bool1} and {bool2} and {bool3}) : {and_result}")
    print(f"({bool1} or {bool2} or {bool3}) : {or_result}")
    print(f"not {bool1} : {not_result_bool1}")
    print(f"not {bool2} : {not_result_bool2}")
    print(f"not {bool3} : {not_result_bool3}")

# function to simplify function input from user
def input_boolean(user_input):
    if(user_input == 1):
        return True
    elif(user_input == 2):
        return False
    else:
        return 1


print("Enter 1 for True and 2 for false")
bool1 = input_boolean(input("Enter the first Boolean value : "))
bool2 = input_boolean(input("Enter the second Boolean value: "))
bool3 = input_boolean(input("Enter the third Boolean value : "))

logical_operations(bool1, bool2, bool3)




"""
5. Write a Python program that takes a list and an element from the user and demonstrates the
use of membership operators (in, not in) and identity operators (is, is not). Display the results
of this operation
"""
def identity_operations(user_list, element):
    in_list = element in user_list
    not_in_list = element not in user_list

    is_same_object = element is user_list
    is_not_same_object = element is not user_list

    print(f"{element} in {user_list} : {in_list}")
    print(f"{element} not in {user_list} : {not_in_list}")

    print(f"{element} is {user_list} : {is_same_object}")
    print(f"{element} is not {user_list} : {is_not_same_object}")


user_input_list = input("Enter a list of elements separated by commas: ")
user_list = user_input_list.split(",")

element = input("Enter an element to check: ")

identity_operations(user_list, element)
