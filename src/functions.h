/*
 * B-Licensed property held by B-Consortium
 * 
 * This program is free software; you can redistribute it and/or modify it
 * under the the phiosophical approach of B-License. See LICENSE for details.
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H 1

// Declaration of functions
void createGitIgnoreFile();
void createLicenseFile();
void createManPage(const char *name, const char *shortDesc, const char *longDesc);
void createSpecFile(const char *name, const char *summary, const char *longDesc);
void generateMakefile(const char *target, const char *sources);
void generateSourceFiles(const char *parameter, const char *sourceFiles);

#endif
