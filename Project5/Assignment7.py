#Cheyenne Kent
from tkinter import *
from rectpack import *
import sys
#creates a canvas that can be used
class CustomCanvas:
    def __init__(self, height, width):
        self.myCanvas = Canvas(Tk(), bg="black", width = width, height = height)
        self.myCanvas.pack()
#creates a rectangle object
class Rectangle:
    def __init__(self, height, width, x = 0, y = 0):
        self.height = height
        self.width = width
        self.x = x
        self.y = y
#creates more rectangle objects and positions on where to place them
def pack(allRect, canvasSize):
    packer = newPacker()
    newRectangles = []
    rectangles = []
    canvas = [canvasSize]

    for y in allRect:
        rectangles.append((y.height, y.width))
    for r in rectangles:
        packer.add_rect(*r)
    for x in canvas:
        packer.add_bin(*x)
    packer.pack()

    for abin in packer:
      for rect in abin:
        newRectangles.append(Rectangle(rect.height, rect.width, rect.x, rect.y))
    return newRectangles
#reads in the files and creates and displays rectangles
def main():
    count = 0
    rectList = []
    fp = sys.argv[1]
    file = open(fp)
    lines = file.readlines()
    #reads in the lines, calls to create a canvas and rectangles
    for line in lines:
        values = line.split(",")
        if count == 0:
            canvas = CustomCanvas(int(values[0]), int(values[1]))
            canvasSize = (int(values[0]), int(values[1]))
        else:
            rectList.append(Rectangle(int(values[0]), int(values[1])))
        count += 1
    file.close()
    #packs the rectangles and canvas and then prints the rectangles to the canvas
    allRect = pack(rectList, canvasSize)
    for rect in allRect:
        w = canvas.myCanvas.create_rectangle(rect.x, rect.y, (rect.x + rect.width), (rect.y + rect.height), fill = "blue")

if __name__ == '__main__':
    main()
    mainloop()
