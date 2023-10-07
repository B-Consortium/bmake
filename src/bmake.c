#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "functions.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <parameter> <source_files>\n", argv[0]);
        return 1;
    }

    const char *parameter = argv[1];
    const char *sourceFiles = argv[2];

    // Get short and long descriptions interactively
    char shortDesc[1000];
    char longDesc[1000];
    
    printf("Enter short description: ");
    if (fgets(shortDesc, sizeof(shortDesc), stdin) == NULL) {
        printf("Error reading short description.\n");
        return 1;
    }
    shortDesc[strcspn(shortDesc, "\n")] = '\0'; // Remove newline character

    printf("Enter long description (end with a period on its own line):\n");
    if (fgets(longDesc, sizeof(longDesc), stdin) == NULL) {
        printf("Error reading long description.\n");
        return 1;
    }
    // Remove trailing newline character
    longDesc[strcspn(longDesc, "\n")] = '\0';

    createGitIgnoreFile();
    createLicenseFile();
    createManPage(parameter, shortDesc, longDesc);
    createSpecFile(parameter, shortDesc, longDesc);
    generateMakefile(parameter, sourceFiles);
    generateSourceFiles(parameter, sourceFiles);

    return 0;
}
