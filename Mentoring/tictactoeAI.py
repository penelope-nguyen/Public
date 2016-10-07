import random

winStates = [ [0,1,2],
              [3,4,5],
              [6,7,8],
              [0,3,6],
              [1,4,7],
              [2,5,8],
              [0,4,8],
              [2,4,6]
             ] 

corners = [0, 2, 6, 8]

def printBoard(aBoard):
    print ()
    for row in board:
        print (" | ".join(row))
        
def compAI(turn, userSpaces, compSpaces): 
    if turn == 0:
        move = 4
    elif turn == 1:
        move = random.choice(corners)
    else:
        userSet = set(userSpaces)
        compSet = set(compSpaces)

        possibleMoves = set()  

        for state in winStates:
            stateSet = set(state)
            if len(stateSet & compSet) == 2:
                possibleMoves.update([stateSet - compSet])
                possibleMoves = possibleMoves - (userSet & compSet)
                possibleMoves = list(possibleMoves)
                print (possibleMoves) 
                move = random.choice(possibleMoves)
                print ('comp moves', possibleMoves, move)
                break 
            elif len(stateSet & userSet)== 2:
                possibleMoves.update([stateSet - userSet])
                possibleMoves = possibleMoves - (userSet & compSet)
                possibleMoves = list(possibleMoves)
                print (possibleMoves) 
                move = random.choice(possibleMoves)
                print ('usermove ', possibleMoves, move)
                break 

            else:
                move = (random.choice(corners))
    return move 
    
            
def checkWin(userSpace, compSpace):
    winner = "__NO ONE__" 
    winStates = [ [0,1,2],
                  [3,4,5],
                  [6,7,8],
                  [0,3,6],
                  [1,4,7],
                  [2,5,8],
                  [0,4,8],
                  [2,4,6]
                 ]
    for state in winStates:
        if (compSpace == state) or (set(state) < set(compSpace)):
           winner = "__THE COMPUTER__" 
        if (userSpace == state) or (set(state) < set(userSpace)):
            winner = "__YOU__"
    return winner
    
board = [ ['0', '1', '2'] , ['3', '4', '5'] , ['6', '7', '8'] ] 
    
playersMoves = [ ] 
user = ''
comp = ''
userSpaces = []
compSpaces = []
user = input('would you like to be x or o? ')
while (user != 'x') and  (user != 'o'): 
    user = input('that is not a valid choice. please try again: ')
    
if user == 'x':
    comp = 'o'
else:
    comp = 'x' 
userTurn = input("would you like to be player one or player two? please enter one or two: ")
while (userTurn  != "one") and (userTurn != "two"): 
    userTurn = input("that is not a valid choice. the accepted answers are one or one: ")
if userTurn == "one":
    playersMoves.append(['user', user])
    playersMoves.append(['comp', comp]) 
else:
    playersMoves.append(['comp', comp]) 
    playersMoves.append(['user', user]) 
print("these are the places where you can enter moves:")
printBoard(board)
for turn in range(9):
    if turn >= 4:  
        winner = checkWin(compSpaces, userSpaces)
        if winner != "__NO ONE__":
            break
    
    currentPlayer = playersMoves[turn%2][0] 
    if currentPlayer == 'user':
        move = playersMoves[turn%2][1] 
        print ("\n//IT'S THE USER'S TURN//")
        while True:
            try:
                space = int(input("please enter a number between 0-8 for your move: "))
                if space not in range(0,9):
                    print("this number is not between 0-8") 
                    continue
                if space in userSpaces or space in compSpaces: 
                    print("this space has already been used.")
                    continue
                break 
            except ValueError:
                print ("that is not a valid number. Please try again. ")
        userSpaces.append(space) 
        
    
    else:
        print("\n//IT'S THE COMPUTER'S TURN//")
        move = playersMoves[turn%2][1] 
        space = compAI(turn, userSpaces, compSpaces)
        compSpaces.append(space) 
        
    row = space//3
    column = space%3 
    board[row][column] = move
    
    printBoard(board)
    
print ("THE WINNER IS: ", winner) 
