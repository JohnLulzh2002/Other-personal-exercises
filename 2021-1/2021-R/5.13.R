attach(mtcars)
opar <- par(no.readonly = TRUE)

layout(matrix(c(1, 1, 2, 3), 2, 2, byrow = TRUE))
plot(wt ~ mpg)
hist(mpg)
plot(as.factor(am), mpg)

par(fig = c(0, 0.8, 0, 0.8))
plot(wt, mpg,
    xlab = "Miles Per Gallon",
    ylab = "Car Weight"
)
par(fig = c(0, 0.8, 0.55, 1), new = TRUE) # new 表示在原有图形上加图
boxplot(wt, horizontal = TRUE, axes = FALSE)
par(fig = c(0.65, 1, 0, 0.8), new = TRUE)
boxplot(mpg, axes = FALSE)
mtext("Enhanced Scatterplot", side = 3, outer = TRUE, line = -3)

detach(mtcars)
par(opar)


set.seed(123)
x <- rnorm(500)
y <- rnorm(500)
par(fig = c(0, 1, 0, 0.9))
plot(x, y)
# cor(x,y)

par(fig = c(0, 1, 0.5, 1))
plot(density(x),new=TRUE,
    axes = FALSE, xlab = "", ylab = "",
    xlim = c(-1000, 1000), ylim = c(-1000, 1000)
)
