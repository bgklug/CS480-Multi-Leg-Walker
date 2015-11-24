//https://bitbucket.org/leoken/arduino-mounting-openscad-library/downloads
use<ARDUINO/arduino.scad>


include<servo_9g.scad>

//This is the wiggle room on either side of the servo
tol = .2;

//Hexa = 6
//Octo = 8
sides = 6;
angle = 180-(sides-2)*180/sides;
theta = angle/2;
echo(angle);

radius = 75;
corner_r = 3;
length = (radius-corner_r)/cos(theta);
echo("lenght", length);
height = 2;

wall_t = 2;
up = 1;

cube_x = wall_t*2 + servo_l+tol*2;
cube_y = wall_t*2 + servo_w+tol*2+wing_w*2; 


servo_tol   = 0.3;
servo_x     = servo_l + servo_tol*2; //~12
servo_y     = servo_w + servo_tol*8; //~23


translate([22,-50,-10])
rotate([ 0, 180, 0 ])
%arduino("Mega");
//*/
difference() 
{
    union() 
    {
        //Base of the polygon
        rotate([0,0,theta]) // align with x axis
        hull()
        {
            for(i=[0:sides-1])
            {
                rotate([0,0,angle*i]) 
                translate([length,0,0])
                cylinder(r=corner_r,h=height);
            }
        }
        //Servo Mount boxes
        for(i=[0:sides-1])
        {
            rotate([0,0,angle*i]) 
            translate([radius-cube_y/2+tol,0,height])
            servo_slot();
        }
		//Inner Support walls
		lll = radius-cube_y;
        for(i=[0:sides-1])
        {
            rotate([0,0,angle*i]) 
            translate([lll-wall_t,-lll*tan(theta),2])
            cube([wall_t,lll*tan(theta)*2,wing_place+up]);
        }
		//
		ppp = radius*7/8;
        for(i=[0:sides-1])
        {
            rotate([0,0,angle*i]) 
            translate([ppp-wall_t,-ppp*tan(theta),2])
            cube([wall_t,ppp*tan(theta)*2,wing_place+up]);
        }
		
    }
	
    for(i=[0:sides-1])
    {
        rotate([0,0,angle*i]) 
        translate([radius-cube_y/2+servo_tol*4,0,0])
        rotate([0,0,90])
        translate([-servo_l/2-servo_tol,-servo_w/2-.2,-10])
        {
            cube([servo_x, servo_y, 50]);
            translate([servo_tol,servo_tol*4,0])
            servo_9g(hole=true,wings= false);
        }
    }
    
}
//*/

//servo_slot();
module servo_slot() 
{
    
    //center the servo
    rotate([0,0,90])
    translate([-servo_l/2,-servo_w/2,0])
    difference() 
    {
        //outside box
        translate([-wall_t,-wall_t-wing_w,0])
        cube([cube_x, cube_y, wing_place+up]);
		
        //inner servo tol box
        translate([-servo_tol, -servo_tol*4, -0.5])
        cube([servo_x, servo_y, 30]);
        //mounting holes
        translate([0,0,up])
            servo_9g(hole=true,wing= false);
    }
}