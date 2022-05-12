a <- 10:30
a > 23 & a < 27
a[a > 23 & a < 27]
a[1:5]
b <- sample(letters, 10)
b
sort(b)
sort(b, decreasing = T)
c <- rep(c("R", "W", "B"), c(5, 2, 2))
c
sample(c, 5)
x <- 1:4
sin(pi / 2 * x)
set.seed(1111)
x <- rnorm(100, 1, 2)
min(x)
which.min(x)
which.max(x)
mean(x)
summary(x)
sum(x)/length(x)
