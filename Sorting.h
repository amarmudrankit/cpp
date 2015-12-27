#include <fstream>	// required for ifstream / ofstream

class Sorting {

	string input_file, output_file;

	ifstream infile;
	ofstream outfile;

public:
	Sorting(string input_file, string output_file);		// Constructor
	~Sorting();						// Destructor
	int copy();
};

// "::" is a scope resolution operator for a function, telling compiler to call the
// function in the scope of given class
Sorting::Sorting(string input_file, string output_file)
{
	input_file = input_file;
	output_file = output_file;

	// Constructor of ifstream expects a const char * and not a string
	// object.  Hence the conversion
	infile.open(input_file.c_str());
	if (!infile) {
		cerr << "Failed to open input file: " << input_file << endl;
		exit(1);
	}

	outfile.open(output_file.c_str());
	if (!outfile) {
		cerr << "Failed to open output file: " << output_file << endl;
		exit(1);
	}
}

Sorting::~Sorting()
{
	infile.close();
	outfile.close();
}

int Sorting::copy()
{
	string line;
	unsigned long num_lines = 0;

	while (getline(infile, line)) {
		outfile << line << "\n";
		num_lines++;
	}

	outfile.flush();
	return num_lines;
}
