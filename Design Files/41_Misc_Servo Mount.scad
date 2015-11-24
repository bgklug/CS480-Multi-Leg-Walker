include<servo_9g.scad>

mount_x = 36;
mount_y = servo_l+2;
servo_tol   = 0.3;
servo_x     = servo_l + servo_tol*2; //~12
servo_y     = servo_w + servo_tol*8; //~23

difference() {
    union() {
        cube([mount_x,mount_y,wing_place+2]);
    }
    translate([mount_x/2,mount_y/2,19])
    cube([servo_y, servo_x, 40], center = true);
    
    
    translate([(36-servo_y)/2+servo_y-4*servo_tol,(mount_y-servo_l)/2,2])
    rotate([0,0,90])
    servo_9g(true,false);
    
    translate([-1,3,3])
    rotate([0,90,0])
    cylinder(r=1, h=50);
    translate([-1,mount_y-3,3])
    rotate([0,90,0])
    cylinder(r=1, h=50);
    translate([-1,3,3+8])
    rotate([0,90,0])
    cylinder(r=1, h=50);
    translate([-1,mount_y-3,3+8])
    rotate([0,90,0])
    cylinder(r=1, h=50);
}