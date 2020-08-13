import os 

test_path = "C:/Users/ITD/Desktop/1071 資料結構 答題記錄/1071 資料結構 答題記錄/"



def read_directory(directory_name):
    array_of_img = []
    # this loop is for read each image in this foder,directory_name is the foder name with images.
    for filename in os.listdir(directory_name):
        array_of_img.append(filename)
    return array_of_img



def main():
    dir_name = read_directory(test_path)
    for di in dir_name:
        print(di)
        each_dir = read_directory(test_path + di + "/")
        for i in each_dir:
            print("           ", i)
            tp = os.path.splitext(i)[0]
            os.rename(test_path + di + "/" + i, test_path + di + "/" + tp + ".cpp")
    


if __name__ == '__main__':
    main()