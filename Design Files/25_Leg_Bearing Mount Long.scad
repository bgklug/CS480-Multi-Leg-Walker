
mount_y = 12;
mount_x = 32-mount_y/2;

bearing_r = 3.7;
bearing_h = 1.2;

thick   = 2.4;

difference() {
    union() {
        hull() {
            cylinder(r=mount_y/2, h=thick);
            translate([0,-mount_y/2,0])
            cube([mount_x,mount_y,thick]);
        }
        translate([0,0,bearing_h])
        cylinder(r=bearing_r+1.8, h=2.4, $fn=32);
    }
    translate([0,0,bearing_h])
    cylinder(r=bearing_r, h=15, $fn=32);
    
    translate([12,0,0])
    cube([12,6,12], center= true);
    
    translate([mount_x-3,-4,-.1])
    cylinder(r=1.2, h=15, $fn=12);
    translate([mount_x-3,4,-.1])
    cylinder(r=1.2, h=15, $fn=12);
    
    translate([mount_x-3.1*2, -mount_y/2-.1,2])
    cube([6+.6,mount_y+.2,8]);
}