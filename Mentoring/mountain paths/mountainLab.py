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
    min_num = int(list_of_lists[0][0])
    max_num = int(list_of_lists[0][0])
    
    for someList in list_of_lists:
        for num in someList:
            num = int(num) 
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
    
    glib.open_window(900, 900)
    img = glib.create_image(width, height)
    
    pixels = glib.get_pixels(img) 
    for w in range(width):
        for h in range(height):
            color = pixels.getpixel(w, h)
            new_pixel = list_of_lists[h][w]
            pixels.setpixel(w, h, (new_pixel, new_pixel, new_pixel)) 
    return img 

def greedy_walk(listOfLists, start_row, img, RGB):
    
    height = img.size[1] 
    column_limit = img.size[0] - 1 
    row_limit = height - 1 
    r, g, b, = RGB
    totals = []
    paths = []
    h = 0
    w = 0 
    for h in range (start_row, height):
        new_path = [(h, 0)]
        total_changes = 0
        row = h 
        for column in range(column_limit):
            current_step = listOfLists[row][column] 
            move_right = listOfLists[row][column + 1]
            best_move = abs(move_right - current_step)
            
            if (row!= 0 and column != column_limit):
                move_up = listOfLists[row - 1][column + 1]
                poss_move = abs(move_up - current_step)
                if (poss_move < best_move):
                    best_move = poss_move
                    row -= 1
                    
            if (row != row_limit and column != column_limit):
                move_down = listOfLists[row + 1][column + 1]
                poss_move = abs(move_down - current_step)
                if (poss_move < best_move):
                    best_move = poss_move
                    row += 1
                    
            total_changes += best_move
            new_path.append((row, column + 1))  
            if (column == (column_limit - 1)): 
                totals.append(total_changes)
                paths.append(new_path)
            pixels = glib.get_pixels(img) 
            pixels.setpixel(column + 1, row, (r, g, b))
            
    glib.update()
    return paths, totals 
            
def find_best_path(list_of_paths, totals, img):
    least_elevation_change = totals[0]
    best_path = 0 
    totals_length = len(totals)
    
    for num in range(1, totals_length):
        if totals[num] < least_elevation_change:
            least_elevation_change = totals[num] 
            best_path = num
            
    best_path = list_of_paths[best_path]
    pixels = glib.get_pixels(img)
    for coordinate in best_path:
        x = coordinate[1] 
        y = coordinate[0] 
        pixels.setpixel(x, y, (51, 255, 51))
        
    glib.update()
    
def main():
    start = 0
    color_triple = (255, 100, 100)
    
    f_name = input("Please enter a filename: ")
    print("Processing into image...") 
    file_lists = read_file(f_name)
    width, height = find_width_height(file_lists) 
    file_lists = normalize(file_lists)
    image = display(file_lists, width, height)
    paths, elevation_totals = greedy_walk(file_lists, start, image, color_triple)
    find_best_path(paths, elevation_totals, image)
    glib.show_image(image, 450, 450)
    
main()