use<horn1.scad>

mount_y = 12;
mount_x = 51-mount_y;

thick   = 4;

difference() {
    union() {
        hull() {
            cylinder(r=mount_y/2, h=thick,$fn = 64);
            translate([mount_x,0,0])
            cylinder(r=mount_y/2, h=thick,$fn = 64);
        }
    }
    translate([0,0,1.2])
    horn1();
    translate([0,0,-.1])
    cylinder(r=3,h=5, $fn = 32);
    
    translate([mount_x,0,1.2])
    rotate([0,0,180])
    horn1();
    translate([mount_x,0,-.1])
    cylinder(r=3,h=5, $fn = 32);
    
    
    translate([mount_x/2,-4,-.1])
    cylinder(r=1.2, h=15, $fn=12);
    translate([mount_x/2,4,-.1])
    cylinder(r=1.2, h=15, $fn=12);
    
    translate([mount_x/2-3.1, -mount_y/2-.1,2])
    cube([6.2,mount_y+.2,8]);
}