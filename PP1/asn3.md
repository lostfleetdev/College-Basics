## 1. Write a Python program that takes a student's score as input and uses conditional statements to determine the corresponding grade. The grading system is as follows:
Score >= 90: Grade A  
Score >= 80: Grade B  
Score >= 70: Grade C  
Score >= 60: Grade D  
Score < 60: Grade F

```python
score = int(input("Enter your score: "))

if score >= 90 and score < 100:
    print("Grade A")
if score < 90 and score >= 80:
    print("Grade B")
if score < 80 and score >= 70:
    print("Grade C")
if score < 70 and score >= 60:
    print("Grade D")
if score < 60 and score >= 0:
    print("Grade F")
```
### Output

```bash
Enter your score: 85
Grade B
```

---

## 2. Write a Python program that takes a positive integer n as input and uses a while loop to calculate and print the sum of the first n natural numbers.

```python
n = int(input("Sum of first n integers: "))
o = 1
sum = 0

while o <= n:
    sum += o
    o += 1

print(sum)
```
### Output

```bash
Sum of first n integers: 5
15
```

---

## 3. Write a Python program that takes an integer n as input and uses a for loop to generate and print the multiplication table for that number up to 10.

```python
tabl = int(input("Table for: "))

for i in range(1, 11):
    print(i, "*", tabl, " = ", i * tabl)
```
### Output

```bash
Table for: 7
1 * 7  =  7
2 * 7  =  14
3 * 7  =  21 
4 * 7  =  28
5 * 7  =  35
6 * 7  =  42
7 * 7  =  49
8 * 7  =  56
9 * 7  =  63
10 * 7  =  70
```

---

## 4. Write a Python program that takes a positive integer n as input and uses nested loops to print a right-angled triangle pattern of n rows using asterisks (*).

```python
p = int(input("Pyramid up to: "))

for i in range(1, p + 1):
    for j in range(i):
        print("*", end='')
    print()
```
### Output

```bash
Pyramid up to: 4
*
**
***
****
```

---

## 5. Write a Python program that implements a simple number guessing game. The program should generate a random number between 1 and 100 and allow the user to guess the number. The program should provide feedback if the guess is too high or too low. The game should continue until the user guesses the correct number or decides to quit by entering 0. Use break and continue statements to control the flow of the game.

```python
import random

print("A number guessing game:")

ran = random.randint(1, 100)
guess = 101

while guess != ran:
    guess = int(input("Enter your guess: "))

    if guess < ran:
        print("Guess is smaller")
    if guess > ran:
        print("Guess is larger")
    if guess == 0:
        break

if guess == ran:
    print("You won!")
if guess == 0:
    print("Better luck next time")
```
### Output

```bash
A number guessing game:
Enter your guess: 50
Guess is larger
Enter your guess: 25
Guess is smaller
Enter your guess: 37
You won!
```