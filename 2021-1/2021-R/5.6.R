mc <- mtcars
fix(mc)
plot(mc)
plot(mc$wt)
plot(mc$wt, mc$mpg, type = "h", lwd = 5)
md <- mc[order(mc$wt), ]
plot(md$wt, md$mpg, type = "l")
plot(md$wt, md$mpg,
    cex = 2, col = rainbow(7),
    type = "o",
    xlab = "wt", ylab = "mpg",
    cex.lab = 2
)
plot(md$wt, md$mpg,
    cex = 2, col = rainbow(7),
    type = "o",
    xlab = "wt", ylab = "mpg",
    cex.lab = 2,
    ann = F
)
title(
    xlab = "Weight",
    col.lab = "orange",
    cex.lab = 1.5, font.lab = 3
)