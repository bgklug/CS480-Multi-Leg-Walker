module m2Hole(x,y,z) {
    translate([x,y,z-.1])
    cylinder(r=1,h=50);
}