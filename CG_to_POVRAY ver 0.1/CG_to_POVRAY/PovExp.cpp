#include "PovExp.h"
//#include "Lego.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>(*out)

#define header1(x)\
	x << "//GEOM DATABASE";\
	x << "#include \"Lego_1x1_geom.inc\"\n";\
	x << "#include \"Lego_1x2_geom.inc\"\n";\
	x << "#include \"Lego_1x3_geom.inc\"\n";\
	x << "#include \"Lego_1x4_geom.inc\"\n";\
	x << "#include \"Lego_1x6_geom.inc\"\n";\
	x << "#include \"Lego_1x8_geom.inc\"\n";\
	x << "#include \"Lego_2x2_geom.inc\"\n";\
	x << "#include \"Lego_2x4_geom.inc\"\n";\
	x << "#include \"Lego_2x6_geom.inc\"\n";\
	x << "#include \"Lego_1x1_Probe_geom.inc\"\n";\
	x << "#include \"Lego_1x2_Slope_geom.inc\"\n";\
	x << "#include \"Lego_1x3_Slope_geom.inc\"\n";\
	x << "#include \"Lego_1x3_Heli_geom.inc\"\n";\
	x << "#include \"Lego_1x6_Arch_geom.inc\"\n";

#define camera1(x,TX,TY,TZ,RX,RY,RZ,SX,SY,SZ)\
	x << "camera {\n"\
    x << "	location <0,0,0>\n"\
    x << "	look_at <0,0,11.36285>\n"\
    x << "	angle 32.93461 // horizontal FOV angle\n"\
    x << "	rotate <" << RX << "," << RY << "," << RZ << ">\n"\
	x << "	scale <" << 1.0f/SX << "," << 1.0f/SY << "," << 1.0f/RZ << ">\n"\
    x << "	translate <" << TX << "," << TY << "," <<TZ << ">\n"\
    x << "}\n"

#define parallel_light1(x, PX, PY, PZ,RX,RY,RZ,R,G,B,)\
	x << "light_source {\n"\
    x << "      <" << PX << "," << PY << "," << PZ << ">\n"\
    x << "     color rgb <" << R << "," << G << "," << B << ">\n"\
    x << "     parallel\n"\
    x << "     point_at <0,0,0>\n"\
    x << "     rotate <" << RX << "," << RY << "," << RZ << ">\n"\
    x << "}\n"

#define area_light1(x,PX, PY, PZ, SIZE, R, G, B)\
	x << "light_source {\n"\
	x << "	<" << PX  << "," << PY << "," << PZ ">\n"\
	x << "	color rgb <" << R << "," << G << "," << B ">\n"\
	x << "	area_light <" << SIZE << ", 0, 0>, <0, 0, " << SIZE << ">, " << SIZE << "," << 5 << "\n"\
	x << "	adaptive 1\n"\
	x << "	jitter\n"\
    x << "}\n"


int timestamp = 1;
std::string extension = ".pov";

void header(FILE * out){
	fprintf( out,  "//GEOM DATABASE\n");
	fprintf( out,  "#include \"Lego_1x1_geom.inc\"\n");
	fprintf( out,  "#include \"Lego_1x2_geom.inc\"\n");
	fprintf( out,  "#include \"Lego_1x3_geom.inc\"\n");
	fprintf( out,  "#include \"Lego_1x4_geom.inc\"\n");
	fprintf( out,  "#include \"Lego_1x6_geom.inc\"\n");
	fprintf( out,  "#include \"Lego_1x8_geom.inc\"\n");
	fprintf( out,  "#include \"Lego_2x2_geom.inc\"\n");
	fprintf( out,  "#include \"Lego_2x4_geom.inc\"\n");
	fprintf( out,  "#include \"Lego_2x6_geom.inc\"\n");
	fprintf( out,  "#include \"Lego_1x1_Probe_geom.inc\"\n");
	fprintf( out,  "#include \"Lego_1x2_Slope_geom.inc\"\n");
	fprintf( out,  "#include \"Lego_1x3_Slope_geom.inc\"\n");
	fprintf( out,  "#include \"Lego_1x3_Heli_geom.inc\"\n");
	fprintf( out,  "#include \"Lego_1x6_Arch_geom.inc\"\n");
}

void camera(FILE * out, float TX, float TY, float TZ, float RX, float RY, float RZ, float SX, float SY, float SZ){

	fprintf(out, "camera {\n");
    fprintf(out, "	location <%f,%f,%f>\n",TX,TY,TZ);
    fprintf(out, "	look_at <0,0,0>\n");
    fprintf(out, "	angle 32.93461 // horizontal FOV angle\n");
    fprintf(out, "	rotate <%f, %f, %f>\n", RX,RY,RZ);
	fprintf(out, "	scale < %f, %f, %f >\n", 1.0f/SX, 1.0f/SY, 1.0f,SZ);
    fprintf(out, "	translate <%f,%f,%f>\n", TX, TY, TZ);
    fprintf(out, "}\n");

}

void parallel_light(FILE * out, float PX, float PY, float PZ, float RX, float RY, float RZ, float R, float G, float B){
	fprintf(out, "light_source {\n");
    fprintf(out, "      <%f, %f, %f>\n",PX,PY,PZ);
    fprintf(out, "     color rgb <%f,%f,%f>\n",R,G,B);
    fprintf(out, "     parallel\n");
    fprintf(out, "     point_at <0,0,0>\n");
    fprintf(out, "     rotate <%f,%f,%f>\n", RX,RY,RZ);
    fprintf(out, "}\n");
}

void area_light(FILE * out, float PX, float PY, float PZ, int SIZE, float R, float G, float B){
	fprintf(out, "light_source {\n");
	fprintf(out, "	<%f,%f,%f>\n",PX, PY, PZ);
	fprintf(out, "	color rgb <%f,%f,%f>\n",R,G,B);
	fprintf(out, "	area_light <%d, 0, 0>, <0, 0, %d>, %d,%d\n",SIZE,SIZE,SIZE,SIZE);
	fprintf(out, "	adaptive 1\n");
	fprintf(out, "	jitter\n");
    fprintf(out, "}\n");
}

void ground_plane(FILE * out, float y, float R, float G, float B){
	fprintf(out, "plane{\n");
    fprintf(out, "<0,1,0>, %f\n", y);
    fprintf(out, "pigment {color rgb <%f,%f,%f>}\n",R,G,B);
	fprintf(out,"}\n");
}

void origin_sphere(FILE * out, float size, float R, float G, float B){
	fprintf(out, "sphere{ <0,0,0> 1 pigment {color rgb <%f,%f,%f> }}\n",R,G,B);
}

void lego(FILE * out, char* lego, float PX, float PY, float PZ, int rotation, float R, float G, float B){
	fprintf(out, "object{\n");
	fprintf(out, "%s\n", lego);
	fprintf(out, "translate <-0.5,0,0.5>\n");
	fprintf(out, "rotate <0,%d,0>\n",rotation);
	fprintf(out, "translate <%f,%f,%f>\n", PX,PY,PZ);
	fprintf(out, "texture { pigment {color <%f,%f,%f>}}\n", R,G,B);
	fprintf(out, "}\n");
}

void PovExp::convert(std::string filename ){
	FILE * out;
	std::string file = filename + extension;
	out = fopen( file.c_str(),"w" );
	header(out);
	camera(out,0,3,2,15,0,0,1,1,1);
	parallel_light(out,0,5,5,15,15,15,1,1,1);
	ground_plane(out,0,0.5,0.5,0.5);
	lego(out, "Lego_2x2",0,0,0,0,1,0,0);
	lego(out, "Lego_1x3",3,0,3,90,1,1,0);
	fclose(out);
	//camera(out, TX, TY, TZ, RX, RY, RZ, SX, SY, SZ);




}

void PovExp::convert(){
	char* file;
	itoa(timestamp, file, 10);
	convert(file);
}

int main(){
	PovExp::convert("test1");
	system("POV-Ray\\v3.6\\bin\\pvengine64.exe \/RENDER test3.pov");
}