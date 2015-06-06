#include "POVExp.h"
#include "Lego.h"
#include "Camera.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>


std::string extension = ".pov";

PovExp::PovExp(){
	PovExp::timestamp = 1;
}

void header(FILE * out){
	fprintf( out,  "//GEOM DATABASE\n");
	fprintf( out,  "#include \"POV_GEOM\\Lego_1x1_geom.inc\"\n");
	fprintf( out,  "#include \"POV_GEOM\\Lego_1x1_Base_geom.inc\"\n");
	fprintf( out,  "#include \"POV_GEOM\\Lego_1x2_geom.inc\"\n");
	fprintf( out,  "#include \"POV_GEOM\\Lego_1x3_geom.inc\"\n");
	fprintf( out,  "#include \"POV_GEOM\\Lego_1x4_geom.inc\"\n");
	fprintf( out,  "#include \"POV_GEOM\\Lego_1x6_geom.inc\"\n");
	fprintf( out,  "#include \"POV_GEOM\\Lego_1x8_geom.inc\"\n");
	fprintf( out,  "#include \"POV_GEOM\\Lego_2x2_geom.inc\"\n");
	fprintf( out,  "#include \"POV_GEOM\\Lego_2x4_geom.inc\"\n");
	fprintf( out,  "#include \"POV_GEOM\\Lego_2x6_geom.inc\"\n");
	fprintf( out,  "#include \"POV_GEOM\\Lego_1x1_Probe_geom.inc\"\n");
	fprintf( out,  "#include \"POV_GEOM\\Lego_1x2_Slope_geom.inc\"\n");
	fprintf( out,  "#include \"POV_GEOM\\Lego_1x3_Slope_geom.inc\"\n");
	fprintf( out,  "#include \"POV_GEOM\\Lego_1x3_Heli_geom.inc\"\n");
	fprintf( out,  "#include \"POV_GEOM\\Lego_1x6_Arch_geom.inc\"\n");
}

void camera(FILE * out, float TX, float TY, float TZ, float RX, float RY, float RZ, float SX, float SY, float SZ, float LAX, float LAY, float LAZ){
	float vx = LAX - TX, vy = LAY - TY, vz = LAZ - TZ;
	cout << "Init Camera at position " << TX << "," << TY << "," <<TZ << " look at " << LAX << "," << LAY << "," << LAZ << endl;
	fprintf(out, "camera {\n");
if(World::isbp){
	float td=World::bp->thetha*toDg,ad=World::bp->alpha*toDg;
		fprintf(out, "	location <%d,%d,%d>\n",0 ,0,0);
		fprintf(out, "	look_at <%d,%d,%d>\n", 0,1,0 );
	printf( "	rotate al %f>\n",ad);
		fprintf(out, "	rotate <%f, %d, %d>\n", td,0,0);
		fprintf(out, "	rotate <%d, %f, %d>\n",0,180-ad,0);
		fprintf(out, "	translate <%f,%f,%f>\n", World::bp->cx+ World::worldX/2, World::bp->cy, -World::bp->cz-World::worldZ/2);
		
	
	
}
else{
	fprintf(out, "	location <%f,%f,%f>\n",TX + World::worldX/2 - 1.2*vx ,TY  - 1.2*vy,-(TZ + World::worldZ/2  ) +1.2*vz );
	fprintf(out, "	look_at <%f,%f,%f>\n", LAX + World::worldX/2, LAY, -(LAZ + World::worldZ/2  ));
	cout << "Map to POV-RAY Camera at position " << TX << "," << TY << "," <<TZ << " look at " << LAX+World::worldX << "," << LAY << "," << LAZ-World::worldZ << endl;
    fprintf(out, "	angle 32.93461 // horizontal FOV angle\n");
    fprintf(out, "	rotate <%f, %f, %f>\n", RX,RY,RZ);
	fprintf(out, "	scale < %f, %f, %f >\n", (SX == 0) ? 1 : 1.0f/SX, (SY == 0) ? 1 : 1.0f/SY, (SZ == 0) ? 1 : 1.0f/SZ);
	}
    //fprintf(out, "	translate <%f,%f,%f>\n", TX, TY, TZ);
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

void finally_setting(FILE * out){
	fprintf(out, "finish { phong 0.15 phong_size 0.1 specular 0.05 reflection{0} }\n" );
}

void lego_block(FILE * out, std::string lego, float PX, float PY, float PZ, int rotation, float R, float G, float B){
	cout << "Creating Lego Block " << lego << " at :" << PX << "," <<PY << "," << PZ << endl;
	fprintf(out, "object{\n");
	fprintf(out, "%s\n", lego.c_str());
	fprintf(out, "translate <-0.5,0,0.5>\n");
	fprintf(out, "scale<0,0,-1>\n");
	fprintf(out, "rotate <0,%d,0>\n",-(rotation));
	fprintf(out, "translate <%f,%f,%f>\n", PX,PY/3,-PZ);
	fprintf(out, "texture { pigment {color <%f,%f,%f>}\n", R,G,B);
	finally_setting(out);
	fprintf(out, "}\n");
	//finally_setting(out);
	fprintf(out, "}\n");
}



void lego_plane(FILE * out, float y, int sizeX, int sizeZ, float R, float G, float B){
	cout << "Creating Lego plane" << endl;
	fprintf(out, "#declare DistanceX = 1.00;\n");
	fprintf(out, "#declare DistanceZ = 1.00;\n");
	fprintf(out, "#declare NrX = 0;      // startX\n");
	fprintf(out, "#declare EndNrX = %d;   // endX\n", sizeX);
	fprintf(out, "#while (NrX < EndNrX) // <-- loop X\n");
	fprintf(out, "#declare NrZ = 0;     // start\n");
	fprintf(out, "#declare EndNrZ = -%d;  // end\n", sizeZ);
	fprintf(out, "#while (NrZ > EndNrZ) // <- loop Z\n");
	fprintf(out, "object{Lego_1x1_Base\n");
	fprintf(out, "        translate<-0.5,0,0.5>\n");
	fprintf(out, "        translate<NrX*DistanceX, %f, NrZ*DistanceZ>\n", y);
    fprintf(out, "		texture {pigment { color rgb <%f,%f,%f> }}\n",R,G,B);
    fprintf(out, "              }\n");
	fprintf(out, "#declare NrZ = NrZ - 1;  // next NrZ\n");
	fprintf(out, " #end // --------------- end of loop Z\n");
	fprintf(out, " #declare NrX = NrX + 1;// next NrX\n");
	fprintf(out, "#end // ------------- end of loop X --\n");
}

void hdr(FILE * out){
	fprintf(out, "sky_sphere{\npigment{\nimage_map{ hdr \"Warehouse-with-lights.hdr\"\ngamma 1.1\nmap_type 1 interpolate 2}\n}// end pigment\nrotate <0,40,0> //\n} // end sphere with hdr image -----------  \n");
}

void callPov(std::string filename, int timestamp){
	std::string destination = "\"v3.7 RC7\\bin\\pvengine.exe\" \+I"+ filename;
	destination = destination + " +W1024 +H768 /EXIT";
	cout << "cmd : " << destination.c_str() << endl;
	system(destination.c_str());
	int len = filename.length();
	const char* fileTmp = filename.c_str();
	char *file = (char*) malloc(sizeof(char) * len);
	strcpy(file, fileTmp);
	file[len-1] = 'g';
	file[len-2] = 'n';
	file[len-3] = 'p';
	printf("%s", file);
	system(file);
}

void PovExp::convert(World w, Camera c, std::string filename ){
	vector<Lego*> L = w.allLego;
	
	float Cx = c.getEyeX();
	float Cy = c.getEyeY();
	float Cz = c.getEyeZ();
	float ATx = c.getCenterX();
	float ATy = c.getCenterY();
	float ATz = c.getCenterZ();

	FILE * out;
	std::string file = filename + extension;
	out = fopen( file.c_str(),"w" );
	header(out);
	camera(out, Cx, Cy, Cz, 0,0,0,0,0,0, ATx, ATy, ATz);
	parallel_light(out,0,5,5,15,15,15,1,1,1);
	//ground_plane(out,0,0.5,0.5,0.5);
	lego_plane(out,-0.2,32,32,0.2,1,0.2); 

	for(vector<Lego*>::iterator it = L.begin(); it != L.end(); ++it){
		Lego* l = *it;
		int legoPiece = l->index;
		float R = l->R;
		float G = l->G;
		float B = l->B;
		float PX = l->x;
		float PY = l->y;
		float PZ = l->z;
		int rotation = l->thetha;
		std::string legoP;

		switch(legoPiece){
			case 0 : legoP = "Lego_1x1"; break;
			case 1 : legoP = "Lego_1x2"; break;
			case 2 : legoP = "Lego_1x3"; break;
			case 3 : legoP = "Lego_1x4"; break;
			case 4 : legoP = "Lego_1x6"; break;
			case 5 : legoP = "Lego_1x8"; break;
			case 6 : legoP = "Lego_2x2"; break;
			case 7 : legoP = "Lego_2x4"; break;
			case 8 : legoP = "Lego_2x6"; break;
			case 9 : legoP = "Lego_1x1_Probe"; break;
			case 10: legoP = "Lego_1x2_Slope"; break;
			case 11: legoP = "Lego_1x3_Heli"; break;
			case 12: legoP = "Lego_1x3_Slope"; break;
			case 13: legoP = "Lego_1x6_Arch"; break;
			default: legoP = "EasterEgg"; break;
		}
		cout << legoPiece << endl;
		if(legoPiece == 9){
			cout << "IT'S FUCKING IN!!" << endl;
			lego_block(out, "Lego_1x1", PX,PY,PZ,rotation,R,G,B);
			fprintf(out, "object{\n");
			fprintf(out, "%s\n", legoP);
			fprintf(out, "translate <-0.5,0,0.5>\n");
			fprintf(out, "scale<0,0,-1>\n");
			fprintf(out, "rotate <0,%d,0>\n",-rotation);
			float yy = PY/3; float zz = -PZ;
			fprintf(out, "translate <%f,%f,%f>\n", PX,yy,zz);
			fprintf(out, "}\n");


		} else {
			lego_block(out, legoP, PX, PY, PZ, rotation, R, G,B);
		}
	}

	std::fclose(out);
	callPov(file, timestamp);

}

void PovExp::convert(World w, Camera c){
	char* file = (char*) malloc(sizeof(char) * 10000);
	itoa(timestamp, file, 10);
	timestamp++;
	convert(w, c, file);
}

void PovExp::convert(World * w, Camera * c, std::string filename ){
	vector<Lego*> L = w->allLego;
	
	float Cx = c->getEyeX();
	float Cy = c->getEyeY();
	float Cz = c->getEyeZ();
	float ATx = c->getCenterX();
	float ATy = c->getCenterY();
	float ATz = c->getCenterZ();

	FILE * out;
	std::string file = filename + extension;
	out = fopen( file.c_str(),"w" );
	cout << "File Created" << endl;
	header(out);
	camera(out, Cx, Cy, Cz, 0,0,0,0,0,0, ATx, ATy, ATz);
	hdr(out);
	area_light(out, 16, 50 , -16, 10, 0.3,0.3,0.3);
	area_light(out, 0, 30 , -32, 5, 0.3,0.3,0.3);
	area_light(out, 32, 30 , 0, 5, 0.3,0.3,0.3);
	area_light(out, 32, 30 , -32, 5, 0.3,0.3,0.3);
	area_light(out, 0, 30 , 0, 5, 0.3,0.3,0.3);

	//parallel_light(out,0,5,5,15,15,15,1,1,1);
	ground_plane(out,-0.2,0.5,0.5,0.5);
	lego_plane(out,-0.2,32,32,0,0.3,0); 

	for(vector<Lego*>::iterator it = L.begin(); it != L.end(); ++it){
		Lego* l = *it;
		int legoPiece = l->index;
		float R = l->R;
		float G = l->G;
		float B = l->B;
		float PX = l->x;
		float PY = l->y;
		float PZ = l->z;
		int rotation = l->thetha;
		std::string legoP = "";

		switch(legoPiece){
			case 0 : legoP = "Lego_1x1"; break;
			case 1 : legoP = "Lego_1x2"; break;
			case 2 : legoP = "Lego_1x3"; break;
			case 3 : legoP = "Lego_1x4"; break;
			case 4 : legoP = "Lego_1x6"; break;
			case 5 : legoP = "Lego_1x8"; break;
			case 6 : legoP = "Lego_2x2"; break;
			case 7 : legoP = "Lego_2x4"; break;
			case 8 : legoP = "Lego_2x6"; break;
			case 9 : legoP = "Lego_1x1_Probe"; break;
			case 10: legoP = "Lego_1x2_Slope"; break;
			case 11: legoP = "Lego_1x3_Heli"; break;
			case 12: legoP = "Lego_1x3_Slope"; break;
			case 13: legoP = "Lego_1x6_Arch"; break;
			default: legoP = "EasterEgg"; break;
		}

		if(legoPiece == 9){
			lego_block(out, "Lego_1x1", PX,PY,PZ,rotation,R,G,B);
			fprintf(out, "object{\n");
			fprintf(out, "%s\n", legoP.c_str());
			fprintf(out, "translate <-0.5,0,-0.5>\n");
			fprintf(out, "scale<0,0,-1>\n");
			fprintf(out, "rotate <0,%d,0>\n",-rotation);
			fprintf(out, "translate <%f,%f,%f>\n", PX,PY/3,-PZ);
			fprintf(out, "finish { phong 0.15 phong_size 0.2 specular 0.1 reflection{0.05} }\n" );
			fprintf(out, "}\n");

			fprintf(out,"light_source{ <0,0, 0>   color rgb<1,1,1> translate<0,0,-0.75> rotate<0,%d,0> translate<%f,%f,%f> \n", -rotation-180, PX, PY/3, -PZ);
            fprintf(out, "  fade_distance 1.0\n");
			fprintf(out, "}\n"); 
		} else {
			lego_block(out, legoP, PX, PY, PZ, rotation, R, G,B);
		}
	}

	std::fclose(out);
	callPov(file, timestamp);

}

void PovExp::convert(World * w, Camera * c){
	std::cout << "[Converting]" << endl;
	std::cout << "via Cam X : " << c->x << ", Cam Y : " << c->y << ", Cam Z : " << c->z <<endl;
	char* file = (char*) malloc(sizeof(char) * 10000);
	itoa(timestamp, file, 10);
	timestamp++;
	convert(w, c, file);
}