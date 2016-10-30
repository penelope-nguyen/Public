import glib 

def read_file(file_name):
    file = open((file_name + '.txt'), 'r') 
    lists_in_file = []

    for line in file:
        line = line.split()
        lists_in_file.append(line)

    return lists_in_file 

def find_width_height(list_of_lists):
    height = len(list_of_lists)
    width = len(list_of_lists[0])
    return width, height

def scale(orig_scale, bottom, top, value):
    
    new_scale = (top - bottom) / orig_scale 
    scale = abs((-1 - value) * new_scale)
    
    return int(scale) 
def findNewScale(list_of_lists):
    max_num = 0
    min_num = 0 
    list_length = len(list_of_lists[0])
    
    for someList in list_of_lists:
        max_num = int(someList[0])
        max_num = int(someList[0]) 
        for i in range(1, list_length):
            num = int(someList[i]) 
            if num < min_num:
                min_num = num
            if num > max_num:
                max_num = num
                
    return (max_num - min_num) 
    
def normalize(list_of_lists):
    new_list = []

    new_scale = findNewScale(list_of_lists) 
    
    for list in list_of_lists:
        new_line = []
        for num in list:
            value = int(num)
            value = scale(new_scale, 0, 255, value)
            new_line.append(value)

        new_list.append(new_line) 
    return new_list 

def display(list_of_lists, width, height): 
    glib.open_window(1000, 1000)
    img = glib.create_image(width, height)
    
    pixels = glib.get_pixels(img) 
    for w in range(width):
        for h in range(height):
            color = pixels.getpixel( w, h)
            new_pixel = list_of_lists[h][w]
            pixels.setpixel(w, h, (new_pixel, new_pixel, new_pixel)) 
    return img 

def greedy_walk(listOfLists, start_row, img, RGB):
    
    width,height = img.size
    column_limit = img.size[0] - 1
    row_limit = img.size[1] - 1 
    r, g, b, = RGB
    totals = []
    paths = [] 
    for h in range (start_row, row_limit):
        new_path = [(h, 0)]
        paths.append(new_path)
        total_changes = 0
        row = h 
        for column in range(column_limit):
            current_step = listOfLists[row][column] 
            move_right = listOfLists[row][column + 1]
            best_move = abs(move_right - current_step)
            
            if (row!= 0):
                move_up = listOfLists[row - 1][column + 1]
                poss_move = abs(move_up - current_step)
                if (poss_move < best_move):
                    best_move = poss_move
                    row -= 1 
            if (row != row_limit):
                try: 
                    move_down = listOfLists[row + 1][column + 1]
                    poss_move = abs(move_down - current_step)
                    if (poss_move < best_move):
                        best_move = poss_move
                        row += 1
                except:
                    print(row + 1, column + 1)  
            total_changes += best_move
            new_path.append((row, column + 1))  
            if (row == row_limit and h != row_limit):
                totals.append(total_changes)
                paths.append(new_path)
                print(row, h)
            else:
                pass
            pixels = glib.get_pixels(img) 
            pixels.setpixel(column + 1, row, (r, g, b))
    print (len(paths))
    print (paths[0]) 
    print(paths[1]) 
    glib.update()
    glib.show_image(img, 500, 500) 
            
            
    """
    for h in range(start_row, 10):
        current_step = lists_of-lists[h][0]
        best_move = abs(lists_of_lists[h][1] - current_step) 
        for w in range(2, width):
            possible_step = lists_of_lists[h][w]
            move = current_step - possible_move 
            if 
            if move < best_move:
                best_move = move
                print(current_step, next_step)
        print (best_move) 
    """ 
            
        
    
def main():
    
    # f_name = input("Please enter a filename: ")
    file_lists = read_file("Colorado_480x480")
    width, height = find_width_height(file_lists) 
    file_lists =  normalize(file_lists)
    image = display(file_lists, width, height)
    glib.show_image(image, 500, 500) 
    start = 0
    color_triple = (255, 100, 100) 
    greedy_walk(file_lists, start, image, color_triple) 
    
main()
