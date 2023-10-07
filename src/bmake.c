#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <parameter> <source_files>\n", argv[0]);
        return 1;
    }

    const char *parameter = argv[1];
    const char *sourceFiles = argv[2];

    createGitIgnoreFile();
    createLicenseFile();
    createManPage(parameter, "Short Description", "Long Description");
    generateMakefile(parameter, sourceFiles);
    generateSourceFiles(parameter, sourceFiles);

    return 0;
}
