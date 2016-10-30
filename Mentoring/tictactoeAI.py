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

userScores = [0,
              0,
              0,
              0,
              0,
              0,
              0,
              0]

diamond = [1,3, 5, 7]
corners = [0, 2, 6, 8]
center = 4
availableSpaces = [0, 1, 2, 3, 4, 5, 6, 7, 8]


board = [ ['0', '1', '2'] , ['3', '4', '5'] , ['6', '7', '8'] ] 

firstTurn = ['1', "one"]
secondTurn = ['2', "two"] 
playersMoves = [ ] 
user = ''
comp = ''
userSpaces = []
compSpaces = []
winner = "__NO ONE__" 

print ("☆ﾟ.*･｡ﾟ welcome to penelope's tic-tac-toe game ☆ﾟ.*･｡ﾟ\n")
user = input('would you like to be x or o? ')
while (user != 'x') and  (user != 'o'): 
    user = input('that is not a valid choice. please try again: ')
    
if user == 'x':
    comp = 'o'
else:
    comp = 'x' 

userTurn = input("would you like to be player one or player two? please enter 1/one or 2/two: ")
while (userTurn not in firstTurn) and (userTurn not in secondTurn): 
    userTurn = input("that is not a valid choice. the accepted answers are 1/one OR 2/two: ")
    
if userTurn in firstTurn:
    playersMoves.append(['user', user])
    playersMoves.append(['comp', comp]) 
else:
    playersMoves.append(['comp', comp]) 
    playersMoves.append(['user', user])

print("\nthis is your opponent: takkie Σ(‘◉⌓◉’)")     
print("these are the places where you can enter moves:\n")

for row in board: 
    print (" | ".join(row))
    
for turn in range(9):

    if (turn >= 4):
            if 3 in userScores:
                winner = "__YOU__" 

    if winner != "__NO ONE__":
        break
    
    currentPlayer = playersMoves[turn%2][0]

    if currentPlayer == 'user':
                
        move = playersMoves[turn%2][1] 
        print ("\n★ IT'S THE USER'S TURN ★")
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

        for i in range(8):
            if space in winStates[i]:
                userScores[i] += 1 
        
        userSpaces.append(space)

    else:
        
        print("\n☆ﾟ IT'S THE COMPUTER'S TURN ☆ﾟ")
        move = playersMoves[turn%2][1]

        space = -1
        winSpace = -2 
        defendSpace =  -3
        
        if (len(compSpaces) == 0) and (len(userSpaces) == 0):
            space = random.choice(corners)
            
        elif (len(compSpaces) == 1) and (len(userSpaces) == 1):  
            if (userSpaces[0] in corners):
                if (compSpaces[0] in corners):
                    space = center
                    center = -4
                else:
                    while (space not in availableSpaces):
                        space = random.choice(corners)
            else:
                while (space not in availableSpaces): 
                    space = random.choice(corners)
        else:
            
            for state in winStates:
                compAvailSpaces = state.copy()
                userAvailSpaces = state.copy() 
            
                winLevel = 0
                threatLevel = 0 

                for num in state:
                    if (num in compSpaces):
                        winLevel += 1
                        compAvailSpaces.remove(num)
                        
                    if (num in userSpaces):
                        threatLevel +=1
                        userAvailSpaces.remove(num)

                if (winLevel >= 2):
                    if (compAvailSpaces[0] in availableSpaces):
                        winSpace = compAvailSpaces[0]
                        
                elif (threatLevel >=2):
                    if (userAvailSpaces[0] in availableSpaces):
                        defendSpace = userAvailSpaces[0]

            if winSpace >= 0:
                space = winSpace
                winner = "__ TAKKIE Σ(‘◉⌓◉’) __" 
            
            elif defendSpace >=0:
                print ("pls") 
                space = defendSpace

            else:
                while (space not in availableSpaces): 
                    if len(corners) != 0:
                        space = random.choice(corners)
                        corners.remove(space)
                    elif center >= 0:
                        space = center
                        center = -4
                    else:
                        space = random.choice(diamond)
                        diamond.remove(space)

       
        compSpaces.append(space)
        print ("Σ(‘◉⌓◉’) takkie says: i marked space {}.".format(space))


    availableSpaces.remove(space) 

    row = space//3
    column = space%3 
    board[row][column] = move
    
    print ()
    for row in board: 
        print (" | ".join(row))
    
print ("THE WINNER IS: ", winner)
print ("Σ(‘◉▽◉’)☆ takkie says: thanks for playing!")