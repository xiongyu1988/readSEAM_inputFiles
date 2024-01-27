
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "filemanager.h"

std::string UNIFIL, FNCFIL;

std::string fileFolder = "seamInputFiles\\";
std::string fileName = "seam.in";
const std::string FILEIN{ fileFolder + fileName };

std::string extractFilename(const std::string& fullPath) {
	std::string directory = "seamInputFiles\\";
	size_t pos = fullPath.find(directory);
	if (pos != std::string::npos) {
		// Add the length of directory to the found position to start from the end of the directory name
		return fullPath.substr(pos + directory.length());
	}
	// Return empty string if the directory is not found in the path
	return ""; 
}

int main()
{
	std::ifstream file(FILEIN);
	FileManager fileManager; // Instance of FileManager to store file path

	if (file) {
		std::string line;
		while (getline(file, line)) {
			char cAddress = line[0];
			char cDrive = 'C';
			if (cAddress != cDrive) {
				continue;
			}

			if (line.find(".mat") != std::string::npos) {
				std::string filename = extractFilename(line);
				std::ifstream testFile(fileFolder + filename);
				if (testFile) {
					fileManager.setMATFIL(line);
				}
				else {
					if (line.find(".mat") != std::string::npos) {
						std::cerr << "Error: MAT file does not exist - " << line << std::endl;
					}
				}
			}
			else if (line.find(".sub") != std::string::npos) {
				std::string filename = extractFilename(line);
				std::ifstream testFile(fileFolder + filename);
				if (testFile) {
					fileManager.setSUBFIL(line);
				}
				else {
					if (line.find(".sub") != std::string::npos) {
						std::cerr << "Error: SUB file does not exist - " << line << std::endl;
					}
				}
			}
			else if (line.find(".jun") != std::string::npos) {
				std::string filename = extractFilename(line);
				std::ifstream testFile(fileFolder + filename);
				if (testFile) {
					fileManager.setJNCFIL(line);
				}
				else {
					if (line.find(".jun") != std::string::npos) {
						std::cerr << "Error: JUN file does not exist - " << line << std::endl;
					}
				}
			}
			else if (line.find(".exc") != std::string::npos) {
				std::string filename = extractFilename(line);
				std::ifstream testFile(fileFolder + filename);
				if (testFile) {
					fileManager.setEXCFIL(line);
				}
				else {
					if (line.find(".exc") != std::string::npos) {
						std::cerr << "Error: EXC file does not exist - " << line << std::endl;
					}
				}
			}
			else if (line.find(".par") != std::string::npos) {
				std::string filename = extractFilename(line);
				std::ifstream testFile(fileFolder + filename);
				if (testFile) {
					fileManager.setPARFIL(line);
				}
				else {
					if (line.find(".par") != std::string::npos) {
						std::cerr << "Error: PAR file does not exist - " << line << std::endl;
					}
				}
			}
			else {
				// If the file extension is not recognized, print a generic error message
				std::cerr << "Error: File does not exist or unsupported file type - " << line << std::endl;
			}
		}
	}
	else {
		std::cerr << "Unable to open the input file" << std::endl;
		return 1;
	}

	std::cout << "MAT file path: " << fileManager.getMATFIL() << std::endl;
	std::cout << "SUB file path: " << fileManager.getSUBFIL() << std::endl;
	std::cout << "JNC file path: " << fileManager.getJNCFIL() << std::endl;
	std::cout << "EXC file path: " << fileManager.getEXCFIL() << std::endl;
	std::cout << "PAR file path: " << fileManager.getPARFIL() << std::endl;


	//ISEAM();

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file