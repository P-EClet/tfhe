#ifndef TFHE_IO_H
#define TFHE_IO_H

#include "tfhe_core.h"
#include "lwekey.h"
#include "lweparams.h"
#include "lwesamples.h"

#ifdef __cplusplus
#include <cstdio>
#else
#include <stdio.h>
#endif


/**
 * This function prints the lwe parameters to a file
 */
EXPORT void export_lweParams_toFile(FILE* F, const LweParams* lweparams);

/**
 * This constructor function reads and creates a LWEParams from a File. The result
 * must be deleted with delete_lweParams();
 */
EXPORT LweParams* new_lweParams_fromFile(FILE* F);


#ifdef __cplusplus
#include <iostream>

/**
 * This function prints a lweParams to a stream
 */
EXPORT void export_lweParams_toStream(std::ostream& out, const LweParams* lweparams);

/**
 * This constructor function reads and creates a LWEParams from a stream. The result
 * must be deleted with delete_lweParams();
 */
EXPORT LweParams* new_lweParams_fromStream(std::istream& in);


//---------------------------------------------------------------

class TextModeProperties {
    public:
	virtual const std::string& getTypeTitle() const =0;
	virtual const std::string& getProperty(const std::string& name) const =0;
	virtual void setTypeTitle(const std::string& title)=0;
	virtual void setProperty(const std::string& name, const std::string& value)=0;
	virtual ~TextModeProperties() {}
};

TextModeProperties* new_TextModeProperties_fromFile(FILE* F);
TextModeProperties* new_TextModeProperties_fromStream(std::istream& F);
void delete_TextModeProperties(TextModeProperties* ptr);
void print_TextModeProperties_toFile(FILE* F, const TextModeProperties* props);
void print_TextModeProperties_toStream(std::ostream& F, const TextModeProperties* props);


#endif

#endif // TFHE_IO_H

