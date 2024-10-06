# random password generator
import random
import string

def generate(len=12): #default set to 12
    low = string.ascii_lowercase #abcdefghijklmnopqrstuvwxyz
    upr = string.ascii_uppercase #ABCDEFGHIJKLMNOPQRSTUVWXYZ 
    num = string.digits #0123456789
    spe_ch = string.punctuation #!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~

    all = low + upr + num + spe_ch
    
    passwd = "" #declaring passwd as a string

    for i in range(len):
        passwd += random.choice(all) #choose a random char from 'all'

    return passwd

