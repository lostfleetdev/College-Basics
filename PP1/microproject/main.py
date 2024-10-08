# random password generator
import random
import string

def generate(len=12, up=3, lo=3, n=3, sp=3): #default set to 12
    low = ''.join(random.choice(string.ascii_lowercase) for i in range(lo)) 
    #chooses lo numner of characters from : abcdefghijklmnopqrstuvwxyz
    upr = ''.join(random.choice(string.ascii_uppercase) for i in range(up)) 
    #ABCDEFGHIJKLMNOPQRSTUVWXYZ 
    num = ''.join(random.choice(string.digits) for i in range(n)) 
    #0123456789
    spe_ch = ''.join(random.choice(string.punctuation) for i in range(sp)) 
    #!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~

    temp = low + upr + num + spe_ch
    
    #to resolve error generated when characters are less or more, 
    if len < (up + lo + n + sp):
        raise ValueError("Total character types exceed password length.") # raises an error

    #add random characters to meet the total length
    pswd = ''.join(random.sample(temp, len))
    return pswd


while True:
    print("Randomised Password Generator:")
    l = int(input("Enter Length of Password: "))
    u = int(input("Enter no. of Uppercase characters: "))
    lo = int(input("Enter no. of Lowercase characters: "))
    d = int(input("Enter number of digits: "))
    s = int(input("Enter no. of Special characters: "))

    print("Password: ", generate(l,u,lo,d,s))

    e = input("Want to Exit(x) Or Continue(c)")
    if(e == 'x'):
        break