//!OpenSCAD

module make_fluke() {
    // fluke
    intersection() {
        scale([2, 0.3, 2]){
            difference() {
                translate([-3, 0, 0]){
                    sphere(r=5);
                }

                rotate([0, 0, 315]){
                    scale([0.5, 0.8, 0.6]){
                        intersection() {
                            sphere(r=10);

                            translate([5, 0, 0]){
                                sphere(r=10);
                            }

                        }
                    }
                }
                rotate([0, 0, 45]){
                    scale([0.5, 0.8, 0.6]){
                        intersection() {
                            sphere(r=10);

                            translate([5, 0, 0]){
                                sphere(r=10);
                            }

                        }
                    }
                }
            }
        }

        rotate([90, 0, 0]){
            cylinder(r1=9.5, r2=9.5, h=10, center=true);
        }

    }
}

module eyeball() {
    union(){
        // torus
        rotate_extrude($fn=22) {
            translate([4, 0, 0]) {
                circle(r=2, $fn=22);
            }
        }
        translate([0, 0, -1.5]){
            sphere(r=4);
        }
    }
}

module make_front_fin() {
    translate([0, 0, 1]){
        scale([2, 1.9, 1]){
            difference() {
                make_fluke();

                translate([0, 0, 5]){
                    cube([30, 10, 10], center=true);
                }
            }
        }
    }
}

module front_fin_with_rib() {
    union(){
        make_front_fin();
        // rib
        translate([-7.5, 0, 1]){
            difference() {
                rotate([90, 0, 0]){
                    cylinder(r1=8, r2=8, h=2, center=true);
                }

                translate([3, 0, 0]){
                    rotate([90, 0, 0]){
                        cylinder(r1=9.5, r2=9.5, h=2, center=true);
                    }
                }
                translate([0, 0, 5]){
                    cube([20, 20, 10], center=true);
                }
            }
        }
    }
}

module make_side_fin() {
    union(){
        intersection() {
            union(){
                rotate([90, 0, 0]){
                    cylinder(r1=10, r2=4, h=12, center=false);
                }
                difference() {
                    scale([1, 0.7, 1]){
                        sphere(r=10);
                    }

                    translate([0, -15, 0]){
                        cube([30, 30, 30], center=true);
                    }
                }
            }

            cube([1, 30, 30], center=true);

        }
        // side fin ribs
        for (i = [-2 : abs(1) : 2]) {
            translate([0, -11, (i * 1.6)]){
                rotate([(270 + i * 7), 0, 0]){
                    scale([1, 1, (1.2 - 0.07 * abs(i))]){
                        cylinder(r1=1, r2=1, h=13, center=false);
                    }
                }
            }
        }

    }
}

// right side fin
translate([0, 8.5, 0]){
rotate([0, 180, 290]){
scale([1, 0.5, 0.5]){
make_side_fin();
}
}
}
// body with pointy ends
hull(){
    translate([-22, 0, 0]){
        // tip of nose
        difference() {
            translate([5.15, 0, 0]){
                scale([0.3, 0.112, 0.148]){
                    sphere(r=20);
                }
            }

            translate([8, 0, 0]){
                cube([16, 10, 10], center=true);
            }
        }
    }
    // body
    scale([2, 0.75, 1]){
        sphere(r=10);
    }
    // connect fluke to body
    translate([26.5, 0, 0]){
        scale([1, 0.74, 1]){
            rotate([0, 90, 0]){
                {
                    $fn=16;    //set sides to 16
                    cylinder(r1=2, r2=2, h=0.1, center=true);
                }
            }
        }
    }
}
// left side fin
translate([0, -8.5, 0]){
rotate([0, 0, 250]){
scale([1, 0.5, 0.5]){
make_side_fin();
}
}
}
// fluke body smoother
difference() {
    translate([8.6, 0, 0]){
        // fluke body smoother
        scale([2, 0.56, 1.85]){
            // fluke body smoother unsized
            rotate([180, 90, 0]){
                rotate_extrude($fn=35){
                    translate([0.001, 0, 0]){
                        rotate([0, 0, 270]){
                            difference() {
                                square([10, 4.5], center=false);

                                translate([-3, 6, 0]){
                                    rotate([0, 0, 337]){
                                        square([10, 5], center=false);
                                    }
                                }
                                translate([7.2, 4.94, 0]){
                                    scale([0.1, 0.1, 1]){
                                        circle(r=30);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    translate([37, 0, 0]){
        scale([1, 1, 1.2]){
            rotate([90, 0, 0]){
                cylinder(r1=10, r2=10, h=10, center=true);
            }
        }
    }
}
// top fin
union(){
// top fin
difference() {
    // top fin
    intersection() {
        translate([0, 0, 4]){
            rotate([90, 0, 0]){
                scale([2.1, 1, 1]){
                    cylinder(r1=10, r2=10, h=1, center=true);
                }
            }
        }

        union(){
            translate([-2, 0, 6]){
                rotate([90, 0, 0]){
                    cylinder(r1=10, r2=10, h=10, center=true);
                }
            }
            translate([15, 0, 6]){
                rotate([90, 0, 0]){
                    cylinder(r1=20, r2=20, h=10, center=true);
                }
            }
        }

    }

    translate([21, 0, 2]){
        rotate([90, 0, 0]){
            cylinder(r1=5, r2=5, h=2, center=true);
        }
    }
}
// top fin
difference() {
    translate([-2, 0, 6]){
        rotate([90, 0, 0]){
            cylinder(r1=10, r2=10, h=1, center=true);
        }
    }

    translate([2, 0, 6]){
        rotate([90, 0, 0]){
            cylinder(r1=12, r2=12, h=2, center=true);
        }
    }
}
}
// fluke and front fins
difference() {
    union(){
        translate([10, -1, -7.5]){
            rotate([330, 0, 0]){
                front_fin_with_rib();
            }
        }
        translate([44.4, 0, 0]){
            scale([1.9, 1.6, 1.6]){
                make_fluke();
            }
        }
        translate([10, 1, -7.5]){
            rotate([30, 0, 0]){
                front_fin_with_rib();
            }
        }
    }

    color([0,0,0]) {
        translate([0, 0, -17]){
            cube([99, 66, 5], center=true);
        }
    }
}
// caudal ribs
for (j = [1 : abs(1) : 14]) {
scale([1, 2, 1]){
intersection() {
    translate([(j * 1.4 + 11.8), 0, (0 - j * 1)]){
        rotate([90, 0, 0]){
            // torus
            rotate_extrude($fn=60) {
                translate([25, 0, 0]) {
                    circle(r=0.5, $fn=4);
                }
            }
        }
    }

    // top fin
    intersection() {
        translate([0, 0.5, 4]){
            rotate([90, 0, 0]){
                scale([2.1, 1, 1]){
                    cylinder(r1=10, r2=10, h=1, center=false);
                }
            }
        }

        union(){
            translate([-2, 0, 6]){
                rotate([90, 0, 0]){
                    cylinder(r1=10, r2=10, h=10, center=true);
                }
            }
            translate([15, 0, 6]){
                rotate([90, 0, 0]){
                    cylinder(r1=20, r2=20, h=10, center=true);
                }
            }
        }

    }

}
}
}

// bad fluke ribs
difference() {
    // bad fluke ribs
    for (i = [-3 : abs(1) : 3]) {
        translate([(abs(i * 1.5) + 26.3), 0, (i * 3)]){
            rotate([(270 + i * 7), 0, 270]){
                scale([1.3, 0.6, 0.6]){
                    cylinder(r1=1, r2=0, h=13, center=false);
                }
            }
        }
    }

    translate([49, 0, 0]){
        rotate([90, 0, 0]){
            cylinder(r1=17, r2=17, h=10, center=true);
        }
    }
}
// anal fin
translate([2, -0.5, -9]){
union(){
difference() {
    rotate([0, 10, 0]){
        cube([20, 1, 10], center=false);
    }

    translate([25, 0, 0]){
        rotate([90, 0, 0]){
            cylinder(r1=10, r2=10, h=10, center=true);
        }
    }
}
for (i = [-2 : abs(1) : 0]) {
translate([1, 0.5, (i * 0.6 + 2)]){
rotate([(270 + i * 4), 0, 270]){
scale([1, 0.5, 1]){
cylinder(r1=1, r2=1, h=13, center=false);
}
}
}
}

}
}
// left eyeball
translate([-14.3, 4.75, 2.7]){
rotate([285, 0, 20]){
scale([0.3, 0.3, 0.3]){
eyeball();
}
}
}
// right eyeball
translate([-14.3, -4.75, 2.7]){
rotate([75, 0, 340]){
scale([0.3, 0.3, 0.3]){
eyeball();
}
}
}