#include "Orthopedic.h"



Orthopedic::Orthopedic() :Doctor() {

}
Orthopedic::Orthopedic(string user, string pass, string cn, string em, double hour_char, string hosp, string loc, int ex) :Doctor(user, pass, cn, em, hour_char, hosp, loc, ex) {

}

string Orthopedic::getUserType() {
	return "Orthopedic";
}