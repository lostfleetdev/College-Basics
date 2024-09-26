def create_file(fil):
    with open(fil, 'w') as file:
        print("File Created: ", fil)
        exit

def read_file(fil):
    with open(fil, 'r+') as file:
        print("Contents of File: ", fil)
        content = file.read()
    print(content)

def write_file(fil,txt):
    with open(fil, 'r+') as file:
        print("Written text to file: ", fil)
        file.write(txt)


filename = 'input.txt'
content = "Hello Fuck U maam"
create_file(filename)
write_file(filename, content)
read_file(filename)