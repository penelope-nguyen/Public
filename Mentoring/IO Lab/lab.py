
inFile = open("data.txt", 'r')
outFile = open("grades.txt", 'w')

for line in inFile:
    total = 0
    average = 0
    
    line = line.split() 
    first_name = line[0]
    last_name = line[1]
    for position in range(2, 22):
        num = int(line[position])
        total += num 

    average = total/20
    
    line = "{}\t{}\t{}".format(first_name, last_name, average)
    outFile.write(line) 

inFile.close()
outFile.close() 
