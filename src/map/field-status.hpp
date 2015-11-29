/**
 * @author Arwed Mett
 */
#ifndef THESEUS_MAP_FIELDSTATUS
#define THESEUS_MAP_FIELDSTATUS

namespace theseus {
namespace map {
	enum FieldStatus {
		FREE,
		OCCUPIED, //A brick will be placed here.
		VERTICAL_RESTRICTED, //No Vertical brick can be placed on the field
		HORIZONTAL_RESTRICTED, //No horizontal bick can be placed on the field
		RESTRICTED //This field is reserved, so no object (brick) can be placed on it.
	};
}
}

#endif
