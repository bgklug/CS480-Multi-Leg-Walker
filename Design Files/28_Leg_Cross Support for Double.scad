include<servo_9g.scad>

$fn = 12;

l = 38; 
w = 12;
t = 6;

rad = 0.9;
difference() {
    cube([l,w,t]);
    
    translate([-.1,2,t/2])
    rotate([0,90,0])
    cylinder(r=rad, h=8);
    translate([-.1,10,t/2])
    rotate([0,90,0])
    cylinder(r=rad, h=8);
    
    
    translate([.1+l,2,t/2])
    rotate([0,-90,0])
    cylinder(r=rad, h=10);
    translate([.1+l,10,t/2])
    rotate([0,-90,0])
    cylinder(r=rad, h=10);
    
    
    translate([17,-1,t/2])
    rotate([-90,0,0])
    cylinder(r=rad, h=30);
    translate([9,-1,t/2])
    rotate([-90,0,0])
    cylinder(r=rad, h=30);
}