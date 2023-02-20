#input 50 x&y coordinates from data.txt file
#output 50 x&y coordinates as points on a graph using turtle

import turtle
import numpy as np

#read data from data.txt file stored as (x,y) on each line as a string
x, y = np.loadtxt('D:\Algorithms-C\Exp3\data.txt', delimiter=',', unpack=True, dtype='str')

#convert string to float
x = x.astype(float)
y = y.astype(float)

#set turtle window size
turtle.setup(800, 800)
turtle.title("Graph")
turtle.bgcolor("white")
turtle.pencolor("black")
turtle.pensize(3)
turtle.speed(0)

#reset turtle
turtle.penup()
turtle.goto(0, 0)
turtle.pendown()
turtle.left(90)

# draw the y-axis
turtle.forward(400)
turtle.penup()
turtle.goto(0, 0)
turtle.pendown()
turtle.backward(400)

#reset turtle
turtle.right(90)

#draw x-axis
turtle.penup()
turtle.goto(-400, 0)
turtle.pendown()
turtle.forward(800)

#draw x-axis ticks
turtle.left(90)
for i in range(-400, 400, 25):
    turtle.penup()
    turtle.goto(i, 0)
    turtle.pendown()
    turtle.forward(10)

#draw y-axis ticks
turtle.right(90)
for i in range(-400, 400, 25):
    turtle.penup()
    turtle.goto(0, i)
    turtle.pendown()
    turtle.forward(10)

#draw x-axis labels
for i in range(-400, 400, 25):
    turtle.penup()
    turtle.goto(i, -20)
    turtle.pendown()
    turtle.write(i)

#draw y-axis labels
for i in range(-400, 400, 25):
    turtle.penup()
    turtle.goto(-20, i)
    turtle.pendown()
    turtle.write(i)

#draw points
for i in range(0, len(x)):
    turtle.penup()
    turtle.goto(x[i], y[i])
    turtle.pendown()
    turtle.dot(5)

#draw convex hull
#brute force method
# x1,y1,x2,y2 = np.loadtxt('D:\Algorithms-C\Exp3\ch1.txt', delimiter=',', unpack=True, dtype='str')
#graham scan method
x1,y1,x2,y2 = np.loadtxt('D:\Algorithms-C\Exp3\ch2.txt', delimiter=',', unpack=True, dtype='str')
#divide and conquer method
# x1,y1,x2,y2 = np.loadtxt('D:\Algorithms-C\Exp3\ch3.txt', delimiter=',', unpack=True, dtype='str')

x1 = x1.astype(float)
y1 = y1.astype(float)
x2 = x2.astype(float)
y2 = y2.astype(float)

turtle.pencolor("red")
for i in range(0, len(x1)):
    turtle.penup()
    turtle.goto(x1[i], y1[i])
    turtle.pendown()
    turtle.dot(5)
    turtle.goto(x2[i], y2[i])

turtle.done()