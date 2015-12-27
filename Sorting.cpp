#include <iostream>
using namespace std;

#include <getopt.h>
#include <cstdlib>	// required for 'exit'
#include <string>	// string objects

#include "Sorting.h"

string progname;

void usage()
{
	cerr << progname << " -i <input file> -o <output file>" << endl;
	cerr << "-i : Name of file to sort" << endl;
	cerr << "-o : Name of file to store the sorted result" << endl;
        exit(1);
}

int main(int argc, char **argv)
{
	string input_file, output_file;
	int c;

	progname = argv[0];

	while ((c = getopt(argc, argv, "i:o:")) != -1) {
		switch (c) {
			case 'i': input_file = optarg;
				  break;
			case 'o': output_file = optarg;
				  break;
			default :
				  usage();
		}
	}

	if (input_file.empty()) {
		cerr << "Empty input filename" << endl;
		usage();
	}

	if (output_file.empty()) {
		cerr << "Empty output filename" << endl;
		usage();
	}

	cout << "Input File to sort: " << input_file << endl;
	cout << "Output File to store the sorted result: " << output_file << endl;

	Sorting* sort_file = new Sorting(input_file, output_file);

	// Let us just copy the file to start off with
	unsigned long num_lines = sort_file->copy();

	cout << "Number of lines copied: " << num_lines << endl;

	return 0;
}
