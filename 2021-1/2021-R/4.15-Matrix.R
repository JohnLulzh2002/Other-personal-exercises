y <- matrix(1:20, 4)
y
y[2]
y[2, ]
y[, 2]
y[, c(T, F)]

set.seed(110)
a <- matrix(rnorm(12), 3)
b <- matrix(rnorm(12, -1, 2), 3)
a * b
a %*% b
a %*% t(b)

d <- round(matrix(rnorm(16),4))
d
dim(d)
det(d)
solve(d)
g <- 1:4
solve(d)%*%g