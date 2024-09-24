## 1. Write a Python program that takes two numbers as input from the user and prints their sum.

```python
n1 = int(input("Enter a Number: "))
n2 = int(input("Enter another Number: "))

print(f"Sum: {n1} + {n2} = ", n1 + n2)
```
### Output

```bash
Enter a Number: 5
Enter another Number: 10
Sum: 5 + 10 =  15
```

---

## 2. Write a Python program that asks the user for their name and then prints a greeting message that says "Hello, [name]!".

```python
name = input("What's your name? : ")
print(f"Hello, {name}")
```
### Output

```
What's your name? : Alice
Hello, Alice
```

---

## 3. Write a Python program that calculates the area of a rectangle. The program should ask the user to input the length and width of the rectangle and then display the calculated area.

```python
b = float(input("What's the breadth?: "))
l = float(input("What's the length?: "))

print(f"Area of rectangle is ", b * l)
```
### Output

```
What's the breadth?: 5
What's the length?: 10
Area of rectangle is  50.0
```

---

## 4. Write a Python program that asks the user for their current age and then calculates and prints their age in five years.

```python
a = int(input("What's your age?: "))
print(f"Your age in 5 years would be", a + 5)
```
### Output

```
What's your age?: 20
Your age in 5 years would be 25
```

---

## 5. Write a Python program that calculates the simple interest on a principal amount. The program should ask the user to input the principal amount, the rate of interest, and the time period (in years). It should then display the calculated simple interest.

```python
principal = float(input("Enter the principal amount: "))
rate = float(input("Enter the rate of interest (in %): "))
time = float(input("Enter the time period (in years): "))

simple_interest = (principal * rate * time) / 100

print(f"The calculated simple interest is: {simple_interest}")
```
### Output

```bash
Enter the principal amount: 1000
Enter the rate of interest (in %): 5
Enter the time period (in years): 3
The calculated simple interest is: 150.0
```
