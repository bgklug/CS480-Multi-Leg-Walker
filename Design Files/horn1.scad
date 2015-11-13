$fn = 64;

horn_r     = 7.4/2;
horn_r2    = 6.6/2;
horn_h     = 4;

center_to_tip_center = 19 - horn_r;

horn_thick = 4;
horn_tip   = 3.9/2;

horn1();

module horn1() {
    hull() {
        cylinder(r=horn_r2, h=horn_thick);
        translate([center_to_tip_center, 0,0])
        cylinder(r=horn_tip, h = horn_thick);
    }
    cylinder(r=horn_r,h=horn_h);
}