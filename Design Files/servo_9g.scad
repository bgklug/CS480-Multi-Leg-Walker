//servo_9g(false);

//use<hub_mount.scad>
use<MCAD/nuts_and_bolts.scad>
$fn = 24;
//x,y,z => l,w,h
servo_l         = 12;
servo_w         = 23;
body_h          = 23;

servo_h         = 27; //not used in code

wing_w          = 5;
wing_h          = 2.33;
wing_place      = 18.3;   
hole_offset     = 2.5;    //not checked
mount_hole_r    = 2/2;
mount_slot      = 1;

servo_ww        = servo_w+wing_w*2; // not used in code but is handy number

hub_h           = 4;
small_hub_r     = 5.68/2;  
horn_r          = 4.66/2;
horn_h          = 3;

wire_l          = 4;
wire_w          = 1.5;
wire_h          = 1;
wire_place      = 4.8;

servo_full_w    = servo_w+wing_w*2;

//servo_9g(true, false);
module servo_9g(hole=false, wings = true) {
    //if a differnce is applied and you want 
    if(hole) {
        translate([servo_l/2,-hole_offset,-10]) 
        cylinder(r=mount_hole_r,h=40);
        translate([servo_l/2,hole_offset+servo_w,-10]) 
        cylinder(r=mount_hole_r,h=40);
        /*translate([servo_l/2,servo_l/2,-15])
        cylinder(r=1.5,h=15);*/
        
        /*translate([servo_l/2,servo_l/2,body_h+hub_h+5])
        #hub_mount();*/
    }
    color("white") translate([servo_l/2,servo_l/2,body_h+hub_h])
    cylinder(r=horn_r,h=horn_h);
    
    color("deepSkyBlue",.7) 
    union() {
        cube([servo_l,servo_w,body_h]);
        translate([servo_l/2,servo_l/2,body_h])
        cylinder(r=servo_l/2,h=hub_h);
        translate([servo_l/2,servo_l+small_hub_r/2,body_h])
        cylinder(r=small_hub_r,h=hub_h);
        
        if(wings) {
            translate([0,servo_w,wing_place])
            difference() {
                cube([servo_l,wing_w,wing_h]);
                translate([servo_l/2,hole_offset,0]) 
                cylinder(r=mount_hole_r,h=5);
                translate([servo_l/2-mount_slot/2,hole_offset+mount_hole_r/2,0])
                if(hole) cube([mount_slot,4,3]);
            }
        
            translate([servo_l,0,wing_place])
            rotate([0,0,180])
            difference() {
                cube([servo_l,wing_w,wing_h]);
                translate([servo_l/2,hole_offset,0]) 
                cylinder(r=mount_hole_r,h=5);
                translate([servo_l/2-mount_slot/2,hole_offset+mount_hole_r/2,0])
                if(hole) cube([mount_slot,4,3]);
            }
        }
    }
    
    /*color("brown") translate([(servo_l-wire_l)/2,-wire_w,wire_place])
    cube([wire_l,wire_w,wire_h]);*/
}