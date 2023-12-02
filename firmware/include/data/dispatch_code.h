//
//	This file is automatically generated
//
switch (*DCOMMAND) {
	case 1:
		switch (*DFUNCTION) {
			case 0:
				DSPReset();
				break;
			case 1:
				*((uint32_t *)DPARAMS) = TMRRead();
				break;
		}
		break;
	case 2:
		switch (*DFUNCTION) {
			case 0:
				CONWrite(*DPARAMS);
				break;
			case 1:
				*(DPARAMS) = KBDGetKey();
				break;
			case 2:
				*(DPARAMS) = KBDIsKeyAvailable() ? 0xFF: 0;
				break;
		}
		break;
	case 3:
		switch (*DFUNCTION) {
		}
		break;
	case 4:
		MATHCommon(DPARAMS);
		switch (*DFUNCTION) {
			case 0:
				if (MATHIsFloatBinary()) {
				MATHWriteFloat(MATHReadFloat(MATH_REG1)+MATHReadFloat(MATH_REG2),MATH_REG1);
				} else {
				MATHWriteInt(MATHReadInt(MATH_REG1)+MATHReadInt(MATH_REG2),MATH_REG1);
				}
				break;
			case 1:
				if (MATHIsFloatBinary()) {
				MATHWriteFloat(MATHReadFloat(MATH_REG1)-MATHReadFloat(MATH_REG2),MATH_REG1);
				} else {
				MATHWriteInt(MATHReadInt(MATH_REG1)-MATHReadInt(MATH_REG2),MATH_REG1);
				}
				break;
			case 2:
				if (MATHIsFloatBinary()) {
				MATHWriteFloat(MATHReadFloat(MATH_REG1)*MATHReadFloat(MATH_REG2),MATH_REG1);
				} else {
				MATHWriteInt(MATHReadInt(MATH_REG1)*MATHReadInt(MATH_REG2),MATH_REG1);
				}
				break;
			case 3:
				f1 = MATHReadFloat(MATH_REG2);
				if (f1 == 0.0) {
				*DERROR = 1;
				} else {
				MATHWriteFloat(MATHReadFloat(MATH_REG1)/f1,MATH_REG1);
				}
				break;
			case 4:
				i1 = MATHReadInt(MATH_REG1);
				i2 = MATHReadInt(MATH_REG2);
				if (i2 == 0) {
				*DERROR = 1;
				} else {
				MATHWriteInt(i1/i2,MATH_REG1);
				}
				break;
			case 5:
				i1 = MATHReadInt(MATH_REG1);
				i2 = MATHReadInt(MATH_REG2);
				if (i2 == 0) {
				*DERROR = 1;
				} else {
				MATHWriteInt(abs(i1) % abs(i2),MATH_REG1);
				}
				break;
			case 6:
				*DSTATUS = 0;
				if (MATHIsFloatBinary()) {
				f1 = MATHReadFloat(MATH_REG1);
				f2 = MATHReadFloat(MATH_REG2);
				float diff = (float_abs(f1)+float_abs(f2)) * 0.0000001f;
				if (float_abs(f1-f2) >= diff) {
				*DSTATUS = (f1 < f2 ? 0xFF:0x01);
				}
				} else {
				i1 = MATHReadInt(MATH_REG1);
				i2 = MATHReadInt(MATH_REG2);
				if (i1 != i2) *DSTATUS = (i1 < i2 ? 0xFF:0x01);
				}
				#define FROMRADIANS(n) 	((n) * 180.0 / M_PI)
				#define TORADIANS(n) ((n) * M_PI / 180.0)
				break;
			case 16:
				if (MATHIsFloatUnary()) {
				MATHWriteFloat(-MATHReadFloat(MATH_REG1),MATH_REG1);
				} else {
				MATHWriteInt(-MATHReadInt(MATH_REG1),MATH_REG1);
				}
				break;
			case 17:
				if (MATHIsFloatBinary()) {
				MATHWriteInt(MATHReadInt(MATH_REG1),MATH_REG1);
				}
				break;
			case 18:
				f1 = MATHReadFloat(MATH_REG1);
				if (f1 >= 0) {
				MATHWriteFloat(sqrt(f1),MATH_REG1);
				} else {
				*DERROR = 1;
				}
				break;
			case 19:
				f1 = MATHReadFloat(MATH_REG1);
				MATHWriteFloat(sin(TORADIANS(f1)),MATH_REG1);
				break;
			case 20:
				f1 = MATHReadFloat(MATH_REG1);
				MATHWriteFloat(cos(TORADIANS(f1)),MATH_REG1);
				break;
			case 21:
				f1 = MATHReadFloat(MATH_REG1);
				MATHWriteFloat(tan(TORADIANS(f1)),MATH_REG1);
				break;
			case 22:
				f1 = MATHReadFloat(MATH_REG1);
				MATHWriteFloat(FROMRADIANS(atan(f1)),MATH_REG1);
				break;
			case 23:
				f1 = MATHReadFloat(MATH_REG1);
				MATHWriteFloat(exp(f1),MATH_REG1);
				break;
			case 24:
				f1 = MATHReadFloat(MATH_REG1);
				if (f1 >= 0) {
				MATHWriteFloat(log(f1),MATH_REG1);
				} else {
				*DERROR = 1;
				}
				break;
			case 25:
				if (MATHIsFloatUnary()) {
				MATHWriteFloat(fabs(MATHReadFloat(MATH_REG1)),MATH_REG1);
				} else {
				u1 = MATHReadInt(MATH_REG1);
				if (u1 & 0x80000000) {
				MATHWriteInt(-u1,MATH_REG1);
				}
				}
				break;
			case 26:
				u1 = 0;
				if (MATHIsFloatUnary()) {
				f1 = MATHReadFloat(MATH_REG1);
				if (f1 != 0.0) u1 = (f1 < 0) ? -1 : 1;
				} else {
				i1 = MATHReadInt(MATH_REG1);
				if (i1 != 0) u1 = (i1 < 0) ? -1 : 1;
				}
				MATHWriteInt(u1,MATH_REG1);
				break;
			case 32:
				MATHProcessDecimal(DCOMMAND);
				break;
		}
		break;
}
