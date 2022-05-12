library(ggplot2)
ggplot(data = iris, aes(x = Species, y = Sepal.Width, color = Species)) +
    geom_point(position = "jitter", size = 3) +
    stat_summary(
        fun.y = "mean",
        geom = "errorbar",
        aes(ymin = ..y.., ymax = ..y..),
        width = 0.6,
        size = 1.5,
        colour = "grey25"
    )

ggplot(data = iris, aes(x = Sepal.Length, y = Sepal.Width, group = Species, color = Species)) +
    geom_line(aes(linetype = Species), size = 1.2) +
    geom_point(aes(shape = Species), size = 3) +
    # scale_shape_manual(values = c(6, 5, 4)) +
    # scale_linetype_manual(values = c("dotdash", "solid", "dotted")) +
    xlab("Sepal Length") +
    ylab("Sepal Width") +
    ggtitle("Line plot of sepal length and width")