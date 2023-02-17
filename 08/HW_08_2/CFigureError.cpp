//
// Created by bogda on 17.02.2023.
//

#include "CFigureError.h"
CFigureError::CFigureError(const char* message) : std::domain_error(message) {}