import turtle
t=turtle.Turtle()
t.speed(1)              #speed
#                     bg color setting
wn=turtle.Screen()
wn.bgcolor("black")
#                      to fill color
t.begin_fill()
t.fillcolor("red")
t.forward(100)
t.left(90)
t.forward(100)
t.left(90)
t.forward(100)
t.left(90)
t.forward(100)

#                     both are same

for i in range(4):
    t.forward(100)
    t.left(90)

#                to hide the moving sign

t.hideturtle()
for i in range(4):
    t.forward(100)
    t.right(90)

t.hideturtle()
for i in range(2 ):
    t.forward(100)
    t.left(90)
for i in range(4):
    t.forward(100)
    t.right(90)

t.end_fill()