tt <- t.test(rnorm(10), rnorm(10), var.equal = T)
tt$statistic
library(ggplot2)
ggplot(mtcars, aes(x = wt, y = mpg)) +
    geom_point()
ggplot(mtcars, aes(x = wt, y = mpg, color = as.factor(am))) +
    geom_point()
# ggplot(mtcars, aes(x=wt, y=mpg ),color="blue")+geom_point()
# ggplot(mtcars, aes(x=wt, y=mpg, color="blue"))+geom_point()
# ggplot(mtcars, aes(x=wt, y=mpg ))+geom_point(aes(color="blue"))
ggplot(mtcars, aes(x = wt, y = mpg)) +
    geom_point(aes(color = "blue")) +
    scale_colour_identity()