include<servo_9g.scad>

//No bearing will print the shaft to the bearing diameter
bearing = false;
radius = bearing ? 1.84 : 3.4;

difference() {
        union() {
            cube([34,14,1]);
            translate([servo_l/2+hole_offset*2,7,1])
            cylinder(r1=radius-.2, r2=radius,h=2.9, $fn = 64);
        }
        translate([hole_offset,7,-10]) 
        cylinder(r=mount_hole_r,h=40);
        translate([hole_offset*3+servo_w-.1,7,-10]) 
        cylinder(r=mount_hole_r,h=40);
        
        //Wire Slot
        translate([20,2.5,-.5])
        cube([4,9,2]);
}