#include "Oncologist.h"


Oncologist::Oncologist() :Doctor() {

}
Oncologist::Oncologist(string user, string pass, string cn, string em, double hour_char, string hosp, string loc, int ex) :Doctor(user, pass, cn, em, hour_char, hosp, loc, ex) {

}

string Oncologist::getUserType() {
	return "Oncologist";
}