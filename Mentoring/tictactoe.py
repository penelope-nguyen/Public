def printBoard(aBoard):
    print ()
    for row in board:
        print (" | ".join(row))

def checkWin(p1, p2):

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

    # following code doesn't work, will fix after finishing homework (Oct. 1 2016) 
    for win in winStates:
        if p1 < win:
            winner = "__PLAYER ONE__" 
        if p2 < win:
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

print("these are the places where you can enter moves:")

printBoard(board)

p1Spaces = []
p2Spaces = []

move = ''
winner = ""

for turn in range(9):
    if turn >= 5:
        winner = checkWin(p1Spaces, p2Spaces) 
        if winner != "":
            break 
        
    if turn%2 == 0: #if turn is even 
        print("\n//PLAYER ONE'S TURN//")
        move = player1
        spacesUsed = p1Spaces

    else:
        print("\n//PLAYER TWO'S TURN//")
        move = player2
        spacesUsed = p2Spaces

    while True:
        try:
            space = int(input("please enter a number between 0-8 for your move: "))
            if space not in range(0,9):
                print("this number is not between 0-8") 
                continue
            if space in p1Spaces or space in p2Spaces:
                print("this space has already been used.")
                continue
            break 
        except ValueError:
            print ("that is not a valid number. Please try again. ")


    spacesUsed.append(space) 
        
    row = space//3
    column = space%3 
    board[row][column] = move
    
    printBoard(board)
    
if winner != "":
    print ("THE WINNER IS", winner)

else:
    print ("NO ONE WON. :(") 

exit() 
