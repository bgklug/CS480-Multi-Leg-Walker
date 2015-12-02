use<horn1.scad>

mount_y = 12;
mount_x = 32-mount_y/2;

thick   = 4;

difference() {
    union() {
        hull() {
            cylinder(r=mount_y/2, h=thick);
            translate([0,-mount_y/2,0])
            cube([mount_x,mount_y,thick]);
        }
		
//    translate([mount_x-3*2, -mount_y/2,thick])
//    cube([6,mount_y,1.5]);
    }
    translate([0,0,1.2])
    horn1();
    translate([0,0,-.1])
    cylinder(r=3,h=5, $fn = 32);
    
    
    translate([mount_x-3,-4,-.1])
    cylinder(r=1.2, h=15, $fn=12);
    translate([mount_x-3,4,-.1])
    cylinder(r=1.2, h=15, $fn=12);
	
	
    translate([mount_x-3.1*2, -mount_y/2-.1,3])
    cube([6+.6,mount_y+.2,8]);
    
}