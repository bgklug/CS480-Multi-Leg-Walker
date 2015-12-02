include<servo_9g.scad>

mount_y = servo_l+2;

foot_x = 30;
foot_y = 4;
foot_z = 4;

difference()
{
	union() 
	{
		cube([1,mount_y,mount_y]);
		hull()
		{
			cube([1,mount_y,mount_y*2/3]);
			
			translate([foot_x/2,mount_y/2, foot_z/2])
				cube([foot_x, foot_y, foot_z], center = true);
		}
	}

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
	
	rrr = 2.4;
	translate([2,3,3])
    rotate([0,90,0])
    cylinder(r=rrr, h=50);
    translate([2,mount_y-3,3])
    rotate([0,90,0])
    cylinder(r=rrr, h=50);
    translate([2,3,3+8])
    rotate([0,90,0])
    cylinder(r=rrr, h=50);
    translate([2,mount_y-3,3+8])
    rotate([0,90,0])
    cylinder(r=rrr, h=50);
	
}