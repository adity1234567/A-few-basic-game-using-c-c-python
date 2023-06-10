import turtle
t=turtle.Turtle()
t.circle(100)
t.undo()
t.right(90)
t.forward(100)
t.left(90)
t.circle(100)
t.reset()
t.goto(0,-100)
t.circle(100)

#          for not to show the radius line
#              an ultimate circle
#        up-->goto-->circle-->down-->circle

t.reset()
t.up()              #up-->the pen up..no drawing when moving
t.goto(0,-100)      #  goto--> move to an absolute position
t.circle(100)
t.down()
t.circle(100)
