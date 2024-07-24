# takes students score as input and determine corosponding grade
#  >= 90 : A
#  >= 80 : B
#  >= 70 : C
#  >= 60 : D
#  < 60  : E

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

# while loop to calculate sum of first n integers
n = int(input("Sum of first n integers: "))
o = 1
sum = 0

while o <= n:
    sum += o
    o += 1

print(sum)

# Table of a number

tabl = int(input("Table for: "))

for i in range(1,11):
    print(i, "*", tabl, " = ", i*tabl)

# right angled triangle made of *
p = int(input("Pyramid upto: "))

for i in range(1, p+1):
   print("*" * i)

# number guessing game that provides feedback on how larger or smaller the number is, and game quits on entering 0
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