//GEOM DATABASE
#include "POV_GEOM\Lego_1x1_geom.inc"
#include "POV_GEOM\Lego_1x1_Base_geom.inc"
#include "POV_GEOM\Lego_1x2_geom.inc"
#include "POV_GEOM\Lego_1x3_geom.inc"
#include "POV_GEOM\Lego_1x4_geom.inc"
#include "POV_GEOM\Lego_1x6_geom.inc"
#include "POV_GEOM\Lego_1x8_geom.inc"
#include "POV_GEOM\Lego_2x2_geom.inc"
#include "POV_GEOM\Lego_2x4_geom.inc"
#include "POV_GEOM\Lego_2x6_geom.inc"
#include "POV_GEOM\Lego_1x1_Probe_geom.inc"
#include "POV_GEOM\Lego_1x2_Slope_geom.inc"
#include "POV_GEOM\Lego_1x3_Slope_geom.inc"
#include "POV_GEOM\Lego_1x3_Heli_geom.inc"
#include "POV_GEOM\Lego_1x6_Arch_geom.inc"
camera {
	location <-32.628158,86.688673,2.666603>
	look_at <16.000000,0.000000,-16.000000>
	angle 32.93461 // horizontal FOV angle
	rotate <0.000000, 0.000000, 0.000000>
	scale < 1.000000, 1.000000, 1.000000 >
}
sky_sphere{
pigment{
image_map{ hdr "Warehouse-with-lights.hdr"
gamma 1.1
map_type 1 interpolate 2}
}// end pigment
rotate <0,40,0> //
} // end sphere with hdr image -----------  
light_source {
	<16.000000,50.000000,-16.000000>
	color rgb <0.300000,0.300000,0.300000>
	area_light <10, 0, 0>, <0, 0, 10>, 10,10
	adaptive 1
	jitter
}
light_source {
	<0.000000,30.000000,-32.000000>
	color rgb <0.300000,0.300000,0.300000>
	area_light <5, 0, 0>, <0, 0, 5>, 5,5
	adaptive 1
	jitter
}
light_source {
	<32.000000,30.000000,0.000000>
	color rgb <0.300000,0.300000,0.300000>
	area_light <5, 0, 0>, <0, 0, 5>, 5,5
	adaptive 1
	jitter
}
light_source {
	<32.000000,30.000000,-32.000000>
	color rgb <0.300000,0.300000,0.300000>
	area_light <5, 0, 0>, <0, 0, 5>, 5,5
	adaptive 1
	jitter
}
light_source {
	<0.000000,30.000000,0.000000>
	color rgb <0.300000,0.300000,0.300000>
	area_light <5, 0, 0>, <0, 0, 5>, 5,5
	adaptive 1
	jitter
}
plane{
<0,1,0>, -0.200000
pigment {color rgb <0.500000,0.500000,0.500000>}
}
#declare DistanceX = 1.00;
#declare DistanceZ = 1.00;
#declare NrX = 0;      // startX
#declare EndNrX = 32;   // endX
#while (NrX < EndNrX) // <-- loop X
#declare NrZ = 0;     // start
#declare EndNrZ = -32;  // end
#while (NrZ > EndNrZ) // <- loop Z
object{Lego_1x1_Base
        translate<-0.5,0,0.5>
        translate<NrX*DistanceX, -0.200000, NrZ*DistanceZ>
		texture {pigment { color rgb <0.000000,0.300000,0.000000> }}
              }
#declare NrZ = NrZ - 1;  // next NrZ
 #end // --------------- end of loop Z
 #declare NrX = NrX + 1;// next NrX
#end // ------------- end of loop X --
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <16.000000,0.000000,-12.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <16.000000,0.000000,-10.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <16.000000,0.000000,-8.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <18.000000,0.000000,-8.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <18.000000,0.000000,-10.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <18.000000,0.000000,-12.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <18.000000,0.000000,-14.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <16.000000,0.000000,-14.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <16.000000,0.000000,-16.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <18.000000,0.000000,-16.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <18.000000,0.000000,-18.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <16.000000,0.000000,-18.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <16.000000,0.000000,-20.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <18.000000,0.000000,-20.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <18.000000,0.000000,-22.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <16.000000,0.000000,-22.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <16.000000,0.000000,-24.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <18.000000,0.000000,-24.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <18.000000,0.000000,-26.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <16.000000,0.000000,-26.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <14.000000,0.000000,-11.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <14.000000,0.000000,-9.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <14.000000,0.000000,-25.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <14.000000,0.000000,-23.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <20.000000,0.000000,-24.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <20.000000,0.000000,-22.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x6
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <20.000000,0.000000,-20.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x6
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <20.000000,0.000000,-14.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x6
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <22.000000,0.000000,-16.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x6
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <22.000000,0.000000,-22.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <22.000000,0.000000,-24.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <20.000000,0.000000,-26.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <22.000000,0.000000,-26.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <24.000000,0.000000,-26.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <24.000000,0.000000,-28.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <26.000000,0.000000,-27.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <20.000000,0.000000,-8.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <22.000000,0.000000,-8.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <22.000000,0.000000,-10.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <24.000000,0.000000,-8.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <24.000000,0.000000,-6.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <26.000000,0.000000,-7.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-270,0>
translate <22.000000,0.000000,-6.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-270,0>
translate <22.000000,0.000000,-27.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <24.000000,0.000000,-23.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <24.000000,0.000000,-9.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <19.000000,1.000000,-10.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <19.000000,1.000000,-8.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <19.000000,1.000000,-24.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <19.000000,1.000000,-22.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x4
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <15.000000,0.000000,-12.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x4
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <15.000000,0.000000,-16.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <15.000000,0.000000,-20.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x6
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <13.000000,0.000000,-19.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x6
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <13.000000,0.000000,-13.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x4
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <13.000000,0.000000,-9.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x4
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <11.000000,0.000000,-8.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x4
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <11.000000,0.000000,-12.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x4
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <11.000000,0.000000,-16.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x4
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <11.000000,0.000000,-20.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <11.000000,0.000000,-24.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <9.000000,0.000000,-12.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <9.000000,0.000000,-14.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <9.000000,0.000000,-16.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <9.000000,0.000000,-18.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <9.000000,0.000000,-20.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <9.000000,0.000000,-22.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <9.000000,0.000000,-10.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <13.000000,0.000000,-7.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <11.000000,0.000000,-6.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <9.000000,0.000000,-7.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <9.000000,0.000000,-25.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <11.000000,0.000000,-26.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_2x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <13.000000,0.000000,-25.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x1
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <17.000000,1.000000,-19.000000>
texture { pigment {color <0.300000,0.300000,0.300000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x1_Probe
translate <-0.5,0,-0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <17.000000,1.000000,-19.000000>
finish { phong 0.15 phong_size 0.2 specular 0.1 reflection{0.05} }
}
light_source{ <0,0, 0>   color rgb<1,1,1> translate<0,0,-0.75> rotate<0,-360,0> translate<17.000000,1.000000,-19.000000> 
  fade_distance 1.0
}
object{
Lego_1x1
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <16.000000,1.000000,-19.000000>
texture { pigment {color <0.300000,0.300000,0.300000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x1_Probe
translate <-0.5,0,-0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <16.000000,1.000000,-19.000000>
finish { phong 0.15 phong_size 0.2 specular 0.1 reflection{0.05} }
}
light_source{ <0,0, 0>   color rgb<1,1,1> translate<0,0,-0.75> rotate<0,-360,0> translate<16.000000,1.000000,-19.000000> 
  fade_distance 1.0
}
object{
Lego_1x1
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <16.000000,2.000000,-21.000000>
texture { pigment {color <0.300000,0.300000,0.300000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x1_Probe
translate <-0.5,0,-0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <16.000000,2.000000,-21.000000>
finish { phong 0.15 phong_size 0.2 specular 0.1 reflection{0.05} }
}
light_source{ <0,0, 0>   color rgb<1,1,1> translate<0,0,-0.75> rotate<0,-180,0> translate<16.000000,2.000000,-21.000000> 
  fade_distance 1.0
}
object{
Lego_1x1
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <17.000000,2.000000,-21.000000>
texture { pigment {color <0.300000,0.300000,0.300000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x1_Probe
translate <-0.5,0,-0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <17.000000,2.000000,-21.000000>
finish { phong 0.15 phong_size 0.2 specular 0.1 reflection{0.05} }
}
light_source{ <0,0, 0>   color rgb<1,1,1> translate<0,0,-0.75> rotate<0,-180,0> translate<17.000000,2.000000,-21.000000> 
  fade_distance 1.0
}
object{
Lego_1x1
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <17.000000,1.000000,-13.000000>
texture { pigment {color <0.300000,0.300000,0.300000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x1_Probe
translate <-0.5,0,-0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <17.000000,1.000000,-13.000000>
finish { phong 0.15 phong_size 0.2 specular 0.1 reflection{0.05} }
}
light_source{ <0,0, 0>   color rgb<1,1,1> translate<0,0,-0.75> rotate<0,-180,0> translate<17.000000,1.000000,-13.000000> 
  fade_distance 1.0
}
object{
Lego_1x1
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <16.000000,1.000000,-13.000000>
texture { pigment {color <0.300000,0.300000,0.300000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x1_Probe
translate <-0.5,0,-0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <16.000000,1.000000,-13.000000>
finish { phong 0.15 phong_size 0.2 specular 0.1 reflection{0.05} }
}
light_source{ <0,0, 0>   color rgb<1,1,1> translate<0,0,-0.75> rotate<0,-180,0> translate<16.000000,1.000000,-13.000000> 
  fade_distance 1.0
}
object{
Lego_1x1
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <16.000000,2.000000,-11.000000>
texture { pigment {color <0.300000,0.300000,0.300000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x1_Probe
translate <-0.5,0,-0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <16.000000,2.000000,-11.000000>
finish { phong 0.15 phong_size 0.2 specular 0.1 reflection{0.05} }
}
light_source{ <0,0, 0>   color rgb<1,1,1> translate<0,0,-0.75> rotate<0,-360,0> translate<16.000000,2.000000,-11.000000> 
  fade_distance 1.0
}
object{
Lego_1x1
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <17.000000,2.000000,-11.000000>
texture { pigment {color <0.300000,0.300000,0.300000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x1_Probe
translate <-0.5,0,-0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <17.000000,2.000000,-11.000000>
finish { phong 0.15 phong_size 0.2 specular 0.1 reflection{0.05} }
}
light_source{ <0,0, 0>   color rgb<1,1,1> translate<0,0,-0.75> rotate<0,-360,0> translate<17.000000,2.000000,-11.000000> 
  fade_distance 1.0
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <15.000000,0.000000,-26.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <14.000000,0.000000,-26.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <14.000000,0.000000,-7.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <15.000000,0.000000,-7.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <13.000000,0.000000,-6.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <12.000000,0.000000,-6.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <12.000000,0.000000,-27.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <13.000000,0.000000,-27.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-90,0>
translate <8.000000,0.000000,-24.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-90,0>
translate <8.000000,0.000000,-9.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x1
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-90,0>
translate <9.000000,0.000000,-9.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x1
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-90,0>
translate <9.000000,0.000000,-24.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <7.000000,0.000000,-15.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <7.000000,0.000000,-17.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <7.000000,0.000000,-13.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <7.000000,0.000000,-19.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x1
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-90,0>
translate <13.000000,1.000000,-16.000000>
texture { pigment {color <0.970000,0.990000,0.500000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x1_Probe
translate <-0.5,0,-0.5>
scale<0,0,-1>
rotate <0,-90,0>
translate <13.000000,1.000000,-16.000000>
finish { phong 0.15 phong_size 0.2 specular 0.1 reflection{0.05} }
}
light_source{ <0,0, 0>   color rgb<1,1,1> translate<0,0,-0.75> rotate<0,-270,0> translate<13.000000,1.000000,-16.000000> 
  fade_distance 1.0
}
object{
Lego_1x1
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <10.000000,1.000000,-15.000000>
texture { pigment {color <0.970000,0.990000,0.500000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x1_Probe
translate <-0.5,0,-0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <10.000000,1.000000,-15.000000>
finish { phong 0.15 phong_size 0.2 specular 0.1 reflection{0.05} }
}
light_source{ <0,0, 0>   color rgb<1,1,1> translate<0,0,-0.75> rotate<0,-180,0> translate<10.000000,1.000000,-15.000000> 
  fade_distance 1.0
}
object{
Lego_1x1
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <10.000000,1.000000,-17.000000>
texture { pigment {color <0.970000,0.990000,0.500000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x1_Probe
translate <-0.5,0,-0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <10.000000,1.000000,-17.000000>
finish { phong 0.15 phong_size 0.2 specular 0.1 reflection{0.05} }
}
light_source{ <0,0, 0>   color rgb<1,1,1> translate<0,0,-0.75> rotate<0,-360,0> translate<10.000000,1.000000,-17.000000> 
  fade_distance 1.0
}
object{
Lego_1x1
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-270,0>
translate <10.000000,1.000000,-16.000000>
texture { pigment {color <0.970000,0.990000,0.500000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x1_Probe
translate <-0.5,0,-0.5>
scale<0,0,-1>
rotate <0,-270,0>
translate <10.000000,1.000000,-16.000000>
finish { phong 0.15 phong_size 0.2 specular 0.1 reflection{0.05} }
}
light_source{ <0,0, 0>   color rgb<1,1,1> translate<0,0,-0.75> rotate<0,-450,0> translate<10.000000,1.000000,-16.000000> 
  fade_distance 1.0
}
object{
Lego_1x1
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <11.000000,1.000000,-12.000000>
texture { pigment {color <0.300000,0.300000,0.300000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x1_Probe
translate <-0.5,0,-0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <11.000000,1.000000,-12.000000>
finish { phong 0.15 phong_size 0.2 specular 0.1 reflection{0.05} }
}
light_source{ <0,0, 0>   color rgb<1,1,1> translate<0,0,-0.75> rotate<0,-180,0> translate<11.000000,1.000000,-12.000000> 
  fade_distance 1.0
}
object{
Lego_1x1
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <9.000000,1.000000,-12.000000>
texture { pigment {color <0.300000,0.300000,0.300000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x1_Probe
translate <-0.5,0,-0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <9.000000,1.000000,-12.000000>
finish { phong 0.15 phong_size 0.2 specular 0.1 reflection{0.05} }
}
light_source{ <0,0, 0>   color rgb<1,1,1> translate<0,0,-0.75> rotate<0,-180,0> translate<9.000000,1.000000,-12.000000> 
  fade_distance 1.0
}
object{
Lego_1x1
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <9.000000,1.000000,-19.000000>
texture { pigment {color <0.300000,0.300000,0.300000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x1_Probe
translate <-0.5,0,-0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <9.000000,1.000000,-19.000000>
finish { phong 0.15 phong_size 0.2 specular 0.1 reflection{0.05} }
}
light_source{ <0,0, 0>   color rgb<1,1,1> translate<0,0,-0.75> rotate<0,-360,0> translate<9.000000,1.000000,-19.000000> 
  fade_distance 1.0
}
object{
Lego_1x1
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <11.000000,1.000000,-19.000000>
texture { pigment {color <0.300000,0.300000,0.300000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x1_Probe
translate <-0.5,0,-0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <11.000000,1.000000,-19.000000>
finish { phong 0.15 phong_size 0.2 specular 0.1 reflection{0.05} }
}
light_source{ <0,0, 0>   color rgb<1,1,1> translate<0,0,-0.75> rotate<0,-360,0> translate<11.000000,1.000000,-19.000000> 
  fade_distance 1.0
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <16.000000,0.000000,-27.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <17.000000,0.000000,-27.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <18.000000,0.000000,-27.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <19.000000,0.000000,-27.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <20.000000,0.000000,-27.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <21.000000,0.000000,-27.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <21.000000,0.000000,-6.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <20.000000,0.000000,-6.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <19.000000,0.000000,-6.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <18.000000,0.000000,-6.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <17.000000,0.000000,-6.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <16.000000,0.000000,-6.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <15.000000,0.000000,-5.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <14.000000,0.000000,-5.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <14.000000,0.000000,-28.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <15.000000,0.000000,-28.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <7.000000,0.000000,-21.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <7.000000,0.000000,-12.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-270,0>
translate <6.000000,0.000000,-10.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-270,0>
translate <6.000000,0.000000,-23.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <7.000000,0.000000,-25.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <7.000000,0.000000,-8.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-270,0>
translate <24.000000,0.000000,-22.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-270,0>
translate <25.000000,0.000000,-21.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-270,0>
translate <25.000000,0.000000,-19.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-270,0>
translate <25.000000,0.000000,-17.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-270,0>
translate <25.000000,0.000000,-15.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-270,0>
translate <25.000000,0.000000,-13.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-270,0>
translate <24.000000,0.000000,-11.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <24.000000,0.000000,-12.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <24.000000,0.000000,-15.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <24.000000,0.000000,-21.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <24.000000,0.000000,-18.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,0,0>
translate <24.000000,0.000000,-17.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x1
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-270,0>
translate <25.000000,0.000000,-18.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x1
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-270,0>
translate <25.000000,0.000000,-16.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x1
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-270,0>
translate <25.000000,0.000000,-14.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x1
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-270,0>
translate <25.000000,0.000000,-12.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x1
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-270,0>
translate <25.000000,0.000000,-20.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x6
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <6.000000,0.000000,-11.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x6
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-180,0>
translate <6.000000,0.000000,-17.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-90,0>
translate <6.000000,0.000000,-9.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-90,0>
translate <6.000000,0.000000,-24.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
object{
Lego_1x2_Slope
translate <-0.5,0,0.5>
scale<0,0,-1>
rotate <0,-90,0>
translate <6.000000,1.000000,-24.000000>
texture { pigment {color <1.000000,1.000000,0.000000>}
finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }
}
}
