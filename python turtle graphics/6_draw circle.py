import turtle
t=turtle.Turtle()
t.color("white")
wn=turtle.Screen()
wn.bgcolor("black")
t.begin_fill()
t.fillcolor("white")
t.circle(20)
t.circle(-50)
t.end_fill()
t.reset()                 #reset the circle
wn.bgcolor("white")
t.begin_fill()
t.fillcolor("red")
t.circle(90,180)

#                 triangle
#t.reset()
t.circle(100,steps=3)
#t.reset()
t.circle(70,steps=5)
#t.reset()
t.end_fill()

#reset use korle clr fill a prb hoi
