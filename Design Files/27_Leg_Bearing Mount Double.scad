mount_y = 12;
mount_x = 51-mount_y;

bearing_r = 3.7;
bearing_h = 1.2;

thick   = 2.4;

difference() {
    union() {
        hull() {
            cylinder(r=mount_y/2, h=thick,$fn = 64);
            translate([mount_x,0,0])
            cylinder(r=mount_y/2, h=thick,$fn = 64);
            
        }
        
            translate([0,0,bearing_h])
            cylinder(r=bearing_r+1.8, h=2.4, $fn=32);
            translate([mount_x,0,bearing_h])
            cylinder(r=bearing_r+1.8, h=2.4, $fn=32);
    }
    translate([0,0,bearing_h])
    cylinder(r1=bearing_r,r2=bearing_r-0.2, h=15, $fn=32);
    translate([mount_x,0,bearing_h])
    cylinder(r1=bearing_r,r2=bearing_r-0.2, h=15, $fn=32);
    
    translate([10,0,0])
    cube([6,6,12], center= true);
    translate([8+mount_x/2,0,0])
    cube([6,6,12], center= true);
    
    translate([mount_x/2,-4,-.1])
    cylinder(r=1.2, h=15, $fn=12);
    translate([mount_x/2,4,-.1])
    cylinder(r=1.2, h=15, $fn=12);
    
    translate([mount_x/2-3.1, -mount_y/2-.1,2])
    cube([6.2,mount_y+.2,8]);
}