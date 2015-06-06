#include <vector>
#include <string>
#include "Lego.h"
#include "Camera.h"
using namespace std;


class PovExp{
	vector<Lego*> legoData;
	string filename;
	int timestamp;
public:
	PovExp();
	void convert(World w, Camera c, string filename);
	void convert(World w, Camera c);
	void convert(World * w, Camera * c, string filename);
	void convert(World * w, Camera * c);
	

};