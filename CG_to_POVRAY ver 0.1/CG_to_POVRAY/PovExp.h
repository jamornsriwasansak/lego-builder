#include <vector>
#include <string>
#include "Lego.h"
using namespace std;


class PovExp{
	static vector<Lego*> legoData;
	string filename;
public:
	static void convert(string filename);
	void convert();
	void convert(World** world , char* filename);
	void convert(vector<Lego*>);
	void init(vector<Lego*>, char* filename);

};