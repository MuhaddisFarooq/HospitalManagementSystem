#include "Dermatologist.h"

Dermatologist::Dermatologist() :Doctor() {

}
Dermatologist::Dermatologist(string user, string pass, string cn, string em, double hour_char, string hosp, string loc, int ex) :Doctor(user, pass, cn, em, hour_char, hosp, loc, ex) {

}

string Dermatologist::getUserType() {
	return "Dermatologist";
}