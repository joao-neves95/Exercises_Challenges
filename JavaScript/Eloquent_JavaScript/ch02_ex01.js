/*
Looping a triangle:

Write a loop that makes seven calls to console.log to output the following
triangle:
#
##
###
####
#####
######
#######
*/



for (var tri = "#"; tri.length <= 7; tri += "#") {
  console.log(tri);
}
