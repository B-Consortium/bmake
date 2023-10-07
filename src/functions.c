#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void createGitIgnoreFile() {
    FILE *file = fopen(".gitignore", "w");
    if (file == NULL) {
        printf("Error: Unable to create .gitignore file.\n");
        return;
    }

    const char *gitignoreContent = 
        "# Precompiled Headers\n"
        "*.gch\n"
        "*.pch\n"
        "\n"
        "# Libraries\n"
        "*.lib\n"
        "*.a\n"
        "*.la\n"
        "*.lo\n"
        "\n"
        "# Shared objects (inc. Windows DLLs)\n"
        "*.dll\n"
        "*.so\n"
        "*.so.*\n"
        "*.dylib\n"
        "\n"
        "# Executables\n"
        "*.exe\n"
        "*.out\n"
        "*.app\n"
        "*.i*86\n"
        "*.x86_64\n"
        "*.hex\n"
        "\n"
        "# Debug files\n"
        "*.dSYM/\n"
        "*.su\n"
        "*.idb\n"
        "*.pdb\n"
        "\n"
        "# Kernel Module Compile Results\n"
        "*.mod*\n"
        "*.cmd\n"
        ".tmp_versions/\n"
        "modules.order\n"
        "Module.symvers\n"
        "Mkfile.old\n"
        "dkms.conf\n";

    fprintf(file, "%s", gitignoreContent);
    fclose(file);
    printf(".gitignore file created successfully.\n");
}

void createLicenseFile() {
    FILE *file = fopen("LICENSE", "w");
    if (file == NULL) {
        printf("Error: Unable to create LICENSE file.\n");
        return;
    }

    const char *licenseContent =
        "B License\n"
        "=========\n"
        "\n"
        "This is unrestricted, free software that has been released into the public domain.\n"
        "\n"
        "This software can be copied, modified, published, used, compiled, sold, or distributed by anyone, for any purpose, commercial or non-commercial,\n"
        "using any method, and for any purpose.\n"
        "\n"
        "The author or authors of this software transfer any copyright interest in the software to the public domain in jurisdictions that recognize copyright laws.\n"
        "We make this commitment to help people in general at large and to the hindrance of our beneficiaries and replacements. Under copyright law, we intend this\n"
        "dedication to be a clear act of giving up all current and future rights to this software.\n"
        "\n"
        "The software is provided \"as is,\" with no express or implied warranties of any kind, including but not limited to the warranties of merchantability,\n"
        "suitability for a specific purpose, and non-infringement. The authors will not be held responsible for any claims, losses, or other liabilities resulting\n"
        "from the software, its use, or other dealings with it, whether in an action of contract, tort, or otherwise.\n";

    fprintf(file, "%s", licenseContent);
    fclose(file);
    printf("LICENSE file created successfully.\n");
}

void createManPage(const char *name, const char *shortDesc, const char *longDesc) {
    char filename[50];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // Generate the filename with the provided parameter
    sprintf(filename, "%s.6", name);

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Unable to create %s file.\n", filename);
        return;
    }

    // Get the current date in the desired format
    char date[20];
    strftime(date, sizeof(date), "%d %B %Y", &tm);

    fprintf(file, ".\" Manpage for %s\n", name);
    fprintf(file, ".\" Author of this manpage is Aitzaz Imtiaz <aitzazimtiaz.ai@gmail.com>, contact him to correct errors or typos.\n");
    fprintf(file, ".\" This man page is released into the public domain by B-Consortium under B-License and Freedom to Public Access\n");
    fprintf(file, ".TH %s 6 \"%s\" \"1.0\" \"%s User Manual\"\n", name, date, name);
    fprintf(file, ".SH NAME\n");
    fprintf(file, "%s \\- %s\n", name, name);
    fprintf(file, ".SH DESCRIPTION\n");
    fprintf(file, "%s\n", longDesc);
    fprintf(file, ".PP\n");
    fprintf(file, "%s\n", shortDesc);
    fprintf(file, ".SH AUTHOR\n");
    fprintf(file, "Aitzaz Imtiaz ( https://github.com/AitzazImtiaz )\n");
    fprintf(file, ".SH COPYRIGHT\n");
    fprintf(file, "%s was made by B-Consortium under the philosophy that public access and development be encouraged due to which\n", name);
    fprintf(file, "the consortium passed its own B-License which allows anyone to copy this work without necessary attributions.\n");

    fclose(file);
    printf("%s file created successfully.\n", filename);
}

void createSpecFile(const char *name, const char *summary, const char *longDesc) {
    char filename[50];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // Generate the filename with the provided parameter
    sprintf(filename, "%s.spec", name);

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Unable to create %s file.\n", filename);
        return;
    }

    // Get the current date in the desired format
    char date[20];
    strftime(date, sizeof(date), "%d %B %Y", &tm);

    fprintf(file, "Name:           %s\n", name);
    fprintf(file, "Version:        0.0.1\n"); // Fixed version
    fprintf(file, "Release:        1%%{?dist}\n"); // Fixed release
    fprintf(file, "Summary:        %s\n", summary); // Updated line to use input summary
    fprintf(file, "Group:          Development/Tools\n");
    fprintf(file, "License:        B-License\n");
    fprintf(file, "URL:            https://github.com/B-Consortium/%s\n", name); // URL is based on the parameter
    fprintf(file, "Source0:        https://github.com/B-Consortium/%s/archive/v0.0.1.tar.gz\n", name); // Source0 based on parameter
    fprintf(file, "BuildRoot:      %(mktemp -ud %%{_tmppath}/%%{name}-0.0.1-1-XXXXXX)\n"); // Fixed version and release
    fprintf(file, "BuildRequires:  ncurses-devel\n");
    fprintf(file, "\n");
    fprintf(file, "%%description\n");
    fprintf(file, "%s\n", longDesc);
    fprintf(file, "\n");
    fprintf(file, "%%prep\n");
    fprintf(file, "%%setup -q -n %%{name}-0.0.1\n"); // Fixed version
    fprintf(file, "\n");
    fprintf(file, "%%build\n");
    fprintf(file, "make %s\n", name);
    fprintf(file, "\n");
    fprintf(file, "%%install\n");
    fprintf(file, "install -d m0755 %%{buildroot}%%{_bindir}\n");
    fprintf(file, "make install prefix=%%{buildroot}/usr\n");
    fprintf(file, "\n");
    fprintf(file, "%%clean\n");
    fprintf(file, "rm -rf %%{buildroot}\n");
    fprintf(file, "\n");
    fprintf(file, "%%files\n");
    fprintf(file, "%%defattr(-,root,root,-)\n");
    fprintf(file, "%%{_bindir}/%s\n", name);
    fprintf(file, "%%{_mandir}/man6/%s.6%%{ext_man}\n", name);

    fclose(file);
    printf("%s file created successfully.\n", filename);
}


void generateMakefile(const char *target, const char *sources) {
    FILE *makefile = fopen("Makefile", "w");
    if (makefile == NULL) {
        printf("Error: Unable to create Makefile.\n");
        return;
    }

    // Write the Makefile content
    fprintf(makefile, "# Installation directories following GNU conventions\n");
    fprintf(makefile, "prefix ?= /usr/local\n");
    fprintf(makefile, "exec_prefix = $(prefix)\n");
    fprintf(makefile, "bindir = $(exec_prefix)/bin\n");
    fprintf(makefile, "sbindir = $(exec_prefix)/sbin\n");
    fprintf(makefile, "datarootdir = $(prefix)/share\n");
    fprintf(makefile, "datadir = $(datarootdir)\n");
    fprintf(makefile, "includedir = $(prefix)/include\n");
    fprintf(makefile, "mandir = $(datarootdir)/man\n");
    fprintf(makefile, "\n");
    fprintf(makefile, "BIN = bin\n");
    fprintf(makefile, "OBJ = obj\n");
    fprintf(makefile, "SRC = src\n");
    fprintf(makefile, "\n");
    fprintf(makefile, "CC ?= gcc\n");
    fprintf(makefile, "CXX ?= g++\n");
    fprintf(makefile, "CFLAGS ?= -Wextra -Wall -O2\n");
    fprintf(makefile, "CXXFLAGS ?= -Wextra -Wall -O2\n");
    fprintf(makefile, "\n");
    fprintf(makefile, ".PHONY: all install uninstall clean\n");
    fprintf(makefile, "\n");

    // Write the target rule
    fprintf(makefile, "%s: $(OBJ)/%s.o $(OBJ)/aitshal.o %s | $(BIN)\n", target, target, sources);
    fprintf(makefile, "\t$(CXX) $(CXXFLAGS) -o $(BIN)/$@ $^ -lcurl\n");
    fprintf(makefile, "\n");

    // Write the all rule
    fprintf(makefile, "all: %s\n", target);
    fprintf(makefile, "\n");

    // Write the source file rules
    char sourcesCopy[1000];
    strcpy(sourcesCopy, sources);
    char *token = strtok(sourcesCopy, " ");
    while (token != NULL) {
        fprintf(makefile, "$(OBJ)/%s.o: $(SRC)/%s | $(OBJ)\n", token, token);
        fprintf(makefile, "\t$(CC) $(CFLAGS) -o $@ -c $<\n");
        fprintf(makefile, "\n");
        token = strtok(NULL, " ");
    }

    // Write the BIN and OBJ directory rules
    fprintf(makefile, "$(BIN):\n");
    fprintf(makefile, "\tmkdir $(BIN)\n");
    fprintf(makefile, "\n");
    fprintf(makefile, "$(OBJ):\n");
    fprintf(makefile, "\tmkdir $(OBJ)\n");
    fprintf(makefile, "\n");

    // Write the clean rule
    fprintf(makefile, "clean:\n");
    fprintf(makefile, "\trm -rf $(BIN)\n");
    fprintf(makefile, "\trm -rf $(OBJ)\n");
    fprintf(makefile, "\n");

    // Write the install rule
    fprintf(makefile, "install:\n");
    fprintf(makefile, "\tinstall -d $(DESTDIR)$(mandir)/man6\n");
    fprintf(makefile, "\tinstall -m644 aitshal.6 $(DESTDIR)$(mandir)/man6\n");
    fprintf(makefile, "\tinstall -d $(DESTDIR)$(bindir)\n");
    fprintf(makefile, "\tcd $(BIN) && install * $(DESTDIR)$(bindir)\n");
    fprintf(makefile, "\n");

    // Write the uninstall rule
    fprintf(makefile, "uninstall:\n");
    fprintf(makefile, "\trm -f $(DESTDIR)$(bindir)/%s;\n", target);
    fprintf(makefile, "\trm -f $(DESTDIR)$(mandir)/man6/aitshal.6\n");
    fprintf(makefile, "\n");

    fclose(makefile);
    printf("Makefile created successfully.\n");
}

const char licenseText[] = "/*\n"
                           " * B-Licensed property held by B-Consortium\n"
                           " * \n"
                           " * This program is free software; you can redistribute it and/or modify it\n"
                           " * under the the philosophical approach of B-License. See LICENSE for details.\n"
                           " */\n";

void generateSourceFiles(const char *parameter, const char *sourceFiles) {
    // Create the src directory if it doesn't exist
    system("mkdir -p src");

    // Create the {parameter}.c file
    char cFileName[100];
    sprintf(cFileName, "src/%s.c", parameter);
    FILE *cFile = fopen(cFileName, "w");
    if (cFile == NULL) {
        printf("Error: Unable to create %s file.\n", cFileName);
        return;
    }

    // Write the license text to the {parameter}.c file
    fprintf(cFile, "%s", licenseText);

    fclose(cFile);
    printf("%s file created successfully.\n", cFileName);

    // Tokenize the source files
    char sourceFilesCopy[1000];
    strcpy(sourceFilesCopy, sourceFiles);
    char *token = strtok(sourceFilesCopy, " ");
    while (token != NULL) {
        // Create the corresponding .c file
        char sourceCFileName[100];
        sprintf(sourceCFileName, "src/%s.c", token);
        FILE *sourceCFile = fopen(sourceCFileName, "w");
        if (sourceCFile == NULL) {
            printf("Error: Unable to create %s file.\n", sourceCFileName);
            return;
        }

        // Write the license text to the .c file
        fprintf(sourceCFile, "%s", licenseText);

        fclose(sourceCFile);
        printf("%s file created successfully.\n", sourceCFileName);

        // Create the corresponding .h file
        char sourceHFileName[100];
        sprintf(sourceHFileName, "src/%s.h", token);
        FILE *sourceHFile = fopen(sourceHFileName, "w");
        if (sourceHFile == NULL) {
            printf("Error: Unable to create %s file.\n", sourceHFileName);
            return;
        }

        // Write the license text to the .h file
        fprintf(sourceHFile, "%s", licenseText);

        fclose(sourceHFile);
        printf("%s file created successfully.\n", sourceHFileName);

        token = strtok(NULL, " ");
    }
}
