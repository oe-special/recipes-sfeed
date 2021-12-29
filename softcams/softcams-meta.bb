SUMMARY = "meta file for enigma2 softcam packages"

require conf/license/license-gplv2.inc

PROVIDES = "openatv-softcams"

DEPENDS = "enigma2-plugin-extensions-oscamsmartcard"

SOFTCAMS = "\
	enigma2-plugin-softcams-oscam-smod \
	enigma2-plugin-softcams-oscam-smod-ipv4only \
	enigma2-plugin-softcams-oscam-emu \
	enigma2-plugin-softcams-oscam-emu-ipv4only \
	enigma2-plugin-softcams-oscam-trunk \
	enigma2-plugin-softcams-oscam-trunk-ipv4only \
	enigma2-plugin-softcams-oscam-stable \
	enigma2-plugin-softcams-oscam-stable-ipv4only \
	\
	enigma2-plugin-softcams-ncam \
	enigma2-plugin-softcams-ncam-ipv4only \
	\
        enigma2-plugin-softcams-gbox \
	\
        enigma2-plugin-softcams-wicardd \
	\
        enigma2-plugin-softcams-mgcamd \
	\
        enigma2-plugin-softcams-cccam \
        \
        ${@bb.utils.contains("TARGET_ARCH", "mipsel", "enigma2-plugin-softcams-doscam", "", d)} \
        ${@bb.utils.contains("DEFAULTTUNE", "cortexa9hf-neon", "enigma2-plugin-softcams-doscam", "", d)} \
        \
        ${@bb.utils.contains("TARGET_ARCH", "mipsel", "enigma2-plugin-softcams-scam", "", d)} \
"

SOFTCAMS:remove:cortexa9hf-neon = "enigma2-plugin-softcams-gbox"
SOFTCAMS:remove:cortexa9hf-neon = "enigma2-plugin-softcams-mgcamd"
SOFTCAMS:remove:cortexa9hf-neon = "enigma2-plugin-softcams-wicardd"
SOFTCAMS:remove:cortexa9hf-neon = "enigma2-plugin-softcams-cccam"
SOFTCAMS:remove:cortexa7hf-vfp = "enigma2-plugin-softcams-gbox"
SOFTCAMS:remove:cortexa7hf-vfp = "enigma2-plugin-softcams-mgcamd"
SOFTCAMS:remove:cortexa7hf-vfp = "enigma2-plugin-softcams-wicardd"
SOFTCAMS:remove:cortexa7hf-vfp = "enigma2-plugin-softcams-cccam"
SOFTCAMS:remove:cortexa7hf = "enigma2-plugin-softcams-gbox"
SOFTCAMS:remove:cortexa7hf = "enigma2-plugin-softcams-mgcamd"
SOFTCAMS:remove:cortexa7hf = "enigma2-plugin-softcams-wicardd"
SOFTCAMS:remove:cortexa7hf = "enigma2-plugin-softcams-cccam"


DEPENDS += "\
	${SOFTCAMS} \
"

PR = "r0"
