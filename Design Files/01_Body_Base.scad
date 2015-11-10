include<servo_9g.scad>

//Hexa = 6
//Octo = 8
sides = 8;
angle = 180-(sides-2)*180/sides;
echo(angle);

radius = 50;
corner_r = 2;
side = 30;
length = radius/sin(angle);
height = 2;

//This is the wiggle room on either side of the servo
tol = .2;


difference() 
{
    union() 
    {
        //Base of the polygon
        rotate([0,0,angle/2]) // align with x axis
        hull()
        {
            for(i=[0:sides-1])
            {
                rotate([0,0,angle*i]) 
                translate([length,0,0])
                cylinder(r=corner_r,h=height);
            }
        }
        for(i=[0:sides-1])
        {
            rotate([0,0,angle*i]) 
            translate([radius-1,0,0])
            servo_slot();
        }
    }
    for(i=[0:sides-1])
    {
        rotate([0,0,angle*i]) 
        translate([radius-1,0,0])
        rotate([0,0,90])
        translate([-servo_l/2,-servo_w/2,-10])
        cube([servo_l+2*tol, servo_w+2*tol, 30]);
    }
    
}

//servo_slot();
module servo_slot() 
{
    wall_t = 2;
    up = 5;
    //center the servo
    rotate([0,0,90])
    translate([-servo_l/2,-servo_w/2,0])
    difference() 
    {
        //outside box
        translate([-wall_t,-wall_t-wing_w,0])
        cube([wall_t*2 + servo_l+tol*2,  
              wall_t*2 + servo_w+tol*2+wing_w*2, 
              wing_place+up]);
        //inner servo tol box
        translate([-tol, -tol, -tol])
        cube([servo_l+2*tol, servo_w+2*tol, 30]);
        //mounting holes
        translate([0,0,up])
            servo_9g(false);
    }
}