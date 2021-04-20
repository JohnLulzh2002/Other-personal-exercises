x=5
x
y=x^2
y
z=sqrt(x)
z

lm.fit <- lm(mpg~disp,data=mtcars)
summary(lm.fit)
plot(lm.fit)

library(vcd)
mosaic(Titanic,shade = TRUE,legend=TRUE)