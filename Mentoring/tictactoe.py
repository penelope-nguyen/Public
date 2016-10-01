def printBoard(aBoard):
    print ()
    for row in board:
        print (" | ".join(row))

def checkWin(listOfSpaces):

    winner = "" 
    winStates = [ [0,1,2],
                  [3,4,5],
                  [6,7,8],
                  [0,3,6],
                  [1,4,7],
                  [2,5,6],
                  [0,4,8],
                  [2,4,6]
                 ]

    for win in winStates:
        if listOfSpaces[0] == win:
            winner = "__PLAYER ONE__" 
        if listOfSpaces[1] == win:
            winner = "__PLAYER TWO__"

    return winner 
    
board = [ ['0', '1', '2'] , ['3', '4', '5'] , ['6', '7', '8'] ] 
    
choices = ['x', 'o']

player1  = ''
player2 = ''

player1 = input('would you like to be x or o? ')

while player1 not in choices:
    player1 = input('that is not a valid choice. please try again: ')

if player1 == choices[0]:
        player2 = choices[1]
else:
    player2 = choices[0] 

print("these are the places where you can enter moves:\n")

printBoard(board)

p1 = []
p2 = []
spacesUsed = [p1, p2]

move = ''
winner = ""

for turn in range(0,9):
    if turn >= 4:
        winner = checkWin(spacesUsed)
        if winner != "":
            break 
        
    if turn%2 == 0: #if turn is even 
        print("\n//PLAYER ONE'S TURN//")
        move = player1 

    else:
        print("\n//PLAYER TWO'S TURN//")
        move = player2

    while True:
        try:
            space = int(input("please enter a number between 0-8 for your move: "))
            if space not in range(0,9):
                print("this number is not between 0-8") 
                continue
            if space in p1 or space in p2:
                print("this space has already been used.")
                continue
            break 
        except ValueError:
            print ("that is not a valid number. Please try again. ")


    spacesUsed[turn%2].append(space) 

    board[int(space/3)][space%3] = move
    
    printBoard(board)
    
if winner != "":
    print ("THE WINNER IS", winner)

else:
    print ("NO ONE WON. :(") 
