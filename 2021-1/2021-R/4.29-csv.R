# setwd("Desktop")
# dirname(parent.frame(2)$ofile)
setwd(dirname(sys.frame(1)$ofile))
diamonds <- read.csv("diamonds.csv")
summary(diamonds)
a <- diamonds$carat
colnames(diamonds)
names(diamonds)
rownames(diamonds)
b <- aggregate(diamonds[, -c(2:4)], by = list(diamonds$cut, diamonds$color), mean)
write.csv(b, "aa.csv")

car <- mtcars
dim(car)
summary(car)
subset(car, car$vs == 1 & car$am == 1)
aggregate(car, by = list(car$vs, car$gear), mean)
?aggregate