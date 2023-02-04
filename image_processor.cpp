#include "BMP.h"
#include "Image.h"
#include "ParseInput.h"
#include <iostream>

void printHelp() {
	std::cout << "Image Processor" << std::endl;
	std::cout << "CommandLine usage: image_processor [input BMP] [output BMP] [-neg]|[-sobel]|[-sharp]|[-gs]|[-crop Width Heigth]|[-edge Threshold]|[-blur Sigma]" << std::endl;
}

int main(int argc, char** argv) {
	if (argc < 2) {
		printHelp();
		system("pause");
		exit(0);
	}

	const auto [input_file, output_file, filter_options] = ParseCommandLine(argc, argv);

	Image image = BMPReader(input_file);

	ImageProcessor image_processor;
	image_processor.Initialize(filter_options);
	image_processor.ApplyFilters(image);

	BMPWriter(image, output_file);
	return 0;
}