import random
import numpy as np
import matplotlib.pyplot as plt


class Logger:
    def __init__(self, file_name):
        self.file_name = file_name

    
    def generate_graph(self):
        for lines in self.file_name:
            

def main():
    dataFile = open("Data.txt", 'r')
    yValue = []
    xValue = []
    count = 0
    time = 0
    for lines in dataFile:
        count += 1
        time = count * 50
        yValue.append(float(lines))
        xValue.append(float(time))

    dataFile.close()
    print(xValue)
    print(yValue)
    plt.xlabel('Time Elapsed')
    plt.ylabel('Power Given to the Motor')
    plt.plot(xValue, yValue, color = 'red', label= "first graph")
    plt.plot([1, 2, 3], [4, 8, 12], color = 'black', label= "second graph")
    plt.legend()
    plt.show()

if __name__ == '__main__':
    main()

