elements = []
while True:
    user_input = input("Enter an element to add to the list (type 'stop' to finish): ")
    if user_input.lower() == 'stop':
        print("Final List:", elements)
        break
    elements.append(user_input)
    print("Current list:", elements)
