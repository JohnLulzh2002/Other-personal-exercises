1:10
c(1, 6, 3, 7, 2)
seq(1, 10, 2)
# ?seq
seq(15, 0)
rep(4, 12)
rep(2:5, 2)
rep(2:5, each = 2)
LETTERS
letters

# library(maps)
# map("world", fill = TRUE, col = rainbow(200), ylim = c(-60, 90), mar = c(0, 0, 0, 0))
# title("world")

# h <- c(1, 2, 3, 4, 5, 6)
# M <- c("A", "B", "C", "D", "E", "F")
# barplot(h,
#     names.arg = M, xlab = "X", ylab = "Y",
#     col = "#00cec9", main = "Chart", border = "#fdcb6e"
# )

rnorm(5)

x <- 11:20
x[1:5]
x[-4:-7]
y <- runif(10) * 100
y
y <- round((y))
y
rev(y)
sort(y)

z <- sample(1:100, 5)
z
sort(z)
rank(z)
order(z)