"""
1. Write a Python program that takes a student's score as input and uses conditional
statements to determine the corresponding grade. The grading system is as follows:
 Score >= 90: Grade A
 Score >= 80: Grade B
 Score >= 70: Grade C
 Score >= 60: Grade D
 Score < 60: Grade F
"""

score = int(input("Enter your score: "))

if score >= 90 and score < 100:
  print("Grade A")
if score < 90 and score >= 80:
  print("Grade B")
if score < 80 and score >= 70:
  print("Grade C")
if score < 70 and score >= 60:
  print("Grade C")
if score < 60 and score >= 0:
  print("Grade F")


"""
2. Write a Python program that takes a positive integer n as input and uses a while loop to
calculate and print the sum of the first n natural numbers.
"""
n = int(input("Sum of first n integers: "))
o = 1
sum = 0

while o <= n:
    sum += o
    o += 1

print(sum)


"""
3. Write a Python program that takes an integer n as input and uses a for loop to generate and
print the multiplication table for that number up to 10.
"""

tabl = int(input("Table for: "))

for i in range(1,11):
    print(i, "*", tabl, " = ", i*tabl)


"""
4. Write a Python program that takes a positive integer n as input and uses nested loops to
print a right-angled triangle pattern of n rows using asterisks (*).
"""
p = int(input("Pyramid upto: "))

for i in range(1, p+1):
   for j in range(i):
      print("*", end='')

"""
5. Write a Python program that implements a simple number guessing game. The program
should generate a random number between 1 and 100 and allow the user to guess the number.
The program should provide feedback if the guess is too high or too low. The game should
continue until the user guesses the correct number or decides to quit by entering 0. Use break
and continue statements to control the flow of the game.
"""
import random

print("A number guessing game:")

ran = random.randint(1, 100)
guess = 101

print(ran)

while guess != ran:
    guess = int(input("Enter your guess: "))

    if guess < ran:
        print("guess is smaller")
    if guess > ran:
       print("guess is Larger")
    if guess == 0:
       break
     

if guess == ran:
  print("You Won")
if guess == 0:
  print("Better luck next time")