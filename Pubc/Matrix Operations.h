/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once

#include <cstddef>
#include "BlackRoot/Pubc/Tuple.h"

namespace BlackRoot {
namespace Math {

    namespace Meta {
        static const int Meta_Largest_Determinant = 3;
    }
	
	template<typename scalar>
	inline scalar Determinant(scalar x0y0) {
		return x0y0;
	}
	
	template<typename scalar>
	inline scalar Determinant(scalar x0y0, scalar x1y0,
							  scalar x0y1, scalar x1y1) {
		return (x0y0 * x1y1) - (x1y0 * x0y1);
	}
	
	template<typename scalar>
	inline scalar Determinant(scalar x0y0, scalar x1y0, scalar x2y0,
							  scalar x0y1, scalar x1y1, scalar x2y1,
							  scalar x0y2, scalar x1y2, scalar x2y2) {
		return   x0y0 * (x1y1 * x2y2 - x2y1 * x1y2)
			   - x1y0 * (x0y1 * x2y2 - x2y1 * x0y2)
			   + x2y0 * (x0y1 * x1y2 - x1y1 * x0y2);
	}

	template<typename scalar, int dimensionality>
	inline scalar Determinant(scalar * dat) {
		if (dimensionality == 1) {
			return Determinant(dat[0]);
		}
		if (dimensionality == 2) {
			return Determinant(dat[0], dat[1],
							   dat[2], dat[3]);
		}
		if (dimensionality == 3) {
			return Determinant(dat[0], dat[1], dat[2],
							   dat[3], dat[4], dat[5],
                               dat[6], dat[7], dat[8]);
		}
	}

}
}