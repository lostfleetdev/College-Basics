"""
1. Write a Python program that takes two numbers as input from the user and prints their
sum.
"""
n1 = int(input("Enter a Number :"))
n2 = int(input("Enter another Number :"))

print(f"Sum: {n1} + {n2} = ", n1+n2)
"""
2. Write a Python program that asks the user for their name and then prints a greeting
message that says "Hello, [name]!".
"""
name = input("Whats Your name? : ")
print(f"Hello, {name}")


"""
3. Write a Python program that calculates the area of a rectangle. The program should ask the
user to input the length and width of the rectangle and then display the calculated area.
"""
b = float(input("Whats breadth?: "))
l = float(input("Whats length ?: "))

print(f"Area of rectangle is ", b*l)

"""
4. Write a Python program that asks the user for their current age and then calculates and
prints their age in five years.
"""
a = int(input("Whats your age?: "))
print(f"Your age in 5 years would be", a+5)

"""
5. Write a Python program that calculates the simple interest on a principal amount. The
program should ask the user to input the principal amount, the rate of interest, and the time
period (in years). It should then display the calculated simple interest.
"""
def calculate_simple_interest(principal, rate, time):
    simple_interest = (principal * rate * time) / 100
    return simple_interest

principal = float(input("Enter the principal amount: "))
rate = float(input("Enter the rate of interest (in %): "))
time = float(input("Enter the time period (in years): "))

simple_interest = calculate_simple_interest(principal, rate, time)

print(f"The calculated simple interest is: {simple_interest}")
