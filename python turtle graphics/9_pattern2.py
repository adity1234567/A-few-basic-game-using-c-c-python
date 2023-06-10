import turtle
t=turtle.Turtle()
list1=["yellow","red","green","blue"]
t.up()
t.goto(200,0)
for i in range (4):
    t.down()
    t.begin_fill()
    t.fillcolor(list1[i])
    t.circle(50)
    t.end_fill()
    t.up()
    t.backward(100)

t.up()
t.goto(200,100)
for i in range (4):
    t.down()
    t.begin_fill()
    t.fillcolor(list1[i])
    t.circle(100)
    t.end_fill()
    t.up()
    t.backward(100)

t.up()
t.goto(0,-100)
for i in range (4):
    t.down()
  # t.begin_fill()
    t.color(list1[i])
    t.pensize(20)
    t.circle(100)
  #t.end_fill()
    t.up()
    t.backward(100)