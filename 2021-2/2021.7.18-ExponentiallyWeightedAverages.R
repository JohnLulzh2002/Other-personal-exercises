d <- rnorm(100)
x <- 1:100
y <- sqrt(x) + d
yrange <- range(y)
plot(x, y, type = "p", ylim = yrange)
par(new = TRUE)
plot(x, y, type = "l", col = "gray", ylim = yrange)
par(new = TRUE)
la <- 0
yp <- c()
b <- 0.9
for (t in seq(length(y))) {
    la <- b * la + (1 - b) * y[t]
    yp <- c(yp, la / (1 - b^t))
}
plot(x, yp, type = "l", col = "red", ylim = yrange)