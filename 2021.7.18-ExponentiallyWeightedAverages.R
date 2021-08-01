d <- rnorm(100)
x <- 1:100
y <- sqrt(x) + d
plot(x, y, type = "p")
par(new = TRUE)
plot(x, y, type = "l", col = "gray")
par(new = TRUE)
la <- 0
yp <- c()
for (t in y) {
    la <- 0.9 * la + 0.1 * t
    yp <- c(yp, la)
}
plot(x, yp, type = "l", col = "red")