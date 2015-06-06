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
	location <17.086795,25.643546,4.737277>
	look_at <16.000000,0.000000,-16.000000>
	angle 32.93461 // horizontal FOV angle
	rotate <0.000000, 0.000000, 0.000000>
	scale < 1.000000, 1.000000, 1.000000 >
}
light_source {
      <0.000000, 5.000000, 5.000000>
     color rgb <1.000000,1.000000,1.000000>
     parallel
     point_at <0,0,0>
     rotate <15.000000,15.000000,15.000000>
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
		texture {pigment { color rgb <0.200000,1.000000,0.200000> }}
              }
#declare NrZ = NrZ - 1;  // next NrZ
 #end // --------------- end of loop Z
 #declare NrX = NrX + 1;// next NrX
#end // ------------- end of loop X --
object{
Lego_1x6_Arch
translate <-0.5,0,0.5>
rotate <0,-180,0>
translate <6.000000,0.000000,-5.000000>
texture { pigment {color <1.000000,0.500000,0.000000>}}
}
object{
Lego_1x1
translate <-0.5,0,0.5>
rotate <0,-180,0>
translate <6.000000,1.000000,-4.000000>
texture { pigment {color <0.500000,1.000000,0.000000>}}
}
object{
Lego_1x1_Probe
translate <-0.5,0,-0.5>
rotate <0,0,0>
translate <6.000000,3.000000,4.000000>
texture { pigment {color <0.500000,1.000000,0.000000>}}
}
object{
Lego_1x2
translate <-0.5,0,0.5>
rotate <0,-180,0>
translate <6.000000,2.000000,-5.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}}
}
object{
Lego_1x1
translate <-0.5,0,0.5>
rotate <0,-180,0>
translate <6.000000,3.000000,-4.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}}
}
object{
Lego_1x2
translate <-0.5,0,0.5>
rotate <0,-180,0>
translate <6.000000,4.000000,-5.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}}
}
object{
Lego_1x4
translate <-0.5,0,0.5>
rotate <0,-180,0>
translate <6.000000,5.000000,-5.000000>
texture { pigment {color <1.000000,1.000000,1.000000>}}
}
object{
Lego_1x4
translate <-0.5,0,0.5>
rotate <0,-180,0>
translate <6.000000,6.000000,-3.000000>
texture { pigment {color <0.000000,1.000000,1.000000>}}
}
object{
Lego_1x4
translate <-0.5,0,0.5>
rotate <0,-180,0>
translate <6.000000,7.000000,-3.000000>
texture { pigment {color <0.000000,1.000000,1.000000>}}
}
object{
Lego_1x4
translate <-0.5,0,0.5>
rotate <0,-180,0>
translate <18.000000,0.000000,-13.000000>
texture { pigment {color <0.000000,1.000000,1.000000>}}
}
object{
Lego_1x4
translate <-0.5,0,0.5>
rotate <0,-180,0>
translate <16.000000,0.000000,-13.000000>
texture { pigment {color <0.000000,1.000000,1.000000>}}
}
object{
Lego_1x4
translate <-0.5,0,0.5>
rotate <0,90,0>
translate <16.000000,1.000000,-13.000000>
texture { pigment {color <0.000000,1.000000,1.000000>}}
}
object{
Lego_1x4
translate <-0.5,0,0.5>
rotate <0,90,0>
translate <16.000000,1.000000,-11.000000>
texture { pigment {color <0.000000,1.000000,1.000000>}}
}
object{
Lego_1x4
translate <-0.5,0,0.5>
rotate <0,90,0>
translate <16.000000,0.000000,-9.000000>
texture { pigment {color <0.000000,1.000000,1.000000>}}
}
object{
Lego_1x4
translate <-0.5,0,0.5>
rotate <0,-180,0>
translate <19.000000,2.000000,-13.000000>
texture { pigment {color <0.000000,1.000000,1.000000>}}
}
object{
Lego_1x4
translate <-0.5,0,0.5>
rotate <0,-90,0>
translate <22.000000,3.000000,-13.000000>
texture { pigment {color <0.000000,1.000000,1.000000>}}
}
object{
Lego_1x4
translate <-0.5,0,0.5>
rotate <0,-90,0>
translate <22.000000,4.000000,-13.000000>
texture { pigment {color <0.000000,1.000000,1.000000>}}
}
