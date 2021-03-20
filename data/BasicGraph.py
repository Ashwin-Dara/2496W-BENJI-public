import random
import numpy as np
import matplotlib.pyplot as plt

data_points = ["Error:", "Power:", "Heading:", "Integral:"]


class Logger:
    def __init__(self, file_name):
        self.file_name = open(file_name, 'r')

    
    def set_axis_names(self, x_axis, y_axis):
        plt.xlabel(x_axis)
        plt.ylabel(y_axis)


    def set_label_and_color(self, label, color):
        self.label = label
        self.color = color


    def generate_graph(self, data_variable):
        x = []
        y = []
        line_time = 0
        for lines in self.file_name:
            first_index = lines.find(data_variable) + len(data_variable + ":") 
            end_index = data_points.index(data_variable) + 1
            y_value = float(lines[first_index:end_index])
            y.append(y_value)

            x.append(int(line_time * 50))
            line_time = line_time + 1

        self.file_name.close()
        plt.plot(x, y, self.label, self.color)
        plt.legend()
        plt.show()


def main():
    linear_movement_logger = Logger("Acceleration_Datastream.txt")
    linear_movement_logger.set_axis_names("time", "Voltage")
    linear_movement_logger.set_label_and_color("Power Progression over time")
    linear_movement_logger.generate_graph("Power")


if __name__ == '__main__':
    main()

