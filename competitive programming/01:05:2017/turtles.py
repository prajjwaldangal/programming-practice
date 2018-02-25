#n, L = [int(el) for el in input().split(' ')]

#cs = [int(el) for el in input().split(' ')]

import turtle

def draw_square():
	window = turtle.Screen()
	window.bgcolor("red")
	brad = turtle.Turtle()
	brad.shape("turtle")
	brad.color("yellow")
	brad.speed(1)
	brad.forward(100)
	brad.left(90)
	brad.forward(100)
	brad.left(90)
	brad.forward(100)
	brad.left(90)
	brad.forward(100)
	brad.left(90)

	window.exitonclick()

#draw_square()	
window = turtle.Screen()
window.bgcolor("green")
brad = turtle.Turtle()
brad.shape("turtle")
brad.color("yellow")
brad.speed(0)
for i in range(500):
	brad.forward(i)
	brad.left(91)
window.exitonclick()

