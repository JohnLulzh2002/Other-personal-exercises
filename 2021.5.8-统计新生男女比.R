getwd()
freshman <- read.csv("FreshMan.CSV")
fix(freshman)
summary(freshman)
s <- freshman$Sex
s[s == "Male"] <- TRUE
s[s == "Female"] <- FALSE
s <- as.logical(s)
s
summary(s)