set.seed(123)
x <- rnorm(500)
set.seed(110)
y <- rnorm(500)
opar <- par(no.readonly = TRUE)
par(fig = c(0, 0.8, 0, 0.8))
plot(x, y)
par(fig = c(0, 0.8, 0.55, 1), new = TRUE)
plot(density(x), axes = F, frame.plot = F, xlab = "", ylab = "", main = "")
par(fig = c(0.65, 1, 0, 0.8), new = TRUE)
plot(density(y)$y, density(y)$x,
    axes = F, frame.plot = F,
    xlab = "", ylab = "", main = "", type = "l"
)
par(opar)

sum(mtcars$mpg < 15)

for (i in 1:4) {
    print(i)
}

for (alpha in seq(0, 2, 1 / 18)) {
    x <- cospi(alpha)
    y <- sinpi(alpha)
    print(paste(alpha, ":", "(", x, ",", y, ")", x * x + y * y))
    # par(fig = c(0, 1, 0, 1), new = TRUE)
}
x <- cospi(1/60)
y <- sinpi(1/60)
plot(c(0, x), c(0, y), axes = FALSE, xlab = "", ylab = "", type = "l")
