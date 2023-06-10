#import turtle
import turtle
t=turtle.Turtle()
t.pensize(4)                          #pen_size..thick
t.up()
t.goto(0,-50)
t.down()
t.begin_fill()
t.fillcolor("green")
t.circle(50)
t.end_fill()
               #2nd circle
t.forward(150)
t.left(90)
t.forward(200)
t.up()
t.goto(200,200)
t.down()
t.begin_fill()
t.fillcolor("red")
t.circle(50)
t.end_fill()
#t.circle(180,270)

            #3rd circle
t.right(90)
t.backward(300)
t.up()
t.goto(-150,150)
t.down()
t.begin_fill()
t.fillcolor("orange")
t.circle(50)
t.end_fill()

             #4rd circle

t.right(90)
t.forward(300)
t.up()
t.goto(-200, -200)
t.down()
t.begin_fill()
t.fillcolor("blue")
t.circle(50)
t.end_fill()

              #5th circle
t.left(90)
t.forward(300)
t.up()
t.goto(150,-250)
t.down()
t.begin_fill()
t.fillcolor("yellow")
t.circle(50)
t.end_fill()
t.up()
t.home()


#           using function
t.reset()
def draw_circle(x,y,color,rad):
    t.up()
    t.goto(x,y)
    t.down()
    t.begin_fill()
    t.fillcolor(color)
    t.circle(rad)
    t.end_fill()
    t.up()
    t.home()

draw_circle(0,-50,"green",50)
draw_circle(200,200,"orange",50)
draw_circle(-200,200,"blue",50)
draw_circle(-200,-200,"orange",50)
draw_circle(200,-200,"pink",50)
